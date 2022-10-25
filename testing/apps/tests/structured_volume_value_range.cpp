// Copyright 2019 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#include "../../external/catch.hpp"
#include "openvkl_testing.h"
#include "rkcommon/utility/multidim_index_sequence.h"

using namespace rkcommon;
using namespace openvkl::testing;

template <typename PROCEDURAL_VOLUME_TYPE>
void computed_vs_api_value_range(vec3i dimensions = vec3i(128))
{
  const float boundingBoxSize = 2.f;

  vec3f gridOrigin;
  vec3f gridSpacing;

  // generate legal grid parameters
  PROCEDURAL_VOLUME_TYPE::generateGridParameters(
      dimensions, boundingBoxSize, gridOrigin, gridSpacing);

  auto v = rkcommon::make_unique<PROCEDURAL_VOLUME_TYPE>(
      dimensions, gridOrigin, gridSpacing);

  VKLVolume vklVolume = v->getVKLVolume(getOpenVKLDevice());

  vkl_range1f apiValueRange = vklGetValueRange(vklVolume);

  range1f computedValueRange = v->getComputedValueRange();

  INFO("api valueRange = " << apiValueRange.lower << " "
                           << apiValueRange.upper);
  INFO("computed valueRange = " << computedValueRange.lower << " "
                                << computedValueRange.upper);

  REQUIRE((apiValueRange.lower == computedValueRange.lower &&
           apiValueRange.upper == computedValueRange.upper));
}

#if OPENVKL_DEVICE_CPU_STRUCTURED_REGULAR || \
    OPENVKL_DEVICE_CPU_STRUCTURED_SPHERICAL
TEST_CASE("Structured volume value range", "[volume_value_range]")
{
  initializeOpenVKL();

#if OPENVKL_DEVICE_CPU_STRUCTURED_REGULAR
  SECTION("structuredRegular")
  {
    SECTION("unsigned char")
    {
      computed_vs_api_value_range<WaveletStructuredRegularVolumeUChar>();
    }

    SECTION("short")
    {
      computed_vs_api_value_range<WaveletStructuredRegularVolumeShort>();
    }

    SECTION("unsigned short")
    {
      computed_vs_api_value_range<WaveletStructuredRegularVolumeUShort>();
    }

    SECTION("half")
    {
      computed_vs_api_value_range<WaveletStructuredRegularVolumeHalf>();
    }

    SECTION("float")
    {
      computed_vs_api_value_range<WaveletStructuredRegularVolumeFloat>();
    }

    SECTION("double")
    {
      computed_vs_api_value_range<WaveletStructuredRegularVolumeDouble>();
    }
  }
#endif

#if OPENVKL_DEVICE_CPU_STRUCTURED_SPHERICAL
  SECTION("structuredSpherical")
  {
    SECTION("unsigned char")
    {
      computed_vs_api_value_range<WaveletStructuredSphericalVolumeUChar>();
    }

    SECTION("short")
    {
      computed_vs_api_value_range<WaveletStructuredSphericalVolumeShort>();
    }

    SECTION("unsigned short")
    {
      computed_vs_api_value_range<WaveletStructuredSphericalVolumeUShort>();
    }

    SECTION("half")
    {
      computed_vs_api_value_range<WaveletStructuredSphericalVolumeHalf>();
    }

    SECTION("float")
    {
      computed_vs_api_value_range<WaveletStructuredSphericalVolumeFloat>();
    }

    SECTION("double")
    {
      computed_vs_api_value_range<WaveletStructuredSphericalVolumeDouble>();
    }
  }
#endif

  shutdownOpenVKL();
}
#endif
