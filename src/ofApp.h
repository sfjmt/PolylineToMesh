#pragma once

#include "ofMain.h"
#include "PolylineToMesh.hpp"

class ofApp : public ofBaseApp {
   public:
    void draw();

   private:
    PolylineToMesh meshManagement;
    string caption();
};
