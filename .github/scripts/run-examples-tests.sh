#!/bin/bash -x
## Copyright 2023 Intel Corporation
## SPDX-License-Identifier: Apache-2.0

IMG_DIFF_TOOL=$STORAGE_PATH/tools/img_diff/img_diff

# Run tests over these volume types
VOLUME_TYPES="structuredRegular unstructured particle vdb"

COMMON_ARGS="-batch -framebufferSize 1024 1024"

# Count errors across all image diffs, and use this as the final exit code
# Note: $IMG_DIFF_TOOL should return only exit codes >0 for this to be robust.
NUM_IMAGE_DIFF_ERRORS=0

for volumeType in $VOLUME_TYPES; do

    ./bin/vklExamplesGPU -renderer density_pathtracer_gpu $COMMON_ARGS -volumeType $volumeType -spp 50
    ./bin/vklExamplesGPU -renderer ray_march_iterator_gpu $COMMON_ARGS -volumeType $volumeType -spp 2
    ./bin/vklExamplesGPU -renderer interval_iterator_debug_gpu $COMMON_ARGS -volumeType $volumeType -spp 2
    ./bin/vklExamplesGPU -renderer hit_iterator_renderer_gpu $COMMON_ARGS -volumeType $volumeType -spp 2

    # Run cpu examples to get reference images
    ./bin/vklExamplesCPU -renderer density_pathtracer $COMMON_ARGS -volumeType $volumeType -spp 50
    ./bin/vklExamplesCPU -renderer ray_march_iterator $COMMON_ARGS -volumeType $volumeType -spp 2
    ./bin/vklExamplesCPU -renderer interval_iterator_debug $COMMON_ARGS -volumeType $volumeType -spp 2
    ./bin/vklExamplesCPU -renderer hit_iterator_renderer $COMMON_ARGS -volumeType $volumeType -spp 2

    # Compare images generated by GPU examples vs CPU examples
    echo "=============================================================================="
    echo "Image diff for volume type: $volumeType"
    echo "=============================================================================="

    $IMG_DIFF_TOOL density_pathtracer.pfm density_pathtracer_gpu.pfm
    NUM_IMAGE_DIFF_ERRORS=$(($NUM_IMAGE_DIFF_ERRORS+$?))

    $IMG_DIFF_TOOL ray_march_iterator.pfm ray_march_iterator_gpu.pfm
    NUM_IMAGE_DIFF_ERRORS=$(($NUM_IMAGE_DIFF_ERRORS+$?))

    $IMG_DIFF_TOOL interval_iterator_debug.pfm interval_iterator_debug_gpu.pfm
    NUM_IMAGE_DIFF_ERRORS=$(($NUM_IMAGE_DIFF_ERRORS+$?))

    $IMG_DIFF_TOOL hit_iterator_renderer.pfm hit_iterator_renderer_gpu.pfm 0.0002
    NUM_IMAGE_DIFF_ERRORS=$(($NUM_IMAGE_DIFF_ERRORS+$?))

    # Retain images in volume-specific subdirectory
    mkdir -p $volumeType
    mv *.pfm $volumeType/
done

exit $NUM_IMAGE_DIFF_ERRORS
