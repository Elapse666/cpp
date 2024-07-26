#include <iostream>   //编译预处理命令

using namespace std;

int* p3(int a) {
    // 表示函数声明，函数名是p，参数是int类型的，返回值是int *类型的
    int *ptr = new int(a); // 动态分配内存并赋值
    return ptr;
}

int square(int x) {
    return x * x;
}

// 定义一个接受两个int参数并返回一个int的函数
int add(int a, int b) {
    return a + b;
}

double multiply(int a, double b) {
    return a * b;
}

int main(){
    int a[20] = {10, 20};
    int *p = a;         
    cout << *++p << endl;
    cout << p << endl;
    cout << a << endl;
    cout << &a << endl;

    int a1 = 10, b1 = 20, c1 = 30;
    int *p1[10];    // 指针数组，每个元素都是一个指向int的指针， p1[0]、p1[1]、... 、p1[9] 都是指针,  都可以指向各自的地址（多个

    p1[0] = &a1;    
    p1[1] = &b1;
    p1[2] = &c1;

    std::cout << *p1[0] << std::endl; // 输出10
    std::cout << *p1[1] << std::endl; // 输出20
    std::cout << *p1[2] << std::endl; // 输出30
    std::cout << "-------------------------------------------" << std::endl; // 分割符号

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int (*p2)[10] = &arr;  // 括起来了表示重点在指针上，指向包含10个int的数组的指针， 其只能指向一个相同大小的数组（单个

    for (int i = 0; i < 10; ++i) {
        std::cout << (*p2)[i] << " ";  // 输出数组中的元素
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------" << std::endl; // 分割符号

    int *ptr = p3(5);       // p3是一个地址 表示函数声明，函数名是p，参数是int类型的，返回值是int *类型的
    std::cout << *ptr << std::endl; // 输出5    
    delete ptr;  // 记得释放动态分配的内存
    std::cout << "-------------------------------------------" << std::endl; // 分割符号

    // 表示函数指针，强调是指针，该指针指向的函数的参数是int类型的，并且返回值是int类型的
    int (*p4)(int) = square;  // 函数指针指向square函数， 
    std::cout << p4(5) << std::endl; // 输出25
    std::cout << "-------------------------------------------" << std::endl; // 分割符号

    // 声明一个指向接受两个int参数并返回一个int的函数的函数指针
    int (*p5)(int, int) = add;
    std::cout << "The sum is: " << p5(3, 4) << std::endl; // 输出7
    std::cout << "-------------------------------------------" << std::endl; // 分割符号

    double (*p6)(int, double) = multiply;
    std::cout << "The product is: " << p6(3, 4.5) << std::endl; // 输出13.5
    std::cout << "-------------------------------------------" << std::endl; // 分割符号

    int b = 100;
    int c = 200;
    const int *p7 = &b;         // 常量指针 *p不变
    int * const p8 = &b;        // 指针常量 p不变
    cout << *p7 << endl;
    p7 = &c;
    *p8 = c;
    cout << *p7 << endl;
    cout << *p8 << endl;
    return 0;
}