#include "Square.h"

int Square::available_calc(){
    return GeometricShape::available_calc(this);
}

void Square::set_sides(double a, double b, double c, double d){
    if(check_valid_sq(a,b,c,d)){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
}

void Square::set_sides(double a){
    if(a > 0) {
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
    }
}

void Square::get_sides(double& a, double& b, double& c, double& d) const {
    a = this->a;
    b = this->b;
    c = this->c;
    d = this->d;
}

void Square::set_points(std::vector<Point>& points, size_t len){
    if(!pts.empty()) pts.clear();
    length = len;
    pts = points;
}

void Square::set_cnds(Conditions cnds) {
    if(this->cnds != cnds){
        this->cnds = cnds;
    }
}

void Square::set_clc(Calculations clc) {
    if(this->clc != clc){
        this->clc = clc;
    }
}

Conditions Square::get_cnds() const {
    return cnds;
}
Calculations Square::get_clc() const {
    return clc;
}

bool Square::check_valid_sq(double a, double b, double c, double d){
    return (a == b) && (c == d) && (a == c) ? true : false;
}

double Square::perimeter(){
    return a + b + c + d;
}

double Square::area(){
    return a * a;
}

double Square::area(std::vector<Point>& points, size_t len){
    double result{0.0}, coords1{0.0}, coords2{0.0};
    set_points(points, len);

    for(size_t i = 1; i < length; ++i){
        coords1 += pts[i-1].get_x() * (pts[i].get_y());
        coords2 += pts[i-1].get_y() * (pts[i].get_x());
    }
    coords1 += pts[length-1].get_x() * pts[0].get_y();
    coords2 += pts[length-1].get_y() * pts[0].get_x();

    result = fabs(coords1 - coords2)/2.00;
    
    return result;

}

std::vector<Point> Square::get_pts(){
    return pts;
}

void Square::show_calc() {
    std::cout << "Доступные вычисления:\n"
              << "  1. Площадь квадрата\n"
              << "  2. Периметр квадрата\n\n"
              << "  0. Выход\n";
}

void Square::show_conditions(Calculations& clc) {
    std::cout << "Как произвести расчеты?\n"
              << "  1. По сторонам квадрата\n"
              << "  2. По координатам вершин квадрата\n\n"
              << "  0. Выход\n";
}

void Square::show_input_form(Conditions& cnds) {
      cnds == sides    ? std::cout << "Введите длину стороны квадрата:\n" 
    : cnds == coords   ? std::cout << "Введите координаты каждой вершины квадрата:\n" 
    : cnds == none_cnd ? std::cout << "Ошибка ввода!\n" 
    : std::cout << "\n";
}
