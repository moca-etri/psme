/*!
 * @brief Chassis discoverer interface.
 *
 * @copyright Copyright (c) 2018-2019 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file chassis_discoverer.hpp
 */

#pragma once


#include "agent-framework/module/model/chassis.hpp"
#include "agent-framework/discovery/discoverers/chassis_discoverer.hpp"


namespace agent {
namespace fpgaof {
namespace discovery {

class FpgaofChassisDiscoverer : public agent_framework::discovery::ChassisDiscoverer {
public:

    /*! Virtual destructor */
    virtual ~FpgaofChassisDiscoverer() {}


    /*!
     * @brief Perform discovery of chassis object.
     * @param parent_uuid Parent UUID.
     * @return Chassis object filled with discovered data.
     * */
    virtual agent_framework::model::Chassis discover(const Uuid& parent_uuid) override;

};

}
}
}