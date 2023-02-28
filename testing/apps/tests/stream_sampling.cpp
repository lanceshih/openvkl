// Copyright 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#include "../../external/catch.hpp"
#include "openvkl_testing.h"
#include "sampling_utility.h"

using namespace rkcommon;
using namespace openvkl::testing;

TEST_CASE("Stream sampling", "[volume_sampling]")
{
  initializeOpenVKL();

#if OPENVKL_DEVICE_CPU_AMR
  SECTION("AMR")
  {
    auto v = std::make_shared<ProceduralShellsAMRVolume<>>(
        vec3i(128), vec3f(0.f), vec3f(1.f));
    test_stream_sampling(v);
  }
#endif

#if OPENVKL_DEVICE_CPU_STRUCTURED_REGULAR
  SECTION("structuredRegular")
  {
    auto v = std::make_shared<WaveletStructuredRegularVolume<float>>(
        vec3i(128), vec3f(0.f), vec3f(1.f));
    test_stream_sampling(v);
  }
#endif

#if OPENVKL_DEVICE_CPU_STRUCTURED_SPHERICAL
  SECTION("structuredSpherical")
  {
    auto v = std::make_shared<WaveletStructuredSphericalVolume<float>>(
        vec3i(128), vec3f(0.f), vec3f(1.f));
    test_stream_sampling(v);
  }
#endif

#if OPENVKL_DEVICE_CPU_UNSTRUCTURED
  SECTION("unstructured")
  {
    auto v = std::make_shared<WaveletUnstructuredProceduralVolume>(
        vec3i(128), vec3f(0.f), vec3f(1.f));
    test_stream_sampling(v);
  }
#endif

#if OPENVKL_DEVICE_CPU_VDB
  SECTION("VDB")
  {
    auto v1 = std::make_shared<WaveletVdbVolumeFloat>(
        getOpenVKLDevice(), vec3i(128), vec3f(0.f), vec3f(1.f), true);
    test_stream_sampling(v1);

    auto v2 = std::make_shared<WaveletVdbVolumeFloat>(
        getOpenVKLDevice(), vec3i(128), vec3f(0.f), vec3f(1.f), false);
    test_stream_sampling(v2);
  }
#endif

  shutdownOpenVKL();
}
