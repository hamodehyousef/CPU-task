#include "ofApp.h"
#include "windows.h"
#include "TCHAR.h"
#include "pdh.h"
#include <iostream>


//--------------------------------------------------------------
void ofApp::setup(){	 

	// Set up the program 
	counter = 0;
	vagRounded.load("vag.ttf", 32);
	ofBackground(50,50,50);	



	

}


double Cpu()

{
	// To get handle to the processor idle time performance counter
	PDH_HQUERY idleQuery;
	PDH_HCOUNTER idleCounter;
	PdhOpenQuery(NULL, NULL, &idleQuery);
	PdhAddCounter(idleQuery, L"\\Processor(_Total)\\% Idle Time", NULL, &idleCounter);
	PdhCollectQueryData(idleQuery);

	// To sleep for Half a  second to get a different value
	Sleep(500);

	// To get new value and calculate CPU usage
	PDH_FMT_COUNTERVALUE counterVal;
	PdhCollectQueryData(idleQuery);
	PdhGetFormattedCounterValue(idleCounter, PDH_FMT_DOUBLE, NULL, &counterVal);
	double cpuUsage = 100.0 - counterVal.doubleValue;

	// Print CPU usage to console
	cout << "CPU Usage: " << cpuUsage << "%" << endl;

	return cpuUsage;
}



//--------------------------------------------------------------
void ofApp::update(){
	

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	

	

	//To draw the Cpu usage on the screen 
	
	string x = "CPU Usage: " + to_string(Cpu()) + "%";
	
	vagRounded.drawString(x, 210, 200);

	//To draw the graph of the CPU Usage in the current moment
	ofSetColor(ofColor::seaGreen);
	ofDrawRectangle(215, 210, Cpu() + 100 , 120);
	
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
   
	
}
