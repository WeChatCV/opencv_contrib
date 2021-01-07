// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
//
// Tencent is pleased to support the open source community by making WeChat QRCode available.
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.

/*
 *  genericgf.hpp
 *  zxing
 *
 *  Created by Lukas Stabe on 13/02/2012.
 *  Copyright 2012 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ZXING_COMMON_REEDSOLOMON_GENERICGF_HPP__
#define __ZXING_COMMON_REEDSOLOMON_GENERICGF_HPP__

#include "zxing/common/counted.hpp"
#include "zxing/errorhandler.hpp"

#include <vector>

namespace zxing {
class GenericGFPoly;

static zxing::ErrorHandler gf_err_handler_;
#define GF_AZTEC_DATA_12 (new GenericGF(0x1069, 4096, 1, gf_err_handler_))
#define GF_AZTEC_DATA_10 (new GenericGF(0x409, 1024, 1, gf_err_handler_))
#define GF_AZTEC_DATA_6 (new GenericGF(0x43, 64, 1, gf_err_handler_))
#define GF_AZTEC_PARAM (new GenericGF(0x13, 16, 1, gf_err_handler_))
#define GF_QR_CODE_FIELD_256 (new GenericGF(0x011D, 256, 0, gf_err_handler_))
#define GF_DATA_MATRIX_FIELD_256 (new GenericGF(0x012D, 256, 1, gf_err_handler_))
#define GF_AZTEC_DATA_8 (new GenericGF(0x012D, 256, 1, gf_err_handler_))
#define GF_MAXICODE_FIELD_64 (new GenericGF(0x43, 64, 1, gf_err_handler_))
// #define GF_WXCODE (new GenericGF(0x011D, 256, 0, gf_err_handler_))

class GenericGF : public Counted {
private:
    std::vector<int> expTable;
    std::vector<int> logTable;
    Ref<GenericGFPoly> zero;
    Ref<GenericGFPoly> one;
    int size;
    int primitive;
    int generatorBase;
    // bool initialized;
    //
    // void initialize();
    // void checkInit();

public:
    // static Ref<GenericGF> AZTEC_DATA_12;
    // static Ref<GenericGF> AZTEC_DATA_10;
    // static Ref<GenericGF> AZTEC_DATA_8;
    // static Ref<GenericGF> AZTEC_DATA_6;
    // static Ref<GenericGF> AZTEC_PARAM;
    // static Ref<GenericGF> QR_CODE_FIELD_256;
    // static Ref<GenericGF> DATA_MATRIX_FIELD_256;
    // static Ref<GenericGF> MAXICODE_FIELD_64;
    // static Ref<GenericGF> WXCODE;

    GenericGF(int primitive, int size, int b, ErrorHandler &err_handler);

    Ref<GenericGFPoly> getZero();
    Ref<GenericGFPoly> getOne();
    int getSize();
    int getGeneratorBase();
    Ref<GenericGFPoly> buildMonomial(int degree, int coefficient, ErrorHandler &err_handler);

    static int addOrSubtract(int a, int b);
    int exp(int a);
    int log(int a, ErrorHandler &err_handler);
    int inverse(int a, ErrorHandler &err_handler);
    int multiply(int a, int b);
};
}  // namespace zxing

#endif  // __ZXING_COMMON_REEDSOLOMON_GENERICGF_HPP__