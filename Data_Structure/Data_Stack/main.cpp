#include<iostream>
#include "MyStackV.h"
#include "MyStackL.h"
using namespace std;
/*
* ʹ�� vector �� list ʵ�� Stack ��
*/


int main() {
	//MyStackVector  mystackvector1(3);
	//MyStackVector  mystackvector2(4);
	//mystackvector1.Swap(mystackvector2);
	//mystackvector1.Print();
	//mystackvector2.Print();

	MyStackList my1;
	MyStackList my2;
	my1.Push(100);// ѹջ
	cout << my1.Top() << endl;;// ����ջ��Ԫ��
	my1.Pop();// ��ջ
	my1.Pop();// ջΪ��ʱ����ջ
	cout << my1.Top() << endl;
	my1.Push(100);
	my1.Back()=1000000;// ����ջ��Ԫ�ص�����
	cout << my1.Top() << endl;
	my2.Push(90);
	my1.Swap(my2);// ��������ջ��Ԫ��
	my1.Print();
	my2.Print();

	cout << "***** ***** ***** *****" << endl;
	cout << "***** ***** ***** *****" << endl << endl;

	MyStackVector my3;
	MyStackVector my4;
	my3.Push(300);// ѹջ
	cout << my3.Top() << endl;;// ����ջ��Ԫ��
	my3.Pop();// ��ջ
	my3.Pop();// ջΪ��ʱ����ջ
	cout << my3.Top() << endl;
	my3.Push(300);
	my3.Back() = 3000000;// ����ջ��Ԫ�ص�����
	cout << my3.Top() << endl;
	my4.Push(90);
	my3.Swap(my4);// ��������ջ��Ԫ��
	my3.Print();
	my4.Print();

	return 0;
}
