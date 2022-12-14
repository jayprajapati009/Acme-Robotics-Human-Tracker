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
 * @file main.cpp
 * @author Jay Prajapati (jayp@umd.edu)
 * @author Shail Shah (sshah115@umd.edu)
 * @author Anukriti Singh (anukriti@umd.edu)
 *
 * @brief Designing and developing 'Perception module' for Acme Robotics
 *        The main.cpp file covers following tasks of project:
 *        1) Human obstacle detection (N>1)
 *        2) Tracks humans with unique IDs
 *        3) Assigns label with co-ordinates of Human's position
 *        4) Works on single monocular video camera
 * @version 2.0
 * @date 2022-10-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <fstream>
#include <opencv2/opencv.hpp>

#include "./../include/draw_label.hpp"
#include "./../include/post_process.hpp"
#include "./../include/pre_process.hpp"

/**
 * @brief 1) Loads object detection class list
 *        2) Loads frames from video stream of monocular camera
 *        3) Loads network for detection result
 *        4) Pre- & Post-processes the acquired detections
 *        5) Displays result in output window
 *
 * @return int
 */
int main() {
  std::vector<std::string> class_list;
  std::ifstream ifs("../app/resources/coco.names");
  std::string line;

  while (getline(ifs, line)) {
    class_list.push_back(line);
  }

  cv::VideoCapture cap(0);
  cv::Mat video_frame;

  while (true) {
    cap.read(video_frame);

    cv::dnn::Net net;
    net = cv::dnn::readNet("./../app/resources/models/yolov5s.onnx");

    std::vector<cv::Mat> detections;
    Preprocess objp;
    detections = objp.pre_process(video_frame, net);

    Postprocess objpp;
    cv::Mat img =
        objpp.post_process(video_frame.clone(), detections, class_list);

    cv::imshow("Output", img);
    cv::waitKey(1);
  }
  return 0;
}
