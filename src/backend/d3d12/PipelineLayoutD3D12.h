// Copyright 2017 The NXT Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef BACKEND_D3D12_PIPELINELAYOUTD3D12_H_
#define BACKEND_D3D12_PIPELINELAYOUTD3D12_H_

#include "backend/PipelineLayout.h"

#include "backend/d3d12/d3d12_platform.h"

namespace backend {
namespace d3d12 {

    class Device;

    class PipelineLayout : public PipelineLayoutBase {
        public:
            PipelineLayout(Device* device, PipelineLayoutBuilder* builder);

            uint32_t GetCbvUavSrvRootParameterIndex(uint32_t group) const;
            uint32_t GetSamplerRootParameterIndex(uint32_t group) const;

            ComPtr<ID3D12RootSignature> GetRootSignature();

        private:
            Device* device;

            std::array<uint32_t, kMaxBindGroups> cbvUavSrvRootParameterInfo;
            std::array<uint32_t, kMaxBindGroups> samplerRootParameterInfo;

            ComPtr<ID3D12RootSignature> rootSignature;
    };

}
}

#endif // BACKEND_D3D12_PIPELINELAYOUTD3D12_H_
