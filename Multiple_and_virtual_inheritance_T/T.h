#pragma once
#include <iostream>
#include <string>

template <typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base() : value1{}, value2{} {}
    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {}
    ~Base() {}

    void Set_Value1(T1 v1) {
        value1 = v1;
    }
    void Set_Value2(T2 v2) {
        value2 = v2;
    }

    T1 Get_Value1() {
        return value1;
    }
    T2 Get_Value2() {
        return value2;
    }

    void Show_Base() {
        std::cout << "Base\nvalue1: " << value1 << "\nvalue2: " << value2 << "\n";
    }
};




template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    Child() : Base<T1, T2>(), value3{}, value4{} {}
    Child(T1 v1, T2 v2, T3 v3, T4 v4)
        : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {}
    ~Child(){}
    void Set_Value3(T3 v3) {
        value3 = v3;
    }
    void Set_Value4(T4 v4) {
        value4 = v4;
    }

    T3 Get_Value3() {
        return value3;
    }
    T4 Get_Value4() {
        return value4;
    }

    void Show_Child() {
        this->Show_Base();
        std::cout << "\nChild\nvalue3: " << value3 << "\nvalue4: " << value4 << "\n";
    }

};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
private:
    T5 value5;
    T6 value6;

public:
    Child2() : Child<T1, T2, T3, T4>(), value5{}, value6{} {}
    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
        : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}

    void Set_Value5(T5 v5) {
        value5 = v5;
    }
    void Set_Value6(T6 v6) {
        value6 = v6;
    }

    T5 Get_Value5() {
        return value5;
    }
    T6 Get_Value6() {
        return value6;
    }

    void Show_Child2() {
        this->Show_Child();
        std::cout << "\nChild2\nvalue5: " << value5 << "\nvalue6: " << value6 << "\n";
    }

};


