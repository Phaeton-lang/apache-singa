/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cassert>
#include "singa/core/common.h"

#include "singa/core/device.h"

namespace singa {

std::string to_string(OpType type) {
#define AddOPType(tp) case OpType::k##tp: return #tp;
    switch (type) {
        AddOPType(Undefined)
        AddOPType(CopyH2H)
        AddOPType(CopyH2D)
        AddOPType(CopyD2H)
        AddOPType(CopyD2D)
        AddOPType(Sync)
        AddOPType(FwdPool)
        AddOPType(BwdPool)
        AddOPType(FwdBN)
        AddOPType(BwdBN)
        AddOPType(FwdRNN)
        AddOPType(BwdRNN)
        AddOPType(FwdActivation)
        AddOPType(BwdActivation)
        AddOPType(FwdDropout)
        AddOPType(BwdDropout)
        AddOPType(FwdConv)
        AddOPType(BwdConvBias)
        AddOPType(BwdConvWeight)
        AddOPType(BwdConvNeuron)
        AddOPType(FwdSoftmax)
        AddOPType(BwdSoftmax)
        AddOPType(FwdLrn)
        AddOPType(BwdLrn)
        AddOPType(CastType)
        AddOPType(L1)
        AddOPType(L2)
        AddOPType(Abs)
        AddOPType(Ceil)
        AddOPType(Exp)
        AddOPType(Log)
        AddOPType(ReLU)
        AddOPType(Sigmoid)
        AddOPType(SoftPlus)
        AddOPType(SoftSign)
        AddOPType(Sign)
        AddOPType(Sqrt)
        AddOPType(Square)
        AddOPType(Transform)
        AddOPType(Cos)
        AddOPType(Cosh)
        AddOPType(Acos)
        AddOPType(Acosh)
        AddOPType(Sin)
        AddOPType(Sinh)
        AddOPType(Asin)
        AddOPType(Asinh)
        AddOPType(Tan)
        AddOPType(Tanh)
        AddOPType(Atan)
        AddOPType(Atanh)
        AddOPType(SoftMax)
        AddOPType(BiasAdd)
        AddOPType(Add)
        AddOPType(Sub)
        AddOPType(EltwiseMult)
        AddOPType(Div)
        AddOPType(dwPow)
        AddOPType(Pow)
        AddOPType(LT)
        AddOPType(LE)
        AddOPType(GT)
        AddOPType(GE)
        AddOPType(ReLUBackward)
        AddOPType(Dot)
        AddOPType(RowMax)
        AddOPType(GEMM)
        AddOPType(GEMV)
        AddOPType(Rand)
        AddOPType(Axpy)
        AddOPType(CrossEntropy)
        AddOPType(SoftmaxCrossEntropy)
        AddOPType(MultColumn)
        AddOPType(MultRow)
        AddOPType(Mult)
        default: assert(0);
    }
#undef AddOPType
    return "";
}

void* Block::mutable_data() {
  if (data_ == nullptr && size_ > 0) {
    data_ = device_->Malloc((int)size_);
  }
  initialized_ = true;
  return static_cast<char*>(data_) + offset_;
}

const void* Block::data() const {
  CHECK(initialized_) << "Must initialize data before reading it";
  return static_cast<char*>(data_) + offset_;
}

void Block::free_data() {
  if (data_) {
    device_->Free(data_);
    data_ = nullptr;
    initialized_ = false;
  }
}

}  // namespace singa
