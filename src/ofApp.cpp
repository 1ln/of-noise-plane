#include "ofApp.h"

void ofApp::setup() {

filepath = filesystem::path("../../src");
shader.load(filepath/"render.vert",filepath/"render.frag");

ofBackground(255);
glPointSize(10.);

w = ofGetWidth();
h = ofGetHeight();

s.allocate(w,h,GL_RGBA);

s.begin();
ofClear(0);
s.end();

plane.set(64 * glm::golden_ratio<float>(),64,256,256);

cam.setPosition(glm::vec3(0,-10,35));
cam.lookAt(glm::vec3(0.0));
cam.setNearClip(.01);

light.setup();
light.enable();
light.setPosition(glm::vec3(0,0,35));

}

void ofApp::draw() {

cam.begin();
shader.begin();

shader.setUniform3f("u_light_pos",light.getPosition());
shader.setUniform4f("u_color",glm::vec4(.05,.05,.05,1.));

plane.drawVertices();

shader.end();
cam.end(); 

}

void ofApp::update() {

w = ofGetWidth();
h = ofGetHeight();

printInfo();

}

void ofApp::printInfo() {

   cout << "Frame Rate: " + ofToString(ofGetFrameRate()) << endl;
   cout << "Camera Position : " + ofToString(cam.getPosition()) << endl;

}

void ofApp::windowResized(int w,int h) {

screen_size = ofToString(w) + "," + ofToString(h);

}

void ofApp::keyPressed(int key) {

    if(key == 's') {
        img.grabScreen(0,0,w,h);
        img.save("../../source.png");
    }
}


