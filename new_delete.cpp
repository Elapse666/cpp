#include <iostream>   //编译预处理命令
#include <string.h>
#include <stdio.h>
using namespace std;    //使用命名空间


// 分配单个对象

int main(){
    int* p = new int(5);       // 分配一个整数
    cout << *p << endl; // 输出5
    cout << p << endl; // 输出p地址
    cout << "-------------------------------------------------------" << endl;

    // 分配数组
    int *arr = new int[10]; // 分配一个包含10个整数的数组
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;         // 初始化数组元素
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " "; // 输出数组元素
    }
    std::cout << std::endl;

}


