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
	delete[]p;
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
	Node* pNum = new Node;
	pNum->m_nKey = number;
	pNum->m_pNext = nullptr;

	Node* pTemp = p;
	for (; pTemp->m_pNext != nullptr; pTemp = pTemp->m_pNext) {}

	pTemp->m_pNext = pNum;

	++p->m_nKey;
}

// �������н��ĸ���
int ListSize(Node* p) {
	return p->m_nKey;
}

// ����ת
void ReversalList(Node* p) {
	Node* pTemp = new Node;
	pTemp->m_nKey = 0;
	pTemp->m_pNext = nullptr;

	// ͷ�ڵ�û�ж�
	while (p->m_pNext != nullptr) {
		Node* pNum = p->m_pNext;
		p->m_pNext = p->m_pNext->m_pNext;  // ͷ�ڵ���һ���ڵ����ʱ����
		pNum->m_pNext = pTemp->m_pNext;  // ͷ�ڵ�ָ������һ���ڵ�
		pTemp->m_pNext = pNum;
	}

	p->m_pNext = pTemp->m_pNext;  // ͷ�ڵ�����ָ����ʱ����ĵ�һ��Ԫ��

	// �ͷ���ʱ��ͷ�ڵ�
	delete pTemp;
	pTemp = nullptr;
}

// ���ҵ������е����� k ��Ԫ��
int search_Reciprocal(Node* p, int k) {
	if (k > 0 && k <= p->m_nKey) {  // kֵ���жϣ�0 < k <= MaxSize
		Node* pTemp = p;
		for (int i = 0; i < p->m_nKey - k; ++i) {
			pTemp = pTemp->m_pNext;
		}
		return pTemp->m_nKey;
	}
	else {
		cout << " �������� " << endl;
		return 500;
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
	Node* pTemp = new Node;
	pTemp->m_nKey = 0;
	pTemp->m_pNext = nullptr;

	Node* pHead = p; // ��ʱ

	// ��ʱͷ�ڵ�û�ж�
	while (pHead->m_pNext != nullptr) {
		Node* pNum = pHead->m_pNext;
		pHead->m_pNext = pHead->m_pNext->m_pNext;  // ��ʱͷ�ڵ���һ���ڵ����ʱ����
		pNum->m_pNext = pTemp->m_pNext;  // �ҵ���ʱ����
		pTemp->m_pNext = pNum;
	}

	Print(pTemp);

	// �ͷ���ʱ��ͷ�ڵ�
	delete pTemp;
	pTemp = nullptr;
}

// ��֪����������pHead1 ��pHead2 �������򣬰����Ǻϲ���һ��������Ȼ����
Node* Merge(Node* p1, Node* p2) {
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
	if (pTemp->m_pNext == nullptr) {  // 
		return false;
	}
	else {
		Node* pHead = p;

		for (int i = 0; i < p->m_nKey; ++i) {  // pTemp ָ��βָ��
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

// �ж������������Ƿ��ཻ
bool IsIntersect(Node* p1, Node* p2) {
	Node* p1Head = p1;
	Node* p2Head = p2;

	Node* p1Temp = p1;
	Node* p2Temp = p2;

	while (p1Head->m_pNext != nullptr) {
		Node* p2Head = p2;  // p2Head ����ָ��ͷָ��
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

// �������������ཻ�ĵ�һ���ڵ�
Node IntersectOneNode(Node* p1, Node* p2) {
	Node* p1Head = p1;
	Node* p2Head = p2;

	Node* pTemp = p1;

	while (p1Head->m_pNext != nullptr) {
		Node* p2Head = p2;  // p2Head ����ָ��ͷָ��
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

// ��֪һ���������д��ڻ�������뻷�еĵ�һ���ڵ�
Node* RingOneNode(Node* p) {
	Node* pTemp = p;
	for (int i = 0; i < p->m_nKey; ++i) {
		pTemp = pTemp->m_pNext;
	}
	return pTemp->m_pNext;
}

// ����һ������ͷָ��pHead��һ�ڵ�ָ��pToBeDeleted��O(1)ʱ�临�Ӷ�ɾ���ڵ�pToBeDeleted

// ʹ������ʵ��Լɪ��(JosephCircle)����


Node* m_p1 = nullptr;
Node* m_p2 = nullptr;
Node* pTemp = nullptr;

int main() {
	/**/
	// �������н��ĸ���
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	cout << "�������н��ĸ��� : " << ListSize(m_p1) << endl << endl;
	Clead_List(m_p1);


	// ����ת
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	Print(m_p1);
	ReversalList(m_p1);
	cout << "��ת֮��" << endl;
	Print(m_p1);
	cout << endl;
	Clead_List(m_p1);


	// ���ҵ������е����� k ��Ԫ��
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	Print(m_p1);
	cout << "�����Ԫ�أ�" << search_Reciprocal(m_p1, 5) << endl << endl;
	Clead_List(m_p1);


	// ���ҵ�������м���
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	Print(m_p1);
	cout << "�м���Ԫ�أ�" << search_Middle(m_p1) << endl << endl;
	Clead_List(m_p1);


	// ��β��ͷ��ӡ������
	Init_List(m_p1);
	for (int i = 1; i <= 10; ++i) {
		AddNode(m_p1, i);
	}
	Print(m_p1);
	cout << "�����ӡ" << endl;
	PrintF(m_p1);
	cout << endl;
	Clead_List(m_p1);


	// ��֪����������pHead1 ��pHead2 �������򣬰����Ǻϲ���һ��������Ȼ����
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
	cout << "�ϲ�֮�� : " << endl;
	Print(pTemp);
	cout << endl;
	Clead_List(m_p1);
	Clead_List(m_p2);
	Clead_List(pTemp);


	// �ж�һ�����������Ƿ��л�
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


	// �ж������������Ƿ��ཻ
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


	// �������������ཻ�ĵ�һ���ڵ�
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
		cout << " ���ཻ������ " << endl;
	}
	Print(m_p1);
	Print(m_p2);
	cout << endl;
	Clead_List(m_p1);
	Clead_List(m_p2);
	Clead_List(pTemp);


	// ��֪һ���������д��ڻ�������뻷�еĵ�һ���ڵ�
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

	// ����һ������ͷָ��pHead��һ�ڵ�ָ��pToBeDeleted��O(1)ʱ�临�Ӷ�ɾ���ڵ�pToBeDeleted


	// ʹ������ʵ��Լɪ��(JosephCircle)����


	return 0;
}
