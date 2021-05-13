#include "particle.h"
#include <cmath>

Particle::Particle() {
    pos = Vec2d(0.0f,0.0f);
    vel = Vec2d(0.0f,0.0f);
    acc = Vec2d(0.0f,0.0f);
    mass = 1.0f;
}

void Particle::updateVelPos(double dt) {
    vel += acc * dt;
    pos += vel * dt;
}

void Particle::resetAccel() {
    acc = {0,0};
}




// update accel of this according to other
// prevent nan from divide by zero
void Particle::updateAccel(const Particle& other) {


    //     //std::vector from i to j
    // float vectorx = bj->posX - bi->posX;
    // float vectory = bj->posY - bi->posY;

    // //c^2 = a^2 + b^2 + softener^2
    // float distSqr = vectorx * vectorx + vectory * vectory + pSoftener * pSoftener;

    // // ivnDistCube = 1/distSqr^(3/2)
    // float distSixth = distSqr * distSqr * distSqr;
    // double invDistCube = 1.0f / (sqrt(distSixth));

    float dx = other.pos.x - pos.x;
    float dy = other.pos.y - pos.y;
    float distsqr = dx*dx + dy*dy + softener2;
    double invDistCube = 1.0f / sqrt(distsqr*distsqr*distsqr);
    acc.x += G * other.mass * invDistCube * dx;
    acc.y += G * other.mass * invDistCube * dy;
}

void Particle::wrapPos(float x, float y) {
    pos.x = fmod(pos.x, x);
    pos.y = fmod(pos.y, y);
}

Particle::Particle(Vec2d pos, Vec2d vel, Vec2d acc, float mass)
    :pos(pos),vel(vel),acc(acc),mass(mass)
{}

