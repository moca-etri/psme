/*!
 * @brief Definition of Network Device Functions Collection endpoint
 *
 * @copyright Copyright (c) 2017-2019 Intel Corporation
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
 * @file network_device_functions_collection.cpp
 */

#include "psme/rest/constants/constants.hpp"
#include "psme/rest/endpoints/system/network_device_functions_collection.hpp"
#include "agent-framework/module/compute_components.hpp"



using namespace psme::rest::endpoint;
using namespace psme::rest::constants;
using namespace agent_framework::module;

namespace {
json::Json make_prototype() {
    json::Json r(json::Json::value_t::object);

    r[Common::ODATA_CONTEXT] = "/redfish/v1/$metadata#NetworkDeviceFunctionCollection.NetworkDeviceFunctionCollection";
    r[Common::ODATA_ID] = json::Json::value_t::null;
    r[Common::ODATA_TYPE] = "#NetworkDeviceFunctionCollection.NetworkDeviceFunctionCollection";
    r[Common::NAME] = "Network Device Functions Collection";
    r[Common::DESCRIPTION] = "Collection of Network Device Functions";
    r[Collection::ODATA_COUNT] = json::Json::value_t::null;
    r[Collection::MEMBERS] = json::Json::value_t::array;

    return r;
}
}


NetworkDeviceFunctionsCollection::NetworkDeviceFunctionsCollection(const std::string& path) : EndpointBase(path) {}


NetworkDeviceFunctionsCollection::~NetworkDeviceFunctionsCollection() {}


void NetworkDeviceFunctionsCollection::get(const server::Request& req, server::Response& res) {
    auto json = ::make_prototype();

    json[Common::ODATA_ID] = PathBuilder(req).build();

    auto device_uuid = psme::rest::model::find<agent_framework::model::System, agent_framework::model::NetworkDevice>(
        utils::get_network_device_request_parameters(req.params)).get_uuid();

    auto keys = ComputeComponents::get_instance()->
        get_network_device_function_manager().get_ids(device_uuid);

    json[Collection::ODATA_COUNT] =
        static_cast<std::uint32_t>(keys.size());
    for (const auto& key : keys) {
        json::Json link_elem(json::Json::value_t::object);
        link_elem[Common::ODATA_ID] = PathBuilder(req).append(key).build();
        json[Collection::MEMBERS].push_back(std::move(link_elem));
    }
    set_response(res, json);
}

