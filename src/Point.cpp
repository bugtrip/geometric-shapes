#include "Point.h"

double Point::getX() const {
    return x;
}
double Point::getY() const {
    return y;
}

void Point::setPts(double x, double y){
    this->x = x;
    this->y = y;
}
