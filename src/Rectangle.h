#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GeometricShape.h"
#include <vector>

class Rectangle : public GeometricShape {
private:
    double a{0.0}, b{0.0}, c{0.0}, d{0.0};
    Conditions cnds{none_cnd};
    Calculations clc{none_clc};
    std::vector<Point> pts{0};
    size_t length{0};
public:
    Rectangle(const Rectangle&) = delete;
    Rectangle& operator=(const Rectangle&) = delete;
    Rectangle(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(none_cnd), clc(none_clc) {
        set_sides(a,b,c,d);
    }
    Rectangle(std::vector<Point>& pts, size_t len) : cnds(none_cnd), clc(none_clc) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c, double d);
    virtual void set_points(std::vector<Point>& points, size_t len) override;
    void get_sides(double& a, double& b, double& c, double& d) const;
    void set_cnds(Conditions) override;
    void set_clc(Calculations) override;
    Conditions get_cnds() const;
    Calculations get_clc() const;
    bool check_valid_rec(double a, double b, double c, double d);
    virtual double perimeter() override;
    std::vector<Point> get_pts();
    int result_calc();
    virtual double area();
    virtual double area(double perim, double a);
    virtual double area(std::vector<Point>& coords, size_t len) override;
    virtual int available_calc();
    virtual void show_conditions(Calculations& clc) override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions& cnds) override;
    virtual ~Rectangle(){}
};

#endif
