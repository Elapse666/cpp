#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include <iostream>
using namespace std;

int main()
{
    const int a = 10;
    cout << "&a = " << &a << endl; // 0x7fffffffdf24
    const int *ptr = &a;
    cout << "*ptr = " << *ptr << endl; // *ptr = 10
    cout << "ptr = " << ptr << endl;   // ptr = 0x7fffffffdf24
    // *ptr2 = 20;  //错误
    int *ptr2 = const_cast<int *>(ptr);
    cout << "ptr2 = " << ptr2 << endl; // ptr2 = 0x7fffffffdf24
    *ptr2 = 20;
    cout << "a = " << a << endl;         // a = 10
    cout << "*ptr = " << *ptr << endl;   // *ptr = 20
    cout << "*ptr2 = " << *ptr2 << endl; // *ptr2 = 20
    cout << "&a = " << &a << endl;       //&a = 0x7fffffffdf24
    cout << "ptr = " << ptr << endl;   // ptr = 0x7fffffffdf24
    cout << "ptr2 = " << ptr2 << endl; // ptr2 = 0x7fffffffdf24
    return 0;
}
