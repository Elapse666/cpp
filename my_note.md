## 左值应用的使用场景和实际意义

# 实际意义：比如在函数的传参方面， 传值传参和传值返回都会产生拷贝，有的甚至是深拷贝，代价很大。而左值引用的实际意义在于做参数和做返回值都可以减少拷贝，从而提高效率。例如：

``` cpp
// 1.左值引用做参数
void func1(string s)    // 深拷贝，代价大
{...}

void func2(const string& s) // 左值引用
{...}


int main()
{
	string s1("Hello World!");
	func1(s1);  // 由于是传值传参且做的是深拷贝，代价较大
	func2(s1);  // 左值引用做参数减少了拷贝，提高了效率
	
	return 0;
}

```

# 左值引用短板
但当对象（对象是函数内的局部对象）出了函数作用域以后不存在时，就不可以使用左值引用返回了
``` cpp
string operator+(const string& s, char ch)
{
	string ret(s);
	ret.push_back(ch);
	return ret;
}

// 拿现在这个函数来举例：ret是函数内的局部对象，出了函数作用域后会被析构，即被销毁了
// 若此时再返回它的别名（左值引用），也就是再拿这个对象来用，就会出问题
```

## 右值引用
# 为解决左值引用的短板，C++11标准增加看右值引用和移动语义

# 1.移动语义（Move semantics）
``` cpp
// 概念： 转移参数右值的资源来构造自己
// 这是一个模拟string类的实现的移动构造
string(string&& s)
	:_str(nullptr)
	, _size(0)
	, _capacity(0)
{
	swap(s);
}
// 总的来说，如果这两个函数都有在类内定义的话，在构造对象时：

// 若是左值做参数，那么就会调用拷贝构造函数，做一次拷贝（如果是像 string 这样的在堆空间上存在资源的类，那么每调用一次拷贝构造就会做一次深拷贝）。
// 若是右值做参数，那么就会调用移动构造，而调用移动构造就会减少拷贝（如果是像 string 这样的在堆空间上存在资源的类，那么每调用一次移动构造就会少做一次深拷贝）。

// 调用该函数后，需要传值返回这种占用很多资源的自定义类型，
// 在 C++98 中，没有移动构造，拷贝构造做深拷贝，花费的代价很大；
// 在 C++11 中，直接移动构造，转移 m 的资源给 ret ，提高了效率。

在加入移动构造前， 同样是 MyLib::string ret = MyLib::to_string(1234); 会使用拷贝构造，作为深拷贝，花费的代价很大
// 在 to_string 函数栈帧销毁前，由于局部对象 str 是左值（可以对它取地址），所以用 str 拷贝构造出临时对象返回到函数调用处，to_string 函数栈帧销毁后，由于临时对象是右值，所以用临时对象移动构造出 ret 。
// 但现在的编译器一般都会进行优化：因为临时对象有 ret 来接收，先拷贝构造出临时对象再用它移动构造出 ret ，临时对象好像没必要产生一样，不如省略掉。既然 str 是 to_string 函数栈帧的局部对象，最后还是要销毁，不如将 str 视为右值，直接转移 str 的资源用来构造 ret ，也就是直接用 str 移动构造出 ret 。
// 原文链接：https://blog.csdn.net/m0_59938453/article/details/125858335
其中
string to_string(int value){
    string str;
    while(value){
        int val = value % 10;
        str += ('0' + val)
        value /= 10
    }
    reverse(str.begin(), str.end());

    return str;
}
```
# 2.移动赋值
```cpp
// 这是一个模拟string类的实现的移动赋值
string& operator=(string&& s)
{
	swap(s);

	return *this;
}
// 拷贝赋值函数和移动赋值函数都是赋值运算符重载函数的重载函数，所不同的是：

// 拷贝赋值函数的参数是 const左值引用，接收左值或右值；
// 移动赋值函数的参数是右值引用，接收右值或被 move 的左值。
// 注：当传来的参数是右值时，虽然拷贝赋值函数可以接收，但是编译器会认为移动赋值函数更加匹配，就会调用移动赋值函数。

string s("11111111111111111");
string s1("22222222222222222");
s1 = s;  // s是左值，所以调用拷贝赋值函数

string s2("333333333333333333");
s2 = std::move(s);  // s被move后变为右值，所以调用移动赋值函数，s的资源会被转移用来赋给s2
// 要注意的是，move一般是不这样用的，因为s的资源被转走了

```
# 2.右值引用的使用场景  std::vector::push_back


# 当类的成员是基本类型时，使用移动构造函数相当于拷贝构造函数
# 因为当类的成员是基本类型（如 int、double、char 等）时，使用移动构造函数和拷贝构造函数在效果上没有明显区别。这是因为基本类型的成员在拷贝和移动时都是按值复制，没有复杂的资源管理需求。所以，当出现一个 包含动态分配资源（例如堆内存）的类 的情况下， 才能利用默认的构造函数进行资源转移




## explicit 关键字  作用：禁止类对象之间的隐式转换、禁止隐式调用拷贝构造函数。
# 个人认为， 这是为了避免一种情况导致的拷贝构造导致的资源浪费
``` cpp
// 例如有这么一个类 Date
class Date{
public:
	Date(int year)
		:_year(year)
	{

	}
private:
	int _year;
	int _month = 3;
	int _day = 31;
}

class Date_explicit{
public:
	explicit Date_explicit(int year)
		:_year(year)
	{

	}
private:
	int _year;
	int _month = 3;
	int _day = 31;
}

    Date d1(2022);
    Date d2 = 2023;         // 在这里会调用构造函数， 构造一个临时变量(假设其为d_temporary），再将其拷贝构造给d2, 这就浪费了时间， 所以引入了explicit关键字
    // 故 其等价于 -----> Date d_temporary = 2023; Date d2 = d_temporary;(or  Date d2(d_temporary); )
    Date_explicit d4(2022);
    Date_explicit d5 = 2022;		// 这里报错	
	Date_explicit d5(d4);	Date_explicit d5 = d4;		// 这几个没问题
```

## 关键字mutable 修改常对象或者常函数里面的参数
```cpp
class person
{
    int m_A;
    mutable int m_B;//特殊变量 在常函数里值也可以被修改
public:
    void add() const//在函数里不可修改this指针指向的值 常量指针
    {
        m_A = 10;//错误  不可修改值，this已经被修饰为常量指针
        m_B = 20;//正确
    }
};

//示例2
class person
{
public:
    int m_A;
    mutable int m_B;//特殊变量 在常函数里值也可以被修改
};

int main()
{
    const person p = person();//修饰常对象 不可修改类成员的值
    p.m_A = 10;//错误，被修饰了指针常量
    p.m_B = 200;//正确，特殊变量，修饰了mutable
}
```

## 强制转换 static_cast
```cpp
class Base {
public:
    int x;
};

class Derived : public Base {
public:
    int y;
};

//下行转换（不安全） 从**基类指针**转换为**派生类指针**。由于没有动态类型检查，所以是不安全的。
Base* base_ptr = new Derived();
Derived* derived_ptr = static_cast<Derived*>(base_ptr); // 将基类指针base_ptr转换为派生类指针derived_ptr
// 上行转换 从**派生类指针**转换为**基类指针**。
Derived* derivedPtr = new Derived();
Base* basePtr = static_cast<Base*>(derivedPtr);

```
