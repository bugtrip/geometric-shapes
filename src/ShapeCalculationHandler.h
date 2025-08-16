#ifndef SHAPECALCULATIONHANDLER_
#define SHAPECALCULATIONHANDLER_

#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <memory>

class ShapeCalculationHandler{
private:
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
	double calculateSquareAreaBySides(const std::shared_ptr<Square>&, Calculations, Conditions);
	double calculateSquareAreaByCoords(std::vector<Point>&, size_t&);
	double calculateSquarePerimBySides(const std::shared_ptr<Square>&, Calculations, Conditions);
	double calculateSquarePerimByCoords(std::vector<Point>&, size_t&);
	double calculateRectangleAreaBySides(const std::shared_ptr<Rectangle>&, Calculations, Conditions);
	double calculateRectangleAreaByPerim(const std::shared_ptr<Rectangle>&, Calculations, Conditions);
	double calculateRectangleAreaByCoords(std::vector<Point>&, size_t&);
	double calculateRectanglePerimBySides(const std::shared_ptr<Rectangle>&, Calculations, Conditions);
	double calculateTriangleAreaBySides(const std::shared_ptr<Triangle>&, Calculations, Conditions);
	double calculateTriangleAreaByCoords(std::vector<Point>&, size_t&);
	double calculateTrianglePerimBySides(const std::shared_ptr<Triangle>&, Calculations, Conditions);
	double calculateTrianglePerimByCoords(std::vector<Point>&, size_t&);
	int processCalculations(const std::shared_ptr<Square>&);
    int processCalculations(const std::shared_ptr<Rectangle>&);
    int processCalculations(const std::shared_ptr<Triangle>&);
	template<typename Type>
	void inputPoints(Type&, std::vector<Point>&, size_t&);
	void inputSides(std::shared_ptr<Square>&, double&);
	void inputSides(std::shared_ptr<Rectangle>&, double&, double&);
	void inputSides(std::shared_ptr<Triangle>&, double&, double&, double&);
	~ShapeCalculationHandler(){}
};

template<typename Type>
void ShapeCalculationHandler::inputPoints(Type& shapePtr, std::vector<Point>& points, size_t& pointCount){
	shapePtr->inputCoords(points, pointCount);
}

#endif
