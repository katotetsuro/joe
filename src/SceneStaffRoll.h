//
//  SceneStaffRoll.h
//  joe
//
//  Created by 加藤 哲朗 on 2013/08/01.
//
//

#ifndef __joe__SceneStaffRoll__
#define __joe__SceneStaffRoll__

#include "BaseScene.h"
#include "ofMain.h"
#include "StaffRoll.h"
#include "Image.h"

class SceneStaffRoll : public BaseScene {
    
public:
    
    typedef vector<nistetsurooy::Image> ImageArray;
    SceneStaffRoll();
    void start();
    void update();
    void draw();
    
private:
    bool isLastImage;
    bool useNameList;
    ImageArray images;
    ImageArray::iterator current, next;
    nistetsurooy::StaffRoll staffRoll;
};

#endif /* defined(__joe__SceneStaffRoll__) */
