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
 * @file pre_process.hpp
 * @author Jay Prajapati (jayp@umd.edu)
 * @author Shail Shah (sshah115@umd.edu)
 * @author Anukriti Singh (anukriti@umd.edu)
 *
 * @brief Preprocess class declaration and definition file
 * @version 2.0
 * @date 2022-10-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_PRE_PROCESS_HPP_
#define INCLUDE_PRE_PROCESS_HPP_

#include <vector>

#include <opencv2/opencv.hpp>

/**
 * @brief Preprocess class defines the outline for preprocessing input frame
 * based on provided network model i.e yolov5s
 *
 */
class Preprocess {
 public:
  const float INPUT_WIDTH = 640.0;
  const float INPUT_HEIGHT = 640.0;

  /**
   * @brief The acquired video frame is provided as input to yolov5s model and
   *        detections are extracted for post-processing.
   *
   * @param input_frame This function uses input_frame as input to pre-process
   * and output detections
   * @param net This param provides yolov5s model for processing of the input
   * frame
   * @return std::vector<cv::Mat> returns the detections as outputs to the main
   * function
   */
  std::vector<cv::Mat> pre_process(cv::Mat input_frame, cv::dnn::Net net) {
    cv::Mat blob;
    cv::dnn::blobFromImage(input_frame, blob, 1. / 255.,
                           cv::Size(INPUT_WIDTH, INPUT_HEIGHT), cv::Scalar(),
                           true, false);

    net.setInput(blob);

    std::vector<cv::Mat> preprocess_outputs;
    net.forward(preprocess_outputs, net.getUnconnectedOutLayersNames());

    return preprocess_outputs;
  }
};

#endif  // INCLUDE_PRE_PROCESS_HPP_
