#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    public:

    void setup();
    void draw();
    void update();  

    void keyPressed(int key);
    void windowResized(int w,int h); 

    void printInfo();

    int w;
    int h;
 
    ofPlanePrimitive plane; 
    ofEasyCam cam;
    ofLight light;

    ofFbo s;

    ofShader shader;
    ofImage img;      

    string screen_size;
    string fps_counter;

    filesystem::path filepath;


};
