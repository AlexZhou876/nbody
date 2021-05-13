#ifndef QTREE_H_
#define QTREE_H_
#include <vector>
#include "particle.h"
#include "vec2d.h"
#include "sim.h"
#include "SFML/Graphics.hpp"

class Node;

class QTree : public Sim {
public:


    QTree();
    QTree(std::vector<Particle*> particles, float width);
    // nested tree traversal to compute next position for all particles
    void next(int iterations);

    // and rebuild tree based on new positions
    void rebuild();

    // return number of nodes in tree
    int size();

    // render the tree's node boundaries onto window
    void renderTree(sf::RenderWindow& window);

    // render the particles onto window
    void renderParticles(sf::RenderWindow& window);

    void render(sf::RenderWindow& w);

    /*
    * @param rhs The right hand side of the assignment statement.
    */
    QTree & operator=(const QTree& rhs);

    /*
    * copy constructor
    * @param other The QTree instance being copied into this
    */
    QTree(const QTree& other);

    /*
    * destructor
    */
    ~QTree();

    

    

    // class Leaf : Node {
    //     Particle* particle;
    // };



    // class Particle {
    //     public:
    //         Vec2d pos;
    //         Vec2d vel;
    //         Vec2d acc;
    //         float mass;

    //         Particle();

    //         Particle(Vec2d pos, Vec2d vel, Vec2d acc, float mass);

    //         void updateAccel(const Particle& other);
    //         void updateAccel(const QTree::Node& other);


        
    //     private:
    


    // };


private:

    Node* root;
    //std::vector<Particle*> particles;
    Node* build(Vec2d ul, std::vector<Particle*>& particles, float width);




};


class Node {
        public:
            Node(Vec2d ul, float width, Vec2d centerOfMass, float totalMass);
            Node(Vec2d ul, float width);
            //std::vector<Particle*> particles;
            Node* nw;
            Node* ne;
            Node* sw;
            Node* se;
            Vec2d ul;
            Vec2d centerOfMass;
            float width;
            float totalMass;
            //int numParticles;
            bool empty;

            void update();       
            void insert(const Particle& p); 
        private:
            float incrementalCtrMass(float newTotalMass, float nthMass, float nthPos, float prevCtrMass);
    };

#endif