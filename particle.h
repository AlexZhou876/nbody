
#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <vector>
#include "vec2d.h"

// #include qtree.h would have caused a circular include

// class QTree {
//     public:
//     class Node;
// };
// can't do that, can't do class QTree::Node; or just class QTree; either.
// must either have both Particle and Node as inner classes or un-nest both.

class QTree;
//class Node;

class Particle {
    public:
        const double G = 6.673e-11;
        const float softener2 = 100;
        //const double dt = 1.0/100.0
        Vec2d pos;
        Vec2d vel;
        Vec2d acc;
        float mass;

        Particle();

        Particle(Vec2d pos, Vec2d vel, Vec2d acc, float mass);

        //void updatePos();
        void wrapPos(float x, float y);

        void updateVelPos(double dt);
        //void updateVel();
        // this pulled by other
        void updateAccel(const Particle& other);
        void resetAccel();
        //void updateAccel(const Node& other);


    
    private:



};



#endif
