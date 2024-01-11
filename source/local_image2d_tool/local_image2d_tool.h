/* 
 *   AgvTools is AgileVision tool library set, added by the tool library developed base on AgileVision framework libary.
 *   Each tool libary is independent with each other.
 *  
 *   File: local_image2d_tool.h  
 *   Copyright (c) 2024-2024 scofieldzhu
 *  
 *   MIT License
 *  
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *  
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *  
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#pragma once

#include <opencv2/opencv.hpp>
#include "agile_vision/core/tool.h"
#include "local_image2d_tool/tool_export.h"

class LOCAL_IMAGE2D_TOOL_API LocalImage2dTool : public agile_vision::Tool
{
public:
    static constexpr agile_vision::PinKey PK_P_ImagePath = "ImagePath";
    static constexpr agile_vision::PinKey PK_P_DirType = "DirType";
    static constexpr agile_vision::PinKey PK_O_ImageData = "ImageData";
    std::string getClsGuid()const override;
    LocalImage2dTool(const std::string& iid);
    ~LocalImage2dTool();

private:
    bool requestOutputData() override;
    cv::Mat image_;
};

RATEL_EXTERN_C_BEGIN
LOCAL_IMAGE2D_TOOL_API const char* GetToolClsID();
LOCAL_IMAGE2D_TOOL_API agile_vision::Tool* CreateToolInstance(const char* iid);
LOCAL_IMAGE2D_TOOL_API void DestroyToolInstance(agile_vision::Tool* t);
RATEL_EXTERN_C_END
