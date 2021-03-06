#pragma once

#include "ofMain.h"
#include "ofxRemoteUIServer.h"

class ofxFilterUnits {
public:
    
    static ofxFilterUnits* one();
    
    void setup();
    
    void setFPS(float __fps) { _fps = __fps; }
    
    // frames per second
    float fps() { return _fps; }
    // seconds per frame
    float spf() { return 1.0/_fps; }
    
    // convert frames to seconds
    float f2s() { return 1.0/_fps; }
    // convert seconds to frames
    float s2f() { return _fps; }
    
    // Convert an easing param from one frame rate to another.
    float convertEaseParam(float param, float refFPS);
    
    
    
    
    
private:
    
    static ofxFilterUnits* _instance;
    
    ofxFilterUnits() {};
    ~ofxFilterUnits() {};
    
    bool bSetup = false;
    
    // Frame rate
    float _fps = 60;

};
