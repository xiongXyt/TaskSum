#ifndef _MYDEQUEL_H_
#define _MYDEQUEL_H_

/***************************************************
*
*	类    名：MyDequeL
*
*	功    能：使用 list 实现简单队列
*
*	修改记录：
*
*		修改时间：【 2023-6-7 】
*		修改内容：【 项目启动，完成 】
*
*	作    者：【 xyt 】
*	联系方式：3124725835@qq.com
*
*	其    他：还有比较多的内容没有实现
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
	int& back();		// 返回最后一个元素
	bool empty();		// 如果队列空则返回真
	int& front();		// 返回第一个元素
	void pop();			// 删除第一个元素
	void push(int num);	// 在末尾加入一个元素
	int size();			// 返回队列中元素的个数

	void print();
};

#endif // !_MYDEQUEL_H_
