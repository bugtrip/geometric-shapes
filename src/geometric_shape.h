#ifndef _GEOMERTIC_H
#define _GEOMETRIC_H
#include <cstddef>

enum Shape{square = 1, rectangle = 2};
enum Calculations{sides, coords};

class Point {
private:
    double x,y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    double get_x();
    double get_y();
};

class Square {
private:
    double a{0.0},b{0.0},c{0.0},d{0.0};
    Calculations calc;
    size_t length{0};
public:
    Square(Calculations calc, double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : calc(calc) {
            set_side(a,b,c,d);
    }
    void set_side(double a, double b, double c, double d);
    void get_side(double& a, double& b, double& c, double& d) const;
    bool check_valid_sq(double a, double b, double c, double d);
    double perimeter();
    ~Square(){
        delete [] pts;
    }
};

#endif
