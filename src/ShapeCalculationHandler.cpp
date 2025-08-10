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
	square_ptr = std::move(rhs.square_ptr);
	rectangle_ptr = std::move(rhs.rectangle_ptr);
	triangle_ptr = std::move(rhs.triangle_ptr);
	rhs.shape = none_sh;
	rhs.square_ptr = nullptr;
	rhs.rectangle_ptr = nullptr;
	rhs.triangle_ptr = nullptr;
}

void ShapeCalculationHandler::setShapeHandler(Shape sh){
	if(this->shape != sh) { this->shape = sh; }
}

Shape& ShapeCalculationHandler::getShapeHandler(){
	return shape;
}

void ShapeCalculationHandler::setSquarePtr(std::shared_ptr<Square> sq){
    square_ptr = sq;
}

std::shared_ptr<Square>& ShapeCalculationHandler::getSquarePtr(){
	return square_ptr;
}

void ShapeCalculationHandler::setRectanglePtr(std::shared_ptr<Rectangle> rec){
    rectangle_ptr = rec;
}

std::shared_ptr<Rectangle>& ShapeCalculationHandler::getRectanglePtr(){
	return rectangle_ptr;
}

void ShapeCalculationHandler::setTrianglePtr(std::shared_ptr<Triangle> tr){
    triangle_ptr = tr;
}

std::shared_ptr<Triangle>& ShapeCalculationHandler::getTrianglePtr(){
	return triangle_ptr;
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
			if(square_ptr != nullptr) { square_ptr->availableCalculations(); }
			break;
		case rectangle:
			if(rectangle_ptr != nullptr){ rectangle_ptr->availableCalculations(); }
			break;
		case triangle:
			if(triangle_ptr != nullptr){ triangle_ptr->availableCalculations(); }
			break;
		case exit_sh:
			return 0;
		case none_sh:
			std::cerr << "Ошибка ввода!" << std::endl;
			return -1;
	}

	return 0;
}

int ShapeCalculationHandler::resultCalc(std::shared_ptr<Square> sq_sh){
    if(square_ptr != sq_sh){ setSquarePtr(sq_sh); }
    if(square_ptr->getCalculations() == Calculations::area && square_ptr->getConditions() == sides) {
        double a{0};
        std::cin >> a;
        square_ptr->setSides(a);
        double area_square_s{0};
        area_square_s = square_ptr->calculateArea();
        square_ptr->printCalculationResult(area_square_s);

        return 0;
    }

    if(square_ptr->getCalculations() == Calculations::area && square_ptr->getConditions() == coords) {
        size_t count_pt{4};
        std::vector<Point> square_points_array;
		square_points_array.reserve(count_pt);
		inputPoints(square_ptr.get(), square_points_array);

		double area_square_c{0};
        area_square_c = square_ptr->calculateArea(square_points_array, count_pt);
        square_ptr->printCalculationResult(area_square_c);

        return 0;
    }

    if(square_ptr->getCalculations() == Calculations::perimeter && square_ptr->getConditions() == sides) {
        double a{0};
        std::cin >> a;
        square_ptr->setSides(a);
        double perim_square_s{0};
        perim_square_s = square_ptr->calculatePerimeter();
        square_ptr->printCalculationResult(perim_square_s);

        return 0;
    }
    
    if(square_ptr->getCalculations() == Calculations::perimeter && square_ptr->getConditions() == coords) {
        size_t count_pt{2};
        std::vector<Point> sq_shape_pts;
		sq_shape_pts.reserve(count_pt);
		inputPoints(square_ptr.get(), sq_shape_pts);

		double perim_square_c{0};
        perim_square_c = square_ptr->calculatePerimeter(sq_shape_pts, count_pt);
        square_ptr->printCalculationResult(perim_square_c);

        return 0;
    }

    return 0;
}

int ShapeCalculationHandler::resultCalc(std::shared_ptr<Rectangle> rec_sh){
    if(rectangle_ptr != rec_sh){ setRectanglePtr(rec_sh); }
    if(rectangle_ptr->getCalculations() == Calculations::area && rectangle_ptr->getConditions() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rectangle_ptr->setSides(a,b,a,b);
        double area_rec_s{0};
        area_rec_s = rectangle_ptr->calculateArea();
        rectangle_ptr->printCalculationResult(area_rec_s);

        return 0;
    }

    if(rectangle_ptr->getCalculations() == Calculations::area && rectangle_ptr->getConditions() == coords) {
        size_t count_pt{4};
        std::vector<Point> rec_shape_pts;
		rec_shape_pts.reserve(count_pt);
		inputPoints(rectangle_ptr.get(), rec_shape_pts);
		
		double area_rec_c{0};
        area_rec_c = rectangle_ptr->calculateArea(rec_shape_pts, count_pt);
        rectangle_ptr->printCalculationResult(area_rec_c);

        return 0;
    }

    if(rectangle_ptr->getCalculations() == Calculations::area && rectangle_ptr->getConditions() == side_perim) {
        double perim{0}, a{0};
        std::cin >> perim >> a;
        double area_rec_sp{0};
        area_rec_sp = rectangle_ptr->calculateArea(perim, a);
        rectangle_ptr->printCalculationResult(area_rec_sp);

        return 0;
    }

    if(rectangle_ptr->getCalculations() == Calculations::perimeter && rectangle_ptr->getConditions() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rectangle_ptr->setSides(a,b,a,b);
        double perim_rec_s{0};
        perim_rec_s = rectangle_ptr->calculatePerimeter();
        rectangle_ptr->printCalculationResult(perim_rec_s);

        return 0;
    }

    return 0;
}

int ShapeCalculationHandler::resultCalc(std::shared_ptr<Triangle> tr_sh){
    if(triangle_ptr != tr_sh){ setTrianglePtr(tr_sh); }
    if(triangle_ptr->getCalculations() == Calculations::area && triangle_ptr->getConditions() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        triangle_ptr->setSides(a,b,c);
        double area_tr_s{0};
        area_tr_s = triangle_ptr->calculateArea(a,b,c);
        triangle_ptr->printCalculationResult(area_tr_s);

        return 0;
    }

    if(triangle_ptr->getCalculations() == Calculations::area && triangle_ptr->getConditions() == coords) {
        size_t count_pt{3};
        std::vector<Point> tr_shape_pts;
		tr_shape_pts.reserve(count_pt);
		inputPoints(triangle_ptr.get(), tr_shape_pts);

		double area_tr_c{0};
        area_tr_c = triangle_ptr->calculateArea(tr_shape_pts, count_pt);
        triangle_ptr->printCalculationResult(area_tr_c);

        return 0;
    }

    if(triangle_ptr->getCalculations() == Calculations::perimeter && triangle_ptr->getConditions() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        triangle_ptr->setSides(a,b,c);
        double perim_triangle_s{0};
        perim_triangle_s = triangle_ptr->calculatePerimeter();
        triangle_ptr->printCalculationResult(perim_triangle_s);

        return 0;
    }

    if(triangle_ptr->getCalculations() == Calculations::perimeter && triangle_ptr->getConditions() == coords) {
        size_t count_pt{3};
        std::vector<Point> tr_shape_pts;
		tr_shape_pts.reserve(count_pt);
		inputPoints(triangle_ptr.get(), tr_shape_pts);

		double perim_tr_c{0};
        perim_tr_c = triangle_ptr->calculatePerimeter(tr_shape_pts, count_pt);
        triangle_ptr->printCalculationResult(perim_tr_c);

        return 0;
    }

    return 0;
}
