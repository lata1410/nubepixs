//
//  nube.hpp
//  nubespix
//
//  Created by Lautaro on 21/2/18.
//
//

#ifndef nube_hpp
#define nube_hpp

#include <stdio.h>
#include "ofMain.h"

class Nube{
public:
	void setup();
	void draw();
	void trazar();
	void cerrarTrazo();
	
	ofPath nube;
	ofPolyline tracker;
	vector<ofPoint> pts;
	vector<ofPoint> ptsQueda;
	float x = 0, y = 0;
	float rectX, rectY;
	float disX, disY;
	float xQueda, yQueda;
	float sumador = 0.5;
	bool cerro = false;
	ofVec3f centroid;

};

#endif /* nube_hpp */
