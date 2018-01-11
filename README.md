# mav-visual-stabilizer

# Launching Gazebo with ROS:
To launch posix_sitl_default via ROS, follow instructions under "Launching Gazebo with ROS Wrappers"
https://dev.px4.io/en/simulation/ros_interface.html

# Using vision_pose_estimate
under ../Firmware/posix-configs/SITL/init/lpe
  edit iris (or whichever model)
   param set ATT_EXT_HDG_M 1 (1 for vision estimate, 2 for mocap estimate)
   param set LPE_FUSION 28 (default 145 for GPS. Explanation of bits in QGroundControl)
*delete gpssim start
