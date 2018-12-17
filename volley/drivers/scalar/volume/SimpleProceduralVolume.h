// ======================================================================== //
// Copyright 2018 Intel Corporation                                         //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "Volume.h"

namespace volley {

  namespace scalar_driver {

    struct SimpleProceduralVolume : public Volume
    {
      void commit() override;

      void intersect(size_t numValues,
                     const vly_vec3f *origins,
                     const vly_vec3f *directions,
                     vly_range1f *ranges) override;

      void sample(VLYSamplingType samplingType,
                  size_t numValues,
                  const vly_vec3f *worldCoordinates,
                  float *results) override;
    };

  }  // namespace scalar_driver
}  // namespace volley
