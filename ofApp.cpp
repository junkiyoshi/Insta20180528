#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	this->draw_circles(ofPoint(-110, 0), ofColor(39));
	ofRotateX(180);
	this->draw_circles(ofPoint(110, 0), ofColor(39));

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::draw_circles(ofPoint point, ofColor color) {

	// Translate Coordinate
	ofPushMatrix();
	ofTranslate(point);

	// Initialize Param Variable
	int radius = 100;
	int circle_span = 20;
	int number_of_circle = 13;

	// Draw Circles
	for (int i = 0; i < number_of_circle; i++) {

		float z = i * circle_span + (int)(ofGetFrameNum() * 0.5) % circle_span;
		ofSetColor(color, ofMap(z, 0, circle_span * number_of_circle, 255, 0));

		ofBeginShape();
		for (int deg = 0; deg < 360; deg++) {

			float x = radius * cos(deg * DEG_TO_RAD);
			float y = radius * sin(deg * DEG_TO_RAD);
			ofVertex(x, y, z);
		}
		ofEndShape(true);
	}

	// Draw Bottom Circle
	ofSetColor(color, ofMap((int)(ofGetFrameNum() * 0.5) % circle_span, 0, circle_span, 0, 255));
	ofBeginShape();
	for (int deg = 0; deg < 360; deg++) {

		float x = radius * cos(deg * DEG_TO_RAD);
		float y = radius * sin(deg * DEG_TO_RAD);
		ofVertex(x, y, 0);
	}
	ofEndShape(true);

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}