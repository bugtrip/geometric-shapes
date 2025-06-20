#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Processing.h"
#include <iostream>

int main(){       
    int num_shape{0};
    Shape sh{none_sh};
    
    GeometricShape::show_menu();

//selection of a geometric shapes
    std::cin >> num_shape;
    std::cout << "\n";
    sh = (num_shape == 1) ? square 
       : (num_shape == 2) ? rectangle 
       : (num_shape == 3) ? triangle 
       : (num_shape == 0) ? exit_sh 
       : none_sh;

    Square sq_shape;
    Rectangle rec_shape;
    Triangle tr_shape;

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
        case none_sh:
           std::cout << "Ошибка ввода!"  << std::endl;
           return 0;
    }

if(sh == square){               //calculations for a square
    Processing p(&sq_shape);
    p.result_calc(&sq_shape);
} else if(sh == rectangle) {    //calculations for a rectangle
    Processing p(&rec_shape);
    p.result_calc(&rec_shape);
} else if(sh == triangle) {     //calculations for a triangle
    Processing p(&tr_shape);
    p.result_calc(&tr_shape);
}

    return 0;
}
