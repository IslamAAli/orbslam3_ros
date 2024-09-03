#!/bin/bash

# Building Script for CARV SLAM docker container

clear
echo "========================================================================================================="
echo "> MAINTAINER: Islam A. Ali <islam.a.mustafa@gmail.com>"
echo "> VERSION: 1.0"
echo "========================================================================================================="

                                                                                                         
# docker build --no-cache --rm -t islamaali/orbslam3_ros-docker:v1.0 .
docker build --rm -t islamaali/orbslam3_ros-docker:v1.0 .
