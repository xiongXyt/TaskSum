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
	this->pHead->data = 0;  // 用来保存当前链表长度
	this->pHead->pFront = this->pHead->pNext = nullptr;  // 辅助头节点的指针域都指向空

	this->pRear = new Node;
	this->pRear->data = 0;  // 用来保存当前指向的元素位置
	// 辅助尾部节点指针域都指向头节点
	this->pRear->pFront = this->pRear->pNext = this->pHead;
}

List::~List() {
	// 断开辅助尾(不存储数据)结点的指针
	this->pRear->pFront = this->pRear->pNext = nullptr;
	delete this->pRear;
	this->pRear = nullptr;

	// 遍历释放释放整个链表
	while (this->pHead->pNext != nullptr) {
		this->pHead->pFront = this->pHead->pNext;
		this->pHead->pNext = this->pHead->pNext->pNext;
		delete this->pHead->pFront;
	}
	// 最后释放辅助头节点
	delete this->pHead;
	this->pHead = nullptr;
}

// 从尾部插入元素
void List::push_back(const int& val) {
	// pNew 节点连接到尾部
	Node* pNew = new Node(val, this->pRear->pNext, nullptr);
	// 辅助尾部节点的 Next 指向 pNew 节点
	this->pRear->pNext->pNext = pNew;
	// 尾部辅助指针后移
	this->pRear->pNext = this->pRear->pNext->pNext;

	// 计算加一
	++this->pHead->data;
}

// 从头部删除
void List::pop_front() {
	if (this->pHead->pNext != nullptr) { // 有元素节点
		if (this->pHead->pNext == this->pRear->pNext) {	// 只有一个节点的情况
			Node* pTemp = this->pHead->pNext;	// 临时节点
			this->pHead->pNext = nullptr;		// 辅助头节点直接指向空
			this->pRear->pNext = this->pHead;	//辅助尾节点直接指向辅助头节点 

			// 释放被移除的节点
			delete pTemp;
			pTemp = nullptr;
		}
		else {  // 有多个节点的情况
			Node* pTemp = this->pHead->pNext;	// 临时节点
			this->pHead->pNext = pTemp->pNext;	// 辅助头节点的下一个节点指针指向第二个节点
			pTemp->pNext->pFront = this->pHead;	// 第二个元素的前一个节点指针指向辅助头节点

			// 释放被移除的节点
			delete pTemp;
			pTemp = nullptr;
		}
		--this->pHead->data;  // 长度减一
	}
	else {  // 没有元素节点
		return;
	}
}

// 打印链表中的数据
void List::print() {
	cout << "长度 : " << this->pHead->data << endl;
	Iterator it = this->begin();
	for (; it != this->end(); ++it) {
		cout << *it << endl;
	}
	cout << "----- ----- ----- " << endl << endl;
}

// 判断为空
bool List::empty() const {
	// 辅助头节点的下一个节点为 nullptr 或者长度为零
	return this->pHead->pNext == nullptr || this->pHead->data == 0;
}

// 清空链表
void List::clear() {
	// 辅助尾节点直接指向辅助头节点
	this->pRear->pNext = this->pHead;

	// 遍历释放元素节点
	while (this->pHead->pNext != nullptr) {
		this->pHead->pFront = this->pHead->pNext;
		this->pHead->pNext = this->pHead->pNext->pNext;
		delete this->pHead->pFront;
	}

	this->pHead->data = 0;  // 长度置零
}

