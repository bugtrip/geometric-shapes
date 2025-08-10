#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ShapeCalculationHandler.h"
#include <iostream>

int main(){       
    int shape_num{0};
    Shape sh{none_sh};
    
    GeometricShape::showMenu();

//selection of a geometric shapes
	
	ShapeCalculationHandler handler(sh);
	std::cin >> shape_num;
	std::cout << "\n";
	handler.setShapeHandler(handler.selectShapes(shape_num));
	sh = handler.getShapeHandler();
	handler.makeShapePtr(sh);

//selection of conditions for calculations

	int select_condition_result = handler.selectConditions(sh);
	if(select_condition_result == -1){ return -1; }

if(sh == square){               //calculations for a square
    ShapeCalculationHandler h(std::move(handler));
    h.resultCalc(h.getSquarePtr());
} else if(sh == rectangle) {    //calculations for a rectangle
    ShapeCalculationHandler h(std::move(handler));
    h.resultCalc(h.getRectanglePtr());
} else if(sh == triangle) {     //calculations for a triangle
    ShapeCalculationHandler h(std::move(handler));
    h.resultCalc(h.getTrianglePtr());
}

    return 0;
}
