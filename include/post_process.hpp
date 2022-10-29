

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
 * @file post_process.hpp
 * @author Jay Prajapati (jayp@umd.edu)
 * @author Shail Shah (sshah115@umd.edu)
 * @author Anukriti Singh (anukriti@umd.edu)
 *
 * @brief Postprocess class declaration and definition file
 * @version 2.0
 * @date 2022-10-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _HOME_JP_VSCODES_ACME_ROBOTICS_HUMAN_TRACKER_INCLUDE_POST_PROCESS_HPP_
#define _HOME_JP_VSCODES_ACME_ROBOTICS_HUMAN_TRACKER_INCLUDE_POST_PROCESS_HPP_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <ostream>
#include <string>
#include <vector>

#include "./../include/draw_label.hpp"
#include "./../include/pre_process.hpp"

/**
 * @brief Postprocess class defines the outline for postprocessing input frame
 * based on provided detections and providing resulting image to main function.
 *
 */
class Postprocess : public Preprocess, public Draw_Label {
private:
  const float SCORE_THRESHOLD = 0.5;
  const float NMS_THRESHOLD = 0.45;
  const float CONFIDENCE_THRESHOLD = 0.45;
  cv::Scalar BLUE = cv::Scalar(255, 178, 50);
  cv::Scalar RED = cv::Scalar(0, 0, 255);

public:
  /**
   * @brief The acquired video frame, detection outputs and detection class list
   * are provided as input to this function. Using these inputs it makes
   * judgement based on confidence level and thresholds filters unwanted
   * detections.
   *
   * @param input_frame This function uses input_frame as input to post-process
   * and output resulting image.
   * @param preprocess_outputs The detections from preprocessing are utilized to
   * filter unwanted detections based on threshols to output final image.
   * @param class_name This list enlists the variety of objects that can be
   * detected using this model.
   * @return cv::Mat
   */
  cv::Mat post_process(cv::Mat input_frame,
                       std::vector<cv::Mat> preprocess_outputs,
                       std::vector<std::string> class_name) {
    std::vector<int> class_ids;
    std::vector<float> confidences;
    std::vector<cv::Rect> boxes;

    float x_factor = input_frame.cols / INPUT_WIDTH;
    float y_factor = input_frame.rows / INPUT_HEIGHT;

    float *data = (float *)preprocess_outputs[0].data;

    const int rows = 25200;

    for (int i = 0; i < rows; ++i) {
      float confidence = data[4];
      if (confidence >= CONFIDENCE_THRESHOLD) {
        float *classes_scores = data + 5;

        cv::Mat scores(1, class_name.size(), CV_32FC1, classes_scores);

        cv::Point class_id;
        double max_class_score;
        minMaxLoc(scores, 0, &max_class_score, 0, &class_id);

        if (max_class_score > SCORE_THRESHOLD) {
          confidences.push_back(confidence);
          class_ids.push_back(class_id.x);

          float cx = data[0];
          float cy = data[1];

          float w = data[2];
          float h = data[3];

          int left = static_cast<int>((cx - 0.5 * w) * x_factor);
          int top = static_cast<int>((cy - 0.5 * h) * y_factor);
          int width = static_cast<int>(w * x_factor);
          int height = static_cast<int>(h * y_factor);

          boxes.push_back(cv::Rect(left, top, width, height));
        }
      }

      data += 85;
    }

    std::vector<int> indices;
    cv::dnn::NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD,
                      indices);
    for (unsigned long int i = 0; i < indices.size(); i++) {
      int idx = indices[i];
      cv::Rect box = boxes[idx];

      int left = box.x;
      int top = box.y;
      int width = box.width;
      int height = box.height;

      rectangle(input_frame, cv::Point(left, top),
                cv::Point(left + width, top + height), BLUE, 3 * THICKNESS);

      std::string label = class_name[class_ids[idx]] + ":";

      Draw_Label objl;
      objl.draw_label(input_frame, label, left, top);
    }
    return input_frame;
  }
};

#endif // _HOME_JP_VSCODES_ACME_ROBOTICS_HUMAN_TRACKER_INCLUDE_POST_PROCESS_HPP_
