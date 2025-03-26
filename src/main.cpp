#include <iostream>
#include <iomanip>
#include "geometric_shape.h"

int main(){
    int num_shape{0}, num_conditions{0}, num_clc{0};
    Conditions cnds{none_cnd};
    Calculations clc{none_clc};
    Shape sh{none_sh};
    
    GeometricShape::show_menu();
    
    Square sq_shape;
    Rectangle rec_shape;
    
    std::cin >> num_shape;
    std::cout << "\n";
    
    sh = (num_shape == 1) ? square : (num_shape == 2) ? rectangle : none_sh;
    
    switch(sh){
        case square:
            sq_shape.show_calc();
            std::cin >> num_clc;
            std::cout << "\n";
            clc = (num_clc == 1) ? area : (num_clc == 2) ? perimeter : none_clc;
            
            if(clc == none_clc) { std::cout << "Ошибка ввода!\n"; return 0; }
            
            else if(clc == area) {
                sq_shape.show_conditions();
                std::cin >> num_conditions;
                std::cout << "\n";
                cnds = (num_conditions == 1) ? sides : (num_conditions == 2) ? coords : none_cnd;
                sq_shape.show_input_form(cnds);
                break;
            }
            
            else if(clc == perimeter){
                sq_shape.show_conditions();
                std::cin >> num_conditions;
                std::cout << "\n";
                cnds = (num_conditions == 1) ? sides : (num_conditions == 2) ? coords : none_cnd;
                sq_shape.show_input_form(cnds);
                break;
            }
        case rectangle:
            rec_shape.show_calc();
            std::cin >> num_clc;
            std::cout << "\n";
            clc = (num_clc == 1) ? area : (num_clc == 2) ? perimeter : none_clc;

            if(clc == none_clc) { std::cout << "Ошибка ввода!\n"; return 0; }

            else if(clc == area) {
                rec_shape.show_conditions();
                std::cin >> num_conditions;
                cnds = (num_conditions == 1) ? sides : (num_conditions == 2) ? coords : none_cnd;
                rec_shape.show_input_form(cnds);
                break;
            }
            
            else if(clc == perimeter){
                rec_shape.show_conditions();
                std::cin >> num_conditions;
                std::cout << "\n";
                cnds = (num_conditions == 1) ? sides : (num_conditions == 2) ? coords : none_cnd;
                rec_shape.show_input_form(cnds);
                break;        
            }
        default:
           std::cout << "Ошибка ввода!"  << std::endl;
    }


    if(sh == square && clc == area && cnds == sides) {
        double a{0},b{0},c{0},d{0};
        std::cin >> a >> b >> c >> d;
        sq_shape.set_sides(a,b,c,d);
        double area_square_s = sq_shape.area();
        std::cout << "Площадь квадрата: " << std::fixed << std::setprecision(4) << area_square_s << std::endl;
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
        std::cout << "Площадь квадрата: " << std::fixed << std::setprecision(4) << area_square_c << std::endl;
        
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
        std::cout << "Периметр квадрата: " << std::fixed << std::setprecision(4) << perim_square_s << std::endl;
        
        return 0;
    }
    if(sh == square && clc == perimeter && cnds == coords) {
        std::cout << "Не реализовано." << std::endl;
    }

    if(sh == rectangle && clc == area && cnds == sides) {
        double a{0},b{0},c{0},d{0};
        std::cin >> a >> b >> c >> d;
        rec_shape.set_sides(a,b,c,d);
        double area_rec_s = rec_shape.area();
        std::cout << "Площадь прямоугольника: " << std::fixed << std::setprecision(4) << area_rec_s << std::endl;
        
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
        std::cout << "Площадь прямоугольника: " << std::fixed << std::setprecision(4) << area_rec_c << std::endl;
    
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
        std::cout << "Периметр прямоугольника: " << std::fixed << std::setprecision(4) << perim_rec_s << std::endl;

        return 0;
    }
    
    if(sh == rectangle && clc == perimeter && cnds == coords) {
        std::cout << "Не реализовано." << std::endl;

        return 0;
    }

    return 0;
}
