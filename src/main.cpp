#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"

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

    //GeometricShape& rf_sq = sq_shape;
    //GeometricShape& rf_rec = rec_shape;
    //GeometricShape& rf_tr = tr_shape;


//selection of conditions for calculations
    switch(sh){
        case square:
            sq_shape.available_calc();
            break;
        case rectangle:
            rec_shape.available_calc();
            break;
        case triangle:
            tr_shape.available_calc();
            break;
        case exit_sh:
            return 0;
        default:
           std::cout << "Ошибка ввода!"  << std::endl;
           return 0;
    }

//calculations for a square
    if(sh == square){
        sq_shape.result_calc();
    } 

//calculations for a rectangle
    if(sh == rectangle){
        rec_shape.result_calc();
    }
    
//calculations for a triangle
    if(sh == triangle){
        tr_shape.result_calc();
    }
    
    return 0;
}
