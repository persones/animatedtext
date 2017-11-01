#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	gui.setup();
	ofParameterGroup particleGui;
	particleGui.add(particle::duration.set("duration", 1000, 10, 10000));
	particleGui.add(particle::fadeIn.set("fade in", 1000, 10, 10000));

	gui.add(fontSize.set("font size", 20, 5, 200));
	gui.add(redraw.setup("redraw"));
	
	

	gui.add(particleGui);
	redraw.addListener(this, &ofApp::init);
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	init();
}

//--------------------------------------------------------------
void ofApp::update(){
	uint64_t now = ofGetElapsedTimeMillis();
	uint64_t delta = now - lastTime;

	for (vector<particle *>::iterator it = particles.begin(); it != particles.end(); ++it) {
		(*it)->update(delta);
	}
	lastTime = now;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);
	ofSetColor(ofColor::white);
	//fbo.draw(0, 0);
	for (vector<particle *>::iterator it = particles.begin(); it != particles.end(); ++it) {
		(*it)->draw();
	}
	gui.draw();
	ofDrawBitmapString(ofGetFrameRate(), 600, 10);
}

void ofApp::init() {
	
	textPoints.clear();
	particles.clear();
	myFont.load("Prototype.ttf", fontSize.get(), true, true, true);
	fbo.begin();
	ofClear(0, 0, 0);
	myFont.drawString("Your cells keep\n regenerating", 0, fontSize.get());
	ofPixels pix;
	fbo.readToPixels(pix);
	int i = 0;
	for (int y = 0; y < ofGetHeight(); ++y) {
		for (int x = 0; x < ofGetWidth(); ++x) {
			if (pix[i] > 0) {
				ofPoint * p = new ofPoint(x, y);
				textPoints.push_back(p);
				particles.push_back(new particle(p));
			}
			i += 4;
		}
	}
	fbo.end();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
