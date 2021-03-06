/*!
 * @brief MemoryChunks builder class implementation.
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
 * @file memory_chunks_builder.cpp
 */

#include "discovery/builders/memory_chunks_builder.hpp"

using namespace agent::compute::discovery;
using namespace agent_framework::model;

agent_framework::model::MemoryChunks MemoryChunksBuilder::build_default(const Uuid& parent_uuid) {
    return MemoryChunks{parent_uuid};
}
