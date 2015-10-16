//\ ofxCMT
//\ rev03132015 Nathan Wade 

#include "ofxCMT.h"

using namespace ofxCv;
using namespace cv;

void ofxCMT::setup()
{
  detect = false;
  start = true;
  is_drawing_box = false;
  initTopLeft = cv::Point2f(0,0);
  initBottomDown = cv::Point2f(0,0);
}

void ofxCMT::update(ofPixelsRef &c)
{
	img = toCv(c);
	cv::cvtColor(img, im_gray, CV_RGB2GRAY);

	if(detect){
		if(start){
			cout << "initTopLeft:" << initTopLeft.x << "  initBottomDown:" << initBottomDown.x << "\n"; //DEBUG
			cmt.initialise(im_gray, initTopLeft, initBottomDown);
			start=false;
		}else{
			cmt.processFrame(im_gray);
		}
	}
}

void ofxCMT::draw()
{
	ofNoFill();

	if(is_drawing_box){
		ofSetColor(0,0,255);
		ofSetLineWidth(3);
		ofRect(toOf(initTopLeft),w,h);
	}

	if (detect && !is_drawing_box){
		//voting features
		for(int i = 0; i<cmt.trackedKeypoints.size(); i++){
			ofSetColor(255);
			ofSetLineWidth(1);
			ofCircle(toOf(cmt.trackedKeypoints[i].first.pt),3);

			cv::circle(img, cmt.trackedKeypoints[i].first.pt, 3, cv::Scalar(255,255,255));
			cv::line(img, cmt.topLeft, cmt.topRight, cv::Scalar(255,255,255));
			cv::line(img, cmt.topRight, cmt.bottomRight, cv::Scalar(255,255,255));
			cv::line(img, cmt.bottomRight, cmt.bottomLeft, cv::Scalar(255,255,255));
			cv::line(img, cmt.bottomLeft, cmt.topLeft, cv::Scalar(255,255,255));
		
			cv::waitKey(1);
		}

		//hitbox
		ofSetColor(0,0,255);
		ofSetLineWidth(3);
		ofLine(toOf(cmt.topLeft),toOf(cmt.topRight));
		ofLine(toOf(cmt.topRight),toOf(cmt.bottomRight));
		ofLine(toOf(cmt.bottomRight),toOf(cmt.bottomLeft));
		ofLine(toOf(cmt.bottomLeft),toOf(cmt.topLeft));
	}

	ofSetColor(255);
}


void ofxCMT::mouseDragged(int x, int y)
{
	
    if (is_drawing_box) {
		initBottomDown.x = x;
		initBottomDown.y = y;
    }

	w = initBottomDown.x - initTopLeft.x;
	h = initBottomDown.y - initTopLeft.y;
}

void ofxCMT::mousePressed(int x, int y)
{
    is_drawing_box = true;
    initTopLeft.x = x;
	initTopLeft.y = y;
}

void ofxCMT::mouseReleased(int x, int y)
{
    is_drawing_box = false;

	//swap points?
    if (initTopLeft.x > initBottomDown.x){
		cv::Point2f t0, t1;
		t0 = cv::Point2f(initTopLeft.x,initTopLeft.y);
		t1 = cv::Point2f(initBottomDown.x, initBottomDown.y);
		initTopLeft = cv::Point2f(t1.x, t1.y);
		initBottomDown = cv::Point2f(t0.x, t0.y);
	}


	if ( w > 1 &&  h > 1){
		detect = true;
		start = true;
	}
	
}

bool  ofxCMT::isDetect()
{
	return detect;
}
