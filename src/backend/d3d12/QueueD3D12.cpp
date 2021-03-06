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

#include "backend/d3d12/QueueD3D12.h"

#include "backend/d3d12/D3D12Backend.h"
#include "backend/d3d12/CommandBufferD3D12.h"

namespace backend {
namespace d3d12 {

    Queue::Queue(Device* device, QueueBuilder* builder)
        : QueueBase(builder), device(device) {
    }

    void Queue::Submit(uint32_t numCommands, CommandBuffer* const * commands) {
        device->Tick();

        device->OpenCommandList(&commandList);
        for (uint32_t i = 0; i < numCommands; ++i) {
            commands[i]->FillCommands(commandList);
        }
        ASSERT_SUCCESS(commandList->Close());

        device->ExecuteCommandLists({ commandList.Get() });

        device->NextSerial();
    }

}
}
