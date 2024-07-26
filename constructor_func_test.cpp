#include <iostream>
using namespace std;

class Person {
private:
    int age;

public:
    // 默认构造函数
    Person() {
        age = 0;
    }
    
    // 初始化构造函数
    Person(int ageVal) {
        age = ageVal;
    }

    // 拷贝构造函数         // 还可以使用 = 完成拷贝
    Person(const Person& other) {
        age = other.age;
    }

    // 移动构造函数
    Person(Person&& other) noexcept {
        age = other.age;
        other.age = 0;
    }

    // 转换构造函数
    Person(double ageVal) {
        age = static_cast<int>(ageVal);
    }

    void print() {
        cout << "Age: " << age << endl;
    }
};

class Date {
public:
	Date(int year = 2022, int month = 8, int day = 20)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year = 2022, int month = 8, int day = 20)" << endl;
	}

	// Date(const Date& d)
	// 	:_year(d._year)
	// 	, _month(d._month)
	// 	, _day(d._day)
	// {
	// 	cout << "Date(const Date& d)" << endl;
	// }

    void print(){
        // cout << "Date(int year = 2022, int month = 8, int day = 20) by print" << endl;
        cout << "Date year = " << _year << " month = " << _month << " day = " << _day << " by print" << endl;
    }

private:
	int _year;
	int _month;
	int _day;
};

class New_Person{
public:
    New_Person(int year = 2022, int month = 8, int day = 20)
        :new_year(year)
        ,new_month(month)
		,new_day(day)
    {
        
    }

    // 移动构造函数和拷贝构造函数会被默认生成

    void print(){
        cout << "Date year = " << new_year << " month = " << new_month << " day = " << new_day << " by print" << endl;
    }
private:
    int new_year;
	int new_month;
	int new_day;
};

int main() {
    // 使用默认构造函数创建对象
    Person p1;
    p1.print();  // 输出：Age: 0

    // 使用带参数构造函数创建对象
    Person p2(25);
    p2.print();  // 输出：Age: 25

    // 使用拷贝构造函数创建对象
    Person p3(p2);
    p3.print();  // 输出：Age: 25

    // 使用移动构造函数创建对象
    Person p4(move(p3));
    p4.print();  // 输出：Age: 25
    p3.print();  // 输出：Age: 0

    // 使用转换构造函数创建对象
    Person p5(20.5);
    p5.print();  // 输出：Age: 20

    Date d1;
    Date d2(2024, 7, 25);
    Date d3 = d1;
    d1.print();
    d2.print();
    d3.print();

    cout << "---------------------------------------------------------------" << endl;
    New_Person n1;
    New_Person n2(2024, 7, 26);
    New_Person n3 = n1;
    New_Person n4(n1);          // n3,n4都为拷贝构造函数
    New_Person n5(move(n1));

    n1.print();
    n2.print();
    // n3.print();
    n4.print();
    n5.print();
    n1.print();
    return 0;
}