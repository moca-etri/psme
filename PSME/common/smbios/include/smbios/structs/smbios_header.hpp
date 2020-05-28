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
 * @file smbios_header.hpp
 *
 * @brief SMBIOS structure header
 * */

#pragma once
#include <cstdint>

#pragma pack(push, 1)

namespace smbios {
namespace parser {

struct SMBIOS_OOB_HEADER {
    uint8_t type;
    uint8_t length;
    uint16_t handle;
};

}
}
#pragma pack(pop)

