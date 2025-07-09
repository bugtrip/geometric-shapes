#ifndef SHAPECALCULATIONHANDLER_
#define SHAPECALCULATIONHANDLER_

#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"

class ShapeCalculationHandler{
private:
    //GeometricShape* shape_proc;
    Square* sq_shape_proc;
    Rectangle* rec_shape_proc;
    Triangle* tr_shape_proc;
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
};

#endif
