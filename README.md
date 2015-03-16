# ofxCMT
Consensus-based Matching and Tracking of Keypoints (CMT) is a novel object tracking algorithm. Optical flow estimation is used to derive the movement of keypoints in a target ROI, and track their transformation over time. Keypoints are continually recomputed through a clustering function and an updated bounding box is solved for each frame. This is an error prone process but allows a very robust, lossy track of arbitrary and changing features without training a matching algorithm.

ofxCMT wraps DelMottea's C++ port of Python CMT:
https://github.com/delmottea/libCMT

Original code base published in the Winter Conference on Applications of Computer Vision, 2014,
"Matching and Tracking of Keypoints for Object Tracking", Nebehay, Georg and Pflugfelder, Roman.
https://github.com/gnebehay/CMT
http://www.gnebehay.com/cmt/

CMT requires OpenCV 2.4.9
http://opencv.org/downloads.html

Download your distribution separately and place the root /build of the distribution into addons/ofxCMT/libs/opencv_2.4.9
These directories are used by the example:
/build
/build/include
/build/include/opencv
/build/include/opencv2
/build/x86/vc11

Copy the appropriate VS compiled DLL's from OpenCV into your bin folder (The compiled example uses VS11 DLLs for Visual Studio 2012 - /addons/ofxCMT/libs/opencv_2.4.9/build/x86/vc11/bin/*.dll).
Use Release build settings for best performance.
