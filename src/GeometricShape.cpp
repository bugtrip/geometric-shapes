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
    int numCondition{0}, numCalculation{0};
    Conditions cnds;
    Calculations clc;
    sh->showCalculations();
    std::cin >> numCalculation;
    std::cout << "\n";
    clc = (numCalculation == 1) ? Calculations::area 
        : (numCalculation == 2) ? Calculations::perimeter 
        : (numCalculation == 0) ? exit_clc 
        : none_clc;

    sh->setCalculations(clc);
    if(clc == none_clc) { std::cout << "Ошибка ввода!\n"; return 0; }

    else if(clc == exit_clc) { return 0; }

    else if(clc == Calculations::area) {
        sh->showConditions(clc);
        std::cin >> numCondition;
        std::cout << "\n";
        cnds = (numCondition == 1) ? sides 
             : (numCondition == 2) ? coords 
             : (numCondition == 3) ? side_perim 
             : (numCondition == 0) ? exit_cnds 
             : none_cnd;

        sh->setConditions(cnds);
        sh->showInputForm(cnds);
    }

    else if(clc == Calculations::perimeter){
        sh->showConditions(clc);
        std::cin >> numCondition;
        std::cout << "\n";
        cnds = (numCondition == 1) ? sides 
             : (numCondition == 2 && (sh->getShape() == square || sh->getShape() == triangle)) ? coords 
             : (numCondition == 0) ? exit_cnds 
             : none_cnd;

        sh->setConditions(cnds);
        sh->showInputForm(cnds);
    }
    return 0;
}

void GeometricShape::replaceCharacter(std::string& input){
	size_t stringSize = input.size();
	for(size_t i = 0; i < stringSize-1; ++i){
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
