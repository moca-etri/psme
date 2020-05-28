/*!
 * @brief Trigger endpoint
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
 * @file trigger.cpp
 */

#include "psme/rest/endpoints/telemetry/trigger.hpp"



using namespace psme::rest;
using namespace psme::rest::constants;


namespace {
json::Json make_prototype() {
    json::Json r(json::Json::value_t::object);

    r[Common::ODATA_CONTEXT] = "/redfish/v1/$metadata#Trigger.Trigger";
    r[Common::ODATA_ID] = json::Json::value_t::null;
    r[Common::ODATA_TYPE] = "#Triggers.v1_0_0.Triggers";
    r[Common::ID] = json::Json::value_t::null;
    r[Common::NAME] = "Triggers";
    r[Common::DESCRIPTION] = "Triggers description";
    r[Common::STATUS][Common::STATE] = json::Json::value_t::null;
    r[Common::STATUS][Common::HEALTH] = json::Json::value_t::null;
    r[Common::STATUS][Common::HEALTH_ROLLUP] = json::Json::value_t::null;
    r[TelemetryCommon::POLLING_INTERVAL_MS] = json::Json::value_t::null;
    r[Trigger::TRIGGER_TYPE] = json::Json::value_t::null;
    r[Trigger::TRIGGER_ACTIONS] = json::Json::value_t::array;
    r[TelemetryCommon::METRIC_REPORT_DESTINATION] = json::Json::value_t::null;
    r[Trigger::NUMERIC_TRIGGERS] = json::Json::value_t::array;
    r[Trigger::DISCRETE_TRIGGERS] = json::Json::value_t::array;
    r[Common::ACTIONS][Common::OEM] = json::Json::value_t::object;
    r[Common::LINKS][TelemetryCommon::METRICS] = json::Json::value_t::array;
    r[Common::LINKS][TelemetryCommon::LOG_TO] = json::Json::value_t::null;

    return r;
}
}


endpoint::Trigger::Trigger(const std::string& path) : EndpointBase(path) {}


endpoint::Trigger::~Trigger() {}


void endpoint::Trigger::get(const server::Request& request, server::Response& response) {
    auto json = make_prototype();
    json[Common::ODATA_ID] = PathBuilder(request).build();

    set_response(response, json);
}


[[noreturn]] void endpoint::Trigger::del(const server::Request&, server::Response&) {
    throw agent_framework::exceptions::NotImplemented("This method is not implemented.");
}
