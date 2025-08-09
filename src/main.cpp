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
	handler.make_shape_ptr(sh);

//selection of conditions for calculations

	int select_condition_result = handler.select_conditions(sh);
	if(select_condition_result == -1){ return -1; }

if(sh == square){               //calculations for a square
    ShapeCalculationHandler h(std::move(handler));
    h.result_calc(h.get_square_ptr());
} else if(sh == rectangle) {    //calculations for a rectangle
    ShapeCalculationHandler h(std::move(handler));
    h.result_calc(h.get_rectangle_ptr());
} else if(sh == triangle) {     //calculations for a triangle
    ShapeCalculationHandler h(std::move(handler));
    h.result_calc(h.get_triangle_ptr());
}

    return 0;
}
