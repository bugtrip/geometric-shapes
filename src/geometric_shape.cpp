#include <iostream>
#include <iomanip>
#include "geometric_shape.h"
#include <cmath>

double Point::get_x() const {
    return x;
}
double Point::get_y() const {
    return y;
}

void Point::set_pt(double x, double y){
    this->x = x;
    this->y = y;
}

void GeometricShape::show_menu() {
    std::cout << "Выберите геометрическую фигуру для расчетов:\n" 
              << "  1. Квадрат\n" 
              << "  2. Прямоугольник\n" 
              << "  3. Треугольник\n\n" 
              << "  0. Выход" << std::endl;
}

//selection of available calculations
int GeometricShape::available_calc(GeometricShape* sh){
    int num_conditions{0}, num_clc{0};
    Conditions cnds;
    Calculations clc;
    sh->show_calc();
    std::cin >> num_clc;
    std::cout << "\n";
    clc = (num_clc == 1) ? Calculations::area : (num_clc == 2) 
                         ? Calculations::perimeter : (num_clc == 0) 
                         ? exit_clc : none_clc;
    sh->set_clc(clc);
    if(clc == none_clc) { std::cout << "Ошибка ввода!\n"; return 0; }

    else if(clc == exit_clc) { return 0; }

    else if(clc == Calculations::area) {
        sh->show_conditions(clc);
        std::cin >> num_conditions;
        std::cout << "\n";
        cnds = (num_conditions == 1) ? sides : (num_conditions == 2) 
                                     ? coords : (num_conditions == 3) 
                                     ? side_perim : (num_conditions == 0) 
                                     ? exit_cnds : none_cnd;
        sh->set_cnds(cnds);
        sh->show_input_form(cnds);
    }

    else if(clc == Calculations::perimeter){
        sh->show_conditions(clc);
        std::cin >> num_conditions;
        std::cout << "\n";
        cnds = (num_conditions == 1) ? sides : (num_conditions == 2) 
                                     ? coords : (num_conditions == 0) 
                                     ? exit_cnds : none_cnd;
        sh->set_cnds(cnds);
        sh->show_input_form(cnds);
    }
    return 0;
}

//Square
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

void Square::set_points(Point** points, size_t len){
    if(pts) delete [] pts;
    length = len;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        this->pts[i] = *points[i];
    }
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

double Square::area(Point** points, size_t len){
    double result{0.0}, coords1{0.0}, coords2{0.0};
    length = len;
    if(pts) delete [] pts;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        pts[i] = *points[i];
    }

    for(size_t i = 1; i < length; ++i){
        coords1 += pts[i-1].get_x() * (pts[i].get_y());
        coords2 += pts[i-1].get_y() * (pts[i].get_x());
    }
    coords1 += pts[length-1].get_x() * pts[0].get_y();
    coords2 += pts[length-1].get_y() * pts[0].get_x();

    result = fabs(coords1 - coords2)/2.00;
    return result;
    
}

Point* Square::get_pts(){
    return pts;
}

int Square::result_calc() {
    if(get_clc() == Calculations::area && get_cnds() == sides) {
        double a{0};
        std::cin >> a;
        set_sides(a);
        double area_square_s = this->area();
        std::cout << "\nПлощадь квадрата: " << std::fixed << std::setprecision(2) << area_square_s << std::endl;
        return 0;
    }
    
    if(get_clc() == Calculations::area && get_cnds() == coords) {
        size_t count_pt{4};
        Point* sq_shape_pts[count_pt] = { 
            new Point(),
            new Point(),
            new Point(),
            new Point()
        };
        
        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            sq_shape_pts[i]->set_pt(a,b);
        }

        //sq_shape.set_points(sq_shape_pts, count_pt);
        double area_square_c = area(sq_shape_pts, count_pt);
        std::cout << "\nПлощадь квадрата: " << std::fixed << std::setprecision(2) << area_square_c << std::endl;
        
        for(size_t i = 0; i < count_pt; ++i){
            delete sq_shape_pts[i];
        }
        
        return 0;
    }

    if(get_clc() == Calculations::perimeter && get_cnds() == sides) {
        double a{0};
        std::cin >> a;
        set_sides(a);
        double perim_square_s = this->perimeter();
        std::cout << "\nПериметр квадрата: " << std::fixed << std::setprecision(2) << perim_square_s << std::endl;
        
        return 0;
    }
    if(get_clc() == Calculations::perimeter && get_cnds() == coords) {
        std::cout << "Не реализовано." << std::endl;
    }

    return 0;
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
    cnds == sides ? std::cout << "Введите длину стороны квадрата:\n" : cnds == coords 
                  ? std::cout << "Введите координаты каждой вершины квадрата:\n" : cnds == none_cnd 
                  ? std::cout << "Ошибка ввода!\n" : std::cout << "\n";
}

//Rectangle
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

