#include"DoubleList.h"

/*
* ˽�г�Ա
*/
/***********************************************************************
* �� �� ����__InitList()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����ʼ�������ͷ�ڵ㣬��ʼ������β�ڵ㲢ָ��ͷ���
*			-- 2 -- ��������Ϊ��
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void DoubleList::__InitList() {
	// ��ʼ�������ͷ�ڵ�
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// ��ʼ������β�ڵ㲢ָ��ͷ���
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;
}

/*
* ���г�Ա
*/
/***********************************************************************
* �� �� ����DoubleList()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���޲ι��캯����
*			-- 2 -- ����ʼ����ͷ�ڵ㣬��ʼ��β�ڵ㲢ָ��ͷ��㡣
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �����ǰ����������ȫ�����ɵ���˽�г�Ա����  __InitList()
***********************************************************************/
DoubleList::DoubleList() {
	this->__InitList();  // ��ʼ������
}

/***********************************************************************
* �� �� ����DoubleList(int num)
* �� �� ��
*			1 ) num -->( int ) : ��Ҫ��ʼ������Ľڵ����
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���вι���
*			-- 2 -- ����ʼ����ͷ�ڵ㣬��ʼ��β�ڵ㲢ָ��ͷ��㡣
*			-- 3 -- ������ 1~num ����������
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �����ǰ������ͷ�巨���ɵ��˹��г�Ա���� AddHeadNum(int num)
***********************************************************************/
DoubleList::DoubleList(int num) {
	this->__InitList();  // ��ʼ������

	for (int i = num; i >= 1; --i) {
		this->AddHeadNum(i);  // ͷ�巨
	}
}

/***********************************************************************
* �� �� ����DoubleList(int n, int num)
* �� �� ��
*			1 ) n ---->( int ) : ��Ҫ��ʼ������Ľڵ����
*			2 ) num -->( int ) : ����ÿ���ڵ��������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���вι���
*			-- 2 -- ����ʼ����ͷ�ڵ㣬��ʼ��β�ڵ㲢ָ��ͷ��㡣
*			-- 3 -- ������ֵ��Ϊ num ������
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �����ǰ������ͷ�巨���ɵ��˹��г�Ա���� AddHeadNum(int num)
***********************************************************************/
DoubleList::DoubleList(int n, int num) {
	this->__InitList();  // ��ʼ������

	for (int i = n; i >= 1; --i) {
		this->AddHeadNum(num);  // ͷ�巨
	}
}

/***********************************************************************
* �� �� ����DoubleList(int* Begin, int* End)
* �� �� ��
*			1 ) Begin --->( int* ) : �����ڴ�ĵ�һ����ַ
*			2 ) End   --->( int* ) : �����ڴ�����һ����ַ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���вι���
*			-- 2 -- ����ʼ����ͷ�ڵ㣬��ʼ��β�ڵ㲢ָ��ͷ��㡣
*			-- 3 -- ������ֵΪһ�������ڴ��ڵ�ֵ������
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �����ǰ������ͷ�巨���ɵ��˹��г�Ա���� AddHeadNum(int num)
***********************************************************************/
DoubleList::DoubleList(int* Begin, int* End) {
	this->__InitList();  // ��ʼ������

	for (int* pNum = Begin; pNum < End; ++pNum) {
		this->AddEndNum(*pNum);  // ͷ�巨
	}
}

/***********************************************************************
* �� �� ����DoubleList(const DoubleList& other)
* �� �� ��
*			1 ) other -->( const DoubleList& ) : ����һ����������
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- �����ƹ��캯��
*			-- 2 -- ����ʼ����ͷ�ڵ㣬��ʼ��β�ڵ㲢ָ��ͷ��㡣
*			-- 3 -- �����һ��ֻ��ֵ��ͬ������
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �����ǰ������β�巨���ɵ��˹��г�Ա���� AddEndNum(int num)
***********************************************************************/
DoubleList::DoubleList(const DoubleList& other) {
	this->__InitList();  // ��ʼ������

	Node* pNum = other.m_pHead->NextNode;  // ����ͷ�ڵ����һ���ڵ�

	// �������β�巨
	while (pNum != nullptr) {
		this->AddEndNum(pNum->number);  // β�巨

		// ָ�����
		pNum = pNum->NextNode;
	}
}

