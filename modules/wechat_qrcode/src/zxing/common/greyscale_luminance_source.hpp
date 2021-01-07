// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
//
// Tencent is pleased to support the open source community by making WeChat QRCode available.
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.

/*
 *  greyscale_luminance_source.hpp
 *  zxing
 *
 *  Copyright 2010 ZXing authors All rights reserved.
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
#ifndef __ZXING_COMMON_GREYSCALE_LUMINANCE_SOURCE_HPP__
#define __ZXING_COMMON_GREYSCALE_LUMINANCE_SOURCE_HPP__

#include "zxing/common/bytematrix.hpp"
#include "zxing/errorhandler.hpp"
#include "zxing/luminance_source.hpp"

namespace zxing {

class GreyscaleLuminanceSource : public LuminanceSource {
private:
    typedef LuminanceSource Super;
    ArrayRef<char> greyData_;
    const int dataWidth_;
    const int dataHeight_;
    const int left_;
    const int top_;

public:
    GreyscaleLuminanceSource(ArrayRef<char> greyData, int dataWidth, int dataHeight, int left,
                             int top, int width, int height, ErrorHandler& err_handler);

    ArrayRef<char> getRow(int y, ArrayRef<char> row, ErrorHandler& err_handler) const;
    ArrayRef<char> getMatrix() const;
    Ref<ByteMatrix> getByteMatrix() const;

    bool isRotateSupported() const { return true; }

    Ref<LuminanceSource> rotateCounterClockwise(ErrorHandler& err_handler) const;
};

}  // namespace zxing

#endif  // __ZXING_COMMON_GREYSCALE_LUMINANCE_SOURCE_HPP__