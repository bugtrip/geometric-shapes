#include <iostream>
#include <iomanip>
#include "geometric_shape.h"

int main(){
    int num_shape{0}; 
    GeometricShape::show_menu();
    
    size_t count_pt{4};
    Point* pts[count_pt] = {
        new Point(1.9, 5.8),
        new Point(2.9, 6.8),
        new Point(3.9, 7.8),
        new Point(4.9, 8.8)
    };
    
       for(size_t i = 0; i < count_pt; ++i){
        delete pts[i];
    }
    
    return 0;
}
