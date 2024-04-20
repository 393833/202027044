#include "Star.hpp"
#include <GLFW/glfw3.h>
#include <random>

float randomColor();

Star::Star(float x, float y)
    : mX(x), mY(y), mR(randomColor()), mG(randomColor()), mB(randomColor()) {}

Star::Star(float x, float y, float r, float g, float b)
    : mX(x), mY(y), mR(r), mG(g), mB(b) {}

float randomColor() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dis(0.0f, 1.0f);
    return dis(gen);
}

void Star::render() {
    float size = 0.1f;

    glBegin(GL_TRIANGLES);
    glColor3f(mR, mG, mB);
    glVertex2f(mX, mY + size);
    glVertex2f(mX - size * 0.2f, mY - size * 0.3f);
    glVertex2f(mX + size * 0.2f, mY - size * 0.3f);

    glVertex2f(mX - size * 0.4f, mY + size * 0.1f);
    glVertex2f(mX + size * 0.3f, mY - size * 0.7f);
    glVertex2f(mX + size * 0.1f, mY + size * 0.1f);

    glVertex2f(mX + size * 0.4f, mY + size * 0.1f);
    glVertex2f(mX - size * 0.1f, mY + size * 0.1f);
    glVertex2f(mX - size * 0.3f, mY - size * 0.7f);
    glEnd();
}
