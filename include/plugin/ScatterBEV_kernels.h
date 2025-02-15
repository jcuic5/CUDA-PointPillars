/*
 * SPDX-FileCopyrightText: Copyright (c) 2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#ifndef _BEV_KERNELS_H_
#define _BEV_KERNELS_H_

#define PILLARS_PER_BLOCK 64 //one thread for one pillar
#define FEATURE_SIZE 64 //feature count for one pillar depands on "params.h"

void scatterBEV_kernel_launcher(const float *pillar_features_data,
              const float *coords_data, const unsigned int *params_data,
              unsigned int featureX, unsigned int featureY,
              float *spatial_feature_data,
              cudaStream_t stream = 0);

#endif
