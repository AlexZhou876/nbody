#ifndef SIM_H_
#define SIM_H_

//#include "SFML/Graphics.hpp"
//#include "SFML/Window.hpp"
//#include "vec2d.h"
//#include "qtree.h"
#include "particle.h"

class Sim {
public:
    
    virtual void next(int iterations) = 0;

    std::vector<Particle*> getParticles() {
        return particles;
    }

protected:
    
    std::vector<Particle*> particles;
    float width;
    float height;



};


#endif


