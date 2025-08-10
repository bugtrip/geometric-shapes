#include "ShapeCalculationHandler.h"
#include <iostream>
#include <sstream>

ShapeCalculationHandler::ShapeCalculationHandler(Shape sh){
	setShapeHandler(sh);
}

ShapeCalculationHandler::ShapeCalculationHandler(std::shared_ptr<Square> sq){
    setSquarePtr(sq);
}
ShapeCalculationHandler::ShapeCalculationHandler(std::shared_ptr<Rectangle> rec){
    setRectanglePtr(rec);
}
ShapeCalculationHandler::ShapeCalculationHandler(std::shared_ptr<Triangle> trian){
    setTrianglePtr(trian);
}

ShapeCalculationHandler::ShapeCalculationHandler(ShapeCalculationHandler&& rhs){
	shape = rhs.shape;
	squarePtr = std::move(rhs.squarePtr);
	rectanglePtr = std::move(rhs.rectanglePtr);
	trianglePtr = std::move(rhs.trianglePtr);
	rhs.shape = none_sh;
	rhs.squarePtr = nullptr;
	rhs.rectanglePtr = nullptr;
	rhs.trianglePtr = nullptr;
}

void ShapeCalculationHandler::setShapeHandler(Shape sh){
	if(this->shape != sh) { this->shape = sh; }
}

Shape& ShapeCalculationHandler::getShapeHandler(){
	return shape;
}

void ShapeCalculationHandler::setSquarePtr(std::shared_ptr<Square> sq){
    squarePtr = sq;
}

std::shared_ptr<Square>& ShapeCalculationHandler::getSquarePtr(){
	return squarePtr;
}

void ShapeCalculationHandler::setRectanglePtr(std::shared_ptr<Rectangle> rec){
    rectanglePtr = rec;
}

std::shared_ptr<Rectangle>& ShapeCalculationHandler::getRectanglePtr(){
	return rectanglePtr;
}

void ShapeCalculationHandler::setTrianglePtr(std::shared_ptr<Triangle> tr){
    trianglePtr = tr;
}

std::shared_ptr<Triangle>& ShapeCalculationHandler::getTrianglePtr(){
	return trianglePtr;
}

void ShapeCalculationHandler::inputPoints(Square* shape, std::vector<Point>& pts){
	shape->inputCoords(pts);
}

void ShapeCalculationHandler::inputPoints(Rectangle* shape, std::vector<Point>& pts){
	shape->inputCoords(pts);
}

void ShapeCalculationHandler::inputPoints(Triangle* shape, std::vector<Point>& pts){
	shape->inputCoords(pts);
}

void ShapeCalculationHandler::inputSides(Rectangle* shape, double& a, double& b){
	shape->inputSides(a,b);
}

Shape ShapeCalculationHandler::selectShapes(int shape_num){
	Shape sh{none_sh};
    sh = (shape_num == 1) ? square
       : (shape_num == 2) ? rectangle
       : (shape_num == 3) ? triangle
       : (shape_num == 0) ? exit_sh
       : none_sh;

	return sh;
}

void ShapeCalculationHandler::makeShapePtr(Shape& sh){
	if(shape != sh){ setShapeHandler(sh); }
	if(shape == square){
		setSquarePtr(std::make_shared<Square>());
	} else if(shape == rectangle){
		setRectanglePtr(std::make_shared<Rectangle>());
	} else if(shape == triangle){
		setTrianglePtr(std::make_shared<Triangle>());
	}
}

int ShapeCalculationHandler::selectConditions(Shape& shape){
	if(this->shape != shape){ setShapeHandler(shape); }
	switch(this->shape){
		case square:
			if(squarePtr != nullptr) { squarePtr->availableCalculations(); }
			break;
		case rectangle:
			if(rectanglePtr != nullptr){ rectanglePtr->availableCalculations(); }
			break;
		case triangle:
			if(trianglePtr != nullptr){ trianglePtr->availableCalculations(); }
			break;
		case exit_sh:
			return 0;
		case none_sh:
			std::cerr << "Ошибка ввода!" << std::endl;
			return -1;
	}

	return 0;
}

