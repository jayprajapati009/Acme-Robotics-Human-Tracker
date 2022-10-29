/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2022 Jay Prajapati, Shail Shah and Anukriti Singh
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * @file test.cpp
 * @author Jay Prajapati (jayp@umd.edu)
 * @author Shail Shah (sshah115@umd.edu)
 * @author Anukriti Singh (anukriti@umd.edu)
 *
 * @brief Test cases declaration and definition file
 * @version 2.0
 * @date 2022-10-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "./../include/draw_label.hpp"
#include "./../include/post_process.hpp"
#include "./../include/pre_process.hpp"

cv::Mat img = cv::imread("./../resources/sample.jpg");
cv::dnn::Net net = cv::dnn::readNet("./../app/resources/models/yolov5s.onnx");

TEST(Test1, should_pass) { EXPECT_EQ(1, 1); }

TEST(Test2, testLabel) {
  std::string bounding_box_label = "Person:1";
  int top = 20;
  int left = 20;
  Draw_Label obj;
  ASSERT_NO_THROW(obj.draw_label(img, bounding_box_label, top, left));
}
