#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GeometricShape.h"
#include <vector>

class Rectangle : public GeometricShape {
private:
    double a{0.0}, b{0.0}, c{0.0}, d{0.0};
    Shape shape{rectangle};
    Conditions cnds{none_cnd};
    Calculations clc{none_clc};
    std::vector<Point> pts{0};
    size_t length{0};
public:
    Rectangle(const Rectangle&) = delete;
    Rectangle& operator=(const Rectangle&) = delete;
    Rectangle(){}
	Rectangle(double, double, double, double);
    Rectangle(std::vector<Point>&, size_t);
    void setSides(double a, double b, double c, double d);
    void setPoints(std::vector<Point>& points, size_t len);
    void getSides(double& a, double& b, double& c, double& d) const;
    void setConditions(Conditions) override;
    void setCalculations(Calculations) override;
    virtual Shape& getShape() override;
    Conditions getConditions() const;
    Calculations getCalculations() const;
    bool checkValidRectangle(double a, double b, double c, double d);
    virtual double calculatePerimeter() override;
    std::vector<Point>& getPoints();
    virtual double calculateArea();
    virtual double calculateArea(double perim, double a);
    virtual double calculateArea(std::vector<Point>& coords, size_t len) override;
    virtual int availableCalculations();
    virtual void showConditions(Calculations& clc) override;
    virtual void showCalculations() override;
    virtual void showInputForm(Conditions& cnds) override;
    void printCalculationResult(double&);
    virtual ~Rectangle(){}
};

#endif
