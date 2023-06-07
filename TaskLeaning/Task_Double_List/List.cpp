#include "List.h"
#include "Node.h"
#include <assert.h>
#include <iostream>
#include "Iterator.h"
using namespace std;

void List::Init_Node(int num) {
	this->pHead = new Node;
	this->pHead->data = num;
	this->pHead->pFront = this->pHead->pNext = nullptr;
}

List::List() {
	this->pHead = new Node;
	this->pHead->data = 0;  // �������浱ǰ������
	this->pHead->pFront = this->pHead->pNext = nullptr;  // ����ͷ�ڵ��ָ����ָ���

	this->pRear = new Node;
	this->pRear->data = 0;  // �������浱ǰָ���Ԫ��λ��
	// ����β���ڵ�ָ����ָ��ͷ�ڵ�
	this->pRear->pFront = this->pRear->pNext = this->pHead;
}

List::~List() {
	// �Ͽ�����β(���洢����)����ָ��
	this->pRear->pFront = this->pRear->pNext = nullptr;
	delete this->pRear;
	this->pRear = nullptr;

	// �����ͷ��ͷ���������
	while (this->pHead->pNext != nullptr) {
		this->pHead->pFront = this->pHead->pNext;
		this->pHead->pNext = this->pHead->pNext->pNext;
		delete this->pHead->pFront;
	}
	// ����ͷŸ���ͷ�ڵ�
	delete this->pHead;
	this->pHead = nullptr;
}

// ��β������Ԫ��
void List::push_back(const int& val) {
	// pNew �ڵ����ӵ�β��
	Node* pNew = new Node(val, this->pRear->pNext, nullptr);
	// ����β���ڵ�� Next ָ�� pNew �ڵ�
	this->pRear->pNext->pNext = pNew;
	// β������ָ�����
	this->pRear->pNext = this->pRear->pNext->pNext;

	// �����һ
	++this->pHead->data;
}

// ��ͷ��ɾ��
void List::pop_front() {
	if (this->pHead->pNext != nullptr) { // ��Ԫ�ؽڵ�
		if (this->pHead->pNext == this->pRear->pNext) {	// ֻ��һ���ڵ�����
			Node* pTemp = this->pHead->pNext;	// ��ʱ�ڵ�
			this->pHead->pNext = nullptr;		// ����ͷ�ڵ�ֱ��ָ���
			this->pRear->pNext = this->pHead;	//����β�ڵ�ֱ��ָ����ͷ�ڵ� 

			// �ͷű��Ƴ��Ľڵ�
			delete pTemp;
			pTemp = nullptr;
		}
		else {  // �ж���ڵ�����
			Node* pTemp = this->pHead->pNext;	// ��ʱ�ڵ�
			this->pHead->pNext = pTemp->pNext;	// ����ͷ�ڵ����һ���ڵ�ָ��ָ��ڶ����ڵ�
			pTemp->pNext->pFront = this->pHead;	// �ڶ���Ԫ�ص�ǰһ���ڵ�ָ��ָ����ͷ�ڵ�

			// �ͷű��Ƴ��Ľڵ�
			delete pTemp;
			pTemp = nullptr;
		}
		--this->pHead->data;  // ���ȼ�һ
	}
	else {  // û��Ԫ�ؽڵ�
		return;
	}
}

// ��ӡ�����е�����
void List::print() {
	cout << "���� : " << this->pHead->data << endl;
	Iterator it = this->begin();
	for (; it != this->end(); ++it) {
		cout << *it << endl;
	}
	cout << "----- ----- ----- " << endl << endl;
}

// �ж�Ϊ��
bool List::empty() const {
	// ����ͷ�ڵ����һ���ڵ�Ϊ nullptr ���߳���Ϊ��
	return this->pHead->pNext == nullptr || this->pHead->data == 0;
}

// �������
void List::clear() {
	// ����β�ڵ�ֱ��ָ����ͷ�ڵ�
	this->pRear->pNext = this->pHead;

	// �����ͷ�Ԫ�ؽڵ�
	while (this->pHead->pNext != nullptr) {
		this->pHead->pFront = this->pHead->pNext;
		this->pHead->pNext = this->pHead->pNext->pNext;
		delete this->pHead->pFront;
	}

	this->pHead->data = 0;  // ��������
}

