#include "GeometricShape.h"
#include <iostream>

void GeometricShape::show_menu() {
    std::cout << "Выберите геометрическую фигуру для расчетов:\n"
              << "  1. Квадрат\n"
              << "  2. Прямоугольник\n"
              << "  3. Треугольник\n\n"
              << "  0. Выход" << std::endl;
}

//selection of available calculations
int GeometricShape::available_calc(GeometricShape* sh){
    int num_conditions{0}, num_clc{0};
    Conditions cnds;
    Calculations clc;
    sh->show_calc();
    std::cin >> num_clc;
    std::cout << "\n";
    clc = (num_clc == 1) ? Calculations::area : (num_clc == 2)
                         ? Calculations::perimeter : (num_clc == 0)
                         ? exit_clc : none_clc;
    sh->set_clc(clc);
    if(clc == none_clc) { std::cout << "Ошибка ввода!\n"; return 0; }

    else if(clc == exit_clc) { return 0; }

    else if(clc == Calculations::area) {
        sh->show_conditions(clc);
        std::cin >> num_conditions;
        std::cout << "\n";
        cnds = (num_conditions == 1) ? sides 
             : (num_conditions == 2) ? coords 
             : (num_conditions == 3) ? side_perim 
             : (num_conditions == 0) ? exit_cnds 
             : none_cnd;

        sh->set_cnds(cnds);
        sh->show_input_form(cnds);
    }

    else if(clc == Calculations::perimeter){
        sh->show_conditions(clc);
        std::cin >> num_conditions;
        std::cout << "\n";
        cnds = (num_conditions == 1) ? sides 
             : (num_conditions == 2) ? coords 
             : (num_conditions == 0) ? exit_cnds 
             : none_cnd;

        sh->set_cnds(cnds);
        sh->show_input_form(cnds);
    }
    return 0;
}
