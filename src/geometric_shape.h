#ifndef _GEOMERTIC_H
#define _GEOMETRIC_H
#include <cstddef>

enum Shape{exit_sh = 0, square = 1, rectangle = 2, triangle = 3, none_sh = 4};
enum Calculations{exit_clc = 0, area = 1, perimeter = 2, none_clc = 3};
enum Conditions{exit_cnds = 0, sides = 1, coords = 2, none_cnd = 3};

class Point {
private:
    double x,y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    double get_x() const;
    double get_y() const;
    void set_pt(double x, double y);
};
/*
template<typename TypeShape> int input(TypeShape& sh, Calculations& clc, Conditions& cnds) {
    int num_conditions{0}, num_clc{0};
    sh.show_calc();
    std::cin >> num_clc;
    std::cout << "\n";
    clc = (num_clc == 1) ? Calculations::area : (num_clc == 2) ? Calculations::perimeter : (num_clc == 0) ? exit_clc : none_clc;

    if(clc == none_clc) { std::cout << "Ошибка ввода!\n"; return 0; }

    else if(clc == exit_clc) { return 0; }

    else if(clc == Calculations::area) {
        sh.show_conditions();
        std::cin >> num_conditions;
        std::cout << "\n";
        cnds = (num_conditions == 1) ? sides : (num_conditions == 2) ? coords : (num_conditions == 0) ? exit_cnds : none_cnd;
        sh.show_input_form(cnds);
    }

    else if(clc == Calculations::perimeter){
        sh.show_conditions();
        std::cin >> num_conditions;
        std::cout << "\n";
        cnds = (num_conditions == 1) ? sides : (num_conditions == 2) ? coords : (num_conditions == 0) ? exit_cnds : none_cnd;
        sh.show_input_form(cnds);
    }
    return 0;
}
*/
class GeometricShape {
public:
    virtual double perimeter() = 0;
    virtual double area(Point** points, size_t len) = 0;                     //calculation of the area of a shape based on coordinates
    virtual void set_points(Point** points, size_t len) = 0;
    static void show_menu();                                                 //display of the main menu
    virtual int available_calc(GeometricShape&, Calculations&, Conditions&); //selection of available calculations
    virtual void show_conditions() = 0;                                      //display of the selection form for conditions 
    virtual void show_calc() = 0;                                            //display of the selection form for available calculations
    virtual void show_input_form(Conditions cnds) = 0;                       //input form for calculation parameters
    virtual ~GeometricShape(){}
};

class Square : public GeometricShape {
private:
    double a{0.0},b{0.0},c{0.0},d{0.0};
    Conditions cnds{none_cnd};
    Point* pts{nullptr};
    size_t length{0};
public:
    Square() = default;
    Square(const Square&) = delete;
    Square& operator=(const Square&) = delete;
    Square(Conditions cnds, double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(cnds) {
            set_sides(a,b,c,d);
    }
    Square(Conditions cnds, Point** pts, size_t& len) : cnds(cnds) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c, double d);
    virtual void set_points(Point** points, size_t len) override;
    void get_sides(double& a, double& b, double& c, double& d) const;
    bool check_valid_sq(double a, double b, double c, double d);
    virtual double perimeter() override;
    Point* get_pts();
    virtual double area();                                                  //calculation of the area of a shape based on sides
    //virtual double area(double a);
    virtual double area(Point** points, size_t len) override;               //calculation of the area of a shape based on coordinates
    virtual int available_calc(GeometricShape&, Calculations&, Conditions&) override;
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
    Conditions cnds{none_cnd};
    //double radius_circumscribed_circle{0};
    Point* pts{nullptr};
    size_t length{0};
public:
    Rectangle() = default;
    Rectangle(const Rectangle&) = delete;
    Rectangle& operator=(const Rectangle&) = delete;
    Rectangle(Conditions cnds, double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(cnds){
        set_sides(a,b,c,d);
    }
    Rectangle(Conditions cnds, Point** pts, size_t& len) : cnds(cnds) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c, double d);
    virtual void set_points(Point** points, size_t len) override;
    void get_sides(double& a, double& b, double& c, double& d) const;
    bool check_valid_rec(double a, double b, double c, double d);
    virtual double perimeter() override;
    Point* get_pts();
    virtual double area();
    //virtual double area(double a, double raduis_circumscribed_circle);
    virtual double area(Point** coords, size_t len) override;
    virtual int available_calc(GeometricShape&, Calculations&, Conditions&) override;
    virtual void show_conditions() override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions cnds) override;
    virtual ~Rectangle(){
        delete [] pts;
    }
};

class Triangle : public GeometricShape {
private:
    double a{0.0}, b{0.0}, c{0.0};
    Conditions cnds{none_cnd};
    Point* pts{nullptr};
    size_t length{0};
public:
    Triangle() = default;
    Triangle(const Triangle&) = delete;
    Triangle& operator=(const Triangle&) = delete;
    Triangle(Conditions cnds, double a = 0.0, double b = 0.0, double c = 0.0) : cnds(cnds){
        set_sides(a,b,c);
    }
    Triangle(Conditions cnds, Point** pts, size_t& len) : cnds(cnds) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c);
    virtual void set_points(Point** points, size_t len) override;
    void get_sides(double& a, double& b, double& c) const;
    bool check_valid_tr(double a, double b, double c);
    Point* get_pts();
    virtual double perimeter() override;
    virtual double area(double a, double b, double c);
    virtual double area(Point** coords, size_t len) override;
    virtual int available_calc(GeometricShape&, Calculations&, Conditions&) override;
    virtual void show_conditions() override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions cnds) override;
    virtual ~Triangle() {
        delete [] pts;
    }  
};

#endif
