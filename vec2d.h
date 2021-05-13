#ifndef VEC2D_H_
#define VEC2D_H_
#include <cmath>
#include <iostream>

struct Vec2d {
    public:
    float x;
    float y;

    Vec2d() {
        x = 0;
        y = 0;
    };

    Vec2d(float x, float y) {
        this->x = x; this->y = y;
    };

    void operator +=(const Vec2d& other) {
        x += other.x;
        y += other.y;
    }

    Vec2d operator +(const Vec2d& other) const {
        return {x + other.x, y + other.y};
    }

    Vec2d operator *(float scale) const {
        return {x*scale, y*scale};
    }



    friend std::ostream &operator<<(std::ostream &os, Vec2d const &v) { 
        return os << "(" + std::to_string(v.x) + "," + std::to_string(v.y) + ")";
    }


};

#endif
