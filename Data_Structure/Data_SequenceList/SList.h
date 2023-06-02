#ifndef _SLIST_H_
#define _SLIST_H_

/***************************************************
*
*	类    名：SList
*
*	功    能：可扩容的顺序线性表
*
*	修改记录：
*
*		修改时间：【 2023-06-1 】
*		修改内容：【 项目启动，添加线性表的基本功能 】
*
*		修改时间：【 2023-06-2 中午 】
*		修改内容：【 注释，项目代码简化 】
*
*	作    者：【 xyt 】
*	联系方式：3124725835@qq.com
*
*	其    他：
*
***************************************************/

#include<iostream>
using namespace std;

#define SNUM short

#define MAXSIZE 10
#define ADDSIZE 10

/*
* 数据成员：最大长度，被使用的长度，数组控制指针
*/

class SList {
private:
	SNUM m_MaxSize;		// 最大长度
	SNUM m_Usedsize;	// 被使用的长度
	SNUM* m_Array;		// 数组控制指针

private:
	bool IsFull();  // 线性表已满
	void AddLen();  // 增加顺序线性表长度

public:
	SList();
	SList(SNUM len, SNUM num);
	SList(SNUM* begin, SNUM* end);
	SList(const SList& other);
	~SList();

	SNUM GetUsedsize()const;
	SNUM* GetArray()const;

	bool IsEmpty();
	void Push_Back(SNUM num);
	void Pop_Back();
	void Insert(SNUM pos, SNUM num);	// 指定位置插入
	void Remove(SNUM num);				// 删除值为val的第一个元素
	void RemoveAll(SNUM num);			// 删除所有值为val的元素
	void Sort(bool flag = true);		// 链表排序，默认是升序
	void SortOne(bool flag = true);		// 排序之后相同元素保留一个

	void PrintArr();

};

#endif // !_SLIST_H_