// �Ƴ����� val ֵ��Ԫ��
void List::remove(const int& val) {
	while (this->pRear->pFront->pNext != nullptr) {
		if (this->pRear->pFront->pNext->data == val) {  // ֵ���
			// ע��ɾ��һ���ڵ�֮�����Ľڵ�������ˣ�����ָ�������

			if (this->pRear->pFront->pNext == this->pRear->pNext) {		// Ϊ���һ���ڵ�
				Node* pTemp = this->pRear->pNext;					// ��ʱ�ڵ�
				this->pRear->pNext = this->pRear->pFront;			// β�ڵ�ǰ��
				this->pRear->pFront->pNext = nullptr;

				// �ͷű��Ƴ��Ľڵ�
				delete pTemp;
				pTemp = nullptr;

				--this->pHead->data;  // ���ȼ�һ
			}
			else {  // ���������һ���ڵ�
				Node* pTemp = this->pRear->pFront->pNext;  // ������ʱ�ڵ�
				this->pRear->pFront->pNext = this->pRear->pFront->pNext->pNext;  // 
				pTemp->pNext->pFront = this->pRear->pFront->pNext;
				// �ͷű��Ƴ��Ľڵ�
				delete pTemp;
				pTemp = nullptr;

				--this->pHead->data;  // ���ȼ�һ
			}
		}
		else {  // ֵ����ȣ�ָ�����
			this->pRear->pFront = this->pRear->pFront->pNext;
		}
	}
	this->pRear->pFront = this->pHead;  // ����β�ڵ�� pFront ����ָ��ͷ�ڵ�
}

// ɾ���������ظ�Ԫ��
void List::unique() {
	Node* pTemp = this->pHead->pNext;  // ��һ��Ԫ�ؿ�ʼ�ı���ָ��
	while (pTemp != nullptr) {
		Node* pNum = pTemp->pNext;  // ����ָ��
		while (pNum != nullptr) {
			if (pTemp->data == pNum->data) {  // ɾ����һ���ظ���Ԫ��
				if (nullptr == pNum->pNext) {  // ���һ��Ԫ��
					Node* pNew = pNum;  // ������Ҫɾ���Ľڵ�
					this->pRear->pNext = pTemp;
					pTemp->pNext = nullptr;

					delete pNew;
					pNew = nullptr;

					pNum = nullptr;
				}
				else {  // �������һ��Ԫ��
					Node* pNew = pNum;  // ������Ҫɾ���Ľڵ�
					pTemp->pNext = pTemp->pNext->pNext;
					pTemp->pNext->pFront = pTemp;

					delete pNew;
					pNew = nullptr;

					pNum = pTemp->pNext;
				}
				--this->pHead->data;  // ���ȼ�һ
			}
			else {
				break;
			}
		}
		pTemp = pTemp->pNext;  // ����ָ�����
	}
	this->pRear->pFront = this->pHead;  // ����β�ڵ�� pFront ����ָ��ͷ�ڵ�
}

// ������������
void List::swap(List& lst) {
	List lTemp;
	Iterator it = this->begin();
	for (; it != this->end(); ++it) {
		lTemp.push_back(it.pNode->data);
	}
	this->clear();
	it = lst.begin();
	for (; it != lst.end(); ++it) {
		this->push_back(it.pNode->data);
	}
	lst.clear();
	it = lTemp.begin();
	for (; it != lTemp.end(); ++it) {
		lst.push_back(it.pNode->data);
	}
	lTemp.clear();
}

// ˳��ת
void List::reverse() {
	// ����ͷβ����ָ�룬����ԭ��һ�� pFront ����
	Node* pTemp = this->pHead->pNext;
	pTemp->pFront = nullptr;
	this->pHead->pNext = this->pRear->pNext;
	this->pRear->pNext = pTemp;

	pTemp = this->pHead;  // ����ͷ�ڵ�

	// ����Ԫ�ؽڵ������ָ�뷴ת
	while (pTemp->pNext != nullptr) {
		Node* pNum = pTemp->pNext;
		pNum->pNext = pNum->pFront;
		pNum->pFront = pTemp;

		pTemp = pTemp->pNext;  // ����ָ�����
	}
}

