//  Created by Дарья Землянская on 21.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
double calculate(double x, double y, const std::function<double(double, double)> t){
    return t(x, y);
}

int main() {
    double x1 = 4.6;
    double x2 = 6.2;
    
    std::vector <std::function<double(double, double)>> v = {
        ([](double x1, double x2){std::cout << "x1+x2:" << " "; return (x1+x2);}),
        ([](double x1, double x2){std::cout << "x1-x2:" << " "; return (x1-x2);}),
        ([](double x1, double x2){std::cout << "x2-x1:" << " "; return (x2-x1);}),
        ([](double x1, double x2){std::cout << "x1*x2:" << " "; return (x1*x2);}),
        ([](double x1, double x2){std::cout << "x1/x2:" << " "; return (x1/x2);}),
        ([](double x1, double x2){std::cout << "x2/x1:" << " "; return (x2/x1);})
        
    };
    
    for (int i = 0; i < v.size(); ++i){
        double a = calculate(x1, x2, v[i]);
        std::cout << a << std::endl;
    }
    return 0;
}
