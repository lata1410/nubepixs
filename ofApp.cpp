#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(120);
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	for(int i = 0; i < ofGetHeight(); i+=5){
		for(int z = 0; z < ofGetWidth(); z+=4){
			Star nuevaEstrella;
			nuevaEstrella.setup(z, i, 1, 1);
			estrellas.push_back(nuevaEstrella);
		}
	}
	
	RUI_SETUP();
	//Expose x and y vars to the server, providing a valid slider range
	
	//share the color param
	RUI_SHARE_COLOR_PARAM(background);
	RUI_SHARE_COLOR_PARAM(_colorNubes);
	RUI_SHARE_COLOR_PARAM(_colorEstrellas);
	RUI_SHARE_PARAM(starwid, 0.1, 30);
	RUI_SHARE_PARAM(primerVelocidad, 0, 15);
	RUI_SHARE_PARAM(segundaVelocidad, 16, 30);




	RUI_SHARE_PARAM(cantidadNubesAgregar, 0, 100);
	
	//load values from XML, as they were last saved (if they were)
	RUI_LOAD_FROM_XML();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(background);
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
	
	
	if(nubes.size()  <= cantidadSemillas){
		for(int i = 0; i < nubes.size(); i++){
			ofFill();
			nubes[i].draw();
		}
	}
	for (int i = 0; i<estrellas.size(); i++) {
		estrellas[i].colorEstrellas = _colorEstrellas;
		estrellas[i].wid = starwid;
		estrellas[i].hei = starwid;
		estrellas[i].draw();
	}
	ofSetRectMode(OF_RECTMODE_CENTER);

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
		geneNubes[i].colorNube = _colorNubes;
		geneNubes[i].draw();
		geneNubes[i].colisiona();
	
		
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
			for(int i = 0; i < cantidadNubesAgregar; i++){
				geneNube nuevaNube;
				geneNubes.push_back(nuevaNube);
				int randomSema = int(ofRandom(nubes.size()-1));
				int comienzo[2];
				comienzo[0] = -150;
				comienzo[1] = ofGetWidth() + 150;
				geneNubes[geneNubes.size() - 1].setup(comienzo[int(ofRandom(2))], ofRandom(ofGetHeight()), ofRandom(primerVelocidad,segundaVelocidad), nubes[randomSema].pts, nubes[randomSema].centroid);
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
