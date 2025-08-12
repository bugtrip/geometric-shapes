#include "Square.h"
#include <iostream>
#include <iomanip>

Square::Square(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(none_cnd), clc(none_clc) {
	setSides(a,b,c,d);
}
Square::Square(std::vector<Point>& pts, size_t len) : cnds(none_cnd), clc(none_clc) {
	setPoints(pts, len);
}

int Square::availableCalculations(){
    return GeometricShape::availableCalculations(this);
}

void Square::setSides(double a, double b, double c, double d){
    if(checkValidSquare(a,b,c,d)){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
}

void Square::setSides(double a){
    if(a > 0) {
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
    }
}

void Square::inputSides(double& a){
	std::string str;
	std::cin.ignore();
	std::getline(std::cin, str);
	if(str.empty()){ return ; }
	replaceCharacter(str);

	std::stringstream ss(str);
	ss >> a;
}

void Square::getSides(double& a, double& b, double& c, double& d) const {
    a = this->a;
    b = this->b;
    c = this->c;
    d = this->d;
}

void Square::setPoints(std::vector<Point>& points, size_t len){
    if(!pts.empty()) pts.clear();
    length = len;
    pts = std::move(points);
}

void Square::setConditions(Conditions cnds) {
    if(this->cnds != cnds){
        this->cnds = cnds;
    }
}

void Square::setCalculations(Calculations clc) {
    if(this->clc != clc){
        this->clc = clc;
    }
}

Shape& Square::getShape() {
    return shape;
}

Conditions Square::getConditions() const {
    return cnds;
}
Calculations Square::getCalculations() const {
    return clc;
}

bool Square::checkValidSquare(double a, double b, double c, double d){
    return (a == b) && (c == d) && (a == c) ? true : false;
}

double Square::calculatePerimeter(){
    return a + b + c + d;
}

double Square::calculatePerimeter(std::vector<Point>& points, size_t len){
    if(points.empty()){ return -1;}
	double result{0.0};
    setPoints(points, len);
    for(size_t i = 1; i < length; ++i){
        result += sqrt(fabs(pow(pts[i].getX() - pts[i-1].getX(), 2)) + fabs(pow(pts[i].getY() - pts[i-1].getY(), 2)));
    }

    return result*4;
}

double Square::calculateArea(){
    if(a != 0) { return a * a; }
	return -1;
}

double Square::calculateArea(std::vector<Point>& points, size_t len){
	if(!(points.empty())){
		double result{0.0}, coords1{0.0}, coords2{0.0};
		setPoints(points, len);

		for(size_t i = 1; i < length; ++i){
			coords1 += pts[i-1].getX() * (pts[i].getY());
			coords2 += pts[i-1].getY() * (pts[i].getX());
		}
		coords1 += pts[length-1].getX() * pts[0].getY();
		coords2 += pts[length-1].getY() * pts[0].getX();

		result = fabs(coords1 - coords2)/2.00;

		return result;
	}
	return -1;
}

std::vector<Point>& Square::getPoints(){
    return pts;
}

void Square::showCalculations() {
    std::cout << "Доступные вычисления:\n"
              << "  1. Площадь квадрата\n"
              << "  2. Периметр квадрата\n\n"
              << "  0. Выход\n";
}

void Square::showConditions(Calculations& clc) {
    std::cout << "Как произвести расчеты?\n"
              << "  1. По сторонам квадрата\n"
              << "  2. По координатам вершин квадрата\n\n"
              << "  0. Выход\n";
}

void Square::showInputForm(Conditions& cnds) {
      cnds == sides                                    ? std::cout << "Введите длину стороны квадрата:\n"
    : cnds == coords && clc == Calculations::area      ? std::cout << "Введите координаты каждой вершины квадрата:\n"
    : cnds == coords && clc == Calculations::perimeter ? std::cout << "Введите координаты двух точек одной из сторон квадрата:\n"
    : cnds == none_cnd                                 ? std::cerr << "Ошибка ввода!\n" : std::cout << "\n";
}

void Square::printCalculationResult(double& calculationResult){
	if(calculationResult == -1){ std::cerr << "=== Ошибка! Не удалось произвести расчеты. ===\n"; return ; }
	getCalculations() == Calculations::area ?
    std::cout << "\nПлощадь квадрата: " << std::fixed << std::setprecision(2) << calculationResult << std::endl :
    std::cout << "\nПериметр квадрата: " << std::fixed << std::setprecision(2) << calculationResult  << std::endl;
}
