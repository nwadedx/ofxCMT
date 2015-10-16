//\ ofxCMT
//\ rev03132015 Nathan Wade 

#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "CMT.h"

using namespace ofxCv;
using namespace cv;

class ofxCMT
{
public:
	void setup();
	void update(ofPixelsRef &c);
	void draw();
	void mouseDragged(int x, int y);
	void mousePressed(int x, int y);
	void mouseReleased(int x, int y);
	bool isDetect();

	bool detect, start, is_drawing_box;

private:
	CMT cmt;
	cv::Mat img, im_gray;
	cv::Point2f initTopLeft, initBottomDown;
	float w, h;

};
