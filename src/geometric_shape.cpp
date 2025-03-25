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

void Point::set_pt(double x, double y){
    this->x = x;
    this->y = y;
}

void GeometricShape::show_menu() {
    std::cout << "Выберите геометрическую фигуру для расчетов:\n" 
              << "1. Квадрат\n" << "2. Прямоугольник\n" << "3. Треугольник\n" << "4. Ромб" << std::endl;
}

void GeometricShape::show_input_form(Conditions cnds){
    cnds == sides ? std::cout << "Введите параметры:\n" : cnds == coords ? std::cout
                              << "Введите координаты:\n" : std::cout
                              << "Ошибка ввода!"  << std::endl;
}

void Square::set_sides(double a, double b, double c, double d){
    if(check_valid_sq(a,b,c,d)){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
}

void Square::get_sides(double& a, double& b, double& c, double& d) const {
    a = this->a;
    b = this->b;
    c = this->c;
    d = this->d;
}

void Square::set_points(Point** points, size_t len){
    if(pts) delete [] pts;
    length = len;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        this->pts[i] = *points[i];
    }
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

double Square::area(Point** points, size_t len){
    double result{0.0}, res1{0.0}, res2{0.0};
    length = len;
    if(pts) delete [] pts;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        pts[i] = *points[i];
    }

    for(size_t i = 1; i < length; ++i){
        res1 += pts[i-1].get_x() * (pts[i].get_y());
        res2 += pts[i-1].get_y() * (pts[i].get_x());
    }
    res1 += pts[len-1].get_x() * pts[0].get_y();
    res2 += pts[len-1].get_y() * pts[0].get_x();

    result = fabs(res1 - res2)/2;
    return result;
    
}

Point* Square::get_pts(){
    return pts;
}

void Square::show_calc() {
    std::cout << "Доступные вычисления:\n"  << "1. Площадь квадрата\n" << "2. Периметр квадрата\n";
}

void Square::show_conditions() {
    std::cout<< "Как произвести расчеты?\n1. По сторонам квадрата\n2. По координатам вершин квадрата\n";
}

void Square::show_input_form(Conditions cnds) {
    GeometricShape::show_input_form(cnds);
}

void Rectangle::set_sides(double a, double b, double c, double d){
    if(check_valid_rec(a,b,c,d)){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
}

void Rectangle::set_points(Point** points, size_t len){
    if(pts) delete [] pts;
    length = len;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        this->pts[i] = *points[i];
    }
}

void Rectangle::get_sides(double& a, double& b, double& c, double& d) const {
    a = this->a;
    b = this->b;
    c = this->c;
    d = this->d;
}

bool Rectangle::check_valid_rec(double a, double b, double c, double d){
    if((a == c && b == d) && c != b) return true;
    return false;
}

double Rectangle::perimeter() {
    return a + b + c + d;
}

double Rectangle::area(){
    double res = (perimeter() * a - 2 * (a*a)) / 2;
    return res;
}


double Rectangle::area(Point** points, size_t len){
    double result{0.0}, res1{0.0}, res2{0.0};
    length = len;
    if(pts) delete [] pts;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        pts[i] = *points[i];
    }
    
    for(size_t i = 1; i < length; ++i){
        res1 += pts[i-1].get_x() * (pts[i].get_y());
        res2 += pts[i-1].get_y() * (pts[i].get_x());
    }
    res1 += pts[len-1].get_x() * pts[0].get_y();
    res2 += pts[len-1].get_y() * pts[0].get_x();

    result = fabs(res1 - res2)/2;
    return result;
}

Point* Rectangle::get_pts(){
    return pts;

}

void Rectangle::show_calc() {
    std::cout << "Доступные вычисления:\n"  << "1. Площадь прямоугольника\n" << "2. Периметр прямоугольника\n";
}

void Rectangle::show_conditions() {
    std::cout << "Как произвести расчеты?\n1. По сторонам прямоугольника\n2. По координатам вершин прямоугольника\n";
}

void Rectangle::show_input_form(Conditions cnds) {
    cnds == sides ? std::cout << "Введите параметры сторон прямоугольника по порядку A B C D:\n" : cnds == coords ? std::cout
                              << "Введите координаты:\n" : std::cout
                              << "Ошибка ввода!"  << std::endl;
}


