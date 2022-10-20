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
 * @file track.hpp
 * @author Phase 1 - Anukriti Singh (design keeper), Jay Prajapati (driver), and
 *                   Shail Shah (navigator)
 * @brief track class declaration for Acme Robotics - Human Tracker
 * @version 0.1
 *
 * @copyright MIT License
 *
 */

#ifndef INCLUDE_TRACK_HPP_
#define INCLUDE_TRACK_HPP_

#include <memory>
#include <vector>


#include <opencv2/core/ocl.hpp>
#include <opencv2/tracking.hpp>


#include <detect.hpp>

namespace acme_robots {

class Track {
public:
  explicit Track(double confidence);
  ~Track();
  std::vector<cv::Rect> TrackHumans(const cv::Mat &frame);

private:
  void InitParams(double confidence);
  void RemoveNoise(const std::vector<acme_robots::Detection> &detections);

private:
  double confidence_thresh_;
  std::vector<cv::Rect> humans_;
  std::unique_ptr<acme_robots::Detector> detector_;
};
} // namespace acme_robots

#endif // INCLUDE_TRACK_HPP_
