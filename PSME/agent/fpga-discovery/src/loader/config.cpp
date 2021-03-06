/*!
 * @brief Implementation of FpgaDiscoveryConfig class.
 *
 * @copyright Copyright (c) 2019 Intel Corporation
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
 * @file config.cpp
 */

#include "loader/config.hpp"

#include <stdexcept>

using namespace std;
using namespace agent::fpga_discovery::loader;

/*! @TODO resolve network intercaces  */
//const nvmf_discovery::Interfaces& FpgaDiscoveryConfig::get_discovery_service_interfaces() const {
//    return m_interfaces;
//}
//
//void FpgaDiscoveryConfig::set_discovery_service_interfaces(const nvmf_discovery::Interfaces& interfaces) {
//    m_interfaces = interfaces;
//}

void FpgaDiscoveryConfig::set_ipv4_address(const string& ip) {
    lock_guard<mutex> lock{m_mutex};
    m_ipv4_address = ip;
}

string FpgaDiscoveryConfig::get_ipv4_address() const {
    lock_guard<mutex> lock{m_mutex};
    return m_ipv4_address;
}

void FpgaDiscoveryConfig::set_location_offset(uint32_t location_offset) {
    lock_guard<mutex> lock{m_mutex};
    m_location_offset = location_offset;
}

uint32_t FpgaDiscoveryConfig::get_location_offset() const {
    lock_guard<mutex> lock{m_mutex};
    return m_location_offset;
}

void FpgaDiscoveryConfig::set_parent_id(const string& parent_id) {
    lock_guard<mutex> lock{m_mutex};
    m_parent_id = parent_id;
}

string FpgaDiscoveryConfig::get_parent_id() const {
    lock_guard<mutex> lock{m_mutex};
    return m_parent_id;
}

FpgaDiscoveryConfig::~FpgaDiscoveryConfig() { }
