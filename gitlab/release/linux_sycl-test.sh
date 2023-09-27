#!/bin/bash
## Copyright 2023 Intel Corporation
## SPDX-License-Identifier: Apache-2.0

# abort on any error
set -e

ROOT_DIR=$PWD

#### Extract release package ####

OPENVKL_PKG_BASE=openvkl-${OPENVKL_RELEASE_PACKAGE_VERSION}.sycl.x86_64.linux
tar -zxvf ${OPENVKL_PKG_BASE}.tar.gz

#### Build tutorial against release package ####

export openvkl_DIR="${ROOT_DIR}/${OPENVKL_PKG_BASE}"

mkdir build_from_release
cd build_from_release

cmake --version

cmake ../examples/from_openvkl_install

cmake --build .

#### Run tutorial to verify functionality ####

export LD_LIBRARY_PATH=${openvkl_DIR}/lib:${LD_LIBRARY_PATH}

./vklTutorialGPU

#### Run binaries from release package to verify functionality ####

${openvkl_DIR}/bin/vklTutorialGPU

${openvkl_DIR}/bin/vklMinimal_06
