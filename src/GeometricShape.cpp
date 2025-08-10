#include "GeometricShape.h"
#include <iostream>
#include <sstream>

void GeometricShape::showMenu() {
    std::cout << "Выберите геометрическую фигуру для расчетов:\n"
              << "  1. Квадрат\n"
              << "  2. Прямоугольник\n"
              << "  3. Треугольник\n\n"
              << "  0. Выход" << std::endl;
}

//selection of available calculations
int GeometricShape::availableCalculations(GeometricShape* sh){
    int num_conditions{0}, num_clc{0};
    Conditions cnds;
    Calculations clc;
    sh->showCalculations();
    std::cin >> num_clc;
    std::cout << "\n";
    clc = (num_clc == 1) ? Calculations::area 
        : (num_clc == 2) ? Calculations::perimeter 
        : (num_clc == 0) ? exit_clc 
        : none_clc;

    sh->setCalculations(clc);
    if(clc == none_clc) { std::cout << "Ошибка ввода!\n"; return 0; }

    else if(clc == exit_clc) { return 0; }

    else if(clc == Calculations::area) {
        sh->showConditions(clc);
        std::cin >> num_conditions;
        std::cout << "\n";
        cnds = (num_conditions == 1) ? sides 
             : (num_conditions == 2) ? coords 
             : (num_conditions == 3) ? side_perim 
             : (num_conditions == 0) ? exit_cnds 
             : none_cnd;

        sh->setConditions(cnds);
        sh->showInputForm(cnds);
    }

    else if(clc == Calculations::perimeter){
        sh->showConditions(clc);
        std::cin >> num_conditions;
        std::cout << "\n";
        cnds = (num_conditions == 1) ? sides 
             : (num_conditions == 2 && (sh->getShape() == square || sh->getShape() == triangle)) ? coords 
             : (num_conditions == 0) ? exit_cnds 
             : none_cnd;

        sh->setConditions(cnds);
        sh->showInputForm(cnds);
    }
    return 0;
}

void GeometricShape::replaceCharacter(std::string& input){
	size_t string_size = input.size();
	for(size_t i = 0; i < string_size-1; ++i){
		if(input[i] == ','){
			if(input[i+1] == ' '){
				input[i] = input[i+1];
			} else {
				input[i] = '.';
			}
		}
	}
}

void GeometricShape::inputCoords(std::vector<Point>& pts){
	double x{0.0};
	double y{0.0};
	std::string str;
	std::cin.ignore();
	std::getline(std::cin, str);
	if(str.empty()){ return; }
	replaceCharacter(str);

	std::stringstream s(str);

	for(size_t i = 0; i < pts.capacity(); ++i){
		if(s >> x && s >> y){
			pts.push_back(Point(x,y));
		} else {
			pts.clear();
			break;
		}
	}
}
