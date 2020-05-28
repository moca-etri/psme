/*!
 * @brief Manager builder class implementation.
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
 * @file manager_builder.cpp
 */

#include "discovery/builders/fpgaof_manager_builder.hpp"


using namespace agent::fpgaof::discovery;


agent_framework::model::Manager FpgaofManagerBuilder::build_enclosure() {
    agent_framework::model::Manager manager{};

    manager.set_manager_type(agent_framework::model::enums::ManagerInfoType::EnclosureManager);
    manager.set_status({agent_framework::model::enums::State::Enabled, agent_framework::model::enums::Health::OK});

    manager.add_collection(agent_framework::model::attribute::Collection{
        agent_framework::model::enums::CollectionName::Chassis,
        agent_framework::model::enums::CollectionType::Chassis
    });
    manager.add_collection(agent_framework::model::attribute::Collection{
        agent_framework::model::enums::CollectionName::Systems,
        agent_framework::model::enums::CollectionType::Systems
    });
    manager.add_collection(agent_framework::model::attribute::Collection{
        agent_framework::model::enums::CollectionName::Fabrics,
        agent_framework::model::enums::CollectionType::Fabrics
    });

    return manager;
}
