
# Acme Robotics Human Tracker Module

[![Build Status](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/actions/workflows/build_and_coveralls.yml/badge.svg?branch=human_tracker)](https://github.com/ayprajapati009/Acme-Robotics-Human-Tracker/actions/workflows/build_and_coveralls.yml?branch=human_tracker)
[![Coverage Status](https://coveralls.io/repos/github/ayprajapati009/Acme-Robotics-Human-Tracker/badge.svg?branch=human_tracker)](https://coveralls.io/github/ayprajapati009/Acme-Robotics-Human-Tracker?branch=human_tracker)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

## Authors

- [Jay Prajapati](https://github.com/https://github.com/jayprajapati009)
- [Shail Shah](https://github.com/https://github.com/sshah115)
- [Anukriti Singh](https://github.com/https://github.com/AnukritiSinghh)

## Table of Contents

1. [Introduction](#introduction)
2. [Project Proposal Documentation](#project-proposal)
3. [Project Planning Documentation](#project-planning)

## Introduction

The goal of human detection is to locate every individual in each video image while making the fewest number of false positives. Because it could be used for military, safety, security, and entertainment purposes, the problem of detecting, localizing, and tracking human presence has received a lot of attention. Finding the locations of all instances of humans present in an image is the goal of human detection, which we will complete by examining every area of the image and locating humans in relation to the robotic frame.
  
### Project proposal

- The Project Proposal Document is attached [here](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/blob/main/proposal_documents/Acme%20Robotics%20Human%20Detector.pdf).  
- The Quad Chart is attached [here](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/blob/main/proposal_documents/QuadChart.pdf).  
- The UML Activity Diagram is attached [here](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/blob/main/proposal_documents/ENPM808X_ACME_Flowchart.pdf).  
- The UML Sequence Diagram is attached [here](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/blob/main/proposal_documents/ENPM808X_Proposal_ACME.pdf).  
- The video for the proposal is attached [here](https://drive.google.com/file/d/1kOzdRt9SPMXR_AmSA19PgOaBzf2L9vJt/view?usp=sharing).

### Project Planning

- As Agile Iterative Process (AIP) is used for the project, the AIP sheet is attached [here](https://docs.google.com/spreadsheets/d/166YucrRE8L5IEZP3Tnl1fXNnf7gSWNF5CJ9GKwdEBdU/edit?usp=sharing)
- The scrum meeting list and  is attached [here](https://docs.google.com/spreadsheets/d/166YucrRE8L5IEZP3Tnl1fXNnf7gSWNF5CJ9GKwdEBdU/edit?usp=sharing)

### Demo

Will be updated soon

### Dependencies

Will be updated soon

###  Issues/Bugs

So far not issues/bugs detected.

### Build Instrutions

Go to the cloned directory,
```sh
cd {path to the directory/test_driven_development}
```

Now we need to generate the build files,
```sh
mkdir build && cd build
```
```sh
cmake ..
```
```sh
make
```
Run the tests,
```sh
./test/human-tracker-test
```
Try out the PID Controller,
```sh
./app/human-tracker
```

###  Generate the Doxygen Documentation

To install doxygen
```sh
sudo apt-get install doxygen -y
```
Now open the cloned directory in the terminal
```sh
cd docs
doxygen Doxyfile
```
The generated file would be in the /docs/html/ directory, so in the cloned directory
```sh
cd docs/html/
google-chrome index.html
```

### Cpplint and Cppcheck

The results are stored in /results/cpplint/ and /results/cppcheck/ directories.
