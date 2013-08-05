//
//  Config.h
//  joe
//
//  Created by 加藤 哲朗 on 2013/07/30.
//
//

#ifndef __joe__Config__
#define __joe__Config__

#include "ofxXmlSettings.h"

class Config {
    
public:
    explicit Config(string file="config.xml");
    float getDuration();
    bool useNameList();
    
private:
    ofxXmlSettings xml;
};

#endif /* defined(__joe__Config__) */
