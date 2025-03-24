#ifndef _GEOMERTIC_H
#define _GEOMETRIC_H
#include <cstddef>

enum Shape{square = 1, rectangle = 2, triangle = 3, none_sh = 4};
enum Calculations{area = 1, perimeter = 2, none_clc = 3};
enum Conditions{sides = 1, coords = 2, none_cnd = 3};

class Point {
private:
    double x,y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    double get_x();
    double get_y();
    void set_pt(double x, double y);
};

class GeometricShape {
public:
    virtual double perimeter() = 0;
    virtual double area(Point** points, size_t len) = 0;
    virtual void set_points(Point** points, size_t len) = 0;
    static void show_menu();
    virtual void show_conditions() = 0;
    virtual void show_calc() = 0;
    virtual void show_input_form(Conditions cnds) = 0;
    virtual ~GeometricShape(){}
};

class Square : public GeometricShape {
private:
    double a{0.0},b{0.0},c{0.0},d{0.0};
    Conditions calc{none_cnd};
    Point* pts{nullptr};
    size_t length{0};
public:
    Square() = default;
    Square(Conditions calc, double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : calc(calc) {
            set_sides(a,b,c,d);
    }
    Square(Conditions calc, Point** pts, size_t& len) : calc(calc) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c, double d);
    void set_points(Point** points, size_t len) override;
    void get_sides(double& a, double& b, double& c, double& d) const;
    bool check_valid_sq(double a, double b, double c, double d);
    double perimeter();
    Point* get_pts();
    virtual double area();
    virtual double area(Point** points, size_t len) override;
    virtual void show_conditions() override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions cnds) override;
    virtual ~Square(){
        delete [] pts;
    }
};

class Rectangle : public GeometricShape {
private:
    double a{0.0}, b{0.0}, c{0.0}, d{0.0};
    Conditions calc{none_cnd};
    Point* pts{nullptr};
    size_t length{0};
public:
    Rectangle() = default;
    Rectangle(Conditions calc, double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0){
        set_sides(a,b,c,d);
    }
    Rectangle(Conditions calc, Point** pts, size_t& len) : calc(calc) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c, double d);
    void set_points(Point** points, size_t len) override;
    void get_sides(double& a, double& b, double& c, double& d) const;
    bool check_valid_rec(double a, double b, double c, double d);
    double perimeter();
    virtual double area();
    virtual double area(Point** coords, size_t len) override;
    virtual void show_conditions() override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions cnds) override;
    virtual ~Rectangle(){
        delete [] pts;
    }
};

class Triangle : public GeometricShape {
private:
    double a{0.0}, b{0.0}, c{0.0}, d{0.0};
    Conditions calc{none_cnd};
    Point* pts{nullptr};
    size_t length{0};
public:
    Triangle() = default;
    Triangle(Conditions calc, double a = 0.0, double b = 0.0, double c = 0.0){
        set_sides(a,b,c);
    }
    Triangle(Conditions calc, Point** pts, size_t& len) : calc(calc) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c);
    void set_points(Point** points, size_t len) override;
    void get_sides(double& a, double& b, double& c) const;
    bool check_valid_rec(double a, double b, double c);
    double perimeter();
    double area(Point** coords, size_t len) override;
    virtual void show_conditions() override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions cnds) override;
    virtual ~Triangle(){
        delete [] pts;
    }   
};

#endif
