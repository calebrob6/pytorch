#pragma once

#include "lazy_tensor_core/csrc/ts_backend/TsNode.h"
#include "lazy_tensor_core/csrc/compiler/data.h"

namespace torch_lazy_tensors {
namespace ir {
namespace ops {

class DeviceData : public TsNode {
 public:
  DeviceData(std::shared_ptr<compiler::BackendData> data);

  std::string ToString() const override;

  const std::shared_ptr<compiler::BackendData>& data() const {
    return data_;
  }

  static const DeviceData* Cast(const torch::lazy::Node* node);

 private:
  std::shared_ptr<compiler::BackendData> data_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_lazy_tensors