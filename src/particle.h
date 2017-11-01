#pragma once
#include "ofPoint.h"
#include "ofParameter.h"

class particle
{
public:
	particle(ofPoint * _dest);
	~particle();
	void draw();
	void update(uint64_t delta);
	static ofParameter<int> duration;
	static ofParameter<int> fadeIn;
	
	
private:
	ofPoint destination;
	ofPoint position;
	ofPoint speed;
	float alpha = 0;

	float invDuration;
	float invFadeIn;
};

