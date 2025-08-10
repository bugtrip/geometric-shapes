#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "GeometricShape.h"
#include <vector>

class Triangle : public GeometricShape {
private:
    double a{0.0}, b{0.0}, c{0.0};
    Shape shape{triangle};
    Conditions cnds{none_cnd};
    Calculations clc{none_clc};
    std::vector<Point> pts{0};
    size_t length{0};
public:
    Triangle(const Triangle&) = delete;
    Triangle& operator=(const Triangle&) = delete;
    Triangle(){}
	Triangle(double, double, double);
    Triangle(std::vector<Point>&, size_t);
    void setSides(double, double, double);
    void setPoints(std::vector<Point>&, size_t);
    void getSides(double&, double&, double&) const;
    void setConditions(Conditions) override;
    void setCalculations(Calculations) override;
    virtual Shape& getShape() override;
    Conditions getConditions() const;
    Calculations getCalculations() const;
    bool checkValidTriangle(double, double, double);
    std::vector<Point>& getPoints();
    virtual double calculatePerimeter() override;
    virtual double calculatePerimeter(std::vector<Point>&, size_t);
    virtual double calculateArea(double, double, double);
    virtual double calculateArea(std::vector<Point>&, size_t) override;
    virtual int availableCalculations();
    virtual void showConditions(Calculations& clc) override;
    virtual void showCalculations() override;
    virtual void showInputForm(Conditions& cnds) override;
    void printCalculationResult(double&);
    virtual ~Triangle() {}
};

#endif
