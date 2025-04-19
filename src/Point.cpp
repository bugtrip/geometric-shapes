#include "Point.h"

double Point::get_x() const {
    return x;
}
double Point::get_y() const {
    return y;
}

void Point::set_pt(double x, double y){
    this->x = x;
    this->y = y;
}
