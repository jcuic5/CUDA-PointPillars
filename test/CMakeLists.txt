# SPDX-FileCopyrightText: Copyright (c) 2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 2.8.7)
set(PROJECT_NAME demo)
find_package(CUDA REQUIRED)

SET(CMAKE_BUILD_TYPE "Release")
add_compile_options(-W)
add_compile_options(-std=c++11)

include_directories(
    /usr/local/cuda/include
    /home/travis/packages/TensorRT-7.1.3.4/include
    ../include/
    ../include/plugin/
)

link_directories(
    /usr/local/cuda/lib64
    /home/travis/packages/TensorRT-7.1.3.4/lib
)

file(GLOB_RECURSE SOURCE_FILES
    ../src/*.cu
    ../src/*.cpp
)

cuda_add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
    libnvinfer.so
    libnvonnxparser.so
)
