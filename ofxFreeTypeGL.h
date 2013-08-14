
//
//  Created by Tadokoro Atsushi on 2013/02/20.
//
//

#pragma once
#include "ofMain.h"
#include "freetype-gl.h"
#include "vertex-buffer.h"
#include "shader.h"
#include "mat4.h"


class ofxFreeTypeGL {
public:
    ofxFreeTypeGL();
    ~ofxFreeTypeGL();
    void setString(wstring wstr);
    void setBaseColor(ofColor color);
    void setBaseColor(int r, int g, int b, int a = 255);
    //void setStyle(ofxTextStyle style, int from = 0, int to = 0);
    //void setBoundary(ofPolyline);
    //void setBoundary(ofPath);
    //void setBoundary(ofRectangle);
    //...
    //void setBaseline(ofPolyline);
    //void setBaseline(ofPath);
    //...
    void update();
    void draw(int x, int y);

private:
    ofTexture texture;
    wstring internalString;
    ofColor baseColor;
};