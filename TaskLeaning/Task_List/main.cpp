#include<iostream>
using namespace std;

//�������������£�
struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

#define Node ListNode

// ��ʼ�������ͷ�ڵ�
void Init_List(Node*& p) {
	p = new Node;
	p->m_nKey = 0;
	p->m_pNext = nullptr;
}

// �������
void Clead_List(Node*& p) {
	p->m_nKey = 0;
	while (p!=nullptr) {
		Node* pTemp = p;
		p = p->m_pNext;

		delete pTemp;
		pTemp = nullptr;
	}
	p = nullptr;
}

// ��ͷ��ӡ����
void Print(Node* p) {
	Node* pTemp = p;
	for (; pTemp->m_pNext != nullptr; pTemp = pTemp->m_pNext) {
		cout << pTemp->m_pNext->m_nKey << endl;
	}
	cout << " ----- ----- " << endl;
}

// Ϊ���п�ͷ�ڵ㣬β����һ���ڵ�
void AddNode(Node* p, int number) {
	// �½ڵ�
	Node* pNum = new Node;
	pNum->m_nKey = number;
	pNum->m_pNext = nullptr;

	// ��ȡβ�ڵ�
	Node* pTemp = p;
	for (; pTemp->m_pNext != nullptr; pTemp = pTemp->m_pNext) {}

	// �½ڵ����ӵ�β�ڵ�֮��
	pTemp->m_pNext = pNum;

	++p->m_nKey;  // ���ȼ�һ
}

// �������н��ĸ���
int ListSize(Node* p) {
	return p->m_nKey;  // ��ͷ�ڵ��������泤��
}

// ����ת
void ReversalList(Node* p) {
	// ��ʱ��ͷ�ڵ�
	Node* pTemp = new Node;
	pTemp->m_nKey = 0;
	pTemp->m_pNext = nullptr;

	// ��ͷ�ڵ㣬���ƣ���������
	while (p->m_pNext != nullptr) {
		// ���浱ǰ��ͷ�ڵ��ָ��ڵ㣬��ͷ�ڵ���ָ�����¸��ڵ�
		Node* pNum = p->m_pNext;
		p->m_pNext = p->m_pNext->m_pNext;

		// ͷ�巨�����ʱ����
		pNum->m_pNext = pTemp->m_pNext;
		pTemp->m_pNext = pNum;
	}

	// ��ͷ�ڵ�����ָ����ʱ����ĵ�һ��Ԫ��
	p->m_pNext = pTemp->m_pNext;  

	// �ͷ���ʱ��ͷ�ڵ�
	delete pTemp;
	pTemp = nullptr;
}

// ���ҵ������е����� k ��Ԫ��
int search_Reciprocal(Node* p, int k) {
	if (k > 0 && k <= p->m_nKey) {  // kֵ���жϣ�0 < k <= MaxSize
		Node* pTemp = p;

		// ��������Ϊ 5 ����Ҫ���ҵ����� 4 ��Ԫ�أ�
		// ��Ϊ���п�ͷ�ڵ㣬���Ծ��������� 5 - 4 + 1 = 2 ��
		for (int i = 0; i < p->m_nKey - k + 1; ++i) {
			pTemp = pTemp->m_pNext;
		}
		return pTemp->m_nKey;
	}
	else {
		cout << " �������� " << endl;
		return p->m_nKey;  // ����������
	}
}

// ���ҵ�������м���
int search_Middle(Node* p) {
	if (0 == p->m_nKey % 2) {  // Ϊż�������� num / 2 
		Node* pTemp = p;
		for (int i = 1; i < p->m_nKey / 2; ++i) {
			pTemp = pTemp->m_pNext;
		}
		return pTemp->m_pNext->m_nKey;
	}
	else {  // Ϊ���������� num / 2 + 1
		Node* pTemp = p;
		for (int i = 1; i < p->m_nKey / 2 + 1; ++i) {
			pTemp = pTemp->m_pNext;
		}
		return pTemp->m_pNext->m_nKey;
	}
}

// ��β��ͷ��ӡ������
void PrintF(Node* p) {
	// ��ʱ��ͷ�ڵ�
	Node* pTemp = new Node;
	pTemp->m_nKey = 0;
	pTemp->m_pNext = nullptr;

	Node* phead = p; // ��ʱ

	// ��ʱͷ�ڵ�û�ж�
	while (phead->m_pNext != nullptr) {
		Node* pNum = new Node;
		pNum->m_nKey = phead->m_pNext->m_nKey;		// ��ʱ��ͷ�ڵ���һ���ڵ��Ԫ�ظ���ʱ����
		pNum->m_pNext = nullptr;
		phead->m_pNext = phead->m_pNext->m_pNext;	// ��ʱ��ͷ�ڵ�ָ�����¸��ڵ�

		// ͷ��ҵ���ʱ����
		pNum->m_pNext = pTemp->m_pNext;  
		pTemp->m_pNext = pNum;
	}

	Print(pTemp);

	// �ͷ���ʱ����
	Clead_List(pTemp);
}

