#ifndef _SLIST_H_
#define _SLIST_H_

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
	SNUM m_MaxSize;
	SNUM m_Usedsize;
	SNUM* m_Array;

private:
	bool IsFull();
	void AddLen();

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
	void Insert(SNUM pos, SNUM num);
	void Remove(SNUM num);
	void RemoveAll(SNUM num);
	void Sort(bool flag = true);
	void SortOne(bool flag = true);

	void PrintArr();

};

#endif // !_SLIST_H_