/***********************************************************************
* �� �� ����~DoubleList()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����������
*			-- 2 -- �������ͷ�
*			-- 3 -- ��β�ڵ��ǵ����ͷŵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �������ͷ���β�ڵ�
***********************************************************************/
DoubleList::~DoubleList() {
	Node* pTemp = nullptr;  // ��ʱ����ڵ�

	// �����ͷ�β�ڵ�
	delete this->m_pEnd;
	this->m_pEnd = nullptr;

	// ��ͷ�ڵ㿪ʼ����ͷŽڵ�
	while (this->m_pHead != nullptr) {
		pTemp = this->m_pHead;
		this->m_pHead = this->m_pHead->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	// ��������Ϊ��
	this->m_Len = 0;
}

/***********************************************************************
* �� �� ����operator+(const DoubleList& other)
* �� �� ��
*			1 ) other -->( const DoubleList& ) : ����һ����������
* �� �� ֵ��
*			1 ) DoubleList : ���ص��������
* �������ܣ�
*			-- 1 -- ���ӷ����غ���
*			-- 2 -- ��β�巨
*			-- 3 -- ����ǰ��������һ�ڵ��һ�������ֵ
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �����ǰ������β�巨���ɵ��˹��г�Ա���� AddEndNum(int num)
***********************************************************************/
DoubleList DoubleList::operator+(const DoubleList& other) {
	Node* pOther = other.m_pHead->NextNode;  // ���洫������ͷ�ڵ����һ���ڵ�

	// �������������
	while (pOther != nullptr) {
		this->AddEndNum(pOther->number);  // β�巨

		// ָ�����
		pOther = pOther->NextNode;
	}
	return *this;
}

/***********************************************************************
* �� �� ����operator=(const DoubleList& other)
* �� �� ��
*			1 ) other -->( const DoubleList& ) : ����һ����������
* �� �� ֵ��
*			1 ) DoubleList : ���ص��������
* �������ܣ�
*			-- 1 -- ���������غ���
*			-- 2 -- ��β�巨
*			-- 3 -- ����ǰ�����ֵΪ����һ�������ֵ�����
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �����ǰ������β�巨���ɵ��˹��г�Ա���� AddEndNum(int num)
***********************************************************************/
DoubleList DoubleList::operator=(const DoubleList& other) {
	this->__InitList();  // ��ʼ������

	Node* pOther = other.m_pHead->NextNode;  // ���洫������ͷ�ڵ����һ���ڵ�

	// �������������
	while (pOther != nullptr) {
		this->AddEndNum(pOther->number);  // β�巨

		// ָ�����
		pOther = pOther->NextNode;
	}
	return *this;
}

/***********************************************************************
* �� �� ����PrintTable()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����ͷ�ڵ���һ���ڵ��ӡȫ�������ֵ
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �������������ȵĴ�ӡ
***********************************************************************/
void DoubleList::PrintTable() {
	Node* pPint = this->m_pHead->NextNode;  // ��������ͷ�ڵ����һ���ڵ�

	// ��ӡ������
	cout << "m_Len : " << this->m_Len << endl;

	// ������ӡ����
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;
		pPint = pPint->NextNode; // ָ�����
	}
	cout << endl << "--------------------" << endl << endl;
}

