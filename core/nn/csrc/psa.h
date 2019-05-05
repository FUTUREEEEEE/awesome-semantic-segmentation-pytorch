#pragma once

#include "cpu/vision.h"

#ifdef WITH_CUDA
#include "cuda/vision.h"
#endif

// Interface for Python
at::Tensor psa_forward(const at::Tensor& h,
                       const int forward_type) {
    if (h.type().is_cuda()) {
  #ifdef WITH_CUDA
      return psa_forward_cuda(h, forward_type);
  #else
      AT_ERROR("Not compiled with GPU support");
  #endif
  }
    return psa_forward_cpu(h, forward);
}

at::Tensor psa_backward(const at::Tensor& dout,
                        const at::Tensor& h,
                        const int forward_type) {
    if (h.type().is_cuda()) {
  #ifdef WITH_CUDA
      return psa_backward_cuda(dout, h, forward_type);
  #else
      AT_ERROR("Not compiled with GPU support");
  #endif
  }
    return psa_backward_cpu(dout, h, forward_type);
}