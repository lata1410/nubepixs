#pragma once

#include "ofMain.h"
#include "nube.hpp"
#include "genen.hpp"
#include "star.hpp"
#include "ofxRemoteUIServer.h"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	vector<ofPoint> pts;
	vector<Nube> nubes;
	vector<geneNube> geneNubes;
	vector<Star> estrellas;


	bool sumarNube = true;
	int cantidadSemillas = 10;
	int cantidadNubesAgregar = 10;
	ofColor background, _colorNubes, _colorEstrellas;
	float starwid, primerVelocidad = 5, segundaVelocidad = 16;
};
