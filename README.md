

# Acme Robotics Human Tracker Module

[![Build Status](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/ayprajapati009/Acme-Robotics-Human-Tracker/actions/workflows/build_and_coveralls.yml)
[![Coverage Status](https://coveralls.io/repos/github/jayprajapati009/Acme-Robotics-Human-Tracker/badge.svg?branch=main)](https://coveralls.io/github/jayprajapati009/Acme-Robotics-Human-Tracker?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Authors

- [Jay Prajapati](https://github.com/https://github.com/jayprajapati009)
- [Shail Shah](https://github.com/https://github.com/sshah115)
- [Anukriti Singh](https://github.com/https://github.com/AnukritiSinghh)

## Table of Contents

1. [Introduction](#introduction)
2. [Project Proposal Documentation](#project-proposal)
3. [Project Implementation Documentation](#project-implementation)
4. [Demo](#demo)
5. [Dependencies](#dependencies)
6. [Build Instruction](#build-instructions)
7. [Doxygen Documentation](#generate-the-doxygen-documentation)
8. [Cpplint and Cppcheck](#cpplint-and-cppcheck)
9. [References](#references)

## Introduction

The goal of human detection is to locate every individual in each video image while making the fewest number of false positives. Because it could be used for military, safety, security, and entertainment purposes, the problem of detecting, localizing, and tracking human presence has received a lot of attention. Finding the locations of all instances of humans present in an image is the goal of human detection, which we will complete by examining every area of the image and locating humans in relation to the robotic frame.
  
### Project proposal
|Deliverable|Link|
|---|---|
|Project Proposal Document|[here](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/blob/main/proposal_documents/Acme%20Robotics%20Human%20Detector.pdf)|
|Quad Chart|[here](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/blob/main/proposal_documents/QuadChart.pdf)|
|UML Activity Diagram|[here](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/blob/main/proposal_documents/ENPM808X_ACME_Flowchart.pdf)|
|UML Sequence Diagram is attached|[here](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/blob/main/proposal_documents/ENPM808X_Proposal_ACME.pdf)|  
|Proposal Video|[here](https://drive.google.com/file/d/1kOzdRt9SPMXR_AmSA19PgOaBzf2L9vJt/view?usp=share_link)|

### Project Implementation
|Deliverable|Link|
|---|---|
|AIP sheet is attached|[here](https://docs.google.com/spreadsheets/d/166YucrRE8L5IEZP3Tnl1fXNnf7gSWNF5CJ9GKwdEBdU/edit?usp=sharing)|
|Sprint and Review Meeting Notes|[here](https://docs.google.com/document/d/1MRIKLqFYe-GjEmR_fL_krQcXT3Q6iq5koS9r7n5rJDE/edit?usp=sharing)|
|Phase-1 Video|[here](https://drive.google.com/file/d/15CELuPP5a5_Knek-NCUMgxb0wNsRb76w/view?usp=share_link)|
|Phase-2 Video|[here](https://drive.google.com/file/d/1XU1qVc-Vq--zFrXQqLE9aakxbYuPS_j6/view?usp=share_link)|
|Updated UML Diagram (Class Diagram)|[here](https://github.com/jayprajapati009/Acme-Robotics-Human-Tracker/tree/main/UML_diagrams/final_uml)|


### Demo

Detection output of running the detection model over live camera feed. [Video](https://drive.google.com/file/d/1e1j4Rlp-jCm_DBXqBRSw_dl0_h2HiZUj/view?usp=sharing)
![alt text](./docs//screen-record.gif?raw=true "Human Detector Result on live feed")

### Dependencies

To install all the required dependencies, run the following command in the cloned  directoy,
```sh
sh cppcheck_and_cpplint.sh
```

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
Try out the Human Tracking,
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

```sh
sh requirements.sh
```

### References 

[1] https://ieeexplore.ieee.org/abstract/document/9431784?casa_token=6QG6gNyMzaAAAAAA:7UZzewC41C_CT4XgNE8sk-X07UprnCQsfflC3bfPc_IdY2SJvaOFf2aKJAp7aRToY38mUv7e6Q

[2] https://www.youtube.com/watch?v=sYFhZ4Jc8k4

[3] https://www.youtube.com/watch?v=2FYm3GOonhk

[4] https://github.com/matlab-deep-learning/Object-Detection-Using-Pretrained-YOLO-v2/blob/main/+helper/coco-classes.txt

[5] https://www.youtube.com/watch?v=BCJYorKIlN8
