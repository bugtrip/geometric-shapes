#ifndef SHAPECALCULATIONHANDLER_
#define SHAPECALCULATIONHANDLER_

#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <memory>

class ShapeCalculationHandler{
private:
    //GeometricShape* shape_proc;
    Shape shape{none_sh};
	std::shared_ptr<Square> square_ptr{nullptr};
    std::shared_ptr<Rectangle> rectangle_ptr{nullptr};
    std::shared_ptr<Triangle> triangle_ptr{nullptr};
public:
	ShapeCalculationHandler(Shape sh);
	ShapeCalculationHandler(std::shared_ptr<Square>);
    ShapeCalculationHandler(std::shared_ptr<Rectangle>);
    ShapeCalculationHandler(std::shared_ptr<Triangle>);
	ShapeCalculationHandler(ShapeCalculationHandler&&);
    ShapeCalculationHandler(const ShapeCalculationHandler&) = delete;
    ShapeCalculationHandler& operator=(const ShapeCalculationHandler&) = delete;
	
	void set_shape(Shape sh);
	Shape& get_shape();
	void set_square_ptr(std::shared_ptr<Square>);
    void set_rectangle_ptr(std::shared_ptr<Rectangle>);
    void set_triangle_ptr(std::shared_ptr<Triangle>);
	std::shared_ptr<Square>& get_square_ptr();
	std::shared_ptr<Rectangle>& get_rectangle_ptr();
	std::shared_ptr<Triangle>& get_triangle_ptr();
	Shape selectShapes(int shape_num);
	int select_conditions(Shape& shape);
	void make_shape_ptr(Shape&);
	int result_calc(std::shared_ptr<Square>);
    int result_calc(std::shared_ptr<Rectangle>);
    int result_calc(std::shared_ptr<Triangle>);
	void input_points(Square*, std::vector<Point>&);
	void input_points(Rectangle*, std::vector<Point>&);
	void input_points(Triangle*, std::vector<Point>&);
	~ShapeCalculationHandler(){}
};

#endif
