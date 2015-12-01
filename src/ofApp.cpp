#include "ofApp.h"

ofSoundPlayer sound;

//--------------------------------------------------------------
void ofApp::setup(){
    
    vidGrabber.initGrabber(320,240);
    finder.setup("haarcascade_frontalface_default.xml");
    
    x = ofRandomWidth();
    y = ofRandomHeight();
    
    xVel = ofRandom(-10,10);
    yVel = ofRandom(-10,10);
    
    sound.loadSound("sounds/Mario.mp3");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew()){
        finder.findHaarObjects(vidGrabber.getPixelsRef());
    }
    
    x+= xVel;
    y+= yVel;
    
    if(x >= ofGetWidth()) {
        x = ofGetWidth();
        xVel *= -1;
        sound.play();
    }
    
    if (x <= 0) {
        x = 0;
        xVel *= -1;
        sound.play();
    }
    
    if(y >= ofGetHeight()) {
        y = ofGetHeight();
        yVel *= -1;
        sound.play();
    }
    
    if (y<= 0) {
        y = 0;
        yVel *= -1;
        sound.play();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw the image you got from the camera scaled up a bit
    vidGrabber.draw(0, 0, 640, 480);
    
    
    //for every face you find, draw a white rectangle around it.
    ofNoFill();
    for(unsigned int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle face = finder.blobs[i].boundingRect;
        ofRect(face.x*2, face.y*2, face.width*2, face.height*2);
        
        if (x < face.x*2 || x>face.x*2 || y < face.y*2  || y > face.y*2 ){
            
            cout << "Please Work" <<endl;
            xVel = -xVel;
            yVel = -yVel;
            
            
        }
    }
    

    ofSetColor(255, 255, 255);
    ofFill();
    ofCircle(x, y, 20);

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
