#ifndef STAR_H
#define STAR_H

#include "MObject.h"

class Star : public MObject {
private:
    float mX;
    float mY;
    float mR; 
    float mG; 
    float mB; 

public:
    Star(float x = 0.0f, float y = 0.0f);
    Star(float x, float y, float r, float g, float b);
    void render() override;
};

#endif 