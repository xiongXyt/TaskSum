#include<iostream>
using namespace std;

//链表结点声明如下：
struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

#define Node ListNode

// 初始化链表空头节点
void Init_List(Node*& p) {
	p = new Node;
	p->m_nKey = 0;
	p->m_pNext = nullptr;
}

// 清空链表
void Clead_List(Node*& p) {
	p->m_nKey = 0;
	delete[]p;
	p = nullptr;
}

// 从头打印链表
void Print(Node* p) {
	Node* pTemp = p;
	for (; pTemp->m_pNext != nullptr; pTemp = pTemp->m_pNext) {
		cout << pTemp->m_pNext->m_nKey << endl;
	}
	cout << " ----- ----- " << endl;
}

// 为含有空头节点，尾插入一个节点
void AddNode(Node* p, int number) {
	Node* pNum = new Node;
	pNum->m_nKey = number;
	pNum->m_pNext = nullptr;

	Node* pTemp = p;
	for (; pTemp->m_pNext != nullptr; pTemp = pTemp->m_pNext) {}

	pTemp->m_pNext = pNum;

	++p->m_nKey;
}

// 求单链表中结点的个数
int ListSize(Node* p) {
	return p->m_nKey;
}

// 链表反转
void ReversalList(Node* p) {
	Node* pTemp = new Node;
	pTemp->m_nKey = 0;
	pTemp->m_pNext = nullptr;

	// 头节点没有动
	while (p->m_pNext != nullptr) {
		Node* pNum = p->m_pNext;
		p->m_pNext = p->m_pNext->m_pNext;  // 头节点下一个节点给临时链表
		pNum->m_pNext = pTemp->m_pNext;  // 头节点指向下下一个节点
		pTemp->m_pNext = pNum;
	}

	p->m_pNext = pTemp->m_pNext;  // 头节点重新指向临时链表的第一个元素

	// 释放临时空头节点
	delete pTemp;
	pTemp = nullptr;
}

// 查找单链表中倒数第 k 个元素
int search_Reciprocal(Node* p, int k) {
	if (k > 0 && k <= p->m_nKey) {  // k值的判断，0 < k <= MaxSize
		Node* pTemp = p;
		for (int i = 0; i < p->m_nKey - k; ++i) {
			pTemp = pTemp->m_pNext;
		}
		return pTemp->m_nKey;
	}
	else {
		cout << " 索引有误！ " << endl;
		return 500;
	}
}

// 查找单链表的中间结点
int search_Middle(Node* p) {
	if (0 == p->m_nKey % 2) {  // 为偶数，返回 num / 2 
		Node* pTemp = p;
		for (int i = 1; i < p->m_nKey / 2; ++i) {
			pTemp = pTemp->m_pNext;
		}
		return pTemp->m_pNext->m_nKey;
	}
	else {  // 为奇数，返回 num / 2 + 1
		Node* pTemp = p;
		for (int i = 1; i < p->m_nKey / 2 + 1; ++i) {
			pTemp = pTemp->m_pNext;
		}
		return pTemp->m_pNext->m_nKey;
	}
}

// 从尾到头打印单链表
void PrintF(Node* p) {
	Node* pTemp = new Node;
	pTemp->m_nKey = 0;
	pTemp->m_pNext = nullptr;

	Node* pHead = p; // 临时

	// 临时头节点没有动
	while (pHead->m_pNext != nullptr) {
		Node* pNum = pHead->m_pNext;
		pHead->m_pNext = pHead->m_pNext->m_pNext;  // 临时头节点下一个节点给临时链表
		pNum->m_pNext = pTemp->m_pNext;  // 挂到临时链表
		pTemp->m_pNext = pNum;
	}

	Print(pTemp);

	// 释放临时空头节点
	delete pTemp;
	pTemp = nullptr;
}

