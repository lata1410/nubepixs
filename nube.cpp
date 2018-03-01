//
//  nube.cpp
//  nubespix
//
//  Created by Lautaro on 21/2/18.
//
//

#include "nube.hpp"




void Nube::draw(){
	if (cerro == true) {
		nube.draw(x, y);
	}
	tracker.draw();
	if(cerro == false){
		for(int i = 0; i < pts.size(); i++){
			ofSetColor(255);
			ofDrawRectangle(pts[i].x, pts[i].y + ofRandom(-0.5,0.5), 4, 4);
			ofDrawRectangle(pts[i].x + 1, pts[i].y + ofRandom(-0.5,0.5), 4, 4);
			ofDrawRectangle(pts[i].x - 1, pts[i].y + ofRandom(-0.5,0.5), 4, 4);
		}
	} else if(cerro == true){
		for(int i = 0; i < pts.size(); i++){
			ofSetColor(255);
			ofDrawRectangle(pts[i].x, pts[i].y, 4, 4);
			ofDrawRectangle(pts[i].x + 1, pts[i].y, 4, 4);
			ofDrawRectangle(pts[i].x - 1, pts[i].y, 4, 4);
		}
	}
}


void Nube::trazar(){
	ofSetColor(255);
	pts.push_back( ofPoint(ofGetMouseX(), ofGetMouseY()));
	tracker.addVertex(pts.back());
	tracker.draw();
}


void Nube::cerrarTrazo(){
	for(int i = 0; i < pts.size(); i++){
		nube.lineTo(pts[i]);
	}
	nube.close();
	tracker.close();
	centroid = tracker.getCentroid2D();
	cout << centroid << endl;
	tracker.clear();
	cerro = true;
}


