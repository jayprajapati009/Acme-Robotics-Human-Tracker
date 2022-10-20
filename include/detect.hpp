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
 * @file detect.hpp
 * @author Phase 1 - Anukriti Singh (Design keeper), Jay Prajapati (Driver), and Shail Shah (Navigator)
 * @brief Detection module for Acme Robotics - Human Tracker
 * @version 0.1
 * 
 * @copyright MIT License
 * 
 */


#ifndef INCLUDE_DETECT_HPP_
#define INCLUDE_DETECT_HPP_

#include <memory>
#include <vector>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/dnn/shape_utils.hpp>

#include <Utils.hpp>


namespace acme_robots {
struct Detection {
      Detection(cv::Rect box, double conf, const std::string &n) :
      bbox(box), confidence(conf), name(n) {}
      cv::Rect bbox;
      double confidence;
      std::string name;
};
class Detector {
 public:
    Detector(double conf, const std::vector<std::string> &classes);
    ~Detector();
      std::vector<acme_robots::Detection> Detect(const cv::Mat& frame);

      void Classes(const std::vector<std::string> &classes = {});
      void NmsThresh(const double nms_thresh);
      void InputWIdth(const int input_width);
      void InputHeight(const int input_height);
      void ScaleFactor(const double scale_factor);
      void MeanToSubtract(const cv::Scalar &mean);
      void SwapRB(const bool swap_rb);
      void CropImg(const bool crop_img);
      void Backend(const int backend);
      void Target(const int target);
      void NumChannels(const int num_channels);

 private:
      void WarmUp();
      void InitModel(double conf, const std::vector<std::string> &c);
      std::vector<acme_robots::Detection> ProcessNet(const cv::Size &s);

 private:
        double conf_thresh_;
        std::vector<std::string> classes_;
        std::vector<std::string> all_classes_;
        double nms_thresh_;
        double input_height_;
        double input_width_; 
        cv::Size size_;
        double scale_;
        cv::Scalar mean_;
        int num_channels_;
        bool swap_;
        bool crop_;
        int backend_;
        int target_;
        cv::dnn::Net network_;
        std::vector<std::string> out_names_;
        std::vector<cv::Mat> outputs_;
};
}  // namespace acme_robots
#endif  // INCLUDE_DETECT_HPP_
