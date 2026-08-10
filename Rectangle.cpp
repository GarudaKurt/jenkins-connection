#include "Rectangle.h"

int Rectangle::GetArea() {
    return this->length * this->width;
}

int Rectangle::GetPeremeter() {
    return 2 * (this->length * this->width);
}