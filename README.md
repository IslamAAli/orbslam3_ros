### Using ROS with ORB-SLAM3 in Monocular mode with usb-camera 
1. Open your camera node 
```
roslaunch ORB_SLAM3 usb_cam.launch
```
2. Launch ORB-SLAM3
```
rosrun ORB_SLAM3 Mono Vocabulary/ORBvoc.txt config_files/Logitech_c270_HD720p.yaml /camera/image_raw:=/usb_cam/image_raw
```