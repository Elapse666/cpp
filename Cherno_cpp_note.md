## Cherno C++ 栈和堆 stack and heap
```cpp

struct Vector3{
    float x, y, z;

    Vector
}

int main(){
    int value = 5;              // stack
    int array[5];               // 对于数组
    array[0] = 1;                               // 复制代码至下一行  alt + shift + 上（下） 
    array[1] = 2;                               // 选中多行代码 ，在首首行 ctrl + alt + 上（下） 可以用于添加同一个前缀
    array[2] = 3;                               // 复制多行代码 ctrl + shift + 上（下）
    array[3] = 4;
    array[4] = 5;
    Vector3 vector;

    int* hvalue = new int;      // heap
    *hvalue = 5;
    int* harray = new int[5];
    harray[0] = 1;                               // 复制代码至下一行  alt + shift + 上（下） 
    harray[1] = 2;
    harray[2] = 3;
    harray[3] = 4;
    harray[4] = 5;
    Vector3* hvector = new Vector();
}


```