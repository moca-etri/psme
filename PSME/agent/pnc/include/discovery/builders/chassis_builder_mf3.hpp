/*!
 * @copyright
 * Copyright (c) 2016-2019 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * @file chassis_builder_mf3.hpp
 *
 * @brief ChassisBuilderMf3 interface
 * */

#pragma once

#include "discovery/builders/abstract_builder.hpp"
#include "agent-framework/module/pnc_components.hpp"
#include "discovery/builders/chassis_builder.hpp"
#include "fru_eeprom.hpp"

namespace agent {
namespace pnc {
namespace discovery {
namespace builders {

/*!
* @brief Builder used to create chassis objects
*/
class ChassisBuilderMf3 : public ChassisBuilder {

public:

    using ReturnType = ChassisBuilderMf3&;

    ChassisBuilderMf3() = default;
    ~ChassisBuilderMf3() = default;

    /*!
    * @brief Performs construction of the default object
    * */
    virtual void build_default() override;

    /*!
     * @brief Updates chassis FRU info
     * @return Pointer to the builder
     * */
    virtual ReturnType update_fru(const FruEeprom& fru_eeprom) override;
};

}
}
}
}


