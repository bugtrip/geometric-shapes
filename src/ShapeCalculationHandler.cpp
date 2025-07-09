#include "ShapeCalculationHandler.h"
#include <iostream>
#include <iomanip>

ShapeCalculationHandler::ShapeCalculationHandler(Square* sq){
    set_square_ptr(sq);
}
ShapeCalculationHandler::ShapeCalculationHandler(Rectangle* rec){
    set_rectangle_ptr(rec);
}
ShapeCalculationHandler::ShapeCalculationHandler(Triangle* trian){
    set_triangle_ptr(trian);
}

void ShapeCalculationHandler::set_square_ptr(Square* sq){
    sq_shape_proc = sq;
}

void ShapeCalculationHandler::set_rectangle_ptr(Rectangle* rec){
    rec_shape_proc = rec;
}

void ShapeCalculationHandler::set_triangle_ptr(Triangle* tr){
    tr_shape_proc = tr;
}

int ShapeCalculationHandler::result_calc(Square* sq_sh){
    set_square_ptr(sq_sh);
    if(sq_shape_proc->get_clc() == Calculations::area && sq_shape_proc->get_cnds() == sides) {
        double a{0};
        std::cin >> a;
        sq_shape_proc->set_sides(a);
        double area_square_s = sq_shape_proc->area();
        std::cout << "\nПлощадь квадрата: " << std::fixed << std::setprecision(2) << area_square_s << std::endl;
        
        return 0;
    }

    if(sq_shape_proc->get_clc() == Calculations::area && sq_shape_proc->get_cnds() == coords) {
        size_t count_pt{4};
        std::vector<Point> sq_shape_pts;
        
        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            sq_shape_pts.push_back(Point(a,b));
        }

        double area_square_c = sq_shape_proc->area(sq_shape_pts, count_pt);
        std::cout << "\nПлощадь квадрата: " << std::fixed << std::setprecision(2) << area_square_c << std::endl;

        return 0;
    }

    if(sq_shape_proc->get_clc() == Calculations::perimeter && sq_shape_proc->get_cnds() == sides) {
        double a{0};
        std::cin >> a;
        sq_shape_proc->set_sides(a);
        double perim_square_s = sq_shape_proc->perimeter();
        std::cout << "\nПериметр квадрата: " << std::fixed << std::setprecision(2) << perim_square_s << std::endl;

        return 0;
    }
    
    if(sq_shape_proc->get_clc() == Calculations::perimeter && sq_shape_proc->get_cnds() == coords) {
        size_t count_pt{2};
        std::vector<Point> sq_shape_pts;

        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            sq_shape_pts.push_back(Point(a,b));
        }

        double perim_square_c = sq_shape_proc->perimeter(sq_shape_pts, count_pt);
        std::cout << "\nПериметр квадрата: " << std::fixed << std::setprecision(2) << perim_square_c << std::endl;

        return 0;
    }

    return 0;
}

int ShapeCalculationHandler::result_calc(Rectangle* rec_sh){
    set_rectangle_ptr(rec_sh);
    if(rec_shape_proc->get_clc() == Calculations::area && rec_shape_proc->get_cnds() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rec_shape_proc->set_sides(a,b,a,b);
        double area_rec_s = rec_shape_proc->area();
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_s << std::endl;

        return 0;
    }

    if(rec_shape_proc->get_clc() == Calculations::area && rec_shape_proc->get_cnds() == coords) {
        size_t count_pt{4};
        std::vector<Point> rec_shape_pts;

        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            rec_shape_pts.push_back(Point(a,b));
        }

        double area_rec_c = rec_shape_proc->area(rec_shape_pts, count_pt);
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_c << std::endl;

        return 0;
    }

    if(rec_shape_proc->get_clc() == Calculations::area && rec_shape_proc->get_cnds() == side_perim) {
        double perim{0}, a{0};
        std::cin >> perim >> a;
        double area_rec_sp = rec_shape_proc->area(perim, a);
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_sp << std::endl;

        return 0;
    }

    if(rec_shape_proc->get_clc() == Calculations::perimeter && rec_shape_proc->get_cnds() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rec_shape_proc->set_sides(a,b,a,b);
        double perim_rec_s = rec_shape_proc->perimeter();
        std::cout << "\nПериметр прямоугольника: " << std::fixed << std::setprecision(2) << perim_rec_s << std::endl;

        return 0;
    }

    return 0;
}

int ShapeCalculationHandler::result_calc(Triangle* tr_sh){
    set_triangle_ptr(tr_sh);
    if(tr_shape_proc->get_clc() == Calculations::area && tr_shape_proc->get_cnds() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        tr_shape_proc->set_sides(a,b,c);
        double area_tr_s = tr_shape_proc->area(a,b,c);
        area_tr_s != -1 ? std::cout << "\nПлощадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_s << std::endl :
                          std::cout << "\nОшибка! Некорректные длины сторон треугольника." << std::endl;

        return 0;
    }

    if(tr_shape_proc->get_clc() == Calculations::area && tr_shape_proc->get_cnds() == coords) {
        size_t count_pt{3};
        std::vector<Point> tr_shape_pts;

        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            tr_shape_pts.push_back(Point(a,b));
        }

        //set_points(tr_shape_pts, count_pt); 
        double area_tr_c = tr_shape_proc->area(tr_shape_pts, count_pt);
        std::cout << "\nПлощадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_c << std::endl;

        return 0;
    }

    if(tr_shape_proc->get_clc() == Calculations::perimeter && tr_shape_proc->get_cnds() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        tr_shape_proc->set_sides(a,b,c);
        double perim_triangle_s = tr_shape_proc->perimeter();
        std::cout << "\nПериметр треугольника: " << std::fixed << std::setprecision(2) << perim_triangle_s << std::endl;
        
        return 0;
    }

    if(tr_shape_proc->get_clc() == Calculations::perimeter && tr_shape_proc->get_cnds() == coords) {
        size_t count_pt{3};
        std::vector<Point> tr_shape_pts;

        for(size_t i = 0; i < count_pt; ++i){
            double a{0.0}, b{0.0};
            std::cin >> a >> b;
            tr_shape_pts.push_back(Point(a,b));
        }

        double perim_tr_c = tr_shape_proc->perimeter(tr_shape_pts, count_pt);
        std::cout << "\nПериметр треугольника: " << std::fixed << std::setprecision(2) << perim_tr_c << std::endl;

        return 0;
    }

    return 0;
}
