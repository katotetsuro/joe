//
//  SceneStaffRoll.cpp
//  joe
//
//  Created by 加藤 哲朗 on 2013/08/01.
//
//

#include "SceneStaffRoll.h"
#include "Config.h"

SceneStaffRoll::SceneStaffRoll() : isLastImage(false) {
    float photoDuration = 3.f;
    // teamLabCamera画像の読み込み
    ofDirectory dir;
    int length = dir.listDir("images");
    ofLogNotice("画像の枚数") << length;
    images.resize(length);
    for (int i=0; i<length; ++i) {
        images[i].loadImage(dir.getFile(i));
        images[i].setAnchorPercent(0.5, 0.5);
        images[i].setDuration(photoDuration);
    }
    std::reverse(images.begin(), images.end());
    current = images.begin();
    next = current+1;
    
    Config config;
    useNameList = config.useNameList();
    if (useNameList) {
        ofLogNotice() << "名前一覧を表示します";
        staffRoll.setup("names/names.txt");
        staffRoll.setTotalTime(photoDuration*images.size()*0.8/*80%進行したら次の画像にいくから*/);
    } else {
        ofLogNotice() << "名前一覧は表示しません";
    }
}


void SceneStaffRoll::start() {
    current->startAnimation();
    
    if (useNameList) {
        staffRoll.start();
    }
}

void SceneStaffRoll::update() {
    if (ofGetFrameNum() == 0) {
        return;
    }
    float dt = ofGetLastFrameTime();
    current->updateAnimation(dt);
    if (!isLastImage) {
        next->updateAnimation(dt);
    }
    
    if (current->shouldStartNext()) {
        next->startAnimation();
    }
    
    if (!current->getAnimating()) {
        if (isLastImage) {
            ofSendMessage(ofMessage("StaffRollEnd"));
        }
        current = next;
        next++;
        if (next == images.end()) {
            isLastImage = true;
            next = images.begin();
//            ofSendMessage(ofMessage("StaffRollEnd"));
        }
    }
    
    if (useNameList) {
        staffRoll.update();
    }
}

void SceneStaffRoll::draw() {
    ofPushMatrix();
    ofTranslate(useNameList ? ofGetWidth()*3/5 : ofGetWidth()/2, ofGetHeight()/2);
    ofScale(1.2, 1.2);
    if (!isLastImage) {
        next->draw();
    }
    current->draw();
    ofPopMatrix();
    
    if (useNameList) {
        staffRoll.draw();
    }
}