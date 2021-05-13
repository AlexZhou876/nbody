#ifndef SIM_H_
#define SIM_H_

#include "SFML/Graphics.hpp"
//#include "SFML/Window.hpp"
//#include "vec2d.h"
//#include "qtree.h"
#include "particle.h"

class Sim {
public:
    
    virtual void next(int iterations) = 0;

    // std::vector<Particle*> getParticles() {
    //     return particles;
    // }

    void render(sf::RenderWindow& w) {
        for (Particle* p : particles) {
            sf::CircleShape circle(5, 30);
            circle.setPosition(sf::Vector2f(p->pos.x, p->pos.y));
            if (p->mass >= 10000) circle.setFillColor(sf::Color::Red);
            w.draw(circle);
        }

    }

protected:
    


    std::vector<Particle*> particles;
    float width;
    float height;



};


#endif