// �ϲ��������������������Ӧ����������
void List::merge(List& lst) {
	Node* pTemp = lst.pHead;
	List lTemp;
	bool flag = true;
	while (flag) {
		if (nullptr == this->pHead->pNext) {  // ���� lst ��ʣ��ڵ�
			while (pTemp->pNext != nullptr) {
				lTemp.push_back(pTemp->pNext->data);
				pTemp = pTemp->pNext;
			}
			flag = false;
		}
		else if (nullptr == pTemp->pNext) {  // ���� this ��ʣ��ڵ�
			while (this->pHead->pNext != nullptr) {
				lTemp.push_back(this->pHead->pNext->data);
				this->pHead = this->pHead->pNext;
			}
			flag = false;
		}
		else {
			if (this->pHead->pNext->data > pTemp->pNext->data) {  // ���� lst �ĵ�һ���ڵ�
				lTemp.push_back(pTemp->pNext->data);
				pTemp = pTemp->pNext;
			}
			else {  // ���� this �ĵ�һ���ڵ�
				lTemp.push_back(this->pHead->pNext->data);
				this->pHead = this->pHead->pNext;
			}
		}
	}
	this->clear();
	while (lTemp.pHead->pNext != nullptr) {
		this->push_back(lTemp.pHead->pNext->data);
		lTemp.pHead = lTemp.pHead->pNext;
	}
}

// ����,Ϊ��������
void List::sort() {
	for (int i = this->pHead->data - 1; i > 0; --i) {
		Node* pTemp1 = this->pHead->pNext;
		Node* pTemp2 = this->pHead->pNext->pNext;
		for (int j = 0; j < i; ++j) {
			if (pTemp1->data > pTemp2->data) {
				int numTemp = pTemp1->data;
				pTemp1->data = pTemp2->data;
				pTemp2->data = numTemp;
			}
			pTemp1 = pTemp1->pNext;
			pTemp2 = pTemp2->pNext;
		}
	}
}
int  List::size() {
	return this->pHead->data;
}

// begin:����ָ��ͷ���ĵ�����
Iterator List::begin() {
	Iterator it(this->pHead->pNext);
	return it;
}

// end:����ָ����β���ĵ�����
Iterator List::end() {
	Iterator it(this->pRear->pNext->pNext);
	return it;
}

// erase
Iterator List::erase(Iterator pos) {
	Iterator it(this->pRear->pNext);
	return it;
}

Iterator List::erase(Iterator start, Iterator end) {
	Iterator it(this->pRear->pNext);
	return it;
}

Iterator List::insert(Iterator pos, const int& val) {
	Iterator it(this->pRear->pNext);
	return it;
}

// ��һ�� list ת��Ԫ�ظ���һ��
void List::splice(Iterator pos, List& lst) {
	Node* pTemp = nullptr;
	Iterator it = lst.begin();
	for (; it != lst.end(); ++it) {
		pTemp = new Node(it.pNode->data);
		pTemp->pFront = pos.pNode;
		pTemp->pNext = pos.pNode->pNext;
		pos.pNode->pNext->pFront = pos.pNode->pNext = pTemp;
		++this->pHead->data;
	}
}

// ��һ�� list ת��Ԫ�ظ���һ��
void List::splice(Iterator pos, List& lst, Iterator first, Iterator last) {
	Node* pTemp = nullptr;
	for (; first != last; ++first) {
		pTemp = new Node(first.pNode->data);
		pTemp->pFront = pos.pNode;
		pTemp->pNext = pos.pNode->pNext;
		pos.pNode->pNext->pFront = pos.pNode->pNext = pTemp;
		++this->pHead->data;
	}
}

bool List::isOrder() {
	/*if (0 == size() || 1 == size()) {
		return true;
	}*/

	Node* pNode = pHead->pNext;
	while (pNode != pRear->pFront) {
		// �Ƚ����ڵ�����ֵ
		if (pNode->data > pNode->pNext->data) {
			return false;
		}
		pNode = pNode->pNext;
	}
	return true;
}

