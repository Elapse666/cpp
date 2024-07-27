#include<iostream>

using namespace std;

class Base {
public:
    int x;
};

class Derived : public Base {
public:
    int y;
};

int main(){
    Base* base_ptr = new Derived();
    Derived * derived_ptr = static_cast<Derived*>(base_ptr);        // 不安全

    Derived* derived_ptr = new Derived();
    Base* base_ptr = static_cast<Base*>(derived_ptr);               // 安全

    return 0;
}