//
//  Image.cpp
//  joe
//
//  Created by 加藤 哲朗 on 2013/07/29.
//
//

#include "Image.h"


using namespace nistetsurooy;

Image::Image() : ofImage() {
    position.setDuration(3);
    position.setCurve(EASE_OUT);
    alpha.setDuration(1);
    alpha.setCurve(EASE_OUT);
    setAnchorPercent(0.5, 0.5);
}

void Image::draw() {
    if (position.isOrWillBeAnimating()) {
        ofPushStyle();
        ofSetColor(ofColor::white, alpha.getCurrentValue());
        // ofImage::draw(ofPoint)はzが考慮されない罠に注意
        ofPoint p = position.getCurrentPosition();
        ofImage::draw(p.x, p.y, p.z);
        ofPopStyle();
    }
}

void Image::startAnimation() {
    init();
}

void Image::init() {
    if (position.isOrWillBeAnimating()) {
        return;
    }
    ofVec3f origin(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
    origin.normalize();
    origin *= 50;
    ofVec3f destination = -origin;
    
    position.setPosition(origin);
    position.animateTo(destination);
    
    alpha.animateFromTo(0, 255);
}

void Image::updateAnimation(float dt) {
    position.update(dt);
    alpha.update(dt);
    if (!alpha.isOrWillBeAnimating()) {
        alpha.setCurve(EASE_IN);
        alpha.animateToAfterDelay(0, max(position.getDuration()-alpha.getDuration()*2, 0.f));
    }
}

bool Image::shouldStartNext() {
    return position.getPercentDone() > 0.8;
}

bool Image::getAnimating() {
    return position.isOrWillBeAnimating();
}