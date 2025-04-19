#ifndef POINT_H
#define POINT_H

enum Shape{exit_sh = 0, square = 1, rectangle = 2, triangle = 3, none_sh = 4};
enum Calculations{exit_clc = 0, area = 1, perimeter = 2, none_clc = 3};
enum Conditions{exit_cnds = 0, sides = 1, coords = 2, side_perim = 3, none_cnd = 4};


class Point {
private:
    double x,y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    double get_x() const;
    double get_y() const;
    void set_pt(double x, double y);
};

#endif
