//  Created by Дарья Землянская on 13.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <stdio.h>
#include <vector>
#include <iostream>

int main() {
    std::cout << "The vector consists of ";
    std::size_t n;
    std::cin >> n;
    
    std::vector <int> v;
    std::cout << "Elements: ";
    
    for (int i = 0; i < n; i++){
        double a;
        std::cin >> a;
        v.push_back(a);
    }
    
    std::sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Search for ";
    double s;
    std::cin >> s;
    
    std::size_t l = 0;
    std::size_t r = n-1;
    while (l <= r){
        std::size_t m = (l+r)/2;
           if (v[m] < s){
               l = m + 1;
           } else if (v[m] > s){
               r = m - 1;
           } else{
               std::cout << "Position: " << m + 1 << std::endl;
               return 0;
           }
    }
    std::cout << "The array does't contain this value." << std::endl;
    return 0;
}
