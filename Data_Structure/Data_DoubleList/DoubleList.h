#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_

/***************************************************
*
*	类    名：DoubleList
*
*	功    能：int 类型双向链表
*
*	修改记录：
*
*		修改时间：【 2023-05-11 】
*		修改内容：【 项目启动，类的数据成员定义、构造析构 】
*
*		修改时间：【 2023-05-12 下午 】
*		修改内容：【 完成操作功能，还有一个排序，确定了新的任务 】
*
*		修改时间：【 2023-05-12 晚上 】
*		修改内容：【 新增排序，确定了新的任务，注释，项目代码简化 】
*
*		修改时间：【 2023-05-13 中午 】
*		修改内容：【 项目收尾工作 】
* 
*		修改时间：【 2023-06-2 中午 】
*		修改内容：【 修改类名为 DoubleList 】
*
*	作    者：【 xyt 】
*	联系方式：3124725835@qq.com
*
*	其    他：
*
***************************************************/

#include<iostream>
using namespace std;

/***************************************************
* 节点结构体，节点能指向上一个节点和下一个节点
***************************************************/
struct Node {
	// 数据域
	int number;
	// 指针域
	Node* FrontNode;  // 前驱节点
	Node* NextNode;   // 后进节点
};

/***************************************************
*	说明：使用空的头节点，里面的数据域用来保存链表的长度
*
*	草    稿    [ DoubleList ]
*
*	类的功能：自己写的链表数组
*
*	描    述：使用空的头节点，非空为节点，里面的头结点的数据域用来保存链表的长度
*			  头结点的下一个节点表示第一个节点
*			  一个节点能够指向上一个节点和下一个节点
*
*	上次任务：
*		项目启动，前期草稿，明确任务
*		创建、遍历、插入、删除
*		项目代码简化、注释、排序
*
*	本次任务：
*		测试，对外接口，按照参考手册实现函数功能
*
***************************************************/
class DoubleList {
private:
	Node* m_pHead;
	Node* m_pEnd;
	int m_Len;

	void __InitList();  // 初始化链表

public:
	DoubleList();
	DoubleList(int num);
	DoubleList(int n, int num);
	DoubleList(int* Begin, int* End);
	DoubleList(const DoubleList& other);
	~DoubleList();

	DoubleList operator+(const DoubleList& other);
	DoubleList operator=(const DoubleList& other);

	void PrintTable();  // 打印函数

	void AddHeadNum(int num);  // 头插入
	void AddEndNum(int num);  // 尾插入
	void AddIndexNum(int index, int num);  // 按照指定位置插入

	void DeleteHeadNum();  // 头删除
	void DeleteEndNum();  // 尾删除

	void DeleteIndexNum(int index);  // 按照指定位置删除
	void DeleteNum(int num, bool flag = false);     // 删除含有 num 数据的第一个节点

	void Sort();           // 排序

};

#endif // !_DOUBLELIST_H_
