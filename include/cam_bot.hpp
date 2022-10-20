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
 * @file cam_bot.hpp
 * @author Phase 1 - Anukriti Singh (Design keeper), Jay Prajapati (Driver), and Shail Shah (Navigator)
 * @brief cam_bot class declaration for Acme Robotics - Human Tracker
 * @version 0.1
 * 
 * @copyright MIT License
 * 
 */


#ifndef INCLUDE_CAM_BOT_HPP_
#define INCLUDE_CAM_BOT_HPP_

#include <string>
#include <vector>
#include <memory>

#include <track.hpp>

namespace acme_robots {
  enum Mode {
       /// Complete detection & tracker module
      RealTime = 0,
      /// Acquiring data for training
      Training,
      /// Testing detector module with user provided test
      /// data and output metrics
      Testing
  };
/**
 * @brief Acme Robotics - Human Tracker
 * 
 * Mode selection is at user's disposal to select as required
 * Display human's coordinates with respect to Robot reference frame
 * 
 */
class cam_bot {
 public:
     /**
      * @brief Construct a new cam_bot object
      * 
      * Initializes default parameters used by cam_bot class
      * 
      * @param camera_id 
      * @param calibration_factor 
      */
      explicit cam_bot(const int camera_id = 0, double calibration_factor = -1);
      /**
       * @brief Deconstruct the cam_bot object
       * 
       */
      ~cam_bot();
     /// Initializing essential funtions based on selected mode of operation
      void Run(const acme_robots::Mode mode);
      void FocalLength(double focal_length);
      void ProcessingSize(const int width, const int height);
      void ProcessingSize(const cv::Size & s);
      void HumanHeight(const double avg_human_height);
      void ShowWindow(const bool show_window);
      void TestCounter(const int counter);

 private:
      void TrainData_collect();
      void TestData_detect();
      void RunRealTime();
      void Calibrate();
      void InitParams(int camera_id, double calib_factor);



 private:
  int camera_id_;
  double focal_length_;
  int frame_width_;
  int frame_height_;
  int frame_rate_;
  double avg_human_height_;
  cv::Mat p_frame_;
  cv::Size p_size_;
  double calib_factor_;
  cv::VideoCapture cap_;
  bool show_window_;
  int test_counter_;
};
}  // namespace acme_robots

#endif  // INCLUDE_CAM_BOT_HPP_
