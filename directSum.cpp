#ifndef DSUM_H_
#define DSUM_H_

#include <iostream>
#include <vector>
#include "particle.h"
#include "vec2d.h"
#include "sim.h"
#include "SFML/Graphics.hpp"



class DirectSum : public Sim {
    public:

        DirectSum(std::vector<Particle*> particles, float width, float height) {
            this->particles = particles;
            this->width = width;
            this->height = height;
        }

        void next(int iterations) {
            for (int i = 0; i < iterations; i++) {
                for (Particle* p : particles) {
                    p->resetAccel();
                    for (Particle* p2 : particles) {
                        if (p != p2) p->updateAccel(*p2);
                        //std::cout << p->acc.x << ',' << p->acc.y << std::endl;
                    }
                }
                for (Particle* p : particles) {
                    p->updateVelPos(1e3);
                    //p->wrapPos(width, height);
                    //std::cout << p->pos.x << ',' << p->pos.y << std::endl;
                    
                }

            }
        }

    private:
};

#endif