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
 * @file track.cpp
 * @author Phase 1 - Anukriti Singh (design keeper), Jay Prajapati (driver), and
 *                   Shail Shah (navigator)
 * @brief track class declaration for Acme Robotics - Human Tracker
 * @version 0.1
 *
 * @copyright MIT License
 *
 */

#include <track.hpp>

acme_robots::Track::Track(double confidence) {
  /// initializing default parameters
  InitParams(confidence);
}

acme_robots::Track::~Track() {}

void acme_robots::Track::InitParams(double confidence) {
  confidence_thresh_ = confidence;
  double detector_conf(0.0);
  std::vector<std::string> classes{"person"};
  detector_ = std::make_unique<acme_robots::Detector>(detector_conf, classes);
  humans_.clear();
}

std::vector<cv::Rect> acme_robots::Track::TrackHumans const cv::Mat &frame) {
  humans_.clear();

  std::vector<acme_robots::Detection> output = detector_->Detect(frame);

  RemoveNoise(output);

  return humans_;
}

void acme_robots::Track::RemoveNoise(
    const std::vector<acme_robots::Detection> &d) {
  for (acme_robots::Detection detect : d) {
    if (detect.confidence >= confidence_thresh_) {
      humans_.push_back(detect.bbox);
    }
  }
}
