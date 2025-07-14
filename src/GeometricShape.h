#ifndef GEOMETRIC_H
#define GEOMETRIC_H

#include "Point.h"
#include <cstddef>
#include <cmath>
#include <vector>

class GeometricShape {
public:
    virtual double calculate_perimeter() = 0;
    virtual double calculate_area(std::vector<Point>& points, size_t len) = 0;//calculation of the area of a shape based on coordinates
    virtual void set_cnds(Conditions) = 0;
    virtual void set_clc(Calculations) = 0;
    virtual Shape& get_shape() = 0;
    static void show_menu();                                                //display of the main menu
    virtual int available_calc(GeometricShape*);                            //selection of available calculations
    virtual void show_conditions(Calculations& clc) = 0;                    //display of the selection form for conditions 
    virtual void show_calc() = 0;                                           //display of the selection form for available calculations
    virtual void show_input_form(Conditions& cnds) = 0;                     //input form for calculation parameters
    virtual ~GeometricShape(){}
};

#endif
