#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundAuto(false);
	ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(154, 215, 221);
	ofDrawBitmapString( ofToString( ofGetFrameRate() ), 250, 20 );
	if(nubes.size() > 1){
		ofDrawBitmapString( ofToString( geneNubes.size() ), 450, 20 );

	}

	for(int i = 0; i < nubes.size(); i++){
		ofFill();
		nubes[i].draw();
	}
	for(int i = 0; i < geneNubes.size(); i++){
		ofFill();
		geneNubes[i].draw();
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(nubes.size() <= cantidadSemillas){
		if(key == 'g'){
			if(sumarNube == true){
				Nube newNube;
				nubes.push_back(newNube);
				sumarNube = false;
			}else{
				nubes[nubes.size() - 1].trazar();
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(nubes.size() <= cantidadSemillas){
		if(key == 'g'){
			sumarNube = true;
			nubes[nubes.size() - 1].cerrarTrazo();
		}
	} else if (nubes.size() >= cantidadSemillas){
		if (key == 's'){
			geneNube nuevaNube;
			geneNubes.push_back(nuevaNube);
			int randomSema = int(ofRandom(nubes.size()-1));
			geneNubes[geneNubes.size() - 1].setup(-100, ofRandom(ofGetHeight()), ofRandom(1, 2), nubes[randomSema].ptsQueda);
			geneNubes[geneNubes.size() - 1].animar();
		}
	}
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