// 已知两个单链表pHead1 和pHead2 各自有序，把它们合并成一个链表依然有序
Node* Merge(Node* p1, Node* p2) {
	Node* pTemp = new Node;
	pTemp->m_nKey = 0;
	pTemp->m_pNext = nullptr;

	Node* pHead1 = p1;
	Node* pHead2 = p2;

	while (true) {
		if (pHead1->m_pNext == nullptr) {  // pHead1 已经全部插入，则插入剩下的 pHear2
			while (pHead2->m_pNext != nullptr) {
				AddNode(pTemp, pHead2->m_pNext->m_nKey);
				pHead2 = pHead2->m_pNext;
			}
			break;
		}
		if (pHead2->m_pNext == nullptr) {  // pHear2 已经全部插入，则插入剩下的 pHead1
			while (pHead1->m_pNext != nullptr) {
				AddNode(pTemp, pHead1->m_pNext->m_nKey);
				pHead1 = pHead1->m_pNext;
			}
			break;
		}
		// 插入
		while (pHead1->m_pNext != nullptr && pHead2->m_pNext != nullptr) {
			if (pHead1->m_pNext->m_nKey > pHead2->m_pNext->m_nKey) {
				AddNode(pTemp, pHead2->m_pNext->m_nKey);
				pHead2 = pHead2->m_pNext;
			}
			else {
				AddNode(pTemp, pHead1->m_pNext->m_nKey);
				pHead1 = pHead1->m_pNext;
			}
		}
	}
	return pTemp;
}

// 判断一个单链表中是否有环
bool IsRing(Node* p) {
	// 直接判断尾指针是否指向链表中的某个节点
	Node* pTemp = p;
	if (pTemp->m_pNext == nullptr) {  // 
		return false;
	}
	else {
		Node* pHead = p;

		for (int i = 0; i < p->m_nKey; ++i) {  // pTemp 指向尾指针
			pTemp = pTemp->m_pNext;
		}
		for (int i = 0; i < p->m_nKey; ++i) {
			if (pHead->m_pNext == pTemp->m_pNext) {
				return true;
			}
			pHead = pHead->m_pNext;
		}
		return false;
	}
}

// 判断两个单链表是否相交
bool IsIntersect(Node* p1, Node* p2) {
	Node* p1Head = p1;
	Node* p2Head = p2;

	Node* p1Temp = p1;
	Node* p2Temp = p2;

	while (p1Head->m_pNext != nullptr) {
		Node* p2Head = p2;  // p2Head 重新指向头指针
		while (p2Head->m_pNext != nullptr) {
			if (p1Head->m_pNext == p2Head->m_pNext) {
				return true;
			}
			else {
				p2Head = p2Head->m_pNext;
			}
		}
		p1Head = p1Head->m_pNext;
	}

	return false;
}

// 求两个单链表相交的第一个节点
Node IntersectOneNode(Node* p1, Node* p2) {
	Node* p1Head = p1;
	Node* p2Head = p2;

	Node* pTemp = p1;

	while (p1Head->m_pNext != nullptr) {
		Node* p2Head = p2;  // p2Head 重新指向头指针
		while (p2Head->m_pNext != nullptr) {
			if (p1Head->m_pNext == p2Head->m_pNext) {
				return *p2Head->m_pNext;
			}
			else {
				p2Head = p2Head->m_pNext;
			}
		}
		p1Head = p1Head->m_pNext;
	}
}

// 已知一个单链表中存在环，求进入环中的第一个节点
Node* RingOneNode(Node* p) {
	Node* pTemp = p;
	for (int i = 0; i < p->m_nKey; ++i) {
		pTemp = pTemp->m_pNext;
	}
	return pTemp->m_pNext;
}

// 给出一单链表头指针pHead和一节点指针pToBeDeleted，O(1)时间复杂度删除节点pToBeDeleted

// 使用链表实现约瑟夫环(JosephCircle)问题


Node* m_p1 = nullptr;
Node* m_p2 = nullptr;
Node* pTemp = nullptr;

