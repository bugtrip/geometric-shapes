#include "Triangle.h"

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
    length = len;
    if(!pts.empty()) pts.clear();
    pts = points;

    for(size_t i = 1; i < length; ++i){
        coords1 += pts[i-1].get_x() * (pts[i].get_y());
        coords2 += pts[i-1].get_y() * (pts[i].get_x());
    }
    coords1 += pts[length-1].get_x() * pts[0].get_y();
    coords2 += pts[length-1].get_y() * pts[0].get_x();

    result = fabs(coords1 - coords2)/2;
    
    return result;
}

int Triangle::result_calc() {
    if(get_clc() == Calculations::area && get_cnds() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        set_sides(a,b,c);
        double area_tr_s = area(a,b,c);
        area_tr_s != -1 ? std::cout << "\nПлощадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_s << std::endl :
                          std::cout << "\nОшибка! Некорректные длины сторон треугольника." << std::endl;

        return 0;
    }

    if(get_clc() == Calculations::area && get_cnds() == coords) {
        size_t count_pt{3};
        Point pt1,pt2,pt3;
        std::vector<Point> tr_shape_pts = {
            pt1,
            pt2,
            pt3
        };
        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            tr_shape_pts[i].set_pt(a,b);
        }

        //tr_shape.set_points(tr_shape_pts, count_pt);
        double area_tr_c = area(tr_shape_pts, count_pt);
        std::cout << "\nПлощадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_c << std::endl;

        return 0;
    }

    if(get_clc() == Calculations::perimeter && get_cnds() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        set_sides(a,b,c);
        double perim_triangle_s = this->perimeter();
        std::cout << "\nПериметр треугольника: " << std::fixed << std::setprecision(2) << perim_triangle_s << std::endl;
        return 0;
    }

    if(get_clc() == Calculations::perimeter && get_cnds() == coords) {
        std::cout << "Не реализовано." << std::endl;

        return 0;
    }

    return 0;
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
    cnds == sides ? std::cout << "Введите через пробел длину каждой стороны треугольника по порядку A B C:\n" : cnds == coords
                  ? std::cout << "Введите координаты каждой вершины треугольника\n" : cnds == none_cnd
                  ? std::cout << "Ошибка ввода!\n" : std::cout << "\n";
}
