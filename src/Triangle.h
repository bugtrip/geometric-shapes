#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "GeometricShape.h"

class Triangle : public GeometricShape {
private:
    double a{0.0}, b{0.0}, c{0.0};
    Conditions cnds{none_cnd};
    Calculations clc{none_clc};
    Point* pts{nullptr};
    size_t length{0};
public:
    Triangle(const Triangle&) = delete;
    Triangle& operator=(const Triangle&) = delete;
    Triangle(double a = 0.0, double b = 0.0, double c = 0.0) : cnds(none_cnd), clc(none_clc) {
        set_sides(a,b,c);
    }
    Triangle(Point** pts, size_t& len) : cnds(none_cnd), clc(none_clc) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c);
    virtual void set_points(Point** points, size_t len) override;
    void get_sides(double& a, double& b, double& c) const;
    void set_cnds(Conditions) override;
    void set_clc(Calculations) override;
    Conditions get_cnds() const;
    Calculations get_clc() const;
    bool check_valid_tr(double a, double b, double c);
    Point* get_pts();
    int result_calc();
    virtual double perimeter() override;
    virtual double area(double a, double b, double c);
    virtual double area(Point** coords, size_t len) override;
    virtual int available_calc();
    virtual void show_conditions(Calculations& clc) override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions& cnds) override;
    virtual ~Triangle() {
        delete [] pts;
    }
};

#endif
