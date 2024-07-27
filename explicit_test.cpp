#include<iostream>

using namespace std;

class Date{
public:
	Date(int year)
		:_year(year)
	{

	}
    void print(){
        cout << "Date year = " << _year << " month = " << _month << " day = " << _day << " by Date print" << endl;
    }

private:
	int _year;
	int _month = 3;
	int _day = 31;
};

class Date_many{
public:
	Date_many(int year, int month, int day)     // 这种情况， 一般可以用
		:_year(year)
        ,_month(month)
        ,_day(day)
	{

	}
    void print(){
        cout << "Date year = " << _year << " month = " << _month << " day = " << _day << " by Date_many print" << endl;
    }

private:
	int _year;
	int _month;
	int _day;
};

class Date_explicit{
public:
	explicit Date_explicit(int year)
		:_year(year)
	{

	}
    void print(){
        cout << "Date year = " << _year << " month = " << _month << " day = " << _day << " by Date_explicit print" << endl;
    }

private:
	int _year;
	int _month = 3;
	int _day = 31;
};

void func1(Date obj);
void func2(Date_explicit obj);

int main(){
    Date d1(2022);
    Date d2 = 2023;         // 在这里会调用构造函数， 构造一个临时变量(假设其为d_temporary），再将其拷贝构造给d2, 这就浪费了时间， 所以引入了explicit关键字
    // 故 其等价于 -----> Date d_temporary = 2023; Date d2 = d_temporary;(or  Date d2(d_temporary); )
    d1.print();
    d2.print();

    Date_many d3 = {2023, 2, 3};        // 或者 Date_many d3(2023, 2, 3);
    d3.print();

    Date_explicit d4(2022);
    // Date_explicit d5 = 2022;

    Date_explicit d6 = d4;
    d6.print();

    Date_explicit d7(d4);
    d7.print();

    func1(2022);                            // 不报错， 允许隐式转换
    func1(Date(2022));                      // 允许显式转换
    // func2(2022);                         // 报错， 不允许隐式转换
    func2(Date_explicit(2022));             // 允许显式转换
    func2(static_cast<Date_explicit>(2022));// 强制类型转换没问题    
    return 0;
}