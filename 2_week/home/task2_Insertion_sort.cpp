
//  Created by Дарья Землянская on 13.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

void Print_vector(std::vector<double>& v){
    std::cout << "Sorted vector: ";
    for (const auto& i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "The vector consists of ";
    std::size_t n;
    std::cin >> n;
    
    std::vector<double> v;
    
    std::cout << "Elements: ";
    for (int i = 0; i < n; i++){
        double k;
        std::cin >> k;
        v.push_back(k);
    }
    
    for(int i = 1; i < n; i++){
        for(int j = i; (j > 0) && (v[j-1] > v[j]); j--){
            std::swap(v[j-1],v[j]);
        }
    }
    
    Print_vector(v);
    return 0;
}
