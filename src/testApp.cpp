#include "testApp.h"
#include "SceneOpening.h"
#include "SceneStaffRoll.h"
#include "SceneLabLogo.h"

int width = 1920;
int height = 1080;

//--------------------------------------------------------------
void testApp::setup(){
    // oF全体の設定
    ofSetLogLevel(OF_LOG_NOTICE);
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetWindowShape(width, height);
    ofSetFullscreen(true);
    
    scenes.resize(3);
    scenes[0] = ofPtr<BaseScene>(new SceneOpening());
    scenes[1] = ofPtr<BaseScene>(new SceneStaffRoll());
    scenes[2] = ofPtr<BaseScene>(new SceneLabLogo());
    
    currentScene = scenes.begin();
    pause = false;
    
    ofHideCursor();
//    CGDisplayHideCursor(kCGDirectMainDisplay);
}

//--------------------------------------------------------------
void testApp::update(){
    if (pause) return;
    (*currentScene)->update();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate(),2));
}

//--------------------------------------------------------------
void testApp::draw(){
    (*currentScene)->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
        case 'p':
            pause = !pause;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    string message = msg.message;
    ofLogNotice() << message;
    ++currentScene;
    (*currentScene)->start();
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
