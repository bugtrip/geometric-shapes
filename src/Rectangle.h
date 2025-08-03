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
    void set_sides(double a, double b, double c, double d);
    void set_points(std::vector<Point>& points, size_t len);
    void get_sides(double& a, double& b, double& c, double& d) const;
    void set_cnds(Conditions) override;
    void set_clc(Calculations) override;
    virtual Shape& get_shape() override;
    Conditions get_cnds() const;
    Calculations get_clc() const;
    bool check_valid_rec(double a, double b, double c, double d);
    virtual double calculate_perimeter() override;
    std::vector<Point>& get_pts();
    virtual double calculate_area();
    virtual double calculate_area(double perim, double a);
    virtual double calculate_area(std::vector<Point>& coords, size_t len) override;
    virtual int available_calc();
    virtual void show_conditions(Calculations& clc) override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions& cnds) override;
    void print_calculation_result(double&);
    virtual ~Rectangle(){}
};

#endif
