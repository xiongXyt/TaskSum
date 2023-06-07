#ifndef _MYSTACKL_H_
#define _MYSTACKL_H_

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
*		修改时间：【 2023-6-7 】
*		修改内容：【 List 和 vector 进行了分文件编写 】
*
*	作    者：【 xyt 】
*	联系方式：3124725835@qq.com
*
*	其    他：
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
