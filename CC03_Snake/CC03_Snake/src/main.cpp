#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // DISABLE THE WINDOWS CONSOLE

#include "ofMain.h"
#include "ofApp.h"

//// Global variables
int scl = 20;			// Scale of the grid 

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
	settings.resizable = false;
	ofCreateWindow(settings);
	ofSetWindowShape(600, 600);
	ofRunApp(new ofApp());
}
