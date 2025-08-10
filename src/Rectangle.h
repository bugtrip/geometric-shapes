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
    void setSides(double, double, double, double);
    void setPoints(std::vector<Point>&, size_t);
    void getSides(double&, double&, double&, double&) const;
    void setConditions(Conditions) override;
    void setCalculations(Calculations) override;
    virtual Shape& getShape() override;
    Conditions getConditions() const;
    Calculations getCalculations() const;
    bool checkValidRectangle(double, double, double, double);
    virtual double calculatePerimeter() override;
    std::vector<Point>& getPoints();
    virtual double calculateArea();
    virtual double calculateArea(double, double);
    virtual double calculateArea(std::vector<Point>&, size_t) override;
    virtual int availableCalculations();
    virtual void showConditions(Calculations& clc) override;
    virtual void showCalculations() override;
    virtual void showInputForm(Conditions& cnds) override;
    void printCalculationResult(double&);
    virtual ~Rectangle(){}
};

#endif
