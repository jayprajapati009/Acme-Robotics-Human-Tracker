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
 * @file Utils.cpp
 * @author Phase 1 - Anukriti Singh (design keeper), Jay Prajapati (driver), and
 *                   Shail Shah (navigator)
 * @brief utils class declaration for Acme Robotics - Human Tracker
 * @version 0.1
 *
 * @copyright MIT License
 *
 */

#include <Utils.hpp>

cv::Mat acme_robots::Utils::DrawBbox(cv::Mat i, const cv::Rect &b,
                                     const std::string &l) {
  cv::Mat frame = i.clone();
  cv::Scalar color = cv::Scalar(0, 0, 255);
  cv::Scalar l_color = cv::Scalar::all(255);

  int f_face(0);

  double f_scale(1);

  cv::Point l_pt;
  cv::Point top_pt;
  cv::Point bottom_pt;
  int b_line(0);
  cv::Size l_size;
  cv::rectangle(frame, b, color, 2, cv::LINE_AA);
  l_size = cv::getTextSize(l, f_face, f_scale, 2, &b_line);
  top_pt = cv::Point(b.x, b.y);
  bottom_pt = cv::Point(b.x + l_size.width, b.y + l_size.height);
  l_pt = cv::Point(b.x, b.y + l_size.height);
  cv::rectangle(frame, top_pt, bottom_pt, color, -1, 16);
  cv::putText(frame, l, l_pt, f_face, f_scale, l_color, 2);
  return frame;
}

cv::Point acme_robots::Utils::GetBboxCenter(const cv::Rect &bbox) {
  int x_center = bbox.width / 2 + bbox.x;
  int y_center = bbox.height / 2 + bbox.y;
  return cv::Point(x_center, y_center);
}

double acme_robots::Utils::GetBboxArea(const cv::Rect &bbox) {
  double area = 0;
  area = bbox.width * bbox.height;
  return area;
}

cv::Mat acme_robots::Utils::ResizeImage(const cv::Mat &i, const cv::Size &s) {
  cv::Mat out_img;
  cv::resize(i, out_img, s);
  return out_img;
}

acme_robots::Pose acme_robots::Utils::PixelsToPose(const cv::Rect &b,
                                                   double calib_factor) {
  /// height of object in pixels
  double height = b.height;
  /// calibrated distance using focal length and calib factor
  double calib_distance = calib_factor / height;
  /// get centre of bbox
  cv::Point centre = acme_robots::Utils::GetBboxCenter(b);

  return acme_robots::Pose(calib_distance, centre.x, centre.y);
}
