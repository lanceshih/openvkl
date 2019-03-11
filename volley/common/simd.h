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

namespace volley {

  template <int W>
  using vfloatn = float[W];

  template <int W>
  using vintn = int[W];

  template <int W>
  struct vrange1fn
  {
    vfloatn<W> lower;
    vfloatn<W> upper;
  };

  template <int W>
  struct vvec3fn
  {
    vfloatn<W> x;
    vfloatn<W> y;
    vfloatn<W> z;
  };

}  // namespace volley
