//
//  star.hpp
//  nubespix
//
//  Created by Lautaro on 1/3/18.
//
//

#ifndef star_hpp
#define star_hpp

#include <stdio.h>
#include "ofMain.h"
class Star {
public:
	void setup(float _x, float _y, float _wid, float _hei);
	void draw();
	float x,y, wid, hei;
	ofColor colorEstrellas;
};

#endif /* star_hpp */
