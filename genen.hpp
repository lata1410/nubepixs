//
//  genen.hpp
//  nubespix
//
//  Created by Lautaro on 24/2/18.
//
//

#ifndef genen_hpp
#define genen_hpp

#include <stdio.h>
#include "ofMain.h"

class geneNube {
public:
	
		void setup(float _x, float _y, float _sumador, vector<ofPoint> _pts, ofVec3f _centroid);
		void draw();
		void animar();
		void colisiona();
		
		ofPath nube;
		ofPolyline tracker;
		vector<ofPoint> pts;
		vector<ofPoint> distCuadra;
		float x = 0, y = 0;
		bool der = false;
		float rectX, rectY;
		float disX, disY;
		float xQueda, yQueda;
		float sumador;
		bool cerro = false;
		ofVec3f centroid;
		ofColor colorNube;
};

#endif /* genen_hpp */
