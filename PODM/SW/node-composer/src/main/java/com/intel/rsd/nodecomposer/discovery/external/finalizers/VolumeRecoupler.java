/*
 * Copyright (c) 2018-2019 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.intel.rsd.nodecomposer.discovery.external.finalizers;

import com.intel.rsd.nodecomposer.persistence.redfish.ComposedNode;
import com.intel.rsd.nodecomposer.persistence.redfish.Volume;
import lombok.extern.slf4j.Slf4j;
import lombok.val;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

import java.net.URI;
import java.util.Collection;
import java.util.Set;

import static com.intel.rsd.nodecomposer.persistence.redfish.base.StatusControl.statusOf;
import static com.intel.rsd.nodecomposer.types.EntityRole.TARGET;
import static java.lang.String.format;
import static java.util.Objects.isNull;
import static java.util.stream.Collectors.toList;
import static java.util.stream.Collectors.toSet;
import static org.apache.commons.collections.CollectionUtils.isNotEmpty;
import static org.springframework.beans.factory.config.ConfigurableBeanFactory.SCOPE_SINGLETON;

@Slf4j
@Component
@Scope(SCOPE_SINGLETON)
class VolumeRecoupler extends Recoupler<Volume> {
    @Override
    protected void reattach(ComposedNode node, Collection<Volume> assets) {
        val associatedVolumesUris = node.getAssociatedVolumesUris();

        val volumesToReAttach = assets.stream()
            .filter(volume -> associatedVolumesUris.contains(volume.getUri().toUri()))
            .collect(toList());

        if (!associatedVolumesUris.isEmpty() && volumesToReAttach.isEmpty()) {
            log.warn(format("Volumes with URIs %s associated with composed node were not found.", associatedVolumesUris));
            return;
        }

        for (Volume volume : volumesToReAttach) {
            node.attachAsset(volume);
        }
    }

    @Override
    protected boolean verify(ComposedNode node) {
        return node.getAssociatedVolumesUris().isEmpty()
            || composedNodeVolumesCollectionIsConsistent(node);
    }

    private boolean composedNodeVolumesCollectionIsConsistent(ComposedNode node) {
        return !node.getVolumes().isEmpty()
            && allVolumesAreConnectedToNode(node)
            && allVolumesAreHealthyAndConnectedWithEndpoints(node);
    }

    private boolean allVolumesAreConnectedToNode(ComposedNode node) {
        return node.getAssociatedVolumesUris().size() == node.getVolumes().size()
            && composedNodeContainsAllAssociatedVolumes(node);
    }

    private boolean composedNodeContainsAllAssociatedVolumes(ComposedNode node) {
        Set<URI> composedNodeVolumesUris = node.getVolumes().stream()
            .filter(Volume::isAchievable)
            .map(volume -> volume.getUri().toUri())
            .collect(toSet());

        return composedNodeVolumesUris.containsAll(node.getAssociatedVolumesUris());
    }

    private boolean allVolumesAreHealthyAndConnectedWithEndpoints(ComposedNode composedNode) {
        return composedNode.getVolumes().stream().allMatch(volume ->
            statusOf(volume).isEnabled().isHealthy().verify()
                && isNotEmpty(volume.getEntityConnections())
                && volume.getEntityConnections().stream()
                .noneMatch(connectedEntity -> isNull(connectedEntity.getEndpoint()) && TARGET.equals(connectedEntity.getEntityRole()))
        );
    }
}
