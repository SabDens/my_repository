#include <iostream>
#include "T.h"


int main() {
    Base<std::string, char> obj("Hi",'D');
    obj.Show_Base();


    Child<std::string, char, int, double> obj_c("Hi", 'D', 17, 17.5);
    obj_c.Show_Child();


    Child2<std::string, char, int, double,bool , float  > obj_c2("Hi", 'D', 17, 17.5, true, 144);
    obj_c2.Show_Child2();

    return 0;
}