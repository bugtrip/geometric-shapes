#ifndef GEOMETRIC_H
#define GEOMETRIC_H

#include "Point.h"
#include <cstddef>
#include <cmath>
#include <vector>
#include <string>

class GeometricShape {
public:
    virtual double calculatePerimeter() = 0;
    virtual double calculateArea(std::vector<Point>& points, size_t len) = 0;//calculation of the area of a shape based on coordinates
    virtual void setConditions(Conditions) = 0;
    virtual void setCalculations(Calculations) = 0;
    virtual Shape& getShape() = 0;
    static void showMenu();                                                //display of the main menu
    virtual int availableCalculations(GeometricShape*);                            //selection of available calculations
    virtual void showConditions(Calculations& clc) = 0;                    //display of the selection form for conditions 
    virtual void showCalculations() = 0;                                           //display of the selection form for available calculations
    virtual void showInputForm(Conditions& cnds) = 0;                     //input form for calculation parameters
	void inputCoords(std::vector<Point>& pts);
	void replaceCharacter(std::string& input);
	virtual ~GeometricShape(){}
};

#endif
