/*
 * Copyright (c) 2019 Intel Corporation
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

package com.intel.rsd.nodecomposer.business.redfish.services.detach;

import com.intel.rsd.nodecomposer.business.redfish.services.actions.ZoneActionsInvoker;
import com.intel.rsd.nodecomposer.business.redfish.services.helpers.AttachDetachOperationContext;
import com.intel.rsd.nodecomposer.persistence.redfish.Endpoint;
import lombok.val;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class EndpointRemoteDetachStrategy implements RemoteDetachStrategy<Endpoint> {

    private final ZoneActionsInvoker zoneActionsInvoker;

    @Autowired
    public EndpointRemoteDetachStrategy(ZoneActionsInvoker zoneActionsInvoker) {
        this.zoneActionsInvoker = zoneActionsInvoker;
    }

    @Override
    public void detachOnRemoteFabric(Endpoint assetToBeDetached, AttachDetachOperationContext context) {
        val endpointOdataId = assetToBeDetached.getUri();
        val zoneOdataId = assetToBeDetached.getZone().getUri();

        zoneActionsInvoker.removeFromZone(endpointOdataId, zoneOdataId);

        context.setTargetEndpointODataId(endpointOdataId);
        context.setRelatedZoneODataId(zoneOdataId);
    }

    @Override
    public void onAfterRemoteDetach(Endpoint resource) {
        //do nothing
    }
}
