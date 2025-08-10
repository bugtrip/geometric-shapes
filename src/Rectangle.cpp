#include "Rectangle.h"
#include <iostream>
#include <iomanip>

Rectangle::Rectangle(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(none_cnd), clc(none_clc) {
	setSides(a,b,c,d);
}
Rectangle::Rectangle(std::vector<Point>& pts, size_t len) : cnds(none_cnd), clc(none_clc) {
   setPoints(pts, len);
}

int Rectangle::availableCalculations(){
    return GeometricShape::availableCalculations(this);
}

void Rectangle::setSides(double a, double b, double c, double d){
    if(checkValidRectangle(a,b,c,d)){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
}

void Rectangle::setPoints(std::vector<Point>& points, size_t len){
    if(!pts.empty()) pts.clear();
    length = len;
    pts = std::move(points);
}

void Rectangle::setConditions(Conditions cnds) {
    if(this->cnds != cnds){
        this->cnds = cnds;
    }
}

void Rectangle::setCalculations(Calculations clc) {
    if(this->clc != clc){
        this->clc = clc;
    }
}

Shape& Rectangle::getShape() {
    return shape;
}

Conditions Rectangle::getConditions() const {
    return cnds;
}
Calculations Rectangle::getCalculations() const {
    return clc;
}

void Rectangle::getSides(double& a, double& b, double& c, double& d) const {
    a = this->a;
    b = this->b;
    c = this->c;
    d = this->d;
}

bool Rectangle::checkValidRectangle(double a, double b, double c, double d){
    return (a < 0 || b < 0 || c < 0 || d < 0) ? false : ((a == c && b == d) && c != b) ? true : false;
}

double Rectangle::calculatePerimeter() {
    return a + b + c + d;
}

double Rectangle::calculateArea(double perim, double a) {
    if(perim > a) {
        this->a = a;
        this->b = 0;
        this->c = 0;
        this->d = 0;

        return ((perim * a) - ((a*a) * 2.00)) / 2.00;
    }

    return -1;
}

double Rectangle::calculateArea(){
    return a * b;
}


double Rectangle::calculateArea(std::vector<Point>& points, size_t len){
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

std::vector<Point>& Rectangle::getPoints(){
    return pts;

}

void Rectangle::showCalculations() {
    std::cout << "Доступные вычисления:\n"
              << "  1. Площадь прямоугольника\n"
              << "  2. Периметр прямоугольника\n\n"
              << "  0. Выход\n";
}

void Rectangle::showConditions(Calculations& clc) {
    std::cout << "Как произвести расчеты?\n"
              << "  1. По длине и ширине прямоугольника\n";

    if(clc == Calculations::area) {
        std::cout << "  2. По координатам вершин прямоугольника\n"
                  << "  3. По периметру и одной стороне прямоугольника\n";
    }

    std::cout << "\n  0. Выход\n";
}

void Rectangle::showInputForm(Conditions& cnds) {
      cnds == sides ? std::cout << "Введите через пробел длину и ширину прямоугольника по порядку A B:\n" 
    : cnds == coords && clc == Calculations::area ? std::cout << "Введите координаты каждой вершины прямоугольника:\n" 
    : cnds == side_perim ? std::cout << "Введите через пробел периметр и длину стороны прямоугольника:\n" 
    : cnds == none_cnd ? std::cout << "Ошибка ввода!\n" 
    : std::cout << "\n";
}

void Rectangle::printCalculationResult(double& calculationResult){
	if(calculationResult == -1){ std::cerr << "=== Ошибка! Не удалось произвести расчеты. ===\n"; return ; }
	getCalculations() == Calculations::area ?
    std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << calculationResult << std::endl :
    std::cout << "\nПериметр прямоугольника: " << std::fixed << std::setprecision(2) << calculationResult  << std::endl;
}
