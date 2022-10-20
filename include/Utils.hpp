/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2022 Anukriti Singh, Jay Prajapati, and Shail Shah
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all copies or substantial portions of the Software.
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
 * @file Utils.hpp
 * @author Phase 1 - Anukriti Singh (design keeper), Jay Prajapati (driver), and
 *                   Shail Shah (navigator)
 * @brief Utils class declaration for Acme Robotics - Human Tracker
 * @version 0.1
 *
 * @copyright MIT License
 *
 */

#ifndef INCLUDE_UTILS_HPP_
#define INCLUDE_UTILS_HPP_

#include <string>
#include <vector>


#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>


namespace acme_robots {

struct Pose {
  Pose() {
    x = -1.0;
    y = -1.0;
    z = -1.0;
  }

  Pose(double x1, double y1, double z1) {
    x = x1;
    y = y1;
    z = z1;
  }
  double x;
  double y;
  double z;
};

class Utils {
 public:
  static cv::Mat DrawBbox(cv::Mat i, const cv::Rect &b, const std::string &l);
  static cv::Point GetBboxCenter(const cv::Rect &bbox);
  static double GetBboxArea(const cv::Rect &bbox);
  static cv::Mat ResizeImage(const cv::Mat &i, const cv::Size &s);
  static double CalculateIOU(const cv::Rect &b1, const cv::Rect &b2);
  static Pose PixelsToPose(const cv::Rect &b, double calib_factor);
};
}  // namespace acme_robots

#endif  // INCLUDE_UTILS_HPP_
