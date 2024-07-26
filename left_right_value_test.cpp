#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include<algorithm>
#include<queue>

using namespace std;

double fmin(int x, int y){
    if (x>y)    return y;
    else        return x;
}

namespace twotwo
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
 
		iterator end()
		{
			return _str + _size;
		}
 
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
 
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
 
		// s1.swap(s2)
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
 
		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
 
			string tmp(s._str);
			swap(tmp);
		}
 
		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			this->swap(s);
		}
 
		// 移动赋值 
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			this->swap(s);
 
			return *this;
		}
 
		
		// 赋值重载(如果用到移动赋值就只能用这个，下面的用不了)
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);
 
			return *this;
		}
 
		// 赋值重载(现代写法)
		//string& operator=(string s)
		//{
		//	cout << "string& operator=(string s) -- 深拷贝" << endl;
		//	swap(s);
 
		//	return *this;
		//}
 
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
 
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
 
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
 
				_capacity = n;
			}
		}
 
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
 
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
 
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
 
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};
 
	twotwo::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}
 
		twotwo::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;
 
			str += ('0' + x);
		}
 
		if (flag == false)
		{
			str += '-';
		}
 
		std::reverse(str.begin(), str.end());
		return str;
	}
}
 
void func1(twotwo::string s)
{}
 
void func2(twotwo::string& s)
{}
 
 
int main()
{
	//twotwo::to_string(1234);
	twotwo::string ret1;
	ret1 = twotwo::to_string(1234);
 
	return 0;
}

// int main(){
//     // 以下的a、p、*p、b都是左值
//     int a = 3;
//     int* p = &a;
//     const int b = 2;
//     double x = 1.3, y = 3.8;

//     // 以下几个是对上面右值的右值引用
//     int&& rr1 = 10;             // int&& rr1 必须是右值引用
//     double&& rr2 = x + y;
//     double&& rr3 = fmin(x, y);


//     int& ra = a;                // 非常量引用的初值必须是左值，不能为100那种
//     int&& rb = std::move(a);    // 右值引用可以引用move以后的左值

//     std::cout << ra << std::endl;   
//     std::cout << rb << std::endl;

//     std::cout << rr2 << std::endl;
//     std::cout << &rr2 << std::endl;
//     return 0;
// }