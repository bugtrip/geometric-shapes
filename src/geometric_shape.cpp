#include <iostream>
#include "geometric_shape.h"
#include <cstring>
#include <cmath>

double Point::get_x(){
    return x;
}
double Point::get_y(){
    return y;
}

void Square::set_side(double a, double b, double c, double d){
    if(check_valid_sq(a,b,c,d)){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
}

void Square::get_side(double& a, double& b, double& c, double& d) const {
    a = this->a;
    b = this->b;
    c = this->c;
    d = this->d;
}

void GeometricShape::show_menu() {
    std::cout << "Выберите геометрическую фигуру для расчетов:\n" 
              << "1. Квадрат\n" << "2. Прямоугольник\n" << "3. Параллелограмм" << std::endl;
}
