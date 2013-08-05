//
//  BaseScene.h
//  joe
//
//  Created by 加藤 哲朗 on 2013/08/01.
//
//

#ifndef joe_BaseScene_h
#define joe_BaseScene_h

class BaseScene {
    
public:
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif
