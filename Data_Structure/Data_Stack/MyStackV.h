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
	void  Push(int num);
	void  Pop();
	int Top();
	int& Back();
	int  Size();
	void  Swap(MyStackVector& other);
	void  Print();

};

#endif // !_MYSTACK_H_