// ��֪����������pHead1 ��pHead2 �������򣬰����Ǻϲ���һ��������Ȼ����
Node* Merge(Node* p1, Node* p2) {
	// ��ʱ��ͷ�ڵ�
	Node* pTemp = new Node;
	pTemp->m_nKey = 0;
	pTemp->m_pNext = nullptr;

	Node* pHead1 = p1;
	Node* pHead2 = p2;

	while (true) {
		if (pHead1->m_pNext == nullptr) {  // pHead1 �Ѿ�ȫ�����룬�����ʣ�µ� pHear2
			while (pHead2->m_pNext != nullptr) {
				AddNode(pTemp, pHead2->m_pNext->m_nKey);
				pHead2 = pHead2->m_pNext;
			}
			break;
		}
		if (pHead2->m_pNext == nullptr) {  // pHear2 �Ѿ�ȫ�����룬�����ʣ�µ� pHead1
			while (pHead1->m_pNext != nullptr) {
				AddNode(pTemp, pHead1->m_pNext->m_nKey);
				pHead1 = pHead1->m_pNext;
			}
			break;
		}
		// ����
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

// �ж�һ�����������Ƿ��л�
bool IsRing(Node* p) {
	// ֱ���ж�βָ���Ƿ�ָ�������е�ĳ���ڵ�
	Node* pTemp = p;
	if (pTemp->m_pNext == nullptr) {  // û��Ԫ�ؽڵ�
		return false;
	}
	else {
		Node* pHead = p;  // ����ָ��

		for (int i = 0; i < p->m_nKey; ++i) {  // pTemp ָ��β�ڵ�
			pTemp = pTemp->m_pNext;
		}
		for (int i = 0; i < p->m_nKey; ++i) {  // �ӵ�һ��Ԫ�ؿ�ʼ�����ж��Ƿ����
			if (pHead->m_pNext == pTemp->m_pNext) {
				return true;
			}
			pHead = pHead->m_pNext;// ����ָ�����
		}
		return false;
	}
}

// ֱ�ӱ�������
void DeleteRing(Node*& p) {
	Node* pTemp = p;
	for (int i = 0; i < p->m_nKey; ++i) {
		pTemp = pTemp->m_pNext;
	}
	pTemp->m_pNext = nullptr;
}

// �ж������������Ƿ��ཻ
bool IsIntersect(Node* p1, Node* p2) {
	Node* p1Head = p1;

	while (p1Head->m_pNext != nullptr) {
		Node* p2Head = p2;  // ÿһ�α����ȽϿ�ʼǰ p2Head ָ��ͷָ��
		while (p2Head->m_pNext != nullptr) {
			if (p1Head->m_pNext == p2Head->m_pNext) {
				return true;
			}
			else {
				p2Head = p2Head->m_pNext;  // ���κ���
			}
		}
		p1Head = p1Head->m_pNext;  // ���κ���
	}
	return false;
}

// �������������ཻ�ĵ�һ���ڵ�
Node IntersectOneNode(Node* p1, Node* p2) {
	Node* p1Head = p1;

	Node* pTemp = p1;

	while (p1Head->m_pNext != nullptr) {
		Node* p2Head = p2;  // ÿһ�α����ȽϿ�ʼǰ p2Head ָ��ͷָ��
		while (p2Head->m_pNext != nullptr) {
			if (p1Head->m_pNext == p2Head->m_pNext) {
				return *p2Head->m_pNext;
			}
			else {
				p2Head = p2Head->m_pNext;  // ���κ���
			}
		}
		p1Head = p1Head->m_pNext;  // ���κ���
	}
}

// ��֪һ���������д��ڻ�������뻷�еĵ�һ���ڵ�
Node* RingOneNode(Node* p) {
	Node* pTemp = p;
	for (int i = 0; i < p->m_nKey; ++i) {  // ������β�ڵ㣬�е�͵��������
		pTemp = pTemp->m_pNext;
	}
	return pTemp->m_pNext;
}

// ����һ������ͷָ��pHead��һ�ڵ�ָ��pToBeDeleted��O(1)ʱ�临�Ӷ�ɾ���ڵ�pToBeDeleted
void DeleteO_ONE(ListNode* pHead, ListNode* pToBeDeleted) {
	if (pToBeDeleted == nullptr) {
		return;
	}
	if (pToBeDeleted->m_pNext != nullptr) {  // �������һ���ڵ�
		pToBeDeleted->m_nKey = pToBeDeleted->m_pNext->m_nKey; // ����һ���ڵ�����ݸ��Ƶ����ڵ㣬Ȼ��ɾ����һ���ڵ�  
		ListNode* temp = pToBeDeleted->m_pNext;
		pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
		delete temp;
	}
	else {  // Ҫɾ���������һ���ڵ�  
		if (pHead == pToBeDeleted) {  // ������ֻ��һ���ڵ�����  
			pHead = nullptr;
			delete pToBeDeleted;
		}
		else {
			ListNode* pNode = pHead;
			while (pNode->m_pNext != pToBeDeleted) // �ҵ������ڶ����ڵ�  
				pNode = pNode->m_pNext;
			pNode->m_pNext = nullptr;
			delete pToBeDeleted;
		}
	}
}

// ʹ������ʵ��Լɪ��(JosephCircle)����
Node* JosephCircle(Node* pHead, unsigned int k) {
	Node* pTemp = pHead->m_pNext; // pTempָ���һ��Ԫ�ؽڵ�
	while (pTemp->m_pNext != nullptr) {  // ������β�ڵ�
		pTemp = pTemp->m_pNext;
	}

	pTemp->m_pNext = pHead->m_pNext; // β�ڵ��NextΪ��һ��Ԫ�ؽڵ�
	pTemp = pHead->m_pNext;// ����ָ���һ��Ԫ��

	while (pTemp->m_pNext != pTemp) {  // ����Ϊһ���ڵ�
		int i = k;
		while (--i) {  // ������ k �ڵ㣬���� k = 3 ʱ����Ϊ��ǰΪһ���������������Ρ�
			pTemp = pTemp->m_pNext;
		}
		// ɾ����ǰԪ�أ����ǵ�ǰ�ڵ�
		Node* pNum = pTemp->m_pNext;
		pTemp->m_nKey = pNum->m_nKey;
		pTemp->m_pNext = pNum->m_pNext;

		delete pNum;
		pNum = nullptr;
	}

	pTemp->m_pNext = nullptr;
	return pTemp;
}

Node* m_p1 = nullptr;
Node* m_p2 = nullptr;
Node* pTemp = nullptr;

int main() {
	//// �������н��ĸ���
	//Init_List(m_p1);
	//for (int i = 1; i <= 10; ++i) {
	//	AddNode(m_p1, i);
	//}
	//cout << "�������н��ĸ��� : " << ListSize(m_p1) << endl << endl;
	//Clead_List(m_p1);


	//// ����ת
	//Init_List(m_p1);
	//for (int i = 1; i <= 10; ++i) {
	//	AddNode(m_p1, i);
	//}
	//Print(m_p1);
	//ReversalList(m_p1);
	//cout << "��ת֮��" << endl;
	//Print(m_p1);
	//cout << endl;
	//Clead_List(m_p1);


	//// ���ҵ������е����� k ��Ԫ��
	//Init_List(m_p1);
	//for (int i = 1; i <= 10; ++i) {
	//	AddNode(m_p1, i);
	//}
	//Print(m_p1);
	//cout << "�������Ԫ�أ�" << search_Reciprocal(m_p1, 5) << endl << endl;
	//Clead_List(m_p1);


	//// ���ҵ�������м���
	//Init_List(m_p1);
	//for (int i = 1; i <= 3; ++i) {
	//	AddNode(m_p1, i);
	//}
	//Print(m_p1);
	//cout << "�м���Ԫ�أ�" << search_Middle(m_p1) << endl << endl;
	//Clead_List(m_p1);


	//// ��β��ͷ��ӡ������
	//Init_List(m_p1);
	//for (int i = 1; i <= 10; ++i) {
	//	AddNode(m_p1, i);
	//}
	//Print(m_p1);
	//cout << "�����ӡ" << endl;
	//PrintF(m_p1);
	//Print(m_p1);
	//cout << endl;
	//Clead_List(m_p1);


	//// ��֪����������pHead1 ��pHead2 �������򣬰����Ǻϲ���һ��������Ȼ����
	//Init_List(m_p1);
	//Init_List(m_p2);
	//for (int i = 1; i <= 20; ++i) {
	//	if (0 == i % 2) {
	//		AddNode(m_p1, i);
	//	}
	//	else {
	//		AddNode(m_p2, i);
	//	}
	//}
	//Print(m_p1);
	//Print(m_p2);
	//pTemp = Merge(m_p1, m_p2);
	//cout << "�ϲ�֮�� : " << endl;
	//Print(pTemp);
	//cout << endl;
	//Clead_List(m_p1);
	//Clead_List(m_p2);
	//Clead_List(pTemp);


	//// �ж�һ�����������Ƿ��л�
	//Init_List(m_p1);
	//pTemp = m_p1;
	//for (int i = 1; i <= 10; ++i) {
	//	AddNode(m_p1, i);
	//}
	//for (int i = 0; i < m_p1->m_nKey; ++i) {
	//	pTemp = pTemp->m_pNext;
	//}
	//Print(m_p1);
	//pTemp->m_pNext = m_p1->m_pNext->m_pNext;
	//cout << "IsRing : " << IsRing(m_p1) << endl << endl;
	//DeleteRing(m_p1);
	//Clead_List(m_p1);


	//// �ж������������Ƿ��ཻ
	//Init_List(m_p1);
	//Init_List(m_p2);
	//for (int i = 1; i <= 20; ++i) {
	//	if (0 == i % 2) {
	//		AddNode(m_p1, i);
	//	}
	//	else {
	//		AddNode(m_p2, i);
	//	}
	//}
	//Node* pTemp = m_p1;
	//while (pTemp->m_pNext != nullptr) {
	//	pTemp = pTemp->m_pNext;
	//}
	//pTemp->m_pNext = m_p2->m_pNext;
	//m_p1->m_nKey += m_p2->m_nKey - 1;
	//Print(m_p1);
	//Print(m_p2);
	//cout << "IsIntersect : " << IsIntersect(m_p2, m_p1) << endl << endl;
	//Clead_List(m_p1);
	//Clead_List(m_p2);
	//Clead_List(pTemp);


	//// �������������ཻ�ĵ�һ���ڵ�
	//Init_List(m_p1);
	//Init_List(m_p2);
	//for (int i = 1; i <= 20; ++i) {
	//	if (0 == i % 2) {
	//		AddNode(m_p1, i);
	//	}
	//	else {
	//		AddNode(m_p2, i);
	//	}
	//}
	//pTemp = m_p1;
	//while (pTemp->m_pNext != nullptr) {
	//	pTemp = pTemp->m_pNext;
	//}
	//pTemp->m_pNext = m_p2->m_pNext;
	//m_p1->m_nKey += m_p2->m_nKey - 1;
	//if (IsIntersect(m_p2, m_p1)) {
	//	cout << "IntersectOneNode : " << IntersectOneNode(m_p2, m_p1).m_nKey << endl;
	//}
	//else {
	//	cout << " ���ཻ������ " << endl;
	//}
	//Print(m_p1);
	//Print(m_p2);
	//cout << endl;
	//Clead_List(m_p1);
	//Clead_List(m_p2);
	//Clead_List(pTemp);


	//// ��֪һ���������д��ڻ�������뻷�еĵ�һ���ڵ�
	//Init_List(m_p1);
	//pTemp = m_p1;
	//for (int i = 1; i <= 10; ++i) {
	//	AddNode(m_p1, i);
	//}
	//for (int i = 0; i < m_p1->m_nKey; ++i) {
	//	pTemp = pTemp->m_pNext;
	//}
	//Print(m_p1);
	//pTemp->m_pNext = m_p1->m_pNext;
	//cout << "RingOneNode : " << RingOneNode(m_p1)->m_nKey << endl;
	//Clead_List(m_p1);
	//Clead_List(pTemp);

	//// ����һ������ͷָ��pHead��һ�ڵ�ָ��pToBeDeleted��O(1)ʱ�临�Ӷ�ɾ���ڵ�pToBeDeleted
	//Init_List(m_p1);
	//pTemp = m_p1;
	//for (int i = 1; i <= 10; ++i) {
	//	AddNode(m_p1, i);
	//}
	//for (int i = 0; i < 6; ++i) {
	//	pTemp = pTemp->m_pNext;
	//}
	//cout << "pTemp : " << pTemp << endl;
	//Print(m_p1);
	//DeleteO_ONE(m_p1, pTemp);
	//Print(m_p1);
	//Clead_List(m_p1);

	//cout << "***** ***** ***** *****" << endl;
	//// ʹ������ʵ��Լɪ��(JosephCircle)����
	//Init_List(m_p1);
	//for (int i = 1; i <= 5; ++i) {
	//	AddNode(m_p1, i);
	//}
	//Print(m_p1);
	//cout << "JosephCircle : " << JosephCircle(m_p1, 3)->m_nKey << endl;
	//Clead_List(m_p1);
	//Init_List(m_p1);
	//Print(m_p1);
	//Clead_List(m_p1);

	return 0;
}
