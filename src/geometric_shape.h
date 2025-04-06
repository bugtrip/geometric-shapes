#ifndef _GEOMERTIC_H
#define _GEOMETRIC_H
#include <cstddef>

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

class GeometricShape {
public:
    virtual double perimeter() = 0;
    virtual double area(Point** points, size_t len) = 0;                    //calculation of the area of a shape based on coordinates
    virtual void set_points(Point** points, size_t len) = 0;
    virtual void set_cnds(Conditions) = 0;
    virtual void set_clc(Calculations) = 0;
    static void show_menu();                                                //display of the main menu
    virtual int available_calc(GeometricShape&);                            //selection of available calculations
    virtual void show_conditions(Calculations& clc) = 0;                    //display of the selection form for conditions 
    virtual void show_calc() = 0;                                           //display of the selection form for available calculations
    virtual void show_input_form(Conditions& cnds) = 0;                     //input form for calculation parameters
    virtual ~GeometricShape(){}
};

class Square : public GeometricShape {
private:
    double a{0.0},b{0.0},c{0.0},d{0.0};
    Conditions cnds{none_cnd};
    Calculations clc{none_clc};
    Point* pts{nullptr};
    size_t length{0};
public:
    Square(const Square&) = delete;
    Square& operator=(const Square&) = delete;
    Square(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(none_cnd), clc(none_clc) {
            set_sides(a,b,c,d);
    }
    Square(Point** pts, size_t& len) : cnds(none_cnd), clc(none_clc) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c, double d);
    void set_sides(double);
    virtual void set_points(Point** points, size_t len) override;
    void get_sides(double& a, double& b, double& c, double& d) const;
    void set_cnds(Conditions) override;
    void set_clc(Calculations) override;
    Conditions get_cnds() const;
    Calculations get_clc() const;
    bool check_valid_sq(double a, double b, double c, double d);
    virtual double perimeter() override;
    Point* get_pts();
    virtual double area();                                                  //calculation of the area of a shape based on sides
    //virtual double area(double a);
    virtual double area(Point** points, size_t len) override;               //calculation of the area of a shape based on coordinates
    virtual int available_calc(GeometricShape&) override;
    virtual void show_conditions(Calculations& clc) override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions& cnds) override;
    virtual ~Square(){
        delete [] pts;
    }
};

class Rectangle : public GeometricShape {
private:
    double a{0.0}, b{0.0}, c{0.0}, d{0.0};
    Conditions cnds{none_cnd};
    Calculations clc{none_clc};
    Point* pts{nullptr};
    size_t length{0};
public:
    Rectangle(const Rectangle&) = delete;
    Rectangle& operator=(const Rectangle&) = delete;
    Rectangle(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0) : cnds(none_cnd), clc(none_clc) {
        set_sides(a,b,c,d);
    }
    Rectangle(Point** pts, size_t& len) : cnds(none_cnd), clc(none_clc) {
       set_points(pts, len);
    }
    void set_sides(double a, double b, double c, double d);
    virtual void set_points(Point** points, size_t len) override;
    void get_sides(double& a, double& b, double& c, double& d) const;
    void set_cnds(Conditions) override;
    void set_clc(Calculations) override;
    Conditions get_cnds() const;
    Calculations get_clc() const;
    bool check_valid_rec(double a, double b, double c, double d);
    virtual double perimeter() override;
    Point* get_pts();
    virtual double area();
    virtual double area(double perim, double a);
    //virtual double area(double a, double raduis_circumscribed_circle);
    virtual double area(Point** coords, size_t len) override;
    virtual int available_calc(GeometricShape&) override;
    virtual void show_conditions(Calculations& clc) override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions& cnds) override;
    virtual ~Rectangle(){
        delete [] pts;
    }
};

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
    virtual double perimeter() override;
    virtual double area(double a, double b, double c);
    virtual double area(Point** coords, size_t len) override;
    virtual int available_calc(GeometricShape&) override;
    virtual void show_conditions(Calculations& clc) override;
    virtual void show_calc() override;
    virtual void show_input_form(Conditions& cnds) override;
    virtual ~Triangle() {
        delete [] pts;
    }  
};

/*
template<typename TypeShape> int available_calc(TypeShape& sh, Calculations& clc, Conditions& cnds) {
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

#endif
