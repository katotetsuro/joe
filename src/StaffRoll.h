//
//  StaffRoll.h
//  joe
//
//  Created by 加藤 哲朗 on 2013/07/30.
//
//

#ifndef __joe__StaffRoll__
#define __joe__StaffRoll__

#include "ofxTrueTypeFontUC.h"

namespace nistetsurooy {
    
    class Name {
    private:
        static ofxTrueTypeFontUC font;
        string name;
        bool isActive;
        float y;
        
    public:
        explicit Name(string name);
        void start();
        void update(float dy);
        void draw();
    };
    
    class StaffRoll {
        
    public:
        void setup(string file);
        void start();
        void update();
        void draw();
        void setTotalTime(float t);
        
    private:
        float startTime;
        int numEmitted;
        vector<Name> names;
        float velocity;
        float interval;
        float offset; // 最初に待つ時間
    };
}


#endif /* defined(__joe__StaffRoll__) */
