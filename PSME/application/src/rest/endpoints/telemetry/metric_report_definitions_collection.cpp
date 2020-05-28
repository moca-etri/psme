/*!
 * @brief Metric report definitions collection endpoint
 *
 * @copyright Copyright (c) 2017-2019 Intel Corporation.
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
 * @file metric_report_definitions_collection.cpp
 */

#include "psme/rest/endpoints/telemetry/metric_report_definitions_collection.hpp"



using namespace psme::rest::constants;
using namespace psme::rest::endpoint;

namespace {
json::Json make_prototype() {
    json::Json r(json::Json::value_t::object);

    r[Common::ODATA_CONTEXT] = "/redfish/v1/$metadata#MetricReportDefinitionCollection.MetricReportDefinitionCollection";
    r[Common::ODATA_ID] = json::Json::value_t::null;
    r[Common::ODATA_TYPE] = "#MetricReportDefinitionCollection.MetricReportDefinitionCollection";
    r[Common::NAME] = "MetricReport Definition Collection";
    r[Common::DESCRIPTION] = "MetricReport Definition Collection";
    r[Collection::ODATA_COUNT] = 0;
    r[Collection::MEMBERS] = json::Json::value_t::array;

    return r;
}
}

MetricReportDefinitionsCollection::MetricReportDefinitionsCollection(const std::string& path) : EndpointBase(path) {}


MetricReportDefinitionsCollection::~MetricReportDefinitionsCollection() {}


void MetricReportDefinitionsCollection::get(const server::Request& request, server::Response& response) {
    auto json = ::make_prototype();

    json[Common::ODATA_ID] = PathBuilder(request).build();

    // TODO: fill count and members

    set_response(response, json);
}


[[noreturn]] void MetricReportDefinitionsCollection::post(const server::Request&, server::Response&) {
    throw agent_framework::exceptions::NotImplemented("This method is not implemented.");
}
