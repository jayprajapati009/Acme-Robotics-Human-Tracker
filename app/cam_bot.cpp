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
 * @file cam_bot.cpp
 * @author Phase 1 - Anukriti Singh (Design keeper), Jay Prajapati (Driver), and Shail Shah (Navigator)
 * @brief cam_bot class definition for Acme Robotics - Human Tracker
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <eigen3/Eigen/Dense>
#include <cam_bot.hpp>

acme_robots::cam_bot::cam_bot(const int camera_id, double calib_factor) {
    /// Initializes default parameters
    InitParams(camera_id, calib_factor);
}

acme_robots::cam_bot::~cam_bot() {}

void acme_robots::cam_bot::Run(const Mode mode) {
    /// Based on the mode selected, run the specific module
    switch ( static_cast<int>(mode) ) {
        case 1:
            TrainData_collect();
            break;
        case 2:
            TestData_detect();
            break;
        default:
            RunRealTime();
            break;
    }
}
void acme_robots::cam_bot::FocalLength(const double fl) {
    /// Initializing FocalLength function
    focal_length_ = fl;
}

void acme_robots::cam_bot::ProcessingSize(const int w, const int h) {
    /// Initializing ProcessingSize function
    cv::Size s = cv::Size(w, h);
    ProcessingSize(s);
}

void acme_robots::cam_bot::ProcessingSize(const cv::Size &s) {
    /// Initializing ProcessingSize object function
    p_size_ = s;
}

void acme_robots::cam_bot::HumanHeight(const double h) {
    /// Initializing HumanHeight function
    avg_human_height_ = h;
}

void acme_robots::cam_bot::ShowWindow(const bool show_window) {
    /// Initializing ShowWindow function
    show_window_ = show_window;
}

void acme_robots::cam_bot::TestCounter(const int counter) {
    /// Initializing TestCounter function
    test_counter_ = counter;
}

void acme_robots::cam_bot::TrainData_collect() {
    /// Initializing TrainData_collect function for training module
    std::string address;
    int frame_count = 0;
    address = "..//data//train//";
    frame_count = 2;
    cv::VideoCapture cap(camera_id_);

  if (!cap.isOpened()) {
    std::cerr << "ERROR: Could not open video " << std::endl;
    return;
  } else {
        for (int counter = 0; counter < frame_count; counter++) {
    cv::Mat frame;
    cap >> frame;
    std::string file_name = address+"//"+std::to_string(counter) + ".jpg";
    cv::imwrite(file_name, frame);
  }
}

  return;
}


void acme_robots::cam_bot::TestData_detect() {
    /// Initializing TestData_detect function for detector module
    cap_.release();
    cv::Mat img1 = cv::imread("..//data//test//1.png");
    cv::Mat img2 = cv::imread("..//data//test//2.png");
    cv::Mat img3 = cv::imread("..//data//test//3.png");
    cv::Mat img4 = cv::imread("..//data//test//4.png");
    cv::Mat img5 = cv::imread("..//data//test//5.jpeg");

    std::vector<cv::Rect> ground_truth_2 = {cv::Rect(330, 107, 160, 294)};

    std::vector<cv::Rect> ground_truth_3 = {cv::Rect(298, 126, 98, 228)};

    std::vector<cv::Rect> ground_truth_1 = {cv::Rect(300, 21, 197, 310)};

    std::vector<cv::Rect> ground_truth_4 = {cv::Rect(297, 84, 147, 265)};

    std::vector<cv::Rect> ground_truth_5 = {cv::Rect(320, 55, 110, 400),
        cv::Rect(430, 50, 120, 415)};
    std::vector<std::vector<cv::Rect>> gts = {ground_truth_1, ground_truth_2,
        ground_truth_3, ground_truth_4, ground_truth_5};


    std::vector <cv::Mat> imgs = {img1, img2, img3, img4, img5};
    for (int i = 0; i < static_cast<int>(imgs.size()); i++) {
        p_frame_ = acme_robots::Utils::ResizeImage(imgs[i], p_size_);
        for ( int j = 0; j < static_cast<int>(gts[i].size()); j++ ) {
        
    }
    }
}



void acme_robots::cam_bot::RunRealTime() {
    /// Initializing RunRealTime function
    if (calib_factor_ == -1) {
        Calibrate();
    }
    const std::string kWindowName = "Display";

    if ( show_window_ ) {
        cv::namedWindow(kWindowName, cv::WINDOW_FREERATIO);
    }
    unsigned int frame_counter = 0;
    std::vector<cv::Rect> human_tracks{};
    cv::Size src_size;
    while (true) {
        cv::Mat src_frame;
        if ( cap_.read(src_frame) ) {
            if ( frame_counter == 0 ) {
                src_size = src_frame.size();
            }
            p_frame_ = acme_robots::Utils::ResizeImage(src_frame, p_size_);
            p_frame_ = acme_robots::Utils::ResizeImage(p_frame_, src_size);

            if ( show_window_ ) {
                cv::imshow(kWindowName, p_frame_);
                char k = cv::waitKey(1);
                if ( k == 27 || k == 'q' ) {
                    return;
                }
            }

            frame_counter++;

            if ( test_counter_ != -1 ) {
                if ( static_cast<int>(frame_counter) > test_counter_ ) {
                    return;
                }
            }
        } else {
            std::cout << "Cannot read frame" << std::endl;
            return;
        }
    }
}

void acme_robots::cam_bot::Calibrate() {
    /// Initializing Calibrate function
    cv::Mat image = cv::imread("..//data//calibrate.jpg", 0);
    cv::Mat thr;
    double original_distance = 20;
    double original_width = 10;
    cv::threshold(image, thr, 150, 255, cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(thr, contours, hierarchy,
                    cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    double maxArea = 0;
    int maxAreaContourId = -1;
    for (int j = 0; j < static_cast<int>(contours.size()); j++) {
        double newArea = cv::contourArea(contours.at(j));
        if (newArea > maxArea) {
            maxArea = newArea;
            maxAreaContourId = j;
        }
    }
    cv::Rect box = cv::boundingRect(contours[maxAreaContourId]);
    double focalLength = (box.width * original_distance) / original_width;
    std::cout << focalLength;
    FocalLength(focalLength);
    calib_factor_ = focalLength * avg_human_height_;
}



void acme_robots::cam_bot::InitParams(int camera_id, double calib_factor) {
    /// Initializing InitParams function for setting initial parameters
    camera_id_ = camera_id;
    calib_factor_ = calib_factor;
    focal_length_ = 0.036;
    avg_human_height_ = 1.7;
    p_size_ = cv::Size(640, 480);
    double confidence_threshold = 0.6;
    show_window_ = true;
    test_counter_ = -1;
    auto path = camera_id_;
    cap_.open(path);
    if ( cap_.isOpened() ) {
        frame_width_ = cap_.get(cv::CAP_PROP_FRAME_WIDTH);
        frame_height_ = cap_.get(cv::CAP_PROP_FRAME_HEIGHT);
        frame_rate_ = cap_.get(cv::CAP_PROP_FPS);
        if (frame_height_ == 0 || frame_width_ == 0) {
            std::cout << "Frame is empty" << std::endl;
            return;
        }
    } else {
            std::cout << "Cannot open camera" << std::endl;
            return;
    }
}