int main() {
	/**/
	// 求单链表中结点的个数
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	cout << "单链表中结点的个数 : " << ListSize(m_p1) << endl << endl;
	Clead_List(m_p1);


	// 链表反转
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	Print(m_p1);
	ReversalList(m_p1);
	cout << "反转之后：" << endl;
	Print(m_p1);
	cout << endl;
	Clead_List(m_p1);


	// 查找单链表中倒数第 k 个元素
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	Print(m_p1);
	cout << "第五个元素：" << search_Reciprocal(m_p1, 5) << endl << endl;
	Clead_List(m_p1);


	// 查找单链表的中间结点
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	Print(m_p1);
	cout << "中间结点元素：" << search_Middle(m_p1) << endl << endl;
	Clead_List(m_p1);


	// 从尾到头打印单链表
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	Print(m_p1);
	cout << "反向打印" << endl;
	PrintF(m_p1);
	cout << endl;
	Clead_List(m_p1);


	// 已知两个单链表pHead1 和pHead2 各自有序，把它们合并成一个链表依然有序
	Init_List(m_p1);
	Init_List(m_p2);
	for (int i = 1; i <= 20; ++i) {
		if (0 == i % 2) {

			AddNode(m_p1, i);
		}
		else {
			AddNode(m_p2, i);
		}
	}
	Print(m_p1);
	Print(m_p2);
	pTemp = Merge(m_p1, m_p2);
	cout << "合并之后 : " << endl;
	Print(pTemp);
	cout << endl;
	Clead_List(m_p1);
	Clead_List(m_p2);
	Clead_List(pTemp);


	// 判断一个单链表中是否有环
	Init_List(m_p1);
	pTemp = m_p1;
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	for (int i = 0; i < m_p1->m_nKey; ++i) {
		pTemp = pTemp->m_pNext;
	}
	Print(m_p1);
	pTemp->m_pNext = m_p1->m_pNext->m_pNext;

	cout << "IsRing : " << IsRing(m_p1) << endl << endl;
	Clead_List(m_p1);
	Clead_List(pTemp);


	// 判断两个单链表是否相交
	Init_List(m_p1);
	Init_List(m_p2);
	for (int i = 1; i <= 20; ++i) {
		if (0 == i % 2) {

			AddNode(m_p1, i);
		}
		else {
			AddNode(m_p2, i);
		}
	}
	Node* pTemp = m_p1;
	while (pTemp->m_pNext != nullptr) {
		pTemp = pTemp->m_pNext;
	}
	pTemp->m_pNext = m_p2->m_pNext;
	m_p1->m_nKey += m_p2->m_nKey - 1;
	Print(m_p1);
	Print(m_p2);
	cout << "IsIntersect : " << IsIntersect(m_p2, m_p1) << endl << endl;
	Clead_List(m_p1);
	Clead_List(m_p2);
	Clead_List(pTemp);


	// 求两个单链表相交的第一个节点
	Init_List(m_p1);
	Init_List(m_p2);
	for (int i = 1; i <= 20; ++i) {
		if (0 == i % 2) {

			AddNode(m_p1, i);
		}
		else {
			AddNode(m_p2, i);
		}
	}
	pTemp = m_p1;
	while (pTemp->m_pNext != nullptr) {
		pTemp = pTemp->m_pNext;
	}

	pTemp->m_pNext = m_p2->m_pNext;
	m_p1->m_nKey += m_p2->m_nKey - 1;

	if (IsIntersect(m_p2, m_p1)) {
		cout << "IntersectOneNode : " << IntersectOneNode(m_p2, m_p1).m_nKey << endl;
	}
	else {
		cout << " 不相交！！！ " << endl;
	}
	Print(m_p1);
	Print(m_p2);
	cout << endl;
	Clead_List(m_p1);
	Clead_List(m_p2);
	Clead_List(pTemp);


	// 已知一个单链表中存在环，求进入环中的第一个节点
	Init_List(m_p1);
	pTemp = m_p1;
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	for (int i = 0; i < m_p1->m_nKey; ++i) {
		pTemp = pTemp->m_pNext;
	}
	Print(m_p1);
	pTemp->m_pNext = m_p1->m_pNext;

	cout << "RingOneNode : " << RingOneNode(m_p1)->m_nKey << endl;
	Clead_List(m_p1);
	Clead_List(pTemp);

	// 给出一单链表头指针pHead和一节点指针pToBeDeleted，O(1)时间复杂度删除节点pToBeDeleted


	// 使用链表实现约瑟夫环(JosephCircle)问题


	return 0;
}
