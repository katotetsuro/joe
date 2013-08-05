//
//  SceneLabLogo.h
//  joe
//
//  Created by 加藤 哲朗 on 2013/08/01.
//
//

#ifndef __joe__SceneLabLogo__
#define __joe__SceneLabLogo__

#include "BaseScene.h"
#include "ofMain.h"
#include "ofxAnimatableFloat.h"

class SceneLabLogo : public BaseScene {
    ofTexture tex;
    ofxAnimatableFloat alpha;
    
public:
    SceneLabLogo();
    void start();
    void update();
    void draw();
};

#endif /* defined(__joe__SceneLabLogo__) */
