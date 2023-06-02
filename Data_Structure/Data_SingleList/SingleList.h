#ifndef _SINGLELIST_H_
#define _SINGLELIST_H_

/***************************************************
*
*	类    名：SingleList
*
*	功    能：int 类型单链表  （ 详细见下方草稿 ）
*
*	修改记录：
*
*		修改时间：【 2023-05-11 中午 】
*		修改内容：【 项目启动，类的数据成员定义、构造析构 】
*
*		修改时间：【 2023-05-11 下午 】
*		修改内容：【 完成所有的预定功能 】
*
*		修改时间：【 2023-06-1 】
*		修改内容：【 添加C++参考手册单链表的函数 】
* 
*		修改时间：【 2023-06-2 】
*		修改内容：【 修改类名为 SingleList 】
*
*	作    者：【 xyt 】
*	联系方式：3124725835@qq.com
*
*	其    他：
*
***************************************************/

#include<iostream>
using namespace std;

#define MAXSIZE 200

/***************************************************
* 节点结构体，节点能指向下一个节点
***************************************************/
struct Node {
	// 数据域
	int number;
	// 指针域
	Node* NextNode;
};

/***************************************************
*	说明：使用空的头节点，里面的数据域用来保存链表的长度
*
*	草    稿    [ SingleList ]
*
*	类的功能：自己写的单链表数组
*
*	描    述：使用空的头节点，里面的头结点的数据域用来保存链表的长度
*			  头结点的下一个节点表示第一个节点
*			  一个节点只能指向下一个节点
*
*	历史任务：
*		项目启动，类的数据成员定义、构造析构（还没有做测试）
*		创建、遍历、插入、删除、排序
*		运算符重载，（ + = ）
*		遍历、项目代码简化、注释、做好所有的测试案例、
*
*	本次任务：
*		实现C++参考手册单链表的函数
*
***************************************************/
class SingleList {
private:
	Node* m_pHead;  // 头指针
	int m_Len;      // 节点的长度

	void __InitList();  // 初始化链表

public:
	SingleList();
	SingleList(int count);
	SingleList(int count, int value);
	SingleList(int* Begin, int* End);
	SingleList(const SingleList& other);
	~SingleList();

	// 运算符重载（ + - ）
	SingleList operator+(const SingleList& other);  // 加法运算符重载
	SingleList operator=(const SingleList& other);  // 等于运算符重载

	void PrintList()const;     // 打印链表
	void Clear();  // 清空链表，保留头指针
	bool IsEmpty();  // 判断链表为空
	int MaxSize();  // 返回最大容量，本程序默认为200个节点

	void AddHeadNum(int value);  // 头插入
	void AddEndNum(int value);  // 尾插入
	void AddIndexNum(int pos, int value);  // 按照指定位置插入

	void DeleteHeadNum();  // 头删除
	void DeleteEndNum();  // 尾删除
	void DeleteIndexNum(int pos);  // 按照指定位置删除
	void DeleteNum(int value, bool flag = false);     // 删除含有 value 数据的第一个节点

	int& Front();  // 返回首元素的引用
	void Assign(int count, int value);  // 以 count 份 value 的副本替换内容。

	void Swap(SingleList& other); // 将内容与 other 的交换
	void Merge(const SingleList& other);  //归并二个已排序链表,链表应以升序排序。

	void Sort();           // 排序

};

#endif // !_SINGLELIST_H_
