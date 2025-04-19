#ifndef GEOMETRIC_H
#define GEOMETRIC_H

#include "Point.h"
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <cmath>

/*
enum Shape{exit_sh = 0, square = 1, rectangle = 2, triangle = 3, none_sh = 4};
enum Calculations{exit_clc = 0, area = 1, perimeter = 2, none_clc = 3};
enum Conditions{exit_cnds = 0, sides = 1, coords = 2, side_perim = 3, none_cnd = 4};
*/
class GeometricShape {
public:
    virtual double perimeter() = 0;
    virtual double area(Point** points, size_t len) = 0;                    //calculation of the area of a shape based on coordinates
    virtual void set_points(Point** points, size_t len) = 0;
    virtual void set_cnds(Conditions) = 0;
    virtual void set_clc(Calculations) = 0;
    static void show_menu();                                                //display of the main menu
    virtual int available_calc(GeometricShape*);                            //selection of available calculations
    virtual void show_conditions(Calculations& clc) = 0;                    //display of the selection form for conditions 
    virtual void show_calc() = 0;                                           //display of the selection form for available calculations
    virtual void show_input_form(Conditions& cnds) = 0;                     //input form for calculation parameters
    virtual ~GeometricShape(){}
};

#endif
