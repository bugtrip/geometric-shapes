#ifndef SHAPECALCULATIONHANDLER_
#define SHAPECALCULATIONHANDLER_

#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"

class ShapeCalculationHandler{
private:
    //GeometricShape* shape_proc;
    Square* square_ptr;
    Rectangle* rectangle_ptr;
    Triangle* triangle_ptr;
public:
    ShapeCalculationHandler(Square*);
    ShapeCalculationHandler(Rectangle*);
    ShapeCalculationHandler(Triangle*);
    ShapeCalculationHandler(const ShapeCalculationHandler&) = delete;
    ShapeCalculationHandler& operator=(const ShapeCalculationHandler&) = delete;
    void set_square_ptr(Square*);
    void set_rectangle_ptr(Rectangle*);
    void set_triangle_ptr(Triangle*);
    int result_calc(Square*);
    int result_calc(Rectangle*);
    int result_calc(Triangle*);
	void input_coords(std::vector<Point>& pts);
};

#endif
