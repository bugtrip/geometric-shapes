#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ShapeCalculationHandler.h"
#include <iostream>

int main(){       
    int shape_num{0};
    Shape sh{none_sh};
    
    GeometricShape::show_menu();

//selection of a geometric shapes
	
	ShapeCalculationHandler handler(sh);
	std::cin >> shape_num;
	std::cout << "\n";
	handler.set_shape(handler.selectShapes(shape_num));
	sh = handler.get_shape();
    
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
    ShapeCalculationHandler h(&sq_shape);
    h.result_calc(&sq_shape);
} else if(sh == rectangle) {    //calculations for a rectangle
    ShapeCalculationHandler h(&rec_shape);
    h.result_calc(&rec_shape);
} else if(sh == triangle) {     //calculations for a triangle
    ShapeCalculationHandler h(&tr_shape);
    h.result_calc(&tr_shape);
}

    return 0;
}
