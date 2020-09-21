//  Created by Дарья Землянская on 20.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>


void Print(std::vector<int> array){
    for (int a = 0; a < array.size(); a++) {
        std::cout << array[a] << " ";
    }
}

int main() {
    int n, a;
    std::vector<int> array;
    std::cout << "Size: ";
    std::cin >> n;
    std::cout << "Vector: ";
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        array.push_back(a);
    }
    
    std::cout << "Sort up: ";
    sort (array.begin(), array.end(), [](const int& a, const int& b){return (a < b);});
    Print(array);
    std::cout << std::endl;
    std::cout << "Sort down: ";
    sort (array.begin(), array.end(), [](const int& a, const int& b){return (a > b);});
    Print(array);
    std::cout << std::endl;
    
    return 0;
}