// 移除所有 val 值的元素
void List::remove(const int& val) {
	while (this->pRear->pFront->pNext != nullptr) {
		if (this->pRear->pFront->pNext->data == val) {  // 值相等
			// 注意删除一个节点之后后面的节点接上来了，不用指针后移了

			if (this->pRear->pFront->pNext == this->pRear->pNext) {		// 为最后一个节点
				Node* pTemp = this->pRear->pNext;					// 临时节点
				this->pRear->pNext = this->pRear->pFront;			// 尾节点前移
				this->pRear->pFront->pNext = nullptr;

				// 释放被移除的节点
				delete pTemp;
				pTemp = nullptr;

				--this->pHead->data;  // 长度减一
			}
			else {  // 不是最后有一个节点
				Node* pTemp = this->pRear->pFront->pNext;  // 保存临时节点
				this->pRear->pFront->pNext = this->pRear->pFront->pNext->pNext;  // 
				pTemp->pNext->pFront = this->pRear->pFront->pNext;
				// 释放被移除的节点
				delete pTemp;
				pTemp = nullptr;

				--this->pHead->data;  // 长度减一
			}
		}
		else {  // 值不相等，指针后移
			this->pRear->pFront = this->pRear->pFront->pNext;
		}
	}
	this->pRear->pFront = this->pHead;  // 辅助尾节点的 pFront 重新指向头节点
}

// 删除连续的重复元素
void List::unique() {
	Node* pTemp = this->pHead->pNext;  // 第一个元素开始的遍历指针
	while (pTemp != nullptr) {
		Node* pNum = pTemp->pNext;  // 查找指针
		while (pNum != nullptr) {
			if (pTemp->data == pNum->data) {  // 删除后一个重复的元素
				if (nullptr == pNum->pNext) {  // 最后一个元素
					Node* pNew = pNum;  // 保存需要删除的节点
					this->pRear->pNext = pTemp;
					pTemp->pNext = nullptr;

					delete pNew;
					pNew = nullptr;

					pNum = nullptr;
				}
				else {  // 不是最后一个元素
					Node* pNew = pNum;  // 保存需要删除的节点
					pTemp->pNext = pTemp->pNext->pNext;
					pTemp->pNext->pFront = pTemp;

					delete pNew;
					pNew = nullptr;

					pNum = pTemp->pNext;
				}
				--this->pHead->data;  // 长度减一
			}
			else {
				break;
			}
		}
		pTemp = pTemp->pNext;  // 遍历指针后移
	}
	this->pRear->pFront = this->pHead;  // 辅助尾节点的 pFront 重新指向头节点
}

// 交换两个链表
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

// 顺序反转
void List::reverse() {
	// 交换头尾辅助指针，并且原第一个 pFront 置零
	Node* pTemp = this->pHead->pNext;
	pTemp->pFront = nullptr;
	this->pHead->pNext = this->pRear->pNext;
	this->pRear->pNext = pTemp;

	pTemp = this->pHead;  // 等于头节点

	// 所有元素节点的上下指针反转
	while (pTemp->pNext != nullptr) {
		Node* pNum = pTemp->pNext;
		pNum->pNext = pNum->pFront;
		pNum->pFront = pTemp;

		pTemp = pTemp->pNext;  // 遍历指针后移
	}
}

// 合并两个以排序的链表，链表应以升序排序
void List::merge(List& lst) {
	Node* pTemp = lst.pHead;
	List lTemp;
	bool flag = true;
	while (flag) {
		if (nullptr == this->pHead->pNext) {  // 链接 lst 的剩余节点
			while (pTemp->pNext != nullptr) {
				lTemp.push_back(pTemp->pNext->data);
				pTemp = pTemp->pNext;
			}
			flag = false;
		}
		else if (nullptr == pTemp->pNext) {  // 链接 this 的剩余节点
			while (this->pHead->pNext != nullptr) {
				lTemp.push_back(this->pHead->pNext->data);
				this->pHead = this->pHead->pNext;
			}
			flag = false;
		}
		else {
			if (this->pHead->pNext->data > pTemp->pNext->data) {  // 链接 lst 的第一个节点
				lTemp.push_back(pTemp->pNext->data);
				pTemp = pTemp->pNext;
			}
			else {  // 链接 this 的第一个节点
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

// 排序,为升序排序
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

// begin:返回指向头结点的迭代器
Iterator List::begin() {
	Iterator it(this->pHead->pNext);
	return it;
}

// end:返回指向辅助尾结点的迭代器
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

// 从一个 list 转移元素给另一个
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

// 从一个 list 转移元素给另一个
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
		// 比较相邻的两个值
		if (pNode->data > pNode->pNext->data) {
			return false;
		}
		pNode = pNode->pNext;
	}
	return true;
}

