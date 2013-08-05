//
//  SceneOpening.cpp
//  joe
//
//  Created by 加藤 哲朗 on 2013/08/01.
//
//

#include "SceneOpening.h"

const int SceneOpening::duration = 12000;

SceneOpening::SceneOpening() : started(false) {
    ofLoadImage(tex, "others/first.jpg");
    tex.setAnchorPercent(0.5, 0.5);
    ofAddListener(ofEvents().keyPressed, this, &SceneOpening::keyPressed);
}

void SceneOpening::start() {
    startTime = ofGetElapsedTimeMillis();
    alpha.setCurve(EASE_OUT);
    alpha.setDuration(2.5);
    alpha.reset(0);
    alpha.animateToAfterDelay(255, 3);
}

void SceneOpening::update() {
    if (!started) return;
    if (ofGetElapsedTimeMillis() - startTime > duration) {
        ofSendMessage("OpeningEnd");
        return;
    }
    
    if (ofGetFrameNum()>0) {
        alpha.update(ofGetLastFrameTime());
    }
    
    if (!alpha.isOrWillBeAnimating()) {
        alpha.setCurve(EASE_IN);
        alpha.animateToAfterDelay(0, duration/1000.f - 2*alpha.getDuration() - 3 - 2);
    }
}

void SceneOpening::draw() {
    if (started) {
        ofPushStyle();
        ofEnableAlphaBlending();
        ofSetColor(255, alpha.getCurrentValue());
        tex.draw(ofGetWidth()/2, ofGetHeight()/2);
        ofPopStyle();
    } else {
        ofDrawBitmapString("-", 0, ofGetHeight()-100);
    }
}

void SceneOpening::keyPressed(ofKeyEventArgs &e) {
    if (e.key == OF_KEY_RETURN) {
        started = true;
        start();
    }
}