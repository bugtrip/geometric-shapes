#ifndef SQUARE_H
#define SQUARE_H

#include "GeometricShape.h"
#include <vector>
#include <sstream>

class Square : public GeometricShape {
private:
    double a{0.0},b{0.0},c{0.0},d{0.0};
    Shape shape{square};
    Conditions cnds{none_cnd};
    Calculations clc{none_clc};
    std::vector<Point> pts{0};
    size_t length{0};
public:
    Square(const Square&) = delete;
    Square& operator=(const Square&) = delete;
    Square(){}
    Square(double, double, double, double);
    Square(std::vector<Point>&, size_t);
    void setSides(double, double, double, double);
    void setSides(double);
    void setPoints(std::vector<Point>&, size_t);
	void getSides(double&, double&, double&, double&) const;
    void setConditions(Conditions) override;
    void setCalculations(Calculations) override;
    virtual Shape& getShape() override;
    Conditions getConditions() const;
    Calculations getCalculations() const;
    bool checkValidSquare(double, double, double, double);
    virtual double calculatePerimeter() override;
    virtual double calculatePerimeter(std::vector<Point>&, size_t);
    std::vector<Point>& getPoints();
    virtual double calculateArea();                                               //calculation of the area of a shape based on sides
    virtual double calculateArea(std::vector<Point>&, size_t) override;//calculation of the area of a shape based on coordinates
    virtual int availableCalculations();
    virtual void showConditions(Calculations& clc) override;
    virtual void showCalculations() override;
    virtual void showInputForm(Conditions& cnds) override;
    void printCalculationResult(double&);
    virtual ~Square(){}
};

#endif
