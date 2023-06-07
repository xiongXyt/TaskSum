#ifndef _MYDEQUEL_H_
#define _MYDEQUEL_H_

/***************************************************
*
*	��    ����MyDequeL
*
*	��    �ܣ�ʹ�� list ʵ�ּ򵥶���
*
*	�޸ļ�¼��
*
*		�޸�ʱ�䣺�� 2023-6-7 ��
*		�޸����ݣ��� ��Ŀ��������� ��
*
*	��    �ߣ��� xyt ��
*	��ϵ��ʽ��3124725835@qq.com
*
*	��    �������бȽ϶������û��ʵ��
*
***************************************************/

#include<iostream>
#include<list>
using namespace std;

class MyDequeL {
private:
	list<int>m_deque;
public:
	MyDequeL();
	~MyDequeL();
	int& back();		// �������һ��Ԫ��
	bool empty();		// ������п��򷵻���
	int& front();		// ���ص�һ��Ԫ��
	void pop();			// ɾ����һ��Ԫ��
	void push(int num);	// ��ĩβ����һ��Ԫ��
	int size();			// ���ض�����Ԫ�صĸ���

	void print();
};

#endif // !_MYDEQUEL_H_
