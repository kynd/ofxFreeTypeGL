//
//  ofxGLSLSandbox.h
//  myGLSLSandbox
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
    void draw();

    //ofFbo fbo;
    //ofShader shader;
    ofTexture texture;
};