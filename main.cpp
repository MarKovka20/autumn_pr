//
//  main.cpp
//  3_sem
//
//  Created by Дарья Землянская on 19.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define VALUE 0 // макрос, не надо, ради всего святого

#include <cassert> // проверим
assert (0 == 1); // внутри уже есть макросы, он отлавливает ошибку, когда програмичт делает  фигню


assert (ptr!= nullptr);
*ptr = 42;

#define DEBAG

#if defined(DEBAG)
# define VALUE  0
#else
# define VALUE 1
#endif
/*
 макросы полезные: могут использоватся при отладке
 __FILE__ // путь до файла где мы находимся
 __LINE__ // линия где это написано
 __FUNCSIG__ // функция где это написано
 */




void print(const std::vector <int> &v); // объвление функции, тут можно не указывать называние аргуменат, то етсть v

long factorial(long l){
    return (l<1 ? l * factorial(l-1): 1); // условие ? если выполн : если не выполнено
}


void print(const std::vector <int> & v){
    for (auto i: v){
        std::cout << i << std::endl;
    }
}

void print(int x){
    std::cout << x << std::endl;
    
}

void g(int x, int y = 2, int z = 1){}; // int y = 1 - значения по умолчанию, нужно делать все аргументы по умолчанию начаиная с конца, БЕЗ ДЫРОК, можно и у всех трёх аргументов сделать это

//Перегрузка функции, функции можно вызвать пл одному имени
void h(double x){};
void h(int x){};
void h(char x){};
// если непонятно какую функцию выбрать, то будет ошибка

void do_print(void(*ptr)(int x), int x){
    (*ptr)(x);
}

void g(std::function<int(int)> lambda){  //БУДЕТ В ДОМАШКЕ
    
}

int main() {
    //лямбда функции // применять в алгоритме типа сорт для сравнения
    std::vector <int> v(10, 42);
    std::for_each(v.begin(), v.end(), [](auto x){
        std::cout << x << std::endl;
    });
    
    
    //лямблды можно сохранять вименнованых объектвъ
    std::function<int(int, int)> lambda = [](int x, int y){return x};  // два инта ибо он принимает 2 инта и возбращает один
    // можно написать через ссылку [](& int x, & int y){return x};
    
    void(*ptr)(int x); //int * ptr
    ptr  = &print;
    print(3);
    do_print(&print, 3);
  //  static int y = 1; // будет в статической памяти, создание переменной и это не будет снова вызыватся при повторном вызове функции, статические объекты живут вдо заверешнмея функции
   // std::vector <int> v(10, 0);
    print(v);
    
    
    // return EXIT_SUCCES //работа с макросами осуществ на этопе пердпроцессинга
    return 0;
}
