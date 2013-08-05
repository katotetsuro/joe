//
//  SceneOpening.h
//  joe
//
//  Created by 加藤 哲朗 on 2013/08/01.
//
//

#ifndef __joe__SceneOpening__
#define __joe__SceneOpening__

#include "BaseScene.h"
#include "ofMain.h"
#include "ofxAnimatableFloat.h"

class SceneOpening : public BaseScene {
    bool started;
    int startTime;
    ofTexture tex;
    static const int duration; // ミリ秒
    ofxAnimatableFloat alpha;
    void keyPressed(ofKeyEventArgs &e);
    
public:
    SceneOpening();
    void start();
    void update();
    void draw();
};

#endif /* defined(__joe__SceneOpening__) */
