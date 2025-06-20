#include "Triangle.h"
#include <iostream>

int Triangle::available_calc(){
    return GeometricShape::available_calc(this);
}

bool Triangle::check_valid_tr(double a, double b, double c){
    if((a + b) > c && (b + c) > a && (a + c) > b) return true;

    return false;
}

void Triangle::set_sides(double a, double b, double c){
    if(check_valid_tr(a,b,c)){
        this->a = a;
        this->b = b;
        this->c = c;
    }
}

void Triangle::set_cnds(Conditions cnds) {
    if(this->cnds != cnds){
        this->cnds = cnds;
    }
}

void Triangle::set_clc(Calculations clc) {
    if(this->clc != clc){
        this->clc = clc;
    }
}

Shape& Triangle::get_shape() {
    return shape;    
}

Conditions Triangle::get_cnds() const {
    return cnds;
}
Calculations Triangle::get_clc() const {
    return clc;
}

void Triangle::get_sides(double& a, double& b, double& c) const {
    a = this->a;
    b = this->b;
    c = this->c;
}

void Triangle::set_points(std::vector<Point>& points, size_t len){
    if(!pts.empty()) pts.clear();
    length = len;
    pts = points;
}

std::vector<Point> Triangle::get_pts(){
    return pts;
}

double Triangle::perimeter(){
    return a + b + c;
}

double Triangle::perimeter(std::vector<Point>& points, size_t len){
    set_points(points, len);
    double result{0};
    for(size_t i = 1; i < length; ++i){
        result += sqrt(fabs(pow(pts[i].get_x() - pts[i-1].get_x(), 2)) + fabs(pow(pts[i].get_y() - pts[i-1].get_y(), 2)));
    }
    result += sqrt(fabs(pow(pts[length-1].get_x() - pts[0].get_x(), 2)) + fabs(pow(pts[length-1].get_y() - pts[0].get_y(), 2)));

    return result;
}

double Triangle::area(double a, double b, double c){
    if(check_valid_tr(a,b,c)){
        this->a = a;
        this->b = b;
        this->c = c;

        double hperim = perimeter()/2;
        return sqrt(hperim * (hperim - this->a) * (hperim - this->b) * (hperim - this->c));
    }
    return -1;
}

double Triangle::area(std::vector<Point>& points, size_t len){
    double result{0.0}, coords1{0.0}, coords2{0.0};
    set_points(points, len);

    for(size_t i = 1; i < length; ++i){
        coords1 += pts[i-1].get_x() * (pts[i].get_y());
        coords2 += pts[i-1].get_y() * (pts[i].get_x());
    }
    coords1 += pts[length-1].get_x() * pts[0].get_y();
    coords2 += pts[length-1].get_y() * pts[0].get_x();

    result = fabs(coords1 - coords2)/2;
    
    return result;
}

void Triangle::show_calc() {
    std::cout << "Доступные вычисления:\n"
              << "  1. Площадь треугольника\n"
              << "  2. Периметр треугольника\n\n"
              << "  0. Выход\n";
}

void Triangle::show_conditions(Calculations& clc) {
    std::cout << "Как произвести расчеты?\n"
              << "  1. По сторонам треугольника\n"
              << "  2. По координатам вершин треугольника\n\n"
              << "  0. Выход\n";
}

void Triangle::show_input_form(Conditions& cnds) {
      cnds == sides    ? std::cout << "Введите через пробел длину каждой стороны треугольника по порядку A B C:\n" 
    : cnds == coords   ? std::cout << "Введите координаты каждой вершины треугольника:\n" 
    : cnds == none_cnd ? std::cout << "Ошибка ввода!\n" 
    : std::cout << "\n";
}
