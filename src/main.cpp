#include <iostream>
#include <iomanip>
#include "geometric_shape.h"

int main(){       
    int num_shape{0};
    Shape sh{none_sh};
        
    GeometricShape::show_menu();

//selection of a geometric shapes
    std::cin >> num_shape;
    std::cout << "\n";
    sh = (num_shape == 1) ? square : (num_shape == 2) ? rectangle 
                                   : (num_shape == 3) ? triangle 
                                   : (num_shape == 0) ? exit_sh 
                                   : none_sh;

    Square sq_shape;
    Rectangle rec_shape;
    Triangle tr_shape;

    GeometricShape& rf_sq = sq_shape;
    GeometricShape& rf_rec = rec_shape;
    GeometricShape& rf_tr = tr_shape;


//selection of conditions for calculations
    switch(sh){
        case square:
            sq_shape.available_calc(rf_sq);
            break;
        case rectangle:
            rec_shape.available_calc(rf_rec);
            break;
        case triangle:
            tr_shape.available_calc(rf_tr);
            break;
        case exit_sh:
            return 0;
        default:
           std::cout << "Ошибка ввода!"  << std::endl;
           return 0;
    }

//calculations for a square
    if(sh == square && sq_shape.get_clc() == area && sq_shape.get_cnds() == sides) {
        double a{0};
        std::cin >> a;
        sq_shape.set_sides(a);
        double area_square_s = sq_shape.area();
        std::cout << "\nПлощадь квадрата: " << std::fixed << std::setprecision(2) << area_square_s << std::endl;
        return 0;
    }
    
    if(sh == square && sq_shape.get_clc() == area && sq_shape.get_cnds() == coords) {
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

    if(sh == square && sq_shape.get_clc() == perimeter && sq_shape.get_cnds() == sides) {
        double a{0};
        std::cin >> a;
        sq_shape.set_sides(a);
        double perim_square_s = sq_shape.perimeter();
        std::cout << "\nПериметр квадрата: " << std::fixed << std::setprecision(2) << perim_square_s << std::endl;
        
        return 0;
    }
    if(sh == square && sq_shape.get_clc() == perimeter && sq_shape.get_cnds() == coords) {
        std::cout << "Не реализовано." << std::endl;
    }

//calculations for a rectangle
    if(sh == rectangle && rec_shape.get_clc() == area && rec_shape.get_cnds() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rec_shape.set_sides(a,b,a,b);
        double area_rec_s = rec_shape.area();
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_s << std::endl;
        
        return 0;
    }

    if(sh == rectangle && rec_shape.get_clc() == area && rec_shape.get_cnds() == coords) {
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
    
    if(sh == rectangle && rec_shape.get_clc() == area && rec_shape.get_cnds() == side_perim) {
        double perim{0}, a{0};
        std::cin >> perim >> a;
        double area_rec_sp = rec_shape.area(perim, a);
        std::cout << "\nПлощадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_sp << std::endl;
        
        return 0;
    }

    if(sh == rectangle && rec_shape.get_clc() == perimeter && rec_shape.get_cnds() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rec_shape.set_sides(a,b,a,b);
        double perim_rec_s = rec_shape.perimeter();
        std::cout << "\nПериметр прямоугольника: " << std::fixed << std::setprecision(2) << perim_rec_s << std::endl;

        return 0;
    }
    
    if(sh == rectangle && rec_shape.get_clc() == perimeter && rec_shape.get_cnds() == coords) {
        std::cout << "Не реализовано." << std::endl;

        return 0;
    }
    
//calculations for a triangle
    if(sh == triangle && tr_shape.get_clc() == area && tr_shape.get_cnds() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        tr_shape.set_sides(a,b,c);
        double area_tr_s = tr_shape.area(a,b,c);
        area_tr_s != -1 ? std::cout << "\nПлощадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_s << std::endl : 
                          std::cout << "\nОшибка! Некорректные длины сторон треугольника." << std::endl;

        return 0;
    }

    if(sh == triangle && tr_shape.get_clc() == area && tr_shape.get_cnds() == coords) {
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

    if(sh == triangle && tr_shape.get_clc() == perimeter && tr_shape.get_cnds() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        tr_shape.set_sides(a,b,c);
        double perim_triangle_s = tr_shape.perimeter();
        std::cout << "\nПериметр треугольника: " << std::fixed << std::setprecision(2) << perim_triangle_s << std::endl;
        return 0;
    }

    if(sh == triangle && tr_shape.get_clc() == perimeter && tr_shape.get_cnds() == coords) {
        std::cout << "Не реализовано." << std::endl;

        return 0;
    }
    
    return 0;
}
