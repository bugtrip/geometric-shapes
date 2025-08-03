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
    void set_sides(double a, double b, double c);
    void set_points(std::vector<Point>& points, size_t len);
    void get_sides(double& a, double& b, double& c) const;
    void set_cnds(Conditions) override;
    void set_clc(Calculations) override;
    virtual Shape& get_shape() override;
    Conditions get_cnds() const;
    Calculations get_clc() const;
    bool check_valid_tr(double a, double b, double c);
    std::vector<Point>& get_pts();
    virtual double calculate_perimeter() override;
    virtual double calculate_perimeter(std::vector<Point>&, size_t);
    virtual double calculate_area(double a, double b, double c);
    virtual double calculate_area(std::vector<Point>& coords, size_t len) override;
    virtual int available_calc();
    virtual void show_conditions(Calculations& clc) override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions& cnds) override;
    void print_calculation_result(double&);
    virtual ~Triangle() {}
};

#endif
