//
//  genen.cpp
//  nubespix
//
//  Created by Lautaro on 24/2/18.
//
//

#include "genen.hpp"

void geneNube::setup(float _x, float _y, float _sumador, vector<ofPoint> _pts){
	x = _x;
	y = _y;
	//xQueda = _xQueda;
	//yQueda = _yQueda;
	sumador = _sumador;
	pts = _pts;
	//disX = ofDist(_xQueda, _yQueda, x, y);
}
void geneNube::draw(){
	if (cerro == true) {
		nube.draw(x, y);
	}
	tracker.draw();
	if(cerro == false){
		for(int i = 0; i < pts.size(); i++){
			ofDrawRectangle(pts[i].x, pts[i].y+ ofRandom(-0.5,0.5), 4, 4);
			ofDrawRectangle(pts[i].x + 1, pts[i].y + ofRandom(-0.5,0.5), 4, 4);
			ofDrawRectangle(pts[i].x - 1, pts[i].y + ofRandom(-0.5,0.5), 4, 4);
		}
	} else if(cerro == true){
		for(int i = 0; i < pts.size(); i++){
			ofDrawRectangle(pts[i].x, pts[i].y, 4, 4);
			ofDrawRectangle(pts[i].x + 1, pts[i].y, 4, 4);
			ofDrawRectangle(pts[i].x - 1, pts[i].y, 4, 4);
		}
	}
}

void geneNube::animar(){
	for(int i = 0; i < pts.size(); i++){
		nube.lineTo(pts[i].x, pts[i].y);
	}
	nube.close();
	tracker.close();
	tracker.clear();
	
	cerro = true;
}
