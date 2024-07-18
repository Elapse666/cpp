#include <iostream>   //编译预处理命令
#include <memory>
using namespace std;    //使用命名空间

class A{
	public:
	void func1(){}
	void func2(){}
	virtual void vfunc(){}
	virtual ~A(){}
	virtual void func(int val = 1){
		cout << "A->" << val << endl;
	}
	virtual void test(){
		func();
	}
};

class B:public A
{
public:
	void func(int val = 0){
		cout << "A->" << val << endl;
	}
};



int add(int a, int b);       //函数原型说明

struct ListNode
{
	/* data */
	shared_ptr<ListNode> _pre;
	shared_ptr<ListNode> _next;
};


int main()  //主函数
{
	cout << "hello world" << endl;

	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	node1->_next = node2;
	node2->_pre = node1;
	cout << "node1 count: " << node1.use_count() << endl;
	cout << "node2 count: " << node2.use_count() << endl; 

	return 0;
}

int add(int a, int b) //定义add()函数，函数值为整型
{
	return a + b;
}

