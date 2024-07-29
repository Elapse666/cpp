#include <iostream>
#include <string>

struct Vector3{
    float x, y, z;

    Vector3()
        :x(10), y(11), z(12)    
    {}
};

int main(){
    int value = 5;              // stack
    int array[5];               // 对于数组
    array[0] = 1;                               // 复制代码至下一行  alt + shift + 上（下） 
    array[1] = 2;                               // 选中多行代码 ，在首首行 ctrl + alt + 上（下） 可以用于添加同一个前缀
    array[2] = 3;                               // 复制多行代码 ctrl + shift + 上（下）
    array[3] = 4;
    array[4] = 5;
    Vector3 vector;             // 以上栈的内容在作用域结束后， 会被弹出

    /**
     *  什么时候使用堆？ 
     *  答：当生命周期比函数的作用域更长， 或者比你在处理的作用域更长， 或者特别需要更多的数据（比如想加载一个纹理， 有50M那么大， 这些东西都不适合在栈上做分配
     *      在调用new的时候， 需要检查空闲列表， 请求内存， 然后记录这些， 这是堆相对于栈慢的原因
     */

    int* hvalue = new int;      // heap
    *hvalue = 5;
    int* harray = new int[5];
    harray[0] = 1;                               // 复制代码至下一行  alt + shift + 上（下） 
    harray[1] = 2;
    harray[2] = 3;
    harray[3] = 4;
    harray[4] = 5;
    Vector3* hvector = new Vector3();

    delete hvalue;              // 如果想要不加这一步的话，需要使用智能指针 make_unique make_shared, 这些会帮我们调用new， 然后帮我们释放
    delete[] harray;
    delete hvector;
}