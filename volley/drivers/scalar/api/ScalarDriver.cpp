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

#include "ScalarDriver.h"
#include "../volume/Volume.h"

namespace volley {
  namespace scalar_driver {

    void ScalarDriver::commit()
    {
      Driver::commit();
    }

    VLYError ScalarDriver::loadModule(const char *moduleName)
    {
      return volley::loadLocalModule(moduleName);
    }

    VLYVolume ScalarDriver::newVolume(const char *type)
    {
      return (VLYVolume)Volume::createInstance(type);
    }

    void ScalarDriver::sampleVolume(VLYVolume volume,
                                    VLYSamplingType samplingType,
                                    size_t numValues,
                                    const vly_vec3f *worldCoordinates,
                                    float *results)
    {
      // TODO: dummy values for API plumbing
      for (size_t i=0; i<numValues; i++) {
        results[i] = float(i);
      }
    }

    VLY_REGISTER_DRIVER(ScalarDriver, scalar_driver)
  }  // namespace scalar_driver
}  // namespace volley

extern "C" VOLLEY_DLLEXPORT void volley_init_module_scalar_driver() {}
