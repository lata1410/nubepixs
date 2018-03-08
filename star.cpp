//
//  star.cpp
//  nubespix
//
//  Created by Lautaro on 1/3/18.
//
//

#include "star.hpp"

void Star::setup(float _x, float _y, float _wid, float _hei){
	x = _x;
	y = _y;
	wid = _wid;
	hei = _hei;
}

void Star::draw(){
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofSetColor(colorEstrellas);
	ofDrawRectangle(x, y + ofRandom(-3 , 3), wid, hei);
}
