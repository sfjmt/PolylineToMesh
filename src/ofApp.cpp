#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::draw() {
    // create : base polyline
    ofPolyline polyBase;
    polyBase.arc(ofPoint(ofGetWidth() * 0.5, ofGetHeight() * 0.5), 300, 100, 0, 360, true);
    polyBase = polyBase.getResampledByCount(100);

    int totalResample = polyBase.getVertices().size();

    // create : fix polyline
    ofPolyline polyFix;
    float d;
    ofPoint posBase;
    ofPoint pos;
    float x;
    float y;
    float timef = ofGetElapsedTimef();
    float elementInterval;
    float speed = 1.0;
    float amount = 10.0;

    for (int i = 0; i < totalResample; i++) {
        posBase = polyBase.getVertices()[i];

        d = abs((float)totalResample * 0.5 - i);
        elementInterval = ofMap(d, 0.0, totalResample * 0.5, 0.0, 10.0);

        x = cos((timef + elementInterval) * speed) * amount;
        y = sin((timef + elementInterval) * speed) * amount;

        pos = ofVec2f(posBase.x + x, posBase.y + y);
        polyFix.addVertex(pos);
    }

    // create : mesh
    ofMesh mesh = meshManagement.getMesh(polyFix);

    // draw : mesh
    ofSetColor(0, 0, 255);
    mesh.drawFaces();

    // draw : fixed polyline
    ofSetColor(255, 0, 0);
    ofSetLineWidth(3);
    polyFix.draw();
    ofSetLineWidth(1);

    // draw : caption
    ofDrawBitmapStringHighlight(caption(), ofPoint(10, 20));
}

//--------------------------------------------------------------
string ofApp::caption() {
    stringstream ss;
    ss << ofGetFrameRate() << endl;
    return ss.str();
}