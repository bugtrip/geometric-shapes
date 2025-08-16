#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ShapeCalculationHandler.h"
#include <iostream>

int main(){       
    int shapeNum{0};
    Shape sh{none_sh};
    
    GeometricShape::showMenu();

//selection of a geometric shapes
	
	ShapeCalculationHandler handler(sh);
	std::cin >> shapeNum;
	std::cout << "\n";
	sh = handler.selectShapes(shapeNum);
	if(sh == none_sh){ return 0; }
	handler.setShapeHandler(sh);
	handler.makeShapePtr(sh);

//selection of conditions for calculations

	int selectedCondition = handler.selectConditions(sh);
	if(selectedCondition == -1){ std::cerr << "Ошибка при выборе условий для расчета!" << std::endl; return 0; }

if(sh == square){               //calculations for a square
    ShapeCalculationHandler h(std::move(handler));
    h.processCalculations(h.getSquarePtr());
	return 0;
} else if(sh == rectangle) {    //calculations for a rectangle
    ShapeCalculationHandler h(std::move(handler));
    h.processCalculations(h.getRectanglePtr());
	return 0;
} else if(sh == triangle) {     //calculations for a triangle
    ShapeCalculationHandler h(std::move(handler));
    h.processCalculations(h.getTrianglePtr());
	return 0;
}

    return 0;
}
