#ifndef SQUARE_H
#define SQUARE_H

#include "GeometricShape.h"
#include <vector>

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
    Square(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(none_cnd), clc(none_clc) {
        set_sides(a,b,c,d);
    }
    Square(std::vector<Point>& pts, size_t len) : cnds(none_cnd), clc(none_clc) {
        set_points(pts, len);
    }
    void set_sides(double a, double b, double c, double d);
    void set_sides(double);
    virtual void set_points(std::vector<Point>& points, size_t len) override;
    void get_sides(double& a, double& b, double& c, double& d) const;
    void set_cnds(Conditions) override;
    void set_clc(Calculations) override;
    virtual Shape& get_shape() override;
    Conditions get_cnds() const;
    Calculations get_clc() const;
    bool check_valid_sq(double a, double b, double c, double d);
    virtual double calculate_perimeter() override;
    virtual double calculate_perimeter(std::vector<Point>&, size_t len);
    std::vector<Point> get_pts();
    virtual double calculate_area();                                               //calculation of the area of a shape based on sides
    virtual double calculate_area(std::vector<Point>& points, size_t len) override;//calculation of the area of a shape based on coordinates
    virtual int available_calc();
    virtual void show_conditions(Calculations& clc) override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions& cnds) override;
    void print_calculation_result(double&);
    virtual ~Square(){}
};

#endif
