//
//  SceneLabLogo.cpp
//  joe
//
//  Created by 加藤 哲朗 on 2013/08/01.
//
//

#include "SceneLabLogo.h"

SceneLabLogo::SceneLabLogo() {
    ofLoadImage(tex, "others/logo.png");
    tex.setAnchorPercent(0.5f, 0.5f);
}

void SceneLabLogo::start() {
    alpha.setCurve(EASE_OUT);
    alpha.setDuration(4);
    alpha.reset(0);
    alpha.animateToAfterDelay(255, 4);
}

void SceneLabLogo::update() {
    alpha.update(ofGetLastFrameTime());
}

void SceneLabLogo::draw() {
    ofPushStyle();
    ofEnableAlphaBlending();
    if (alpha.isOrWillBeAnimating()) {
        ofSetColor(255, alpha.getCurrentValue());
    }
    tex.draw(ofGetWidth()/2, ofGetHeight()/2);
    ofPopStyle();
}