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

void ShapeCalculationHandler::inputSides(Square* shape, double& a){
	shape->inputSides(a);
}

void ShapeCalculationHandler::inputSides(Rectangle* shape, double& a, double& b){
	shape->inputSides(a,b);
}

void ShapeCalculationHandler::inputSides(Triangle* shape, double& a, double& b, double& c){
	shape->inputSides(a,b,c);
}

Shape ShapeCalculationHandler::selectShapes(int numberShape){
	Shape sh{none_sh};
    sh = (numberShape == 1) ? square
       : (numberShape == 2) ? rectangle
       : (numberShape == 3) ? triangle
       : (numberShape == 0) ? exit_sh
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
			if(squarePtr == nullptr) { return -1; } 
			squarePtr->availableCalculations();
			break;
		case rectangle:
			if(rectanglePtr == nullptr){ return -1; }
			rectanglePtr->availableCalculations();
			break;
		case triangle:
			if(trianglePtr == nullptr){ return -1; }
			trianglePtr->availableCalculations();
			break;
		case exit_sh:
			return 0;
		case none_sh:
			std::cerr << "Ошибка ввода!" << std::endl;
			return -1;
	}

	return 0;
}

double ShapeCalculationHandler::calculateSquareAreaBySides(const std::shared_ptr<Square>& sqShape, Calculations clc, Conditions cnds){
	if(sqShape == nullptr){ return -1; }
	if(squarePtr != sqShape){ setSquarePtr(sqShape); }
	if(clc != area || cnds != sides){ return -1; }
	if(squarePtr->getCalculations() != clc){ squarePtr->setCalculations(clc); }
	if(squarePtr->getConditions() != cnds){ squarePtr->setConditions(cnds); }

	double a{0.0};
	inputSides(squarePtr.get(), a);
	squarePtr->setSides(a);
	double squareAreaSides = squarePtr->calculateArea();

	return squareAreaSides;
}

double ShapeCalculationHandler::calculateSquareAreaByCoords(std::vector<Point>& squarePointsArray, size_t& pointsCount){
	if(squarePtr != nullptr){
		inputPoints(squarePtr.get(), squarePointsArray, pointsCount);
		double squareAreaCoords = squarePtr->calculateArea(squarePointsArray, pointsCount);
	
		return squareAreaCoords;
	}
	return -1;
}

double ShapeCalculationHandler::calculateSquarePerimBySides(const std::shared_ptr<Square>& sqShape, Calculations clc, Conditions cnds){
	if(sqShape == nullptr){ return -1;}
	if(squarePtr != sqShape){ setSquarePtr(sqShape); }
	if(clc != perimeter || cnds != sides){ return -1; }
	if(squarePtr->getCalculations()){ squarePtr->setCalculations(clc); }
	if(squarePtr->getConditions()){ squarePtr->setConditions(cnds); }

	double a{0.00};
	inputSides(squarePtr.get(), a);
	squarePtr->setSides(a);
	double squarePerimSides = squarePtr->calculatePerimeter();

	return squarePerimSides;
}

double ShapeCalculationHandler::calculateSquarePerimByCoords(std::vector<Point>& squarePointsArray, size_t& pointsCount){
	if(squarePtr != nullptr){	
		inputPoints(squarePtr.get(), squarePointsArray, pointsCount);
		double squarePerimCoords = squarePtr->calculatePerimeter(squarePointsArray, pointsCount);

		return squarePerimCoords;
	}
	return -1;
}

double ShapeCalculationHandler::calculateRectangleAreaBySides(const std::shared_ptr<Rectangle>& recShape, Calculations clc, Conditions cnds){
	if(recShape == nullptr){ return -1;}
	if(rectanglePtr != recShape){ setRectanglePtr(recShape); }
	if(clc != area || cnds != sides){ return -1; }
	if(rectanglePtr->getCalculations() != clc || rectanglePtr->getConditions() != cnds){ 
		rectanglePtr->setCalculations(clc);
		rectanglePtr->setConditions(cnds);
	}
	double a{0.00}, b{0.00};
	inputSides(rectanglePtr.get(), a, b);
	rectanglePtr->setSides(a,b,a,b);
	double rectangleAreaSides = rectanglePtr->calculateArea();

	return rectangleAreaSides;
}

double ShapeCalculationHandler::calculateRectangleAreaByCoords(std::vector<Point>& rectanglePointsArray, size_t& pointsCount){
	if(rectanglePtr != nullptr){
		inputPoints(rectanglePtr.get(), rectanglePointsArray, pointsCount);
		double rectangleAreaCoords = rectanglePtr->calculateArea(rectanglePointsArray, pointsCount);

		return rectangleAreaCoords;
	}
	return -1;
}

double ShapeCalculationHandler::calculateRectangleAreaByPerim(const std::shared_ptr<Rectangle>& recShape, Calculations clc, Conditions cnds){
	if(recShape == nullptr){ return -1;}
	if(rectanglePtr != recShape){ setRectanglePtr(recShape); }
	if(clc != area || cnds != side_perim){ return -1; }
	if(rectanglePtr->getCalculations() != clc){ rectanglePtr->setCalculations(clc); }
	if(rectanglePtr->getConditions() != cnds){ rectanglePtr->setConditions(cnds); }
	
	double perim{0.00}, a{0.00};
	inputSides(rectanglePtr.get(), perim, a);
	double rectangleAreaPerim = rectanglePtr->calculateArea(perim, a);

	return rectangleAreaPerim;
}

double ShapeCalculationHandler::calculateRectanglePerimBySides(const std::shared_ptr<Rectangle>& recShape, Calculations clc, Conditions cnds){
	if(recShape == nullptr){ return -1; }
	if(rectanglePtr != recShape){ setRectanglePtr(recShape); }
	if(clc != perimeter || cnds != sides){ return -1; }
	if(rectanglePtr->getCalculations() != clc){ rectanglePtr->setCalculations(clc); }
	if(rectanglePtr->getConditions() != cnds){ rectanglePtr->setConditions(cnds); }
	
	double a{0.00}, b{0.00};
	inputSides(rectanglePtr.get(), a, b);
	rectanglePtr->setSides(a,b,a,b);
	double rectanglePerimeterSides = rectanglePtr->calculatePerimeter();

	return rectanglePerimeterSides;
}

double ShapeCalculationHandler::calculateTriangleAreaBySides(const std::shared_ptr<Triangle>& trShape, Calculations clc, Conditions cnds){
	if(trShape == nullptr){ return -1; }
	if(trianglePtr != trShape){ setTrianglePtr(trShape); }
	if(clc != area || cnds != sides){ return -1; }
	if(trianglePtr->getCalculations() != clc){ trianglePtr->setCalculations(clc); }
	if(trianglePtr->getConditions() != cnds){ trianglePtr->setConditions(cnds); }
	
	double a{0.00}, b{0.00}, c{0.00};
	inputSides(trianglePtr.get(), a, b, c);
	double triangleAreaSides = trianglePtr->calculateArea(a,b,c);

	return triangleAreaSides;
}

double ShapeCalculationHandler::calculateTriangleAreaByCoords(std::vector<Point>& trianglePointsArray, size_t& pointsCount){
	if(trianglePtr != nullptr){
		inputPoints(trianglePtr.get(), trianglePointsArray, pointsCount);
		double triangleAreaCoords = trianglePtr->calculateArea(trianglePointsArray, pointsCount);

		return triangleAreaCoords;
	}
	return -1;
}

double ShapeCalculationHandler::calculateTrianglePerimBySides(const std::shared_ptr<Triangle>& trShape, Calculations clc, Conditions cnds){
	if(trShape == nullptr){ return -1; }
	if(trianglePtr != trShape){ setTrianglePtr(trShape); }
	if(clc != perimeter || cnds != sides){ return -1; }
	if(trianglePtr->getCalculations() != clc){ trianglePtr->setCalculations(clc); }
	if(trianglePtr->getConditions() != cnds){ trianglePtr->setConditions(cnds); }

	double a{0.00}, b{0.00}, c{0.00};
	inputSides(trianglePtr.get(), a, b, c);
	trianglePtr->setSides(a,b,c);
	double trianglePerimSides = trianglePtr->calculatePerimeter();

	return trianglePerimSides;
}

double ShapeCalculationHandler::calculateTrianglePerimByCoords(std::vector<Point>& trianglePointsArray, size_t& pointsCount){
	if(trianglePtr != nullptr){
		inputPoints(trianglePtr.get(), trianglePointsArray, pointsCount);
		double trianglePerimCoords = trianglePtr->calculatePerimeter(trianglePointsArray, pointsCount);

		return trianglePerimCoords;
	}
	return -1;
}

int ShapeCalculationHandler::processCalculations(const std::shared_ptr<Square>& sqSh){
    if(sqSh == nullptr){ return -1; }
	if(squarePtr != sqSh){ setSquarePtr(sqSh); }
    
	if(squarePtr->getCalculations() == Calculations::area && squarePtr->getConditions() == sides) {
        double squareAreaSides = calculateSquareAreaBySides(squarePtr, squarePtr->getCalculations(), squarePtr->getConditions());
		squarePtr->printCalculationResult(squareAreaSides);

        return 0;
    }

    if(squarePtr->getCalculations() == area && squarePtr->getConditions() == coords) {
        size_t numberPoints{4};
        std::vector<Point> squarePointsArray;
		squarePointsArray.reserve(numberPoints);
		double squareAreaCoords = calculateSquareAreaByCoords(squarePointsArray, numberPoints);
        squarePtr->printCalculationResult(squareAreaCoords);

        return 0;
    }

    if(squarePtr->getCalculations() == perimeter && squarePtr->getConditions() == sides) {
        double squarePerimSides = calculateSquarePerimBySides(squarePtr, squarePtr->getCalculations(), squarePtr->getConditions());
		squarePtr->printCalculationResult(squarePerimSides);

        return 0;
    }
    
    if(squarePtr->getCalculations() == perimeter && squarePtr->getConditions() == coords) {
        size_t numberPoints{2};
        std::vector<Point> squarePointsArray;
		squarePointsArray.reserve(numberPoints);
		double squarePerimCoords = calculateSquarePerimByCoords(squarePointsArray, numberPoints);
        squarePtr->printCalculationResult(squarePerimCoords);

        return 0;
    }

    return -1;
}

int ShapeCalculationHandler::processCalculations(const std::shared_ptr<Rectangle>& recSh){
	if(recSh == nullptr){ return -1; }
	if(rectanglePtr != recSh){ setRectanglePtr(recSh); }
    
	if(rectanglePtr->getCalculations() == area && rectanglePtr->getConditions() == sides){
		double calculateResult = calculateRectangleAreaBySides(rectanglePtr, rectanglePtr->getCalculations(), rectanglePtr->getConditions());
		rectanglePtr->printCalculationResult(calculateResult);
		
		return 0;
	}
	
    if(rectanglePtr->getCalculations() == area && rectanglePtr->getConditions() == coords) {
        size_t numberPoints{4};
        std::vector<Point> rectanglePointsArray;
		rectanglePointsArray.reserve(numberPoints);
		double calculateResult = calculateRectangleAreaByCoords(rectanglePointsArray, numberPoints);
		rectanglePtr->printCalculationResult(calculateResult);

        return 0;
    }

    if(rectanglePtr->getCalculations() == area && rectanglePtr->getConditions() == side_perim) {
        double calculateResult = calculateRectangleAreaByPerim(rectanglePtr, rectanglePtr->getCalculations(), rectanglePtr->getConditions());
		rectanglePtr->printCalculationResult(calculateResult);
		
		return 0;
	}

    if(rectanglePtr->getCalculations() == perimeter && rectanglePtr->getConditions() == sides) {
        double calculateResult = calculateRectanglePerimBySides(rectanglePtr, rectanglePtr->getCalculations(), rectanglePtr->getConditions());
		rectanglePtr->printCalculationResult(calculateResult);
        
		return 0;
    }

    return -1;
}

int ShapeCalculationHandler::processCalculations(const std::shared_ptr<Triangle>& trShape){
    if(trShape == nullptr){ return -1; }
	if(trianglePtr != trShape){ setTrianglePtr(trShape); }
    
	if(trianglePtr->getCalculations() == area && trianglePtr->getConditions() == sides) {
        double triangleAreaSides = calculateTriangleAreaBySides(trianglePtr, trianglePtr->getCalculations(), trianglePtr->getConditions());
		trianglePtr->printCalculationResult(triangleAreaSides);

        return 0;
    }

    if(trianglePtr->getCalculations() == area && trianglePtr->getConditions() == coords) {
        size_t numberPoints{3};
        std::vector<Point> trianglePointsArray;
		trianglePointsArray.reserve(numberPoints);
		double triangleAreaCoords = calculateTriangleAreaByCoords(trianglePointsArray, numberPoints);
        trianglePtr->printCalculationResult(triangleAreaCoords);

        return 0;
    }

    if(trianglePtr->getCalculations() == perimeter && trianglePtr->getConditions() == sides) {
        double trianglePerimeterSides = calculateTrianglePerimBySides(trianglePtr, trianglePtr->getCalculations(), trianglePtr->getConditions());
		trianglePtr->printCalculationResult(trianglePerimeterSides);

        return 0;
    }

    if(trianglePtr->getCalculations() == perimeter && trianglePtr->getConditions() == coords) {
        size_t numberPoints{3};
        std::vector<Point> trianglePointsArray;
		trianglePointsArray.reserve(numberPoints);
		double trianglePerimCoords = calculateTrianglePerimByCoords(trianglePointsArray, numberPoints);
        trianglePtr->printCalculationResult(trianglePerimCoords);

        return 0;
    }

    return -1;
}
