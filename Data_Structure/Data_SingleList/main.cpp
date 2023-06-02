#include"SingleList.h"
#include<iostream>
using namespace std;

int main() {
	/*
	* 无参构造函数测试
	*/
	//SingleList singlelist;
	//singlelist.PrintList();

	/*
	* 有参构造函数测试
	*/
	SingleList singlelist(10);
	singlelist.PrintList();

	/*
	* 清空链表测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleList singlelist(n, n + 5);
	//singlelist.PrintList();
	//singlelist.Clear();
	//singlelist.PrintList();

	/*
	* 判断链表为空测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleList singlelist(n, n + 5);
	//singlelist.PrintList();
	//singlelist.Clear();
	//singlelist.PrintList();
	//cout << "singlelist.IsEmpty() : " << singlelist.IsEmpty() << endl;

	/*
	* 返回链表最大容量测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleList singlelist(n, n + 5);
	//singlelist.PrintList();
	//cout << "singlelist.MaxSize() : " << singlelist.MaxSize() << endl;

	/*
	* 头部插入测试
	*/
	//SingleList singlelist(2);
	//singlelist.PrintList();
	//singlelist.AddHeadNum(100);
	//singlelist.PrintList();

	/*
	* 尾部插入测试
	*/
	//SingleList singlelist(3);
	//singlelist.PrintList();
	//singlelist.AddEndNum(100);
	//singlelist.PrintList();

	/*
	* 索引插入测试
	*/
	//SingleList singlelist(3);
	//singlelist.PrintList();
	//singlelist.AddIndexNum(4,100);
	//singlelist.PrintList();

	/*
	* 头删除测试
	*/
	//SingleList singlelist(10);
	//singlelist.PrintList();
	//singlelist.DeleteHeadNum();
	//singlelist.PrintList();

	/*
	* 尾删除测试
	*/
	//SingleList singlelist(10);
	//singlelist.PrintList();
	//singlelist.DeleteEndNum();
	//singlelist.PrintList();

	/*
	* 删除数据测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleList singlelist(n, n + 5);
	//singlelist.PrintList();
	//singlelist.DeleteNum(2, true);
	//singlelist.PrintList();

	/*
	* 返回首元素的引用测试
	*/
	//int n[5] = { 1,2,2,1,2 };
	//SingleList singlelist(n, n + 5);
	//singlelist.PrintList();
	//cout << "singlelist.front() : " << singlelist.front() << endl;
	//singlelist.front() = 10;
	//cout << "singlelist.front() : " << singlelist.front() << endl;
	//singlelist.PrintList();

	/*
	* 指定重置链表数据测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleList singlelist(n, n + 5);
	//singlelist.PrintList();
	//singlelist.Assign(10, 100);
	//singlelist.PrintList();

	/*
	* 链表交换数据测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleList singlelist1(n, n + 5);
	//SingleList singlelist2(10, 100);
	//singlelist1.PrintList();
	//singlelist2.PrintList();
	//singlelist1.Swap(singlelist2);
	//singlelist1.PrintList();
	//singlelist2.PrintList();
	//singlelist1.AddHeadNum(10000);
	//singlelist1.PrintList();
	//singlelist2.PrintList();

	/*
	* 归并二个已排序链表测试
	*/
	//int num1[5] = { 1,3,5,7,9 };
	//int num2[5] = { 2,4,6,8,10 };
	//SingleList singlelist1(num1, num1 + 5);
	//SingleList singlelist2(num2, num2 + 5);
	//singlelist1.PrintList();
	//singlelist2.PrintList();
	//singlelist1.Merge(singlelist2);
	//singlelist1.PrintList();
	//singlelist2.PrintList();

	/*
	* 数据排序测试
	*/
	//int n[5] = { 1,2,2,1,2 };
	//SingleList singlelist(n, n + 5);
	//singlelist.PrintList();
	//singlelist.Sort();
	//singlelist.PrintList();
	return 0;
}