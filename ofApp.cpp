#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundAuto(false);
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	RUI_SETUP();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofBackground(154, 215, 221);
	ofBackground(0, 0, 221);
	//ofBackground(0,0,0);
	for(int i = 0; i < ofGetHeight(); i+=5){
		for(int z = 0; z < ofGetWidth(); z+=4){
			ofSetRectMode(OF_RECTMODE_CORNER);
			ofSetColor(160, 72, 0);
			ofDrawRectangle(z, i + ofRandom(-3 , 3), 5, 5);
		}
	}
	ofSetRectMode(OF_RECTMODE_CENTER);

	if(nubes.size() > 1){
		ofDrawBitmapString( ofToString( nubes[0].tracker.getCentroid2D() ), 450, 20 );

	}
	if(nubes.size() <= cantidadSemillas){
		for(int i = 0; i < nubes.size(); i++){
			ofFill();
			nubes[i].draw();
		}
	}

	for(int i = 0; i < geneNubes.size(); i++){
		ofFill();
		if(geneNubes[i].der == true && geneNubes[i].x < -150){
			geneNubes.erase(geneNubes.begin() + i);
			geneNube nuevaNube;
			geneNubes.push_back(nuevaNube);
			int randomSema = int(ofRandom(nubes.size()-1));
			int comienzo[2];
			comienzo[0] = -150;
			comienzo[1] = ofGetWidth() + 150;
			geneNubes[geneNubes.size() - 1].setup(comienzo[int(ofRandom(2))], ofRandom(ofGetHeight()), ofRandom(5,12), nubes[randomSema].pts, nubes[randomSema].centroid);
			geneNubes[geneNubes.size() - 1].animar();
		}
		if(geneNubes[i].der == false && geneNubes[i].x > ofGetWidth() + 150){
			geneNubes.erase(geneNubes.begin() + i);
			geneNube nuevaNube;
			geneNubes.push_back(nuevaNube);
			int randomSema = int(ofRandom(nubes.size()-1));
			int comienzo[2];
			comienzo[0] = -150;
			comienzo[1] = ofGetWidth() + 150;
			geneNubes[geneNubes.size() - 1].setup(comienzo[int(ofRandom(2))], ofRandom(ofGetHeight()), ofRandom(5,12), nubes[randomSema].pts, nubes[randomSema].centroid);
			geneNubes[geneNubes.size() - 1].animar();
		}
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
			for(int i = 0; i < 12; i++){
				geneNube nuevaNube;
				geneNubes.push_back(nuevaNube);
				int randomSema = int(ofRandom(nubes.size()-1));
				int comienzo[2];
				comienzo[0] = -150;
				comienzo[1] = ofGetWidth() + 150;
				geneNubes[geneNubes.size() - 1].setup(comienzo[int(ofRandom(2))], ofRandom(ofGetHeight()), ofRandom(5,12), nubes[randomSema].pts, nubes[randomSema].centroid);
				geneNubes[geneNubes.size() - 1].animar();
			}
		
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
