#ifndef _MYSTACKL_H_
#define _MYSTACKL_H_

/***************************************************
*
*	��    ����MyStackList
*
*	��    �ܣ�ʹ�� List ʵ�ּ�ջ
*
*	�޸ļ�¼��
*
*		�޸�ʱ�䣺�� 2023-6-2 ��
*		�޸����ݣ��� ��Ŀ���� ��
*
*		�޸�ʱ�䣺�� 2023-6-6 ��
*		�޸����ݣ��� ��Ŀ���� ��
* 
*		�޸�ʱ�䣺�� 2023-6-7 ��
*		�޸����ݣ��� List �� vector �����˷��ļ���д ��
*
*	��    �ߣ��� xyt ��
*	��ϵ��ʽ��3124725835@qq.com
*
*	��    ����
*
***************************************************/
#include<iostream>
#include<list>
using namespace std;

class MyStackList {
private:
	list<int> m_L;
public:
	MyStackList();
	MyStackList(int num);
	~MyStackList();

	bool  IsEmpty();
	void  Push(int num);
	void  Pop();
	int Top();
	int& Back();

	int  Size();
	void  Swap(MyStackList& other);
	void  Print();
};

#endif // !_MYSTACKL_H_
