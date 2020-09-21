//  Created by Дарья Землянская on 21.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <functional>



//1
void f1(const int& x){
    std::cout << "fun 1";
};
void f1(int x){
    std::cout << "fun 2";
};

//2
void f2(char x){
    std::cout << "fun 1";
};
void f2(char x, int y = 2){
    std::cout << "fun 2";
};

//3
void f3(char x){
    std::cout << "fun 1";
};
void f3(unsigned char){
    std::cout << "fun 2";
};

//4
void f4(float x){
    std::cout << "fun 1";
};
void f4(double x){
    std::cout << "fun 2";
};

//5
void f5(int x, int y){
    std::cout << "fun 1";
};
void f5(int x, int &y){
    std::cout << "fun 2";
};

int main() {
    int m = 3;
    int g = 2;
    double l = 2.3;
    char k = 3;
    
    //f1(m);
    //f2(k);
    //f3(70);
    //f4(5);
    //f5(m, g);
    
    return 0;
}
