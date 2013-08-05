//
//  StaffRoll.cpp
//  joe
//
//  Created by 加藤 哲朗 on 2013/07/30.
//
//

#include "StaffRoll.h"
#include "ofMain.h"

using namespace nistetsurooy;

ofxTrueTypeFontUC Name::font;

int initialY = 1280;

Name::Name(string name) : isActive(false) {
    this->name = name;
    if (!font.isLoaded()) {
        font.loadFont("fonts/ヒラギノ丸ゴ Pro W4.otf", 40);
    }
    
    y = initialY;
}

void Name::start() {
    isActive = true;
}

void Name::update(float dy) {
    if (!isActive) return;
    y -= dy;
    isActive = y > -200;
}

void Name::draw() {
    if (!isActive) return;
    font.drawString(name, 200, y);
}

void StaffRoll::setup(string file) {
    ofFile nameFile("names/names.txt");
    ofBuffer b = nameFile.readToBuffer();
    while (!b.isLastLine()) {
        names.push_back(Name(b.getNextLine()));
    }
    
    offset = 5;
    velocity = 100.f;
}

void StaffRoll::start() {
    startTime = ofGetElapsedTimef();
    numEmitted = 0;
}

void StaffRoll::update() {
    float elapsed = ofGetElapsedTimef() - startTime;
    
    if (elapsed > offset + numEmitted*interval) {
        names[numEmitted].start();
        ++numEmitted;
    }
    
    if (ofGetFrameNum() == 0) return;
    
    float dy = ofGetLastFrameTime()*velocity;
    for (auto &n : names) {
        n.update(dy);
    }
}

void StaffRoll::draw() {
    ofPushStyle();
    ofSetColor(255);
    for (auto &n : names) {
        n.draw();
    }
    ofPopStyle();
}

void StaffRoll::setTotalTime(float t) {
    interval = (t - (offset+initialY/velocity))/(names.size()-1);
}