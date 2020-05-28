/*
 * Copyright (c) 2015-2019 Intel Corporation
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

package com.intel.rsd.nodecomposer.externalservices.actions;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonPropertyOrder;
import com.intel.rsd.nodecomposer.business.services.redfish.odataid.ODataId;

import static com.fasterxml.jackson.annotation.JsonInclude.Include.NON_DEFAULT;

@JsonPropertyOrder({"Links"})
@JsonInclude(NON_DEFAULT)
public class EthernetSwitchPortResourceModificationRequest {
    @JsonProperty("Links")
    private EthernetSwitchPortLinks links;

    public void setLinks(ODataId primaryVlan) {
        EthernetSwitchPortLinks portLinks = new EthernetSwitchPortLinks();
        portLinks.setPrimaryVlan(primaryVlan);

        if (portLinks.getPrimaryVlan() != null) {
            links = portLinks;
        }
    }
}
