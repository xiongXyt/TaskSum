#ifndef _MYSTACK_H_
#define _MYSTACK_H_

/***************************************************
*
*	类    名：MyStackVector
*
*	功    能：使用 vector 实现简单栈
*
*	修改记录：
*
*		修改时间：【 2023-6-2 】
*		修改内容：【 项目启动，完成 】
*
*	作    者：【 xyt 】
*	联系方式：3124725835@qq.com
*
*	其    他：
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
	void  Push_Back(int num);
	void  Push_Front(int num);
	void  Pop_Back();
	void  Pop_Front();
	int& Back();
	int  Size();
	void  Swap(MyStackVector& other);
	void  Print();

};

/***************************************************
*
*	类    名：MyStackList
*
*	功    能：使用 List 实现简单栈
*
*	修改记录：
*
*		修改时间：【 2023-6-2 】
*		修改内容：【 项目启动 】
*
*		修改时间：【 2023-6-6 】
*		修改内容：【 项目功能 】
*
*	作    者：【 xyt 】
*	联系方式：3124725835@qq.com
*
*	其    他：
*
***************************************************/
class MyStackList {
private:
	list<int> m_L;
public:
	MyStackList();
	MyStackList(int num);
	~MyStackList();

	bool  IsEmpty();
	void  Push_Back(int num);
	void  Pop_Back();
	int& Back();

	int  Size();
	void  Swap(MyStackList& other);
	void  Print();
};


#endif // !_MYSTACK_H_
