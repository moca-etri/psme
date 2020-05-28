/*!
 * @copyright
 * Copyright (c) 2015-2019 Intel Corporation
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
 * @brief Collection of functions for dealing with time
 * @file time.hpp
 * */

#pragma once

#include <string>



namespace agent_framework {
namespace utils {

/*!
 * Make a string containg a timestamp compliant with ISO 8601 standard
 *
 * @return Timestamp string
 * */
const std::string make_iso_8601_timestamp(time_t raw_time = time(nullptr));

}
}
