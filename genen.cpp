//
//  genen.cpp
//  nubespix
//
//  Created by Lautaro on 24/2/18.
//
//

#include "genen.hpp"

void geneNube::setup(float _x, float _y, float _sumador, vector<ofPoint> _pts, ofVec3f _centroid){
	x = _x;
	y = _y;
	sumador = _sumador;
	pts = _pts;
	centroid = _centroid;
	if(x > ofGetWidth()){
		sumador = -sumador;
		der = true;
	}
}
void geneNube::draw(){
	if (cerro == true) {
		nube.setFillColor(colorNube);
		nube.draw(x+=sumador, y);
		for(int i = 0; i < pts.size(); i++){
			ofPushMatrix();
			ofTranslate(x,y);
			ofSetColor(colorNube);
			ofDrawRectangle(distCuadra[i].x, distCuadra[i].y, 6, 6);
			ofPopMatrix();
		}
	}
}
void geneNube::animar(){
	for(int i = 0; i < pts.size(); i++){
		float xran = pts[i].x + ofRandom(-3,3);
		float yran = pts[i].y + ofRandom(-3,3);
		nube.lineTo (xran, yran);
		distCuadra.push_back(ofPoint(xran - centroid.x, yran - centroid.y ));
	}
	nube.close();
	tracker.close();
	tracker.clear();
	nube.translate(ofPoint(-(centroid.x),-(centroid.y)));
	cerro = true;
}
void geneNube::colisiona(){
	if( (der == true && x < -150)  || (der == false && x > ofGetWidth() + 150)){
		muerte = true;
	}
	
}
