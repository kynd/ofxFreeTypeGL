//
//  ofxGLSLSandbox.cpp
//  myGLSLSandbox
//
//  Created by Tadokoro Atsushi on 2013/02/20.
//
//

#include "ofxFreeTypeGL.h"

ofxFreeTypeGL::ofxFreeTypeGL(){
    texture_atlas_t * atlas = texture_atlas_new( ofGetWidth(), ofGetHeight(), 1 );
    texture.allocate(1024, 1024, GL_LUMINANCE_ALPHA);

    const char *filename = "../../../data/fonts/hiraginoKakugoW6.otf";
    const wchar_t *cache = L"Wow,これは面白い!!夜露死苦〠";
    size_t minsize = 4, maxsize = 80;
    size_t count = maxsize - minsize;
    size_t i, missed = 0;
    
    for( i=minsize; i < maxsize; ++i ){
        texture_font_t * font = texture_font_new( atlas, filename, i );
        missed += texture_font_load_glyphs( font, cache );
        texture_font_delete( font );
    }
    
    printf( "Matched font               : %s\n", filename );
    printf( "Number of fonts            : %ld\n", count );
    printf( "Number of glyphs per font  : %ld\n", wcslen(cache) );
    printf( "Number of missed glyphs    : %ld\n", missed );
    printf( "Total number of glyphs     : %ld/%ld\n",
           wcslen(cache)*count - missed, wcslen(cache)*count );
    printf( "Texture size               : %ldx%ld\n", atlas->width, atlas->height );
    printf( "Texture occupancy          : %.2f%%\n",
           100.0*atlas->used/(float)(atlas->width*atlas->height) );
    
    const int SIZE = atlas->width * atlas->height;
    
    vector<unsigned char> temp;
    temp.resize(SIZE * 2);
    
    unsigned char *src = atlas->data;
    unsigned char *dst = temp.data();
    
    for (int i = 0; i < SIZE; i++){
        dst[0] = 255;
        dst[1] = *src;
        src++;
        dst += 2;
    }
    
    texture.loadData(temp.data(), 1024, 1024, GL_LUMINANCE_ALPHA);
}

void ofxFreeTypeGL::draw(){
    ofSetColor(255, 255, 0);
    texture.draw(0,0);
}
