/*!
 * @brief System builder class interface.
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
 * @file system_builder.hpp
 */

#pragma once



#include "agent-framework/discovery/builders/system_builder.hpp"


namespace agent {
namespace fpgaof {
namespace discovery {

class FpgaofSystemBuilder {
public:

    /*!
     * @brief Build default system object.
     * @param[in] parent_uuid UUID of the parent component.
     * @param[in] chassis_uuid UUID of the chassis component.
     * @return Default system object.
     */
    static agent_framework::model::System build_virtual(const Uuid& parent_uuid, const Uuid& chassis_uuid);
};

}
}
}

