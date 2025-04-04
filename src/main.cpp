#include <iostream>
#include <iomanip>
#include "geometric_shape.h"

int main(){
    int num_shape{0};
    Shape sh{none_sh};
    Conditions cnds{none_cnd};
    Calculations clc{none_clc};
    
    GeometricShape::show_menu();    
    
    Square sq_shape;
    Rectangle rec_shape;
    Triangle tr_shape;
    GeometricShape& rf_sq = sq_shape;
    GeometricShape& rf_rec = rec_shape;
    GeometricShape& rf_tr = tr_shape;

//selection of a geometric shapes
    std::cin >> num_shape;
    std::cout << "\n";
    sh = (num_shape == 1) ? square : (num_shape == 2) ? rectangle 
                                   : (num_shape == 3) ? triangle 
                                   : (num_shape == 0) ? exit_sh 
                                   : none_sh;

//selection of conditions for calculations
    switch(sh){
        case square:
            rf_sq.available_calc(rf_sq, clc, cnds);
            break;
        case rectangle:
            rf_rec.available_calc(rf_rec, clc, cnds);
            break;
        case triangle:
            rf_tr.available_calc(rf_tr, clc, cnds);
            break;
        case exit_sh:
            //std::cout << " " << std::endl;
            return 0;
        default:
           std::cout << "Ошибка ввода!"  << std::endl;
           return 0;
    }
    
//Square
    if(sh == square && clc == area && cnds == sides) {
        double a{0};
        std::cin >> a;
        sq_shape.set_sides(a);
        double area_square_s = sq_shape.area();
        std::cout << "\nПлощадь квадрата: " << std::fixed << std::setprecision(2) << area_square_s << std::endl;
        return 0;
    }
    
    if(sh == square && clc == area && cnds == coords) {
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
        double area_square_c = sq_shape.area(sq_shape_pts, count_pt);
        std::cout << "\nПлощадь квадрата: " << std::fixed << std::setprecision(2) << area_square_c << std::endl;
        
        for(size_t i = 0; i < count_pt; ++i){
            delete sq_shape_pts[i];
        }
        
        return 0;
    }

    if(sh == square && clc == perimeter && cnds == sides) {
        double a{0};
        std::cin >> a;
        sq_shape.set_sides(a);
        double perim_square_s = sq_shape.perimeter();
        std::cout << "\nПериметр квадрата: " << std::fixed << std::setprecision(2) << perim_square_s << std::endl;
        
        return 0;
    }
    if(sh == square && clc == perimeter && cnds == coords) {
        std::cout << "Не реализовано." << std::endl;
    }

//Rectangle
    if(sh == rectangle && clc == area && cnds == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rec_shape.set_sides(a,b,a,b);
        double area_rec_s = rec_shape.area();
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_s << std::endl;
        
        return 0;
    }

    if(sh == rectangle && clc == area && cnds == coords) {
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
        double area_rec_c = rec_shape.area(rec_shape_pts, count_pt);
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_c << std::endl;
    
        for(size_t i = 0; i < count_pt; ++i){
            delete rec_shape_pts[i];
        }

        return 0;
    }
    
    if(sh == rectangle && clc == area && cnds == side_perim) {
        double perim{0}, a{0};
        std::cin >> perim >> a;
        double area_rec_sp = rec_shape.area(perim, a);
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_sp << std::endl;
        
        return 0;
    }

    if(sh == rectangle && clc == perimeter && cnds == sides) {
        double a{0},b{0},c{0},d{0};
        std::cin >> a >> b >> c >> d;
        rec_shape.set_sides(a,b,c,d);
        double perim_rec_s = rec_shape.perimeter();
        std::cout << "\nПериметр прямоугольника: " << std::fixed << std::setprecision(2) << perim_rec_s << std::endl;

        return 0;
    }
    
    if(sh == rectangle && clc == perimeter && cnds == coords) {
        std::cout << "Не реализовано." << std::endl;

        return 0;
    }
    
//Triangle
    if(sh == triangle && clc == area && cnds == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        tr_shape.set_sides(a,b,c);
        double area_tr_s = tr_shape.area(a,b,c);
        area_tr_s != -1 ? std::cout << "\nПлощадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_s << std::endl : 
                          std::cout << "\nОшибка! Некорректные длины сторон треугольника." << std::endl;

        return 0;
    }

    if(sh == triangle && clc == area && cnds == coords) {
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
        double area_tr_c = tr_shape.area(tr_shape_pts, count_pt);
        std::cout << "\nПлощадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_c << std::endl;
    
        for(size_t i = 0; i < count_pt; ++i){
            delete tr_shape_pts[i];
        }

        return 0;
    }

    if(sh == triangle && clc == perimeter && cnds == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        tr_shape.set_sides(a,b,c);
        double perim_triangle_s = tr_shape.perimeter();
        std::cout << "\nПериметр треугольника: " << std::fixed << std::setprecision(2) << perim_triangle_s << std::endl;
        return 0;
    }

    if(sh == triangle && clc == perimeter && cnds == coords) {
        std::cout << "Не реализовано." << std::endl;

        return 0;
    }

    return 0;
}
