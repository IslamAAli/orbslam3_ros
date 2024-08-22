#!/bin/bash

docker run -d -p 5900:5900 --memory-swap=16g --memory=8g --cpus="4.0" --rm --network host -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --privileged --device=/dev/video0:/dev/video0 --env QT_X11_NO_MITSHM=1 -it islamaali/orbslam3_ros-docker:v1.0
