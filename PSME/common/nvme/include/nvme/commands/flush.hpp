/*!
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
 * @file nvme/commands/flush.hpp
 */

#pragma once

#include "nvme/commands/generic_nvme_command.hpp"

namespace nvme {
namespace commands {

class Flush final : public GenericNvmeCommand {
public:
    /*!
     * @brief Constructs a valid Flush command
     * @param namespace_id Id of the namespace to be flushed
     */
    explicit Flush(uint32_t namespace_id);

    virtual ~Flush();
};

}
}
