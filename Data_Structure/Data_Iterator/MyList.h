#ifndef _MYLIST_H_
#define _MYLIST_H_
#include<iostream>
using namespace std;


typedef struct ListNode {
	int data;
	ListNode* NextNode;
}Node;

// ��������
class ListIterator {
typedef ListIterator Iterator;
private:
public:	
	Node* m_Node;
	ListIterator(Node* p) {
		this->m_Node = p->NextNode;  // ���ڵ�һ���ڵ�
	}

	int operator*() {
		return this->m_Node->data;  // * ȡ����
	}

	int operator->() {  // -> ȥ����
		return this->m_Node->data;
	}

	// ǰ�� ++
	Iterator& operator++() {  // ����һ������
		this->m_Node = this->m_Node->NextNode;
		return *this;
	}

	// ���� ++
	Iterator operator++(int) {  // ��ʱ���浱ǰ��λ�ã�������
		Node* pTemp = this->m_Node;
		this->m_Node = this->m_Node->NextNode;
		return pTemp;
	}

	// ���� !=
	bool operator!=(const Iterator& other) {
		return this->m_Node != other.m_Node;
	}

	// ���� =
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


// ��������
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

// ����һ������ͷ�ڵ�Ŀ�����
MyList::MyList() {
	this->m_pList = new Node;
	this->m_pList->data = 0;
	this->m_pList->NextNode = nullptr;
}

MyList::~MyList() {
	delete[]m_pList;
	m_pList = nullptr;
}

// ��ӡ����
void MyList::PrintList() {
	Node* pHead = this->m_pList;

	while (pHead->NextNode != nullptr) {
		cout << pHead->NextNode->data << endl;
		pHead = pHead->NextNode;
	}
	cout << "----- ----- ----- " << endl;
}

// ���Ԫ������һ���ڵ�
void MyList::AddList(int num) {
	Node* pNum = new Node;
	pNum->NextNode = nullptr;
	pNum->data = num;

	pNum->NextNode = this->m_pList->NextNode;
	this->m_pList->NextNode = pNum;

	++this->m_pList->data;
}

// ���ص�һ��Ԫ�صĵ�����
Iterator MyList::begin() {
	return Iterator(this->m_pList);
}

// �������һ��Ԫ�ص���һ��λ�õĵ�����
Iterator MyList::end() {
	Node* pTemp = this->m_pList;
	while (pTemp->NextNode!=nullptr) {
		pTemp = pTemp->NextNode;
	}
	return Iterator(pTemp);
}

#endif // !_MYLIST_H_
