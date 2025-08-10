#include "Triangle.h"
#include <iostream>
#include <iomanip>

Triangle::Triangle(double a = 0.0, double b = 0.0, double c = 0.0){
    setSides(a,b,c);
}
Triangle::Triangle(std::vector<Point>& pts, size_t len){
    setPoints(pts, len);
}

int Triangle::availableCalculations(){
    return GeometricShape::availableCalculations(this);
}

bool Triangle::checkValidTriangle(double a, double b, double c){
    if((a + b) > c && (b + c) > a && (a + c) > b) return true;

    return false;
}

void Triangle::setSides(double a, double b, double c){
    if(checkValidTriangle(a,b,c)){
        this->a = a;
        this->b = b;
        this->c = c;
    }
}

void Triangle::setConditions(Conditions cnds) {
    if(this->cnds != cnds){
        this->cnds = cnds;
    }
}

void Triangle::setCalculations(Calculations clc) {
    if(this->clc != clc){
        this->clc = clc;
    }
}

Shape& Triangle::getShape() {
    return shape;    
}

Conditions Triangle::getConditions() const {
    return cnds;
}
Calculations Triangle::getCalculations() const {
    return clc;
}

void Triangle::getSides(double& a, double& b, double& c) const {
    a = this->a;
    b = this->b;
    c = this->c;
}

void Triangle::setPoints(std::vector<Point>& points, size_t len){
    if(!pts.empty()) pts.clear();
    length = len;
    pts = std::move(points);
}

std::vector<Point>& Triangle::getPoints(){
    return pts;
}

double Triangle::calculatePerimeter(){
    return a + b + c;
}

double Triangle::calculatePerimeter(std::vector<Point>& points, size_t len){
	if(points.empty()){ return -1; }
	setPoints(points, len);
    double result{0};
    for(size_t i = 1; i < length; ++i){
        result += sqrt(fabs(pow(pts[i].getX() - pts[i-1].getX(), 2)) + fabs(pow(pts[i].getY() - pts[i-1].getY(), 2)));
    }
    result += sqrt(fabs(pow(pts[length-1].getX() - pts[0].getX(), 2)) + fabs(pow(pts[length-1].getY() - pts[0].getY(), 2)));

    return result;
}

double Triangle::calculateArea(double a, double b, double c){
	if(checkValidTriangle(a,b,c)){
        this->a = a;
        this->b = b;
        this->c = c;

        double hperim = calculatePerimeter()/2;
        return sqrt(hperim * (hperim - this->a) * (hperim - this->b) * (hperim - this->c));
    }
    return -1;
}

double Triangle::calculateArea(std::vector<Point>& points, size_t len){
	if(points.empty()){ return -1; }
	double result{0.0}, coords1{0.0}, coords2{0.0};
    setPoints(points, len);

    for(size_t i = 1; i < length; ++i){
        coords1 += pts[i-1].getX() * (pts[i].getY());
        coords2 += pts[i-1].getY() * (pts[i].getX());
    }
    coords1 += pts[length-1].getX() * pts[0].getY();
    coords2 += pts[length-1].getY() * pts[0].getX();

    result = fabs(coords1 - coords2)/2;
    
    return result;
}

void Triangle::showCalculations() {
    std::cout << "Доступные вычисления:\n"
              << "  1. Площадь треугольника\n"
              << "  2. Периметр треугольника\n\n"
              << "  0. Выход\n";
}

void Triangle::showConditions(Calculations& clc) {
    std::cout << "Как произвести расчеты?\n"
              << "  1. По сторонам треугольника\n"
              << "  2. По координатам вершин треугольника\n\n"
              << "  0. Выход\n";
}

void Triangle::showInputForm(Conditions& cnds) {
      cnds == sides    ? std::cout << "Введите через пробел длину каждой стороны треугольника по порядку A B C:\n" 
    : cnds == coords   ? std::cout << "Введите координаты каждой вершины треугольника:\n" 
    : cnds == none_cnd ? std::cout << "Ошибка ввода!\n" 
    : std::cout << "\n";
}

void Triangle::printCalculationResult(double& calculationResult){
	if(calculationResult == -1){ std::cerr << "=== Ошибка! Не удалось произвести расчеты. ===\n"; return ; }
	getCalculations() == Calculations::area ?
    std::cout << "\nПлощадь треугольника: " << std::fixed << std::setprecision(2) << calculationResult << std::endl :
    std::cout << "\nПериметр треугольника: " << std::fixed << std::setprecision(2) << calculationResult  << std::endl;
}
