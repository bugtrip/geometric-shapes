#include "Square.h"
#include <iostream>
#include <iomanip>

Square::Square(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(none_cnd), clc(none_clc) {
	set_sides(a,b,c,d);
}
Square::Square(std::vector<Point>& pts, size_t len) : cnds(none_cnd), clc(none_clc) {
	set_points(pts, len);
}

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

void Square::input_coords(std::vector<Point>& pts){
	double x{0.0};
	double y{0.0};
	std::string str;
	std::cin.ignore();
	std::getline(std::cin, str);
	if(str.empty()){ return; }
	replace_character(str);
	std::stringstream s(str);
	
	for(size_t i = 0; i < pts.capacity(); ++i){
		if(s >> x && s >> y){
			pts.push_back(Point(x,y));
		} else {
			pts.clear();
			break;
		}
	}
}

void Square::set_points(std::vector<Point>& points, size_t len){
    if(!pts.empty()) pts.clear();
    length = len;
    pts = std::move(points);
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

Shape& Square::get_shape() {
    return shape;
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

double Square::calculate_perimeter(){
    return a + b + c + d;
}

double Square::calculate_perimeter(std::vector<Point>& points, size_t len){
    double result{0.0};
    set_points(points, len);
    for(size_t i = 1; i < length; ++i){
        result += sqrt(fabs(pow(pts[i].get_x() - pts[i-1].get_x(), 2)) + fabs(pow(pts[i].get_y() - pts[i-1].get_y(), 2)));
    }

    return result*4;
}

double Square::calculate_area(){
    return a * a;
}

double Square::calculate_area(std::vector<Point>& points, size_t len){
	if(!(points.empty())){
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
	return -1;
}

std::vector<Point>& Square::get_pts(){
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
      cnds == sides                                    ? std::cout << "Введите длину стороны квадрата:\n"
    : cnds == coords && clc == Calculations::area      ? std::cout << "Введите координаты каждой вершины квадрата:\n"
    : cnds == coords && clc == Calculations::perimeter ? std::cout << "Введите координаты двух точек одной из сторон квадрата:\n"
    : cnds == none_cnd                                 ? std::cerr << "Ошибка ввода!\n" : std::cout << "\n";
}

void Square::print_calculation_result(double& calculation_result){
	if(calculation_result == -1){ std::cerr << "Ошибка! Не удалось произвести расчеты.\n"; return ; }
	get_clc() == Calculations::area ?
    std::cout << "\nПлощадь квадрата: " << std::fixed << std::setprecision(2) << calculation_result << std::endl :
    std::cout << "\nПериметр квадрата: " << std::fixed << std::setprecision(2) << calculation_result  << std::endl;
}
