//
//  Config.cpp
//  joe
//
//  Created by 加藤 哲朗 on 2013/07/30.
//
//

#include "Config.h"

Config::Config(string file) {
    xml.loadFile(file);
}

float Config::getDuration() {
    xml.getValue("duration", 3.0);
}

bool Config::useNameList() {
    return xml.getValue("use_namelist", false);
}