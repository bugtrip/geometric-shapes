#include "Rectangle.h"

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
    pts = points;
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


double Rectangle::area(std::vector<Point>& points, size_t len){
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

std::vector<Point> Rectangle::get_pts(){
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
        Point pt1,pt2,pt3,pt4;
        std::vector<Point> rec_shape_pts = {
            pt1,
            pt2,
            pt3,
            pt4
        };
        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            rec_shape_pts[i].set_pt(a,b);
        }

        //rec_shape.set_points(rec_shape_pts, count_pt);
        double area_rec_c = area(rec_shape_pts, count_pt);
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_c << std::endl;

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
