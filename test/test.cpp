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
 * @file test.cpp
 * @author Phase 1 - Phase 1 - Anukriti Singh (design keeper), Jay Prajapati (driver), and
 *                   Shail Shah (navigator)
 * @brief Unit Tests for Acme Robotics - Human Tracker
 * @version 0.1
 * 
 * @copyright MIT License
 * 
 */

#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>


#include <cam_bot.hpp>
#include <track.hpp>
#include <detect.hpp>
#include <Utils.hpp>


acme_robots::cam_bot robot_object(0, -1);
acme_robots::Track tracker_object(0.1);
std::vector<std::string> classes = {"person"};
acme_robots::Detector detect_object(0.2, classes);
acme_robots::Utils utils_object;

TEST(cam_bot, Run) {
    acme_robots::Mode mode = acme_robots::Mode::RealTime;
    robot_object.TestCounter(1);
    robot_object.ShowWindow(false);
    ASSERT_NO_THROW(robot_object.Run(mode));

    mode = acme_robots::Mode::Testing;
    ASSERT_NO_THROW(robot_object.Run(mode));

    mode = acme_robots::Mode::Training;
    ASSERT_NO_THROW(robot_object.Run(mode));
}
TEST(cam_bot, FocalLength) {
    double fl = 0.036;
    ASSERT_NO_THROW(robot_object.FocalLength(fl));
}
TEST(cam_bot, ProcessingSize) {
    int w = 416;
    int h = 416;
    cv::Size s(w, h);
    ASSERT_NO_THROW(robot_object.ProcessingSize(w, h));
    ASSERT_NO_THROW(robot_object.ProcessingSize(s));
}
TEST(cam_bot, HumanHeight) {
    double height = 1.6;
    ASSERT_NO_THROW(robot_object.HumanHeight(height));
}

TEST(track, TrackHumans) {
    cv::Mat img = cv::imread("..//data//test.png");
    auto output = tracker_object.TrackHumans(img);
    ASSERT_EQ(static_cast<int>(output.size()), 1);
}

TEST(Detector, Detect) {
    cv::Mat img = cv::imread("..//data//test.png");
    auto output = detect_object.Detect(img);
    ASSERT_EQ(static_cast<int>(output.size()), 1);
}
TEST(Detector, ClassesToDetect) {
    ASSERT_NO_THROW(detect_object.Classes());
}
TEST(Detector, NmsThresh) {
    ASSERT_NO_THROW(detect_object.NmsThresh(0.4));
}
TEST(Detector, InputWIdth) {
    ASSERT_NO_THROW(detect_object.InputWIdth(640));
}
TEST(Detector, InputHeight) {
    ASSERT_NO_THROW(detect_object.InputHeight(480));
}
TEST(Detector, SwapRB) {
    ASSERT_NO_THROW(detect_object.SwapRB(true));
}
TEST(Detector, CropImg) {
    ASSERT_NO_THROW(detect_object.CropImg(false));
}
TEST(Detector, Backend) {
    ASSERT_NO_THROW(detect_object.Backend(0));
}
TEST(Detector, Target) {
    ASSERT_NO_THROW(detect_object.Target(0));
}
TEST(Detector, NumChannels) {
    ASSERT_NO_THROW(detect_object.NumChannels(3));
}
TEST(Detector, ScaleFactor) {
    double sf = 1.0;
    ASSERT_NO_THROW(detect_object.ScaleFactor(sf));
}
TEST(Detector, MeanToSubtract) {
    cv::Scalar mean = cv::Scalar();
    ASSERT_NO_THROW(detect_object.MeanToSubtract(mean));
}

TEST(Utils, DrawBbox) {
    cv::Mat img = cv::Mat::zeros(cv::Size(100, 100), CV_8UC3);
    cv::Rect box(2, 2, 2, 2);
    std::string label = "";
    auto output  = utils_object.DrawBbox(img, box, label);
    ASSERT_EQ(static_cast<int>(output.cols), 100);
    ASSERT_EQ(static_cast<int>(output.rows), 100);
}
TEST(Utils, GetBboxCenter) {
    cv::Rect r = cv::Rect(0, 0, 10, 10);
    auto output = utils_object.GetBboxCenter(r);
    ASSERT_EQ(output.x, 5);
    ASSERT_EQ(output.y, 5);
}
TEST(Utils, GetBboxArea) {
    cv::Rect r = cv::Rect(0, 0, 10, 10);
    auto output = utils_object.GetBboxArea(r);
    ASSERT_EQ(output, 100.0);
}
TEST(Utils, ResizeImage) {
    cv::Mat img = cv::Mat::zeros(cv::Size(10, 10), CV_8UC3);
    cv::Size s = cv::Size(20, 20);
    auto output  = utils_object.ResizeImage(img, s);
    ASSERT_EQ(static_cast<int>(output.cols), 20);
    ASSERT_EQ(static_cast<int>(output.rows), 20);
}
