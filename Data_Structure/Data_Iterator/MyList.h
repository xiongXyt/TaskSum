#ifndef _MYLIST_H_
#define _MYLIST_H_
#include<iostream>
using namespace std;


typedef struct ListNode {
	int data;
	ListNode* NextNode;
}Node;

// 迭代器类
class ListIterator {
typedef ListIterator Iterator;
private:
public:	
	Node* m_Node;
	ListIterator(Node* p) {
		this->m_Node = p->NextNode;  // 等于第一个节点
	}

	int operator*() {
		return this->m_Node->data;  // * 取内容
	}

	int operator->() {  // -> 去内容
		return this->m_Node->data;
	}

	// 前置 ++
	Iterator& operator++() {  // 返回一个引用
		this->m_Node = this->m_Node->NextNode;
		return *this;
	}

	// 后置 ++
	Iterator operator++(int) {  // 临时保存当前的位置，在自增
		Node* pTemp = this->m_Node;
		this->m_Node = this->m_Node->NextNode;
		return pTemp;
	}

	// 重载 !=
	bool operator!=(const Iterator& other) {
		return this->m_Node != other.m_Node;
	}

	// 重载 =
	Iterator operator=(const Iterator& other) {
		this->m_Node = other.m_Node;
		return *this;
	}

	~ListIterator ();

};
typedef ListIterator Iterator;

ListIterator ::~ListIterator () {
	m_Node = nullptr;
}


// 单链表类
class MyList {
private:
	Node* m_pList;
public:
	typedef ListIterator Iterator;
	MyList();
	~MyList();

	void PrintList();
	void AddList(int num);

	Iterator begin();
	Iterator end();

};

// 构造一个含有头节点的空链表
MyList::MyList() {
	this->m_pList = new Node;
	this->m_pList->data = 0;
	this->m_pList->NextNode = nullptr;
}

MyList::~MyList() {
	delete[]m_pList;
	m_pList = nullptr;
}

// 打印链表
void MyList::PrintList() {
	Node* pHead = this->m_pList;

	while (pHead->NextNode != nullptr) {
		cout << pHead->NextNode->data << endl;
		pHead = pHead->NextNode;
	}
	cout << "----- ----- ----- " << endl;
}

// 添加元素至第一个节点
void MyList::AddList(int num) {
	Node* pNum = new Node;
	pNum->NextNode = nullptr;
	pNum->data = num;

	pNum->NextNode = this->m_pList->NextNode;
	this->m_pList->NextNode = pNum;

	++this->m_pList->data;
}

// 返回第一个元素的迭代器
Iterator MyList::begin() {
	return Iterator(this->m_pList);
}

// 返回最后一个元素的下一个位置的迭代器
Iterator MyList::end() {
	Node* pTemp = this->m_pList;
	while (pTemp->NextNode!=nullptr) {
		pTemp = pTemp->NextNode;
	}
	return Iterator(pTemp);
}

#endif // !_MYLIST_H_
