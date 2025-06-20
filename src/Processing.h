#ifndef PROCESSING_
#define PROCESSING_

#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"

class Processing{
private:
    //GeometricShape* shape_proc;
    Square* sq_shape_proc;
    Rectangle* rec_shape_proc;
    Triangle* tr_shape_proc;
public:
    Processing(Square*);
    Processing(Rectangle*);
    Processing(Triangle*);
    Processing(const Processing&) = delete;
    Processing& operator=(const Processing&) = delete;
    void set_square_ptr(Square*);
    void set_rectangle_ptr(Rectangle*);
    void set_triangle_ptr(Triangle*);
    int result_calc(Square*);
    int result_calc(Rectangle*);
    int result_calc(Triangle*);
};

#endif
