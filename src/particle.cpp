#include "particle.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

particle::particle(ofPoint * _dest) 
{
	destination = *_dest ;
	position.x = rand() % ofGetWidth();
	position.y = rand() % ofGetHeight();
	position.z = rand() % 3000 - 1500;
	speed = (destination - position) / (float)(duration.get());
	invFadeIn = 1 / (float)(fadeIn.get());
}

particle::~particle()
{
}

void particle::update(uint64_t elapsedMs) {
	position += speed * elapsedMs;
	if (position.distance(destination) < 10) {
		position = destination;
		speed = ofPoint(0, 0);
	}
	if (alpha > 255) {
		alpha = 255; 
	} else {
		alpha += 255 * elapsedMs * invFadeIn;
	}
}

void particle::draw() {
	ofSetColor(ofColor::white, alpha);
	ofFill();
	ofDrawCircle(position, .5f);
}

ofParameter<int> particle::duration;
ofParameter<int> particle::fadeIn;

