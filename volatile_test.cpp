#include<iostream>
 
using namespace std;
 
int main(void)
{
    volatile const int a = 7;       // const int a = 7
    int *p = (int*)&a;
    *p = 8;
    cout << "a = " << a << endl;
    return 0;
}

