#ifndef __RECTANGLE__H
#define __RECTANGLE__H
#include "Shape.h"

class Rectangle : public Shape {
    public:
        int GetArea();
        int GetPeremeter();
};
#endif