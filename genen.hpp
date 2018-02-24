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
	
		void setup(float _x, float _y, float _sumador, vector<ofPoint> _pts);
		void draw();
		void trazar();
		void cerrarTrazo();
		void animar();
		
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


};

#endif /* genen_hpp */
