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

import com.fasterxml.jackson.annotation.JsonProperty;

public class MemorySecureEraseRequest {

    @JsonProperty("ResetConfiguration")
    private Boolean resetConfiguration;

    @JsonProperty("EraseConfigurationKeys")
    private Boolean eraseConfigurationKeys;

    public MemorySecureEraseRequest(Boolean resetConfiguration, Boolean eraseConfigurationKeys) {
        this.resetConfiguration = resetConfiguration;
        this.eraseConfigurationKeys = eraseConfigurationKeys;
    }
}