/***********************************************************************
* �� �� ����AddHeadNum(int num)
* �� �� ��
*			1 ) num -->( int ) : ���������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������ֵ�������ͷ��
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void DoubleList::AddHeadNum(int num) {
	// ��ʼ���½ڵ�
	Node* pNew = new Node;
	pNew->number = num;
	pNew->FrontNode = pNew->NextNode = nullptr;

	if (0 == this->m_Len) {  // ����Ϊ��
		// ��ͷ�ڵ��������µĽڵ�
		this->m_pHead->NextNode = pNew;
		pNew->FrontNode = this->m_pHead;

		// β�ڵ�ָ�����һ���ڵ�
		this->m_pEnd->NextNode = pNew;

		// ��������һ
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {  // ����Ϊ��
		// ��ͷ�ڵ�����µĽڵ�
		pNew->NextNode = this->m_pHead->NextNode;
		pNew->FrontNode = this->m_pHead;
		this->m_pHead->NextNode = pNew;
		pNew->NextNode->FrontNode = pNew;

		// ��������һ
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

/***********************************************************************
* �� �� ����AddEndNum(int num)
* �� �� ��
*			1 ) num -->( int ) : ���������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������ֵ�������β��
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void DoubleList::AddEndNum(int num) {
	// ��ʼ���½ڵ�
	Node* pNew = new Node;
	pNew->number = num;
	pNew->FrontNode = pNew->NextNode = nullptr;

	// �����½ڵ㵽����β��
	this->m_pEnd->NextNode->NextNode = pNew;
	pNew->FrontNode = this->m_pEnd->NextNode;

	// β�ڵ�ָ�����һ���ڵ�
	this->m_pEnd->NextNode = pNew;

	// ��������һ
	++this->m_Len;
	this->m_pHead->number = this->m_Len;
	this->m_pEnd->number = this->m_Len;
}

/***********************************************************************
* �� �� ����AddIndexNum(int index, int num)
* �� �� ��
*			1 ) index -->( int ) : ���������λ��
*			2 ) num -->( int ) : ���������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������ֵ num ������� index λ��
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void DoubleList::AddIndexNum(int index, int num) {
	if (index > 0 && index <= this->m_Len + 1) {  // ������ȷ
		if (this->m_Len + 1 == index) {  // ���λ��
			this->AddEndNum(num);    // β�巨
		}
		else {  // �����λ��
			// ��ʼ���½ڵ�
			Node* pNew = new Node;
			pNew->number = num;
			pNew->FrontNode = pNew->NextNode = nullptr;

			// ����������λ��ǰһ���ڵ�
			Node* pIndex = this->m_pHead;
			for (int i = 1; i < index; i++) {
				pIndex = pIndex->NextNode;
			}

			// �����½ڵ��� index λ��
			pNew->NextNode = pIndex->NextNode;
			pNew->FrontNode = pIndex;
			pIndex->NextNode = pNew;
			pNew->NextNode->FrontNode = pNew;

			// ��������һ
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
		}
	}
	else {  // ��������
		cout << "����λ������" << endl;
	}
}

/***********************************************************************
* �� �� ����DeleteHeadNum()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ�������һ���ڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
***********************************************************************/
void DoubleList::DeleteHeadNum() {
	if (this->m_Len == 0) {   // ����Ϊ��
		cout << "����Ϊ�գ�" << endl;
	}
	else if (this->m_Len == 1) {  // ������Ϊһ
		Node* pTemp = this->m_pHead->NextNode;  // ��������ͷ�ڵ����һ���ڵ�

		// �Ͽ���һ���ڵ�
		this->m_pEnd->NextNode = this->m_pHead;
		this->m_pHead->NextNode = nullptr;

		// ��ӡ��ɾ���Ľڵ���Ϣ
		cout << "ɾ�� : " << pTemp->number << endl;
		cout << "λ�� : 1 " << endl;

		// �ͷű��Ͽ��Ľڵ�
		delete pTemp;
		pTemp = nullptr;

		// ���ȼ���һ
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {  // �����Ȳ�Ϊһ
		Node* pTemp = this->m_pHead->NextNode;  // ��������ͷ�ڵ����һ���ڵ�

		// �Ͽ���һ���ڵ�
		this->m_pHead->NextNode = pTemp->NextNode;
		pTemp->NextNode->FrontNode = this->m_pHead;

		// ��ӡ��ɾ���Ľڵ���Ϣ
		cout << "ɾ�� : " << pTemp->number << endl;
		cout << "λ�� : 1 " << endl;

		// �ͷű��Ͽ��Ľڵ�
		delete pTemp;
		pTemp = nullptr;

		// ���ȼ���һ
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

/***********************************************************************
* �� �� ����DeleteEndNum()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ����������һ���ڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
***********************************************************************/
void DoubleList::DeleteEndNum() {
	if (0 == this->m_Len) {  // ����Ϊ��
		cout << "����Ϊ�գ�" << endl;
	}
	else if (1 == this->m_Len) {  // ������Ϊһ
		Node* pTemp = this->m_pHead->NextNode;  // ��������ͷ�ڵ����һ���ڵ�

		// �Ͽ����һ���ڵ�
		this->m_pEnd->NextNode = this->m_pHead;
		this->m_pHead->NextNode = nullptr;

		// ��ӡ��ɾ���Ľڵ���Ϣ
		cout << "ɾ�� : " << pTemp->number << endl;
		cout << "λ�� : 1 " << endl;

		// �ͷű��Ͽ��Ľڵ�
		delete pTemp;
		pTemp = nullptr;

		// ���ȼ���һ
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {
		Node* pTemp = this->m_pEnd->NextNode;  // �����������һ���ڵ�

		// �Ͽ����һ���ڵ�
		this->m_pEnd->NextNode = pTemp->FrontNode;
		this->m_pEnd->NextNode->NextNode = nullptr;

		// ��ӡ��ɾ���Ľڵ���Ϣ
		cout << "ɾ�� : " << pTemp->number << endl;
		cout << "λ�� : " << this->m_Len << " " << endl;

		// �ͷű��Ͽ��Ľڵ�
		delete pTemp;
		pTemp = nullptr;

		// ���ȼ���һ
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

/***********************************************************************
* �� �� ����DeleteIndexNum(int index)
* �� �� ��
*			1 ) : index -->( int ) ɾ�������λ��
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ������indexλ�õĽڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
* *					2 ������������Ϊ����ж�
***********************************************************************/
void DoubleList::DeleteIndexNum(int index) {
	if (0 == this->m_Len) {  // ����Ϊ��
		cout << "����Ϊ�գ�" << endl;
	}
	else {  // ����Ϊ��
		if (index > 0 && index <= this->m_Len) {  // ������ȷ
			if (1 == index) {  // ��һ���ڵ�
				this->DeleteHeadNum();  // ɾ��ͷ�ڵ�
			}
			else if (index == this->m_Len) {  // ���һ���ڵ�
				this->DeleteEndNum();  // ɾ��β�ڵ�
			}
			else {  // ��ͷβ�ڵ�
				Node* pIndex = this->m_pHead->NextNode;  // ���������һ���ڵ�

				// ��������Ҫɾ���ڵ�ǰһ���ڵ�
				for (int i = 1; i < index; i++) {
					pIndex = pIndex->NextNode;
				}

				// �Ͽ���ɾ���ڵ�
				Node* pTemp = pIndex->NextNode;
				pIndex->NextNode = pTemp->NextNode;
				pTemp->NextNode->FrontNode = pIndex;

				// ��ӡ��ɾ���Ľڵ���Ϣ
				cout << "ɾ�� : " << pTemp->number << endl;
				cout << "λ�� : " << index << " " << endl;

				// �ͷű��Ͽ��Ľڵ�
				delete pTemp;
				pTemp = nullptr;

				// ���ȼ���һ
				--this->m_Len;
				this->m_pHead->number = this->m_Len;
				this->m_pEnd->number = this->m_Len;
			}
		}
		else {  // ��������
			cout << "����λ������" << endl;
		}
	}

}

/***********************************************************************
* �� �� ����DeleteNum(int num, bool flag)
* �� �� ��
*			1 ) : num --->( int ) ��ɾ����ֵ
*			2 ) : flag -->( int ) ȫ��ɾ������numֵ�ı�־
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ������ num ֵ�ĵ�һ���ڵ�
*			-- 2 -- ��flag ( true ) ��Ϣȫ��ɾ������ num ֵ�Ľڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
***********************************************************************/
void DoubleList::DeleteNum(int num, bool flag) {  // flagΪtrue,ȫ��ɾ��
	Node* pTemp = this->m_pHead;  // ����ͷ�ڵ�
	Node* pNum = nullptr;         // �������ݵĽڵ�

	int posindex = 1;  // ��ɾ���ڵ�λ��

	while (pTemp->NextNode != nullptr) {  // ����Ϊ��
		if (pTemp->NextNode == this->m_pEnd->NextNode &&
			pTemp->NextNode->number == num) {  // Ϊ���һ���ڵ㣬����ֵΪ num 
			this->DeleteEndNum();
		}
		else if (pTemp->NextNode->number == num) {  // ��Ϊ���һ���ڵ㣬����ֵΪ num
			/*********************
			* ɾ��Ŀ��ڵ㣬���ͷ�
			* ע��ɾ��֮���ǲ����ƶ���
			* ��Ϊ����Ľڵ㱻��������
			*********************/

			// �Ͽ���ɾ���ڵ�
			Node* pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;
			pNum->NextNode->FrontNode = pTemp;

			// ��ӡ��ɾ���Ľڵ���Ϣ
			cout << "ɾ�� : " << pNum->number << endl;
			cout << "λ�� : " << posindex << " " << endl;

			// �ͷű��Ͽ��Ľڵ�
			delete pNum;
			pNum = nullptr;

			// ���ȼ���һ
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;

			if (!flag)break;  // flagΪtrue,ȫ��ɾ��
		}
		else {  // ��ɾ���ڵ�ʱ�ƶ�
			cout << pTemp->NextNode->number << endl;
			pTemp = pTemp->NextNode;

			// ɾ���ڵ�λ����Ϣ����һ
			++posindex;
		}
	}
}

/***********************************************************************
* �� �� ����Sort()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ð�����򣬵���
* �����ģ�
*			����ʱ�䣺�� 2023.5.12 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע��
***********************************************************************/
void DoubleList::Sort() {
	for (int i = 1; i < this->m_Len; i++) {  // �˴�
		Node* pTemp1 = this->m_pHead->NextNode;
		for (int j = 0; j < this->m_Len - i; j++) {  // ÿ�˽�������

			Node* pTemp2 = pTemp1->NextNode;
			if (pTemp1->number > pTemp2->number) {  // ����

				// �����ڵ������
				int temp = pTemp1->number;
				pTemp1->number = pTemp2->number;
				pTemp2->number = temp;
				/*
				if (pTemp1->NextNode == this->m_pEnd->NextNode) {

					// ����ָ��
					pTemp1->FrontNode->NextNode = pTemp2;
					pTemp1->NextNode = pTemp2->NextNode;
					pTemp2->NextNode = pTemp1;

					// ��ǰ��ָ��
					pTemp2->FrontNode = pTemp1->FrontNode;
					pTemp1->FrontNode = pTemp2;

					// βָ��
					this->m_pEnd->NextNode = pTemp1;

				}
				else {

					// ����ָ��
					pTemp1->FrontNode->NextNode = pTemp2;
					pTemp1->NextNode = pTemp2->NextNode;
					pTemp2->NextNode = pTemp1;

					// ��ǰ��ָ��
					pTemp1->NextNode->FrontNode = pTemp1;
					pTemp2->FrontNode = pTemp1->FrontNode;
					pTemp1->FrontNode = pTemp2;

				}
				*/
			}
			// ָ�����
			pTemp1 = pTemp1->NextNode;
		}
	}
}
