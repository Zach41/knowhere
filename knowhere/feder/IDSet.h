// Copyright (C) 2019-2020 Zilliz. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing permissions and limitations under the License

#pragma once

#include <memory>
#include <unordered_set>
#include <vector>

#include <nlohmann/json.hpp>

namespace knowhere::feder {

class IDSet {
 public:
    IDSet() = default;

    const std::unordered_set<int64_t>&
    GetIDs() {
        return ids_;
    }

    void
    Add(int64_t id) {
        ids_.insert(id);
    }

    void
    Add(const std::vector<int64_t>& ids) {
        ids_.insert(ids.begin(), ids.end());
    }

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(IDSet, ids_);

 private:
    std::unordered_set<int64_t> ids_;
};

} // namespace knowhere::feder
