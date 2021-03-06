#pragma once

#include "ofMain.h"
#include "ofxRemoteUIServer.h"
#include "ofxCv.h"
#include "ofxFilterUtils.h"
#include "ofxFilterData.h"
#include "ofxFilterOp.h"

class ofxFilterOpEasingSettings : public ofxFilterOpSettings {
public:

	ofxFilterOpEasingSettings() {
		type = "easing";
	};
	~ofxFilterOpEasingSettings() {};

	void setupParams();

	float easingParam = 0.9;
    
    // After how many empty frames will we reset the ease?
    // -1   never reset
    // 1    after a single frame
    // n    after n frames
    int nEmptyFramesToReset = 1;

    

};

class ofxFilterOpEasing : public ofxFilterOp {
public:

	// Setup this operator
	void setup(ofxFilterOpSettings* _settings);

	// Apply this operator to data and get transformed data as output
	void process(ofxFilterData& data);


protected:

	ofxFilterData lastValidData;
	bool bFirstEase = true;

    int nFramesSinceObs = 0;

};
