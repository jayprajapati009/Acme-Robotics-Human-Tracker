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
 * @file draw_label.hpp
 * @author Jay Prajapati (jayp@umd.edu)
 * @author Shail Shah (sshah115@umd.edu)
 * @author Anukriti Singh (anukriti@umd.edu)
 *
 * @brief Draw_label class declaration and definition file
 * @version 2.0
 * @date 2022-10-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _HOME_JP_VSCODES_ACME_ROBOTICS_HUMAN_TRACKER_INCLUDE_DRAW_LABEL_HPP_
#define _HOME_JP_VSCODES_ACME_ROBOTICS_HUMAN_TRACKER_INCLUDE_DRAW_LABEL_HPP_

#include <string>
#include <algorithm>
#include <opencv2/opencv.hpp>

/**
 * @brief Label design with layout, font formatting and positioning
 * 
 */
class Draw_Label {
 public:
  cv::Scalar BLACK = cv::Scalar(0, 0, 0);
  cv::Scalar YELLOW = cv::Scalar(0, 255, 255);
  const float FONT_SCALE = 0.7;
  const int FONT_FACE = cv::FONT_HERSHEY_SIMPLEX;
  const int THICKNESS = 1;

  /**
   * @brief Using input frame assigns label with class ID 
   * 
   * @param input_frame The video frame acquired from video camera stream as input
   * @param bounding_box_label The label content as input
   * @param left left-most column of bounding box drawn over detections
   * @param top top-most row of bounding box drawn over detections
   */
  void draw_label(const cv::Mat &input_frame, std::string bounding_box_label,
                  int left, int top) {
    int bottomLine;
    cv::Size labelSize = cv::getTextSize(bounding_box_label, FONT_FACE,
                                         FONT_SCALE, THICKNESS, &bottomLine);
    top = cv::max(top, labelSize.height);

    cv::Point topLeftCorner = cv::Point(left, top);

    cv::Point bottomRIghtCorner =
        cv::Point(left + labelSize.width, top + labelSize.height + bottomLine);

    cv::rectangle(input_frame, topLeftCorner, bottomRIghtCorner, BLACK,
                  cv::FILLED);

    cv::putText(input_frame, bounding_box_label,
                cv::Point(left, top + labelSize.height), FONT_FACE, FONT_SCALE,
                YELLOW, THICKNESS);
  }
};

#endif  // _HOME_JP_VSCODES_ACME_ROBOTICS_HUMAN_TRACKER_INCLUDE_DRAW_LABEL_HPP_
