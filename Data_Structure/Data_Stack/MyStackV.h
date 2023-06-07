#ifndef _MYSTACK_H_
#define _MYSTACK_H_

/***************************************************
*
*	��    ����MyStackVector
*
*	��    �ܣ�ʹ�� vector ʵ�ּ�ջ
*
*	�޸ļ�¼��
*
*		�޸�ʱ�䣺�� 2023-6-2 ��
*		�޸����ݣ��� ��Ŀ��������� ��
*
*	��    �ߣ��� xyt ��
*	��ϵ��ʽ��3124725835@qq.com
*
*	��    ����
*
***************************************************/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<class T>
struct Node {
	T number;
	Node<T>* pNext;
};

class MyStackVector {
private:
	vector<int> m_V;
public:
	MyStackVector();
	MyStackVector(int num);
	~MyStackVector() {
		this->m_V.clear();
	}

	bool  IsEmpty();
	void  Push(int num);
	void  Pop();
	int Top();
	int& Back();
	int  Size();
	void  Swap(MyStackVector& other);
	void  Print();

};

#endif // !_MYSTACK_H_
