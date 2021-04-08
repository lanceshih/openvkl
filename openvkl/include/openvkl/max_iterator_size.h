// Copyright 2020-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#pragma once

// Maximum iterator size over all supported volume and device
// types, and for each target SIMD width.
#define VKL_MAX_INTERVAL_ITERATOR_SIZE_4 1007
#define VKL_MAX_INTERVAL_ITERATOR_SIZE_8 1951
#define VKL_MAX_INTERVAL_ITERATOR_SIZE_16 3903

#if defined(TARGET_WIDTH) && (TARGET_WIDTH == 4)
  #define VKL_MAX_INTERVAL_ITERATOR_SIZE VKL_MAX_INTERVAL_ITERATOR_SIZE_4
#elif defined(TARGET_WIDTH) && (TARGET_WIDTH == 8)
  #define VKL_MAX_INTERVAL_ITERATOR_SIZE VKL_MAX_INTERVAL_ITERATOR_SIZE_8
#else
  #define VKL_MAX_INTERVAL_ITERATOR_SIZE VKL_MAX_INTERVAL_ITERATOR_SIZE_16
#endif
#define VKL_MAX_HIT_ITERATOR_SIZE_4 1263
#define VKL_MAX_HIT_ITERATOR_SIZE_8 2431
#define VKL_MAX_HIT_ITERATOR_SIZE_16 4863

#if defined(TARGET_WIDTH) && (TARGET_WIDTH == 4)
  #define VKL_MAX_HIT_ITERATOR_SIZE VKL_MAX_HIT_ITERATOR_SIZE_4
#elif defined(TARGET_WIDTH) && (TARGET_WIDTH == 8)
  #define VKL_MAX_HIT_ITERATOR_SIZE VKL_MAX_HIT_ITERATOR_SIZE_8
#else
  #define VKL_MAX_HIT_ITERATOR_SIZE VKL_MAX_HIT_ITERATOR_SIZE_16
#endif
