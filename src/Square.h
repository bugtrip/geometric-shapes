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
    void setSides(double a, double b, double c, double d);
    void setSides(double);
    void setPoints(std::vector<Point>&, size_t);
	void getSides(double& a, double& b, double& c, double& d) const;
    void setConditions(Conditions) override;
    void setCalculations(Calculations) override;
    virtual Shape& getShape() override;
    Conditions getConditions() const;
    Calculations getCalculations() const;
    bool checkValidSquare(double a, double b, double c, double d);
    virtual double calculatePerimeter() override;
    virtual double calculatePerimeter(std::vector<Point>&, size_t len);
    std::vector<Point>& getPoints();
    virtual double calculateArea();                                               //calculation of the area of a shape based on sides
    virtual double calculateArea(std::vector<Point>& points, size_t len) override;//calculation of the area of a shape based on coordinates
    virtual int availableCalculations();
    virtual void showConditions(Calculations& clc) override;
    virtual void showCalculations() override;
    virtual void showInputForm(Conditions& cnds) override;
    void printCalculationResult(double&);
    virtual ~Square(){}
};

#endif
