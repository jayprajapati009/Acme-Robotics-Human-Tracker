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
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
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
 * @file Tracker.hpp
 * @author Phase 1 - Anukriti Singh (design keeper), Jay Prajapati (driver), and Shail Shah (navigator)
 * @brief Tracker class declaration for Human Tracking robot
 * @version 0.1
 * 
 * @copyright MIT License
 * 
 */


#ifndef INCLUDE_HUMANTRACKER_HPP_
#define INCLUDE_HUMANTRACKER_HPP_

#include <vector>
#include <memory>

#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>

#include <Detector.hpp>

namespace robot {
/**
 * @brief 
 * 
 */
class Track {
 public:
 /**
  * @brief Object to track humans on basis of confidence 
  * 
  * @param confidence 
  */
  explicit Track(double confidence);

  /**
   * @brief Destroy the Track object
   * 
   */
  ~Track();

  /**
   * @brief Tracks all humans present in the camera view 
   * 
   * @param frame 
   * @return vector of bbox
   */
  std::vector<cv::Rectangle> TrackHumans(const cv::Mat &frame);

 private:
  /**
   * @brief Initializes the default parameters
   * 
   * Required confidence to filter out the detections
   * 
   * @param confidence 
   */
  void InitParams(double confidence);

  /**
   * @brief Use threshold value to filter the most confident detections
   * 
   * @param unfiltered detections from the Detector
   */
  void Noise(const std::vector<acme::Detection>& detections);

 private:
  double confidence_thresh;
  std::vector<cv::Rectangle> humans;
  std::unique_ptr<robot::Detector> detector;
};
}  // namespace robot
#endif  