int ShapeCalculationHandler::resultCalc(std::shared_ptr<Square> sqSh){
    if(squarePtr != sqSh){ setSquarePtr(sqSh); }
    if(squarePtr->getCalculations() == Calculations::area && squarePtr->getConditions() == sides) {
        double a{0.0};
        std::cin >> a;
        squarePtr->setSides(a);
        double areaSquareSides{0.0};
        areaSquareSides = squarePtr->calculateArea();
        squarePtr->printCalculationResult(areaSquareSides);

        return 0;
    }

    if(squarePtr->getCalculations() == Calculations::area && squarePtr->getConditions() == coords) {
        size_t numberPoints{4};
        std::vector<Point> squarePointsArray;
		squarePointsArray.reserve(numberPoints);
		inputPoints(squarePtr.get(), squarePointsArray);

		double areaSquareCoords{0.0};
        areaSquareCoords = squarePtr->calculateArea(squarePointsArray, numberPoints);
        squarePtr->printCalculationResult(areaSquareCoords);

        return 0;
    }

    if(squarePtr->getCalculations() == Calculations::perimeter && squarePtr->getConditions() == sides) {
        double a{0.0};
        std::cin >> a;
        squarePtr->setSides(a);
        double perimeterSquareSides{0.00};
        perimeterSquareSides = squarePtr->calculatePerimeter();
        squarePtr->printCalculationResult(perimeterSquareSides);

        return 0;
    }
    
    if(squarePtr->getCalculations() == Calculations::perimeter && squarePtr->getConditions() == coords) {
        size_t numberPoints{2};
        std::vector<Point> squarePointsArray;
		squarePointsArray.reserve(numberPoints);
		inputPoints(squarePtr.get(), squarePointsArray);

		double perimeterSquareCoords{0};
        perimeterSquareCoords = squarePtr->calculatePerimeter(squarePointsArray, numberPoints);
        squarePtr->printCalculationResult(perimeterSquareCoords);

        return 0;
    }

    return 0;
}

int ShapeCalculationHandler::resultCalc(std::shared_ptr<Rectangle> recSh){
    if(rectanglePtr != recSh){ setRectanglePtr(recSh); }
    if(rectanglePtr->getCalculations() == Calculations::area && rectanglePtr->getConditions() == sides) {
        double a{0},b{0};
        /*
		std::cin >> a >> b;
        */
		inputSides(rectanglePtr.get(), a, b);
		rectanglePtr->setSides(a,b,a,b);
        double areaRectangleSides{0};
        areaRectangleSides = rectanglePtr->calculateArea();
        rectanglePtr->printCalculationResult(areaRectangleSides);

        return 0;
    }

    if(rectanglePtr->getCalculations() == Calculations::area && rectanglePtr->getConditions() == coords) {
        size_t numberPoints{4};
        std::vector<Point> rectanglePointsArray;
		rectanglePointsArray.reserve(numberPoints);
		inputPoints(rectanglePtr.get(), rectanglePointsArray);
		
		double areaRectangleCoords{0};
        areaRectangleCoords = rectanglePtr->calculateArea(rectanglePointsArray, numberPoints);
        rectanglePtr->printCalculationResult(areaRectangleCoords);

        return 0;
    }

    if(rectanglePtr->getCalculations() == Calculations::area && rectanglePtr->getConditions() == side_perim) {
        double perim{0}, a{0};
        std::cin >> perim >> a;
        double areaRectanglePerim{0};
        areaRectanglePerim = rectanglePtr->calculateArea(perim, a);
        rectanglePtr->printCalculationResult(areaRectanglePerim);

        return 0;
    }

    if(rectanglePtr->getCalculations() == Calculations::perimeter && rectanglePtr->getConditions() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rectanglePtr->setSides(a,b,a,b);
        double perimeterRectangleSides{0};
        perimeterRectangleSides = rectanglePtr->calculatePerimeter();
        rectanglePtr->printCalculationResult(perimeterRectangleSides);

        return 0;
    }

    return 0;
}

int ShapeCalculationHandler::resultCalc(std::shared_ptr<Triangle> trSh){
    if(trianglePtr != trSh){ setTrianglePtr(trSh); }
    if(trianglePtr->getCalculations() == Calculations::area && trianglePtr->getConditions() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        trianglePtr->setSides(a,b,c);
        double areaTriangleSides{0};
        areaTriangleSides = trianglePtr->calculateArea(a,b,c);
        trianglePtr->printCalculationResult(areaTriangleSides);

        return 0;
    }

    if(trianglePtr->getCalculations() == Calculations::area && trianglePtr->getConditions() == coords) {
        size_t numberPoints{3};
        std::vector<Point> trianglePointsArray;
		trianglePointsArray.reserve(numberPoints);
		inputPoints(trianglePtr.get(), trianglePointsArray);

		double areaTriangleCoords{0};
        areaTriangleCoords = trianglePtr->calculateArea(trianglePointsArray, numberPoints);
        trianglePtr->printCalculationResult(areaTriangleCoords);

        return 0;
    }

    if(trianglePtr->getCalculations() == Calculations::perimeter && trianglePtr->getConditions() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        trianglePtr->setSides(a,b,c);
        double perimeterTriangleSides{0};
        perimeterTriangleSides = trianglePtr->calculatePerimeter();
        trianglePtr->printCalculationResult(perimeterTriangleSides);

        return 0;
    }

    if(trianglePtr->getCalculations() == Calculations::perimeter && trianglePtr->getConditions() == coords) {
        size_t numberPoints{3};
        std::vector<Point> trianglePointsArray;
		trianglePointsArray.reserve(numberPoints);
		inputPoints(trianglePtr.get(), trianglePointsArray);

		double perimeterTriangleCoords{0};
        perimeterTriangleCoords = trianglePtr->calculatePerimeter(trianglePointsArray, numberPoints);
        trianglePtr->printCalculationResult(perimeterTriangleCoords);

        return 0;
    }

    return 0;
}
