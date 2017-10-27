//
//  PolylineToMesh.hpp
//
//  Created by shohei fujimoto
//
//

#ifndef PolylineToMesh_hpp
#define PolylineToMesh_hpp

#include "ofMain.h"

class PolylineToMesh {
   public:
    PolylineToMesh(){};
    ~PolylineToMesh(){};

    //--------------------------------------------------------------
    inline ofMesh getMesh(ofPolyline poly, ofPrimitiveMode mode = OF_PRIMITIVE_TRIANGLE_STRIP) {
        // 1. Create path.
        ofPath path = getPathFromPolyline(poly);

        // 2. Create mesh.
        ofMesh mesh = path.getTessellation();
        mesh.setMode(mode);

        return mesh;
    };

   private:
    //--------------------------------------------------------------
    inline ofPath getPathFromPolyline(ofPolyline poly) {
        ofPath path;

        int size = poly.getVertices().size();

        for (int i = 0; i < size; i++) {
            ofPoint pos = poly.getVertices()[i];

            if (i == 0) {
                // begin
                path.moveTo(pos.x, pos.y);
            } else {
                // add vertex
                path.lineTo(pos.x, pos.y);
            }
        }

        // close
        path.close();

        return path;
    };
};

#endif /* PolylineToMesh_hpp */
