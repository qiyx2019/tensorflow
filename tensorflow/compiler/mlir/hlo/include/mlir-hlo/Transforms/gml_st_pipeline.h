/* Copyright 2022 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_MLIR_HLO_INCLUDE_MLIR_HLO_TRANSFORMS_GML_ST_PIPELINE_H_
#define TENSORFLOW_COMPILER_MLIR_HLO_INCLUDE_MLIR_HLO_TRANSFORMS_GML_ST_PIPELINE_H_

#include "mlir/Pass/PassManager.h"
#include "mlir/Pass/PassOptions.h"
#include "mlir/Pass/PassRegistry.h"

namespace mlir {
struct GmlStPipelineOptions
    : public mlir::PassPipelineOptions<GmlStPipelineOptions> {
  ListOption<int64_t> tileSizes{
      *this, "tile-sizes",
      llvm::cl::desc("tile-sizes option for the tiling pass")};
};

void createGmlStPipeline(mlir::OpPassManager& pm,
                         const GmlStPipelineOptions& options);

}  // namespace mlir

#endif  // TENSORFLOW_COMPILER_MLIR_HLO_INCLUDE_MLIR_HLO_TRANSFORMS_GML_ST_PIPELINE_H_