void Rectangle::set_points(Point** points, size_t len){
    if(pts) delete [] pts;
    length = len;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        this->pts[i] = *points[i];
    }
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

double Rectangle::perimeter() {
    return a + b + c + d;
}

double Rectangle::area(double perim, double a) {
    if(perim > a) {
        this->a = a;
        this->b = 0;
        this->c = 0;
        this->d = 0;

        return ((perim * a) - ((a*a) * 2.00)) / 2.00;
    }
    
    return 0;
}

double Rectangle::area(){
    return a * b;
}


double Rectangle::area(Point** points, size_t len){
    double result{0.0}, coords1{0.0}, coords2{0.0};
    length = len;
    if(pts) delete [] pts;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        pts[i] = *points[i];
    }
    
    for(size_t i = 1; i < length; ++i){
        coords1 += pts[i-1].get_x() * (pts[i].get_y());
        coords2 += pts[i-1].get_y() * (pts[i].get_x());
    }
    coords1 += pts[length-1].get_x() * pts[0].get_y();
    coords2 += pts[length-1].get_y() * pts[0].get_x();

    result = fabs(coords1 - coords2)/2;
    return result;
}

Point* Rectangle::get_pts(){
    return pts;

}

int Rectangle::result_calc() {
    if(get_clc() == Calculations::area && get_cnds() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        set_sides(a,b,a,b);
        double area_rec_s = this->area();
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_s << std::endl;
        
        return 0;
    }

    if(get_clc() == Calculations::area && get_cnds() == coords) {
        size_t count_pt{4};
        Point* rec_shape_pts[count_pt] = { 
            new Point(),
            new Point(),
            new Point(),
            new Point()
        };
        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            rec_shape_pts[i]->set_pt(a,b);
        }

        //rec_shape.set_points(rec_shape_pts, count_pt);
        double area_rec_c = area(rec_shape_pts, count_pt);
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_c << std::endl;
    
        for(size_t i = 0; i < count_pt; ++i){
            delete rec_shape_pts[i];
        }

        return 0;
    }
    
    if(get_clc() == Calculations::area && get_cnds() == side_perim) {
        double perim{0}, a{0};
        std::cin >> perim >> a;
        double area_rec_sp = area(perim, a);
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_sp << std::endl;
        
        return 0;
    }

    if(get_clc() == Calculations::perimeter && get_cnds() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        set_sides(a,b,a,b);
        double perim_rec_s = this->perimeter();
        std::cout << "\nПериметр прямоугольника: " << std::fixed << std::setprecision(2) << perim_rec_s << std::endl;

        return 0;
    }
    
    if(get_clc() == Calculations::perimeter && get_cnds() == coords) {
        std::cout << "Не реализовано." << std::endl;

        return 0;
    }

    return 0;
}

void Rectangle::show_calc() {
    std::cout << "Доступные вычисления:\n"  
              << "  1. Площадь прямоугольника\n" 
              << "  2. Периметр прямоугольника\n\n"
              << "  0. Выход\n";
}

void Rectangle::show_conditions(Calculations& clc) {
    std::cout << "Как произвести расчеты?\n" 
              << "  1. По длине и ширине прямоугольника\n" 
              << "  2. По координатам вершин прямоугольника\n"; 
    
    if(clc == Calculations::area) {
        std::cout << "  3. По периметру и одной стороне прямоугольника\n";
    }
       
    std::cout << "\n  0. Выход\n";
}

void Rectangle::show_input_form(Conditions& cnds) {
    cnds == sides ? std::cout << "Введите через пробел длину и ширину прямоугольника по порядку A B:\n" : cnds == coords 
                  ? std::cout << "Введите координаты каждой вершины прямоугольника:\n" : cnds == side_perim 
                  ? std::cout << "Введите через пробел периметр и длину стороны прямоугольника:\n" : cnds == none_cnd 
                  ? std::cout << "Ошибка ввода!\n" : std::cout << "\n";
}

//Triangle
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

void Triangle::set_points(Point** points, size_t len){
    if(pts) delete [] pts;
    length = len;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        this->pts[i] = *points[i];
    }
}

Point* Triangle::get_pts(){
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

double Triangle::area(Point** points, size_t len){
    double result{0.0}, coords1{0.0}, coords2{0.0};
    length = len;
    if(pts) delete [] pts;
    pts = new Point[length];
    for(size_t i = 0; i < length; ++i){
        pts[i] = *points[i];
    }
    
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
        Point* tr_shape_pts[count_pt] = { 
            new Point(),
            new Point(),
            new Point()
        };
        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            tr_shape_pts[i]->set_pt(a,b);
        }

        //tr_shape.set_points(tr_shape_pts, count_pt);
        double area_tr_c = area(tr_shape_pts, count_pt);
        std::cout << "\nПлощадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_c << std::endl;
    
        for(size_t i = 0; i < count_pt; ++i){
            delete tr_shape_pts[i];
        }

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

