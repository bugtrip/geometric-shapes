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
    Triangle(double a = 0.0, double b = 0.0, double c = 0.0) : cnds(none_cnd), clc(none_clc) {
        set_sides(a,b,c);
    }
    Triangle(std::vector<Point> pts, size_t len) : cnds(none_cnd), clc(none_clc) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c);
    virtual void set_points(std::vector<Point>& points, size_t len) override;
    void get_sides(double& a, double& b, double& c) const;
    void set_cnds(Conditions) override;
    void set_clc(Calculations) override;
    virtual Shape& get_shape() override;
    Conditions get_cnds() const;
    Calculations get_clc() const;
    bool check_valid_tr(double a, double b, double c);
    std::vector<Point> get_pts();
    virtual double perimeter() override;
    virtual double perimeter(std::vector<Point>&, size_t);
    virtual double area(double a, double b, double c);
    virtual double area(std::vector<Point>& coords, size_t len) override;
    virtual int available_calc();
    virtual void show_conditions(Calculations& clc) override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions& cnds) override;
    virtual ~Triangle() {}
};

#endif
