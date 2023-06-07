#include<iostream>
#include "MyStackV.h"
#include "MyStackL.h"
using namespace std;
/*
* 使用 vector 和 list 实现 Stack 。
*/


int main() {
	//MyStackVector  mystackvector1(3);
	//MyStackVector  mystackvector2(4);
	//mystackvector1.Swap(mystackvector2);
	//mystackvector1.Print();
	//mystackvector2.Print();

	MyStackList my1;
	MyStackList my2;
	my1.Push(100);// 压栈
	cout << my1.Top() << endl;;// 访问栈顶元素
	my1.Pop();// 出栈
	my1.Pop();// 栈为空时，出栈
	cout << my1.Top() << endl;
	my1.Push(100);
	my1.Back()=1000000;// 返回栈顶元素的引用
	cout << my1.Top() << endl;
	my2.Push(90);
	my1.Swap(my2);// 交换两个栈的元素
	my1.Print();
	my2.Print();

	cout << "***** ***** ***** *****" << endl;
	cout << "***** ***** ***** *****" << endl << endl;

	MyStackVector my3;
	MyStackVector my4;
	my3.Push(300);// 压栈
	cout << my3.Top() << endl;;// 访问栈顶元素
	my3.Pop();// 出栈
	my3.Pop();// 栈为空时，出栈
	cout << my3.Top() << endl;
	my3.Push(300);
	my3.Back() = 3000000;// 返回栈顶元素的引用
	cout << my3.Top() << endl;
	my4.Push(90);
	my3.Swap(my4);// 交换两个栈的元素
	my3.Print();
	my4.Print();

	return 0;
}
