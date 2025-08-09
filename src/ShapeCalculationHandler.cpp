#include "ShapeCalculationHandler.h"
#include <iostream>
#include <sstream>

ShapeCalculationHandler::ShapeCalculationHandler(Shape sh){
	set_shape(sh);
}

ShapeCalculationHandler::ShapeCalculationHandler(std::shared_ptr<Square> sq){
    set_square_ptr(sq);
}
ShapeCalculationHandler::ShapeCalculationHandler(std::shared_ptr<Rectangle> rec){
    set_rectangle_ptr(rec);
}
ShapeCalculationHandler::ShapeCalculationHandler(std::shared_ptr<Triangle> trian){
    set_triangle_ptr(trian);
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

void ShapeCalculationHandler::set_shape(Shape sh){
	if(this->shape != sh) { this->shape = sh; }
}

Shape& ShapeCalculationHandler::get_shape(){
	return shape;
}

void ShapeCalculationHandler::set_square_ptr(std::shared_ptr<Square> sq){
    square_ptr = sq;
}

std::shared_ptr<Square>& ShapeCalculationHandler::get_square_ptr(){
	return square_ptr;
}

std::shared_ptr<Rectangle>& ShapeCalculationHandler::get_rectangle_ptr(){
	return rectangle_ptr;
}

std::shared_ptr<Triangle>& ShapeCalculationHandler::get_triangle_ptr(){
	return triangle_ptr;
}

void ShapeCalculationHandler::set_rectangle_ptr(std::shared_ptr<Rectangle> rec){
    rectangle_ptr = rec;
}

void ShapeCalculationHandler::set_triangle_ptr(std::shared_ptr<Triangle> tr){
    triangle_ptr = tr;
}

void ShapeCalculationHandler::input_points(Square* shape, std::vector<Point>& pts){
	shape->input_coords(pts);
}

void ShapeCalculationHandler::input_points(Rectangle* shape, std::vector<Point>& pts){
	shape->input_coords(pts);
}

void ShapeCalculationHandler::input_points(Triangle* shape, std::vector<Point>& pts){
	shape->input_coords(pts);
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

void ShapeCalculationHandler::make_shape_ptr(Shape& sh){
	if(shape != sh){ set_shape(sh); }
	if(shape == square){
		set_square_ptr(std::make_shared<Square>());
	} else if(shape == rectangle){
		set_rectangle_ptr(std::make_shared<Rectangle>());
	} else if(shape == triangle){
		set_triangle_ptr(std::make_shared<Triangle>());
	}
}

int ShapeCalculationHandler::select_conditions(Shape& shape){
	if(this->shape != shape){ set_shape(shape); }
	switch(this->shape){
		case square:
			if(square_ptr != nullptr) { square_ptr->available_calc(); }
			break;
		case rectangle:
			if(rectangle_ptr != nullptr){ rectangle_ptr->available_calc(); }
			break;
		case triangle:
			if(triangle_ptr != nullptr){ triangle_ptr->available_calc(); }
			break;
		case exit_sh:
			return 0;
		case none_sh:
			std::cerr << "Ошибка ввода!" << std::endl;
			return -1;
	}

	return 0;
}

int ShapeCalculationHandler::result_calc(std::shared_ptr<Square> sq_sh){
    if(square_ptr != sq_sh){ set_square_ptr(sq_sh); }
    if(square_ptr->get_clc() == Calculations::area && square_ptr->get_cnds() == sides) {
        double a{0};
        std::cin >> a;
        square_ptr->set_sides(a);
        double area_square_s{0};
        area_square_s = square_ptr->calculate_area();
        square_ptr->print_calculation_result(area_square_s);

        return 0;
    }

    if(square_ptr->get_clc() == Calculations::area && square_ptr->get_cnds() == coords) {
        size_t count_pt{4};
        std::vector<Point> sq_shape_pts;
		sq_shape_pts.reserve(count_pt);
		input_points(square_ptr.get(), sq_shape_pts);

		double area_square_c{0};
        area_square_c = square_ptr->calculate_area(sq_shape_pts, count_pt);
        square_ptr->print_calculation_result(area_square_c);

        return 0;
    }

    if(square_ptr->get_clc() == Calculations::perimeter && square_ptr->get_cnds() == sides) {
        double a{0};
        std::cin >> a;
        square_ptr->set_sides(a);
        double perim_square_s{0};
        perim_square_s = square_ptr->calculate_perimeter();
        square_ptr->print_calculation_result(perim_square_s);

        return 0;
    }
    
    if(square_ptr->get_clc() == Calculations::perimeter && square_ptr->get_cnds() == coords) {
        size_t count_pt{2};
        std::vector<Point> sq_shape_pts;
		sq_shape_pts.reserve(count_pt);
		input_points(square_ptr.get(), sq_shape_pts);

		double perim_square_c{0};
        perim_square_c = square_ptr->calculate_perimeter(sq_shape_pts, count_pt);
        square_ptr->print_calculation_result(perim_square_c);

        return 0;
    }

    return 0;
}

int ShapeCalculationHandler::result_calc(std::shared_ptr<Rectangle> rec_sh){
    if(rectangle_ptr != rec_sh){ set_rectangle_ptr(rec_sh); }
    if(rectangle_ptr->get_clc() == Calculations::area && rectangle_ptr->get_cnds() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rectangle_ptr->set_sides(a,b,a,b);
        double area_rec_s{0};
        area_rec_s = rectangle_ptr->calculate_area();
        rectangle_ptr->print_calculation_result(area_rec_s);

        return 0;
    }

    if(rectangle_ptr->get_clc() == Calculations::area && rectangle_ptr->get_cnds() == coords) {
        size_t count_pt{4};
        std::vector<Point> rec_shape_pts;
		rec_shape_pts.reserve(count_pt);
		input_points(rectangle_ptr.get(), rec_shape_pts);
		
		double area_rec_c{0};
        area_rec_c = rectangle_ptr->calculate_area(rec_shape_pts, count_pt);
        rectangle_ptr->print_calculation_result(area_rec_c);

        return 0;
    }

    if(rectangle_ptr->get_clc() == Calculations::area && rectangle_ptr->get_cnds() == side_perim) {
        double perim{0}, a{0};
        std::cin >> perim >> a;
        double area_rec_sp{0};
        area_rec_sp = rectangle_ptr->calculate_area(perim, a);
        rectangle_ptr->print_calculation_result(area_rec_sp);

        return 0;
    }

    if(rectangle_ptr->get_clc() == Calculations::perimeter && rectangle_ptr->get_cnds() == sides) {
        double a{0},b{0};
        std::cin >> a >> b;
        rectangle_ptr->set_sides(a,b,a,b);
        double perim_rec_s{0};
        perim_rec_s = rectangle_ptr->calculate_perimeter();
        rectangle_ptr->print_calculation_result(perim_rec_s);

        return 0;
    }

    return 0;
}

int ShapeCalculationHandler::result_calc(std::shared_ptr<Triangle> tr_sh){
    if(triangle_ptr != tr_sh){ set_triangle_ptr(tr_sh); }
    if(triangle_ptr->get_clc() == Calculations::area && triangle_ptr->get_cnds() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        triangle_ptr->set_sides(a,b,c);
        double area_tr_s{0};
        area_tr_s = triangle_ptr->calculate_area(a,b,c);
        triangle_ptr->print_calculation_result(area_tr_s);

        return 0;
    }

    if(triangle_ptr->get_clc() == Calculations::area && triangle_ptr->get_cnds() == coords) {
        size_t count_pt{3};
        std::vector<Point> tr_shape_pts;
		tr_shape_pts.reserve(count_pt);
		input_points(triangle_ptr.get(), tr_shape_pts);

		double area_tr_c{0};
        area_tr_c = triangle_ptr->calculate_area(tr_shape_pts, count_pt);
        triangle_ptr->print_calculation_result(area_tr_c);

        return 0;
    }

    if(triangle_ptr->get_clc() == Calculations::perimeter && triangle_ptr->get_cnds() == sides) {
        double a{0},b{0},c{0};
        std::cin >> a >> b >> c;
        triangle_ptr->set_sides(a,b,c);
        double perim_triangle_s{0};
        perim_triangle_s = triangle_ptr->calculate_perimeter();
        triangle_ptr->print_calculation_result(perim_triangle_s);

        return 0;
    }

    if(triangle_ptr->get_clc() == Calculations::perimeter && triangle_ptr->get_cnds() == coords) {
        size_t count_pt{3};
        std::vector<Point> tr_shape_pts;
		tr_shape_pts.reserve(count_pt);
		input_points(triangle_ptr.get(), tr_shape_pts);

		double perim_tr_c{0};
        perim_tr_c = triangle_ptr->calculate_perimeter(tr_shape_pts, count_pt);
        triangle_ptr->print_calculation_result(perim_tr_c);

        return 0;
    }

    return 0;
}
