#include "qtree.h"
#include "vec2d.h"
#include "particle.h"

Node::Node(Vec2d ul, float width, Vec2d centerOfMass, float totalMass) 
    :ul(ul),width(width),centerOfMass(centerOfMass),totalMass(totalMass),nw(NULL),ne(NULL),sw(NULL),se(NULL)
{}

Node::Node(Vec2d ul, float width) 
    :ul(ul),width(width),centerOfMass(),totalMass(),nw(NULL),ne(NULL),sw(NULL),se(NULL)
{}

// QTree::Particle::Particle() {
//     pos = Vec2d(0.0f,0.0f);
//     vel = Vec2d(0.0f,0.0f);
//     acc = Vec2d(0.0f,0.0f);
//     mass = 1.0f;
// }

// QTree::Particle::Particle(Vec2d pos, Vec2d vel, Vec2d acc, float mass)
//     :pos(pos),vel(vel),acc(acc),mass(mass)
// {}

//Particle(Vec2d pos, Vec2d vel, Vec2d acc, float mass);

QTree::QTree(std::vector<Particle*> particles, float width) {
    // costly, probably, but not done often
    this->particles = particles;
    Vec2d ul(0.0,0.0);
    root = new Node(ul,width);
    #pragma omp for
    for (int i = 0; i < particles.size(); i++) {
        root->insert(*particles[i]);
    }
}

// insert a particle while building tree.
void Node::insert(const Particle& p) {
    totalMass += p.mass;
    centerOfMass =  {
                        Node::incrementalCtrMass(totalMass, p.mass, p.pos.x, centerOfMass.x),
                        Node::incrementalCtrMass(totalMass, p.mass, p.pos.y, centerOfMass.y)
                    };
    if (empty) {
        return;
    }

    if (p.pos.x > ul.x + width / 2 && p.pos.y > ul.y + width / 2) {
        // SE


    } else if (p.pos.x > ul.x + width / 2) {
        // NE
    } else if (p.pos.y > ul.y + width / 2) {
        // SW
    } else {
        // NW
    }
}


void QTree::next(int iterations) {
    
}

// not sure if correct?
float Node::incrementalCtrMass(float newTotalMass, float nthMass, float nthPos, float prevCtrMass) {
    return prevCtrMass + (nthMass*nthPos - prevCtrMass) / newTotalMass;
}

// this version is too costly to run every x timesteps
// QTree::Node* QTree::build(Vec2d ul, std::vector<Particle*>& particles, float width) {
//     std::vector<Particle*> nw;
//     std::vector<Particle*> ne;
//     std::vector<Particle*> sw;
//     std::vector<Particle*> se;
//     std::vector<Particle*>::iterator it;
//     for (it = particles.begin(); it != particles.end(); it++) {
//     }
//     return NULL;
// }
