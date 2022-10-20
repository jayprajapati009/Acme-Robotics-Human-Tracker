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
 * @file main.cpp
 * @author Phase 1 - Anukriti Singh (design keeper), Jay Prajapati (driver), and Shail Shah (navigator)
 * @brief main file for Acem Robotic Human Tracker
 * @version 0.1
 * 
 * @copyright MIT License
 * 
 */



#include "cam_bot.hpp"

int main() {
    /// define the operation mode
    acme_robots::Mode mode = acme_robots::Mode::RealTime;

    /// Initializing cam_bot
    acme_robots::cam_bot HumanTracking(0, 0.5);

    /// Calling run methof
    HumanTracking.Run(mode);

    std::cout << "Successfully Created Acme cam_bot" << std::endl;
    return 0;
}
