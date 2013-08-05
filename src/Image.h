//
//  Image.h
//  joe
//
//  Created by 加藤 哲朗 on 2013/07/29.
//
//

#ifndef __joe__Image__
#define __joe__Image__

#include "ofMain.h"
#include "ofxAnimatableOfPoint.h"
#include "ofxAnimatableFloat.h"

namespace nistetsurooy {
    class Image : public ofImage {
    public:
        Image();
        void setDuration(float t) {
            position.setDuration(t);
        }
        void draw();
        void startAnimation();
        void updateAnimation(float dt);
        bool shouldStartNext();
        bool getAnimating();
        
    private:
        ofxAnimatableOfPoint position;
        ofxAnimatableFloat alpha;
        void init(); // 動いていく方向を初期化する
    };
}

#endif /* defined(__joe__Image__) */
