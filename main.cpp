#include "stdio.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "vec2d.h"
#include "qtree.h"
#include "particle.h"
#include "sim.h"
#include "directSum.cpp"


int main() {

    // Particle* s = new Particle({300.0f,300.0f},{0.0f,0.0f},{0.0f,0.0f}, 10000.0f);

    // Particle* e = new Particle({330.0f,300.0f},{0.0f, sqrt(s->mass/30.0f)},{0.0f,0.0f}, 1000.0f);
    // Particle* m = new Particle({330.0, 310.0f},{sqrt(1000.0f/10.0f),sqrt(s->mass/30.0f)},{0.0f,0.0f}, 1.0f);

    Particle* p = new Particle({100,100},{0,0},{0,0},100);
    Particle* p2 = new Particle({500,500},{0,-7e-6},{0,0},100);
    Particle* p3 = new Particle({150,100},{0,0},{0,0},100);
    Particle* p4 = new Particle({550,500},{0,-7e-6},{0,0},100);
    Particle* p5 = new Particle({100,200},{0,0},{0,0},100);
    Particle* p6 = new Particle({500,600},{0,-1e-5},{0,0},100);
    Particle* p7 = new Particle({400,100},{0,1e-3},{0,0},10000);
    Particle* p8 = new Particle({100,500},{0,-7e-6},{0,0},100);





// constexpr float dt=1.0/100.0f;
// 	constexpr float r=5.5f,R=30.0f;
// 	Body Sun(10000.0f,7.0f);
// 	Body Earth(1000.0f,2.0f);
// 	Body Moon(1.0f,1.2f);
	
// 	Sun.pos={0.0f,0.0f};
// 	Sun.vel={0.0f,0.0f};
	
// 	Earth.pos={R,0.0f};
// 	Earth.vel={0.0f,sqrt(Sun.m/R)};
	
// 	Moon.pos={R,r};
// 	Moon.vel={sqrt(Earth.m/r),Earth.vel.y};

    std::vector<Particle*> vec = {p,p2,p3,p4,p5,p6,p7,p8};
    Sim* sim = new DirectSum(vec, 1500, 1500);

    //sf::Window window(sf::VideoMode(800, 600), "My window");
    sf::RenderWindow w(sf::VideoMode(800, 600), "My window");
    while (w.isOpen())
    {

 

        // for (int i = 0; i < 100; i++) {
        //     sim->next(1);
        //     std::cout << p->pos << p1->pos << std::endl;


        //     // s.setFillColor(sf::Color(Red * 255, Green * 255, Blue * 255, 128));
        //     // s.setPosition(pBodies.at(i)->posX, pBodies.at(i)->posY);
        //     // pTarget->draw(Temp);
        // }
        sim->next(1);

        


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (w.pollEvent(event))
        {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            w.close();
        }

         // clear the window with black color
        w.clear(sf::Color::Black);

        // draw everything here...

        for (Particle* p : sim->getParticles()) {
            sf::CircleShape circle(5, 30);
            circle.setPosition(sf::Vector2f(p->pos.x, p->pos.y));
            w.draw(circle);
        }
        // sf::Vertex point(sf::Vector2f(100, 100), sf::Color::White);

        
        // w.draw(&point, 1, sf::Points);

        // end the current frame
        w.display();
    }
return 0;

    // create particles in a uniform disk

    // build the quadtree using the collection of particles

    // run the simulation

    // while (1) {

    // }

}