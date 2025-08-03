#include "Rectangle.h"
#include <iostream>
#include <iomanip>

Rectangle::Rectangle(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(none_cnd), clc(none_clc) {
	set_sides(a,b,c,d);
}
Rectangle::Rectangle(std::vector<Point>& pts, size_t len) : cnds(none_cnd), clc(none_clc) {
   set_points(pts, len);
}

int Rectangle::available_calc(){
    return GeometricShape::available_calc(this);
}

void Rectangle::set_sides(double a, double b, double c, double d){
    if(check_valid_rec(a,b,c,d)){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
}

void Rectangle::set_points(std::vector<Point>& points, size_t len){
    if(!pts.empty()) pts.clear();
    length = len;
    pts = std::move(points);
}

void Rectangle::set_cnds(Conditions cnds) {
    if(this->cnds != cnds){
        this->cnds = cnds;
    }
}

void Rectangle::set_clc(Calculations clc) {
    if(this->clc != clc){
        this->clc = clc;
    }
}

Shape& Rectangle::get_shape() {
    return shape;
}

Conditions Rectangle::get_cnds() const {
    return cnds;
}
Calculations Rectangle::get_clc() const {
    return clc;
}

void Rectangle::get_sides(double& a, double& b, double& c, double& d) const {
    a = this->a;
    b = this->b;
    c = this->c;
    d = this->d;
}

bool Rectangle::check_valid_rec(double a, double b, double c, double d){
    return (a < 0 || b < 0 || c < 0 || d < 0) ? false : ((a == c && b == d) && c != b) ? true : false;
}

double Rectangle::calculate_perimeter() {
    return a + b + c + d;
}

double Rectangle::calculate_area(double perim, double a) {
    if(perim > a) {
        this->a = a;
        this->b = 0;
        this->c = 0;
        this->d = 0;

        return ((perim * a) - ((a*a) * 2.00)) / 2.00;
    }

    return 0;
}

double Rectangle::calculate_area(){
    return a * b;
}


double Rectangle::calculate_area(std::vector<Point>& points, size_t len){
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

std::vector<Point>& Rectangle::get_pts(){
    return pts;

}

void Rectangle::show_calc() {
    std::cout << "Доступные вычисления:\n"
              << "  1. Площадь прямоугольника\n"
              << "  2. Периметр прямоугольника\n\n"
              << "  0. Выход\n";
}

void Rectangle::show_conditions(Calculations& clc) {
    std::cout << "Как произвести расчеты?\n"
              << "  1. По длине и ширине прямоугольника\n";

    if(clc == Calculations::area) {
        std::cout << "  2. По координатам вершин прямоугольника\n"
                  << "  3. По периметру и одной стороне прямоугольника\n";
    }

    std::cout << "\n  0. Выход\n";
}

void Rectangle::show_input_form(Conditions& cnds) {
      cnds == sides ? std::cout << "Введите через пробел длину и ширину прямоугольника по порядку A B:\n" 
    : cnds == coords && clc == Calculations::area ? std::cout << "Введите координаты каждой вершины прямоугольника:\n" 
    : cnds == side_perim ? std::cout << "Введите через пробел периметр и длину стороны прямоугольника:\n" 
    : cnds == none_cnd ? std::cout << "Ошибка ввода!\n" 
    : std::cout << "\n";
}

void Rectangle::print_calculation_result(double& calculation_result){
    get_clc() == Calculations::area ?
    std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << calculation_result << std::endl :
    std::cout << "\nПериметр прямоугольника: " << std::fixed << std::setprecision(2) << calculation_result  << std::endl;
}
