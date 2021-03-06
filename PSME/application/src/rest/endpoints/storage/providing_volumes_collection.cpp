/*!
 * @brief Providing Volumes collection endpoint
 *
 * @copyright Copyright (c) 2019 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file providing_volumes_collection.cpp
 */


#include "psme/rest/constants/constants.hpp"
#include "psme/rest/endpoints/storage/providing_volumes_collection.hpp"
#include "psme/rest/validators/json_validator.hpp"
#include "psme/rest/model/handlers/generic_handler_deps.hpp"



using namespace psme::rest;
using namespace psme::rest::endpoint;
using namespace psme::rest::validators;
using namespace psme::rest::constants;

using namespace agent_framework::module;

namespace {

json::Json make_prototype() {
    json::Json r(json::Json::value_t::object);

    r[Common::ODATA_CONTEXT] = "/redfish/v1/$metadata#VolumeCollection.VolumeCollection";
    r[Common::ODATA_ID] = json::Json::value_t::null;
    r[Common::ODATA_TYPE] = "#VolumeCollection.VolumeCollection";
    r[Common::NAME] = "Volume Collection";
    r[Common::DESCRIPTION] = "Volume Collection description";
    r[Collection::ODATA_COUNT] = 0;
    r[Collection::MEMBERS] = json::Json::value_t::array;

    return r;
}

}


ProvidingVolumesCollection::ProvidingVolumesCollection(const std::string& path) : EndpointBase(path) {}


ProvidingVolumesCollection::~ProvidingVolumesCollection() {}


void ProvidingVolumesCollection::get(const server::Request& request, server::Response& response) {
    auto r = ::make_prototype();
    r[constants::Common::ODATA_ID] = PathBuilder(request).build();

    auto storage_pool_uuid =
        psme::rest::model::try_find<agent_framework::model::StorageService, agent_framework::model::StoragePool>(
            request.params).get_uuid();

    if (!storage_pool_uuid.has_value()) {
        auto volume_uuid =
            psme::rest::model::try_find<agent_framework::model::StorageService, agent_framework::model::Volume>(
                request.params).get_uuid();

        if (!volume_uuid.has_value()) {
            throw agent_framework::exceptions::NotFound("StoragePool or Volume with given ID not found.");
        }
    }

    set_response(response, r);
}
