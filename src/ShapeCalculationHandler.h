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
	std::shared_ptr<Square> squarePtr{nullptr};
    std::shared_ptr<Rectangle> rectanglePtr{nullptr};
    std::shared_ptr<Triangle> trianglePtr{nullptr};
public:
	ShapeCalculationHandler(Shape sh);
	ShapeCalculationHandler(std::shared_ptr<Square>);
    ShapeCalculationHandler(std::shared_ptr<Rectangle>);
    ShapeCalculationHandler(std::shared_ptr<Triangle>);
	ShapeCalculationHandler(ShapeCalculationHandler&&);
    ShapeCalculationHandler(const ShapeCalculationHandler&) = delete;
    ShapeCalculationHandler& operator=(const ShapeCalculationHandler&) = delete;
	
	void setShapeHandler(Shape sh);
	Shape& getShapeHandler();
	void setSquarePtr(std::shared_ptr<Square>);
    void setRectanglePtr(std::shared_ptr<Rectangle>);
    void setTrianglePtr(std::shared_ptr<Triangle>);
	std::shared_ptr<Square>& getSquarePtr();
	std::shared_ptr<Rectangle>& getRectanglePtr();
	std::shared_ptr<Triangle>& getTrianglePtr();
	Shape selectShapes(int shape_num);
	int selectConditions(Shape& shape);
	void makeShapePtr(Shape&);
	int resultCalc(std::shared_ptr<Square>);
    int resultCalc(std::shared_ptr<Rectangle>);
    int resultCalc(std::shared_ptr<Triangle>);
	void inputPoints(Square*, std::vector<Point>&);
	void inputPoints(Rectangle*, std::vector<Point>&);
	void inputPoints(Triangle*, std::vector<Point>&);
	~ShapeCalculationHandler(){}
};

#endif
