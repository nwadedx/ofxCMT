//\ ofxCMT Example
//\ rev03132015 Nathan Wade 

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


	cam.listDevices();
	cam.setDeviceID(1); //edit index to match source
	cam.setVerbose(true);
	cam.initGrabber(640, 480); //edit size to match source

    	cmt.setup();
	pause = 0;

}

//--------------------------------------------------------------
void testApp::update(){

	//we update only if target ROI is not being set
	if(!cmt.is_drawing_box){
		cam.update();
		if(cam.isFrameNew()) {
			cmt.update(cam.getPixelsRef());
		}
	}

}

//--------------------------------------------------------------
void testApp::draw(){
	
	cam.draw(0,0);
	cmt.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

///--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
	cmt.mouseDragged(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	cmt.mousePressed(x, y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
	cmt.mouseReleased(x, y);
	cmt.update(cam.getPixelsRef());
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
