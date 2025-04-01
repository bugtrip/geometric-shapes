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
    //GeometricShape* ptr_sq = &sq_shape;
    //GeometricShape* ptr_rec = &rec_shape;

    std::cin >> num_shape;
    std::cout << "\n";
    
    sh = (num_shape == 1) ? square : (num_shape == 2) ? rectangle 
                                   : (num_shape == 3) ? triangle 
                                   : (num_shape == 0) ? exit_sh 
                                   : none_sh;
    
    switch(sh){
        case square:
            sq_shape.input(clc, cnds);
            break;
        case rectangle:
            rec_shape.input(clc, cnds);
            break;
        case triangle:
            tr_shape.input(clc, cnds);
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
        double a{0},b{0},c{0},d{0};
        std::cin >> a >> b >> c >> d;
        sq_shape.set_sides(a,b,c,d);
        double area_square_s = sq_shape.area();
        std::cout << "Площадь квадрата: " << std::fixed << std::setprecision(2) << area_square_s << std::endl;
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
        std::cout << "\n";

        sq_shape.set_points(sq_shape_pts, count_pt);
        
        double area_square_c = sq_shape.area(sq_shape_pts, count_pt);
        std::cout << "Площадь квадрата: " << std::fixed << std::setprecision(2) << area_square_c << std::endl;
        
        for(size_t i = 0; i < count_pt; ++i){
            delete sq_shape_pts[i];
        }
        
        return 0;
    }

    if(sh == square && clc == perimeter && cnds == sides) {
        double a{0},b{0},c{0},d{0};
        std::cin >> a >> b >> c >> d;
        sq_shape.set_sides(a,b,c,d);
        double perim_square_s = sq_shape.perimeter();
        std::cout << "Периметр квадрата: " << std::fixed << std::setprecision(2) << perim_square_s << std::endl;
        
        return 0;
    }
    if(sh == square && clc == perimeter && cnds == coords) {
        std::cout << "Не реализовано." << std::endl;
    }

//Rectangle
    if(sh == rectangle && clc == area && cnds == sides) {
        double a{0},b{0},c{0},d{0};
        std::cin >> a >> b >> c >> d;
        rec_shape.set_sides(a,b,c,d);
        double area_rec_s = rec_shape.area();
        std::cout << "Площадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_s << std::endl;
        
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
        std::cout << "\n";

        rec_shape.set_points(rec_shape_pts, count_pt);

        double area_rec_c = rec_shape.area(rec_shape_pts, count_pt);
        std::cout << "Площадь прямоугольника: " << std::fixed << std::setprecision(2) << area_rec_c << std::endl;
    
        for(size_t i = 0; i < count_pt; ++i){
            delete rec_shape_pts[i];
        }

        return 0;
    }
               
    if(sh == rectangle && clc == perimeter && cnds == sides) {
        double a{0},b{0},c{0},d{0};
        std::cin >> a >> b >> c >> d;
        rec_shape.set_sides(a,b,c,d);
        double perim_rec_s = rec_shape.perimeter();
        std::cout << "Периметр прямоугольника: " << std::fixed << std::setprecision(2) << perim_rec_s << std::endl;

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
        area_tr_s != -1 ? std::cout << "Площадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_s << std::endl : 
                          std::cout << "Ошибка! Некорректные длины сторон треугольника." << std::endl;

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
        std::cout << "\n";

        tr_shape.set_points(tr_shape_pts, count_pt);

        double area_tr_c = tr_shape.area(tr_shape_pts, count_pt);
        std::cout << "Площадь треугольника: " << std::fixed << std::setprecision(2) << area_tr_c << std::endl;
    
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
        std::cout << "Периметр треугольника: " << std::fixed << std::setprecision(2) << perim_triangle_s << std::endl;
        return 0;
    }

    if(sh == triangle && clc == perimeter && cnds == coords) {
        std::cout << "Не реализовано." << std::endl;

        return 0;
    }

    return 0;
}
