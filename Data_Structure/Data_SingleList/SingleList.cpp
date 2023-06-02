#include"SingleList.h"

/***********************************************************************
* �� �� ����__InitList()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����ʼ�������ͷ�ڵ�
*			-- 2 -- ��������Ϊ��
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����д����
***********************************************************************/
void SingleList::__InitList() {
	// ��ʼ�������ͷ�ڵ�
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;
	this->m_pHead->number = this->m_Len = 0;  // ����ĳ���Ϊ ��
}

/***********************************************************************
* �� �� ����SingleList()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����ʼ�������ͷ�ڵ�
*			-- 2 -- ��������Ϊ��
*			-- 3 -- ���޲�������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
***********************************************************************/
SingleList::SingleList() {
	this->__InitList();  // ��ʼ������
}

/***********************************************************************
* �� �� ����SingleList(int count)
* �� �� ��
*			1 ) count -->( int ) : ��Ҫ��ʼ������Ľڵ����
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���вι���
*			-- 2 -- ����ʼ�������ͷ�ڵ�
*			-- 3 -- ������ 1~n ����������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
*					2 ��β�巨�����ɵ� AddEndNum(int value) ����
***********************************************************************/
SingleList::SingleList(int count) {
	this->__InitList();  // ��ʼ������

	for (int i = 0; i < count; i++) {
		this->AddEndNum(i + 1);  // β�巨
	}
}

/***********************************************************************
* �� �� ����SingleList(int count, int value)
* �� �� ��
*			1 ) count ---->( int ) : ��Ҫ��ʼ������Ľڵ����
*			2 ) value ---->( int ) : ����ÿ���ڵ��������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���вι���
*			-- 2 -- ����ʼ�������ͷ�ڵ�
*			-- 3 -- ������ֵ��Ϊ value ������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
*					2 ��β�巨�����ɵ� AddEndNum(int value) ����
***********************************************************************/
SingleList::SingleList(int count, int value) {
	this->__InitList();  // ��ʼ������

	for (int i = 0; i < count; i++) {
		this->AddEndNum(value);  // β�巨
	}
}

/***********************************************************************
* �� �� ����DoubleListTable(int* Begin, int* End)
* �� �� ��
*			1 ) Begin --->( int* ) : �����ڴ�ĵ�һ����ַ
*			2 ) End   --->( int* ) : �����ڴ�����һ����ַ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���вι���
*			-- 2 -- ����ʼ�������ͷ�ڵ�
*			-- 3 -- ������ֵΪһ�������ڴ��ڵ�ֵ������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
*					2 ��β�巨�����ɵ� AddEndNum(int value) ����
***********************************************************************/
SingleList::SingleList(int* Begin, int* End) {
	this->__InitList();  // ��ʼ������

	for (int* temp = Begin; temp < End; ++temp) {
		this->AddEndNum(*temp);  // β�巨
	}
}

/***********************************************************************
* �� �� ����SingleList(const SingleList& other)
* �� �� ��
*			1 ) other -->( const SingleList& ) : ����һ����������
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- �����ƹ��캯��
*			-- 2 -- ����ʼ�������ͷ�ڵ�
*			-- 3 -- �����һ��ֻ��ֵ��ͬ������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �����ȴӸ�ֵ��ʽ��Ϊ����
*					2 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
*					2 ��β�巨�����ɵ� AddEndNum(int value) ����
***********************************************************************/
SingleList::SingleList(const SingleList& other) {
	this->__InitList();  // ��ʼ������

	Node* pother = other.m_pHead;  // ��ʱ���洫�������ָ��

	// ��ͷ��ʼ����
	while (pother->NextNode != nullptr) {  // ��ʱ���洫�������ָ�벻Ϊ��
		this->AddEndNum(pother->NextNode->number);  // β�巨

		// �ڵ�ָ�����
		pother = pother->NextNode;
	}
}

/***********************************************************************
* �� �� ����~SingleList()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- �������������ֶ��ͷ�������ڴ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
SingleList::~SingleList() {
	Node* pTemp = nullptr;  // ��ʱ����ڵ�

	// ��ǰ�������ͷ�
	while (this->m_pHead != nullptr) {
		pTemp = this->m_pHead;
		this->m_pHead = this->m_pHead->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	// ������Ϊ��
	this->m_Len = 0;
	this->m_pHead = nullptr;
}

/***********************************************************************
* �� �� ����operator+(const SingleList& other)
* �� �� ��
*			1 ) other -->( const SingleList& ) : ����һ����������
* �� �� ֵ��
*			1 ) SingleList : ���ص��������
* �������ܣ�
*			-- 1 -- ���ӷ����غ���
*			-- 2 -- ��β�巨
*			-- 3 -- ����ǰ��������һ�ڵ��һ�������ֵ
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
SingleList SingleList::operator+(const SingleList& other) {
	Node* pHead = this->m_pHead;  // ����ͷָ��

	// �ƶ������һ���ڵ�
	while (pHead->NextNode != nullptr) {
		pHead = pHead->NextNode;
	}

	// ���ؽڵ㵽���һ��
	for (Node* pOther = other.m_pHead->NextNode; pOther != nullptr; pOther = pOther->NextNode) {
		// ��ȡ�����������
		Node* pNum = new Node;
		pNum->number = pOther->number;
		pNum->NextNode = nullptr;

		//�����½ڵ㵽���ڵ�
		pHead->NextNode = pNum;
		pHead = pHead->NextNode;
	}
	return *this;
}

/***********************************************************************
* �� �� ����operator=(const SingleList& other)
* �� �� ��
*			1 ) other -->( const SingleList& ) : ����һ����������
* �� �� ֵ��
*			1 ) SingleList : ���ص�ǰ������
* �������ܣ�
*			-- 1 -- ���������غ���
*			-- 2 -- ��β�巨
*			-- 3 -- ����ǰ�����ֵΪ����һ�������ֵ�����
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��β�巨�����ɵ� AddEndNum(int value) ����
***********************************************************************/
SingleList SingleList::operator=(const SingleList& other) {
	this->__InitList();  // ��ʼ������

	Node* pother = other.m_pHead;  // ��ʱ���洫�������ָ��

	// ��ͷ��ʼ����
	while (pother->NextNode != nullptr) {  // ��ʱ���洫�������ָ�벻Ϊ��
		this->AddEndNum(pother->NextNode->number);  // β�巨

		// �ڵ�ָ�����
		pother = pother->NextNode;
	}
	return *this;
}

/***********************************************************************
* �� �� ����PrintList()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����ͷ�ڵ���һ���ڵ��ӡȫ�������ֵ
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �������������ȵĴ�ӡ
***********************************************************************/
void SingleList::PrintList() const {
	Node* pPint = this->m_pHead->NextNode;  // ��������ͷ�ڵ����һ���ڵ�

	// ��ӡ������
	cout << "m_Len : " << this->m_Len << endl;

	// ������ӡ����
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;
		pPint = pPint->NextNode; // ����
	}
	cout << endl << "--------------------" << endl << endl;
}

/***********************************************************************
* �� �� ����Clear()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- �������������ͷָ��
* �����ģ�
*			����ʱ�䣺�� 2023.6.1 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������������ʵ�ֹ���
***********************************************************************/
void SingleList::Clear() {
	Node* pTemp = nullptr;  // ��ʱ����ڵ�

// ��ǰ�������ͷ�
	while (this->m_pHead->NextNode != nullptr) {
		pTemp = this->m_pHead->NextNode;
		this->m_pHead->NextNode = this->m_pHead->NextNode->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	// ������Ϊ��
	this->m_Len = 0;
	this->m_pHead->number = 0;

	// ����ͷָ��
	this->m_pHead->NextNode = nullptr;
}

/***********************************************************************
* �� �� ����IsEmpty()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���ж�����Ϊ��
*			-- 2 -- ��ָ��Ϊ�ջ��߳���Ϊ��
* �����ģ�
*			����ʱ�䣺�� 2023.6.1 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������������ʵ�ֹ���
***********************************************************************/
bool SingleList::IsEmpty() {
	/* ָ��Ϊ�ջ��߳���Ϊ�� */
	return 0 == this->m_Len || 0 == this->m_pHead->number
		|| this->m_pHead->NextNode == nullptr;
}
/***********************************************************************
* �� �� ����MaxSize()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���������������������Ĭ��Ϊ200���ڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.6.1 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������������ʵ�ֹ���
***********************************************************************/
int SingleList::MaxSize() {
	return MAXSIZE;  // 200
}

/***********************************************************************
* �� �� ����AddHeadNum(int value)
* �� �� ��
*			1 ) value -->( int ) : ���������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������ֵ�������ͷ��
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void SingleList::AddHeadNum(int value) {
	// �½ڵ�
	Node* pNew = new Node;
	pNew->number = value;
	pNew->NextNode = nullptr;

	// ͷ�巨
	if (0 == this->m_Len) {  // ����Ϊ�㣬ֱ�ӹ��ڵ�һ��λ��

		// ָ��ı仯
		this->m_pHead->NextNode = pNew;  // ͷ������һ��Ϊ pNew

		// ���Ⱥ�ͷָ���������仯
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // ͷ����ͷָ���������޸�

		// ָ��ı仯
		pNew->NextNode = this->m_pHead->NextNode;  // pNew ��һ���ڵ�Ϊ��һ���ڵ�
		this->m_pHead->NextNode = pNew;            // ͷ������һ��Ϊ pNew

		// ���Ⱥ�ͷָ���������仯
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

/***********************************************************************
* �� �� ����AddEndNum(int value)
* �� �� ��
*			1 ) value -->( int ) : ���������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������ֵ�������β��
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void SingleList::AddEndNum(int value) {
	// �½ڵ�
	Node* pNew = new Node;
	pNew->number = value;
	pNew->NextNode = nullptr;

	// β�巨
	if (0 == this->m_Len) {  // ����Ϊ�㣬ֱ�ӹ��ڵ�һ��λ��

		// ָ��ı仯
		this->m_pHead->NextNode = pNew;  // ͷ������һ��Ϊ pNew

		// ���Ⱥ�ͷָ���������仯
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // β�巨��βָ�����޸�
		Node* pTemp = this->m_pHead;

		// �ƶ����������Ľڵ�
		while (pTemp->NextNode != nullptr) {
			pTemp = pTemp->NextNode;  // ����
		}

		// ����
		pTemp->NextNode = pNew;

		// ���Ⱥ�ͷָ���������仯
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

/***********************************************************************
* �� �� ����AddIndexNum(int pos, int value)
* �� �� ��
*			1 ) pos -->( int ) : ���������λ��
*			2 ) value -->( int ) : ���������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������ֵ value ������� pos λ��
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void SingleList::AddIndexNum(int pos, int value) {
	if (pos<1 || pos>this->m_Len) {  // ��������
		cout << "----- �������Ϸ� -----" << endl << endl;
	}
	else {
		Node* pTemp = this->m_pHead;  // ��ʱָ��

		// ��Ҫ����Ľڵ��ʼ��
		Node* pNum = new Node;
		pNum->number = value;
		pNum->NextNode = nullptr;

		// �ҵ���Ҫ�����ǰһ��λ��
		for (int i = 1; i < pos; i++) {
			pTemp = pTemp->NextNode;  // ����
		}

		// ����
		pNum->NextNode = pTemp->NextNode; // �ȹ���ȥ
		pTemp->NextNode = pNum;           // ������

		// ���ȸ���
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

/***********************************************************************
* �� �� ����DeleteHeadNum()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ�������һ���ڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
***********************************************************************/
void SingleList::DeleteHeadNum() {
	if (this->m_Len != 0) {  // ���Ȳ�Ϊ�㣬ɾ����һ��
		Node* pNum = nullptr;         // ����ڵ��ָ��

		// ָ��ı仯��ɾ��֮���ͷű�ɾ���Ľڵ�
		pNum = this->m_pHead->NextNode;  // ͷ������һ��
		this->m_pHead->NextNode = pNum->NextNode; // ͷ�������¸�

		// ��ӡ��ɾ���Ľڵ���Ϣ
		cout << "ɾ�� : " << pNum->number << endl;
		cout << "λ�� : 1 " << endl;

		// �ͷű�ɾ���Ľڵ�
		delete pNum;
		pNum = nullptr;

		// ���Ⱥ�ͷָ���������仯
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // ����Ϊ��
		cout << "����Ϊ�գ�" << endl;
	}
}

/***********************************************************************
* �� �� ����DeleteIndexNum(int pos)
* �� �� ��
*			1 ) : pos -->( int ) ɾ�������λ��
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ������posλ�õĽڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
***********************************************************************/
void SingleList::DeleteEndNum() {
	if (0 != this->m_Len) {  // ���Ȳ�Ϊ�㣬ɾ�����һ��
		Node* pNum = nullptr;      // ����ڵ��ָ��

		Node* pTemp = this->m_pHead;   // ��ʱָ��

		// �ƶ����������ڵ��ǰһ��λ��
		while (pTemp->NextNode->NextNode != nullptr) {
			pTemp = pTemp->NextNode;  // ����
		}

		// ָ��ı仯��ɾ��֮���ͷű�ɾ���Ľڵ�
		pNum = pTemp->NextNode;
		pTemp->NextNode = nullptr;

		// ��ӡ��ɾ���Ľڵ���Ϣ
		cout << "ɾ�� : " << pNum->number << endl;
		cout << "λ�� : " << this->m_Len << " " << endl;

		// �ͷű�ɾ���Ľڵ�
		delete pNum;
		pNum = nullptr;

		// ���Ⱥ�ͷָ���������仯
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // ����Ϊ��
		cout << "����Ϊ�գ�" << endl;
	}
}

/***********************************************************************
* �� �� ����DeleteIndexNum(int pos)
* �� �� ��
*			1 ) : pos -->( int ) ɾ�������λ��
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ������posλ�õĽڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
*					2 ������������Ϊ����ж�
***********************************************************************/
void SingleList::DeleteIndexNum(int pos) {
	if (0 != this->m_Len) {  // ���Ȳ�Ϊ��
		if (pos<1 || pos>this->m_Len) {  // ��������
			cout << "----- �������Ϸ� -----" << endl << endl;
		}
		else {  // ������ȷ
			Node* pTemp = this->m_pHead;  // ��ʱָ��
			Node* pNum = nullptr;         // ����ڵ��ָ��

			// �ҵ���Ҫɾ����ǰһ��λ��
			for (int i = 1; i < pos; i++) {
				pTemp = pTemp->NextNode;  // ����
			}

			// ɾ��֮���ͷű�ɾ���Ľڵ�
			pNum = pTemp->NextNode;       // ���汻ɾ���Ľڵ�
			pTemp->NextNode = pNum->NextNode;  // �Ͽ�����������һ���ڵ�

			// ��ӡ��ɾ���Ľڵ���Ϣ
			cout << "ɾ�� : " << pNum->number << endl;
			cout << "λ�� : " << pos << " " << endl;

			delete pNum;  // �ͷű�ɾ���Ľڵ�
			pNum = nullptr;

			// ���ȸ���
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
	else {  // ����Ϊ��
		cout << "����Ϊ�գ�" << endl;
	}

}

/***********************************************************************
* �� �� ����DeleteNum(int value, bool flag)
* �� �� ��
*			1 ) : value --->( int ) ��ɾ����ֵ
*			2 ) : flag -->( int ) ȫ��ɾ������valueֵ�ı�־
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ������ value ֵ�ĵ�һ���ڵ�
*			-- 2 -- ��flag ( true ) ��Ϣȫ��ɾ������ value ֵ�Ľڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
***********************************************************************/
void SingleList::DeleteNum(int value, bool flag) {  // flagΪtrue,ȫ��ɾ��
	Node* pTemp = this->m_pHead;  // ��ʱָ��
	Node* pNum = nullptr;         // ����ڵ��ָ��

	int posindex = 1;  // ��ɾ���ڵ�λ��

	while (pTemp->NextNode != nullptr) {  // ����Ϊ��
		if (pTemp->NextNode->number == value) {
			/*********************
			* ɾ��Ŀ��ڵ㣬���ͷ�
			* ע��ɾ��֮���ǲ����ƶ���
			* ��Ϊ����Ľڵ㱻��������
			*********************/

			// �Ͽ���ɾ���ڵ�
			pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;

			// ��ӡ��ɾ���Ľڵ���Ϣ
			cout << "ɾ�� : " << pNum->number << endl;
			cout << "λ�� : " << posindex << " " << endl;

			// �ͷű��Ͽ��Ľڵ�
			delete pNum;
			pNum = nullptr;

			// ���ȸ���
			--this->m_Len;
			this->m_pHead->number = this->m_Len;

			if (!flag)break;  // flagΪtrue,ȫ��ɾ��
		}
		else {  // ��ɾ���ڵ�ʱ�ƶ�
			pTemp = pTemp->NextNode;

			// ɾ���ڵ�λ����Ϣ����һ
			++posindex;
		}
	}
}

/***********************************************************************
* �� �� ����Front()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������Ԫ�ص�����
* �����ģ�
*			����ʱ�䣺�� 2023.6.1 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������������ʵ�ֹ���
***********************************************************************/
int& SingleList::Front() {
	if (this->m_pHead->NextNode != nullptr) {  // ��Ϊ�շ��ص�һ��Ԫ��
		return this->m_pHead->NextNode->number;
	}
	else {
		return this->m_pHead->number;  // Ϊ�շ���ͷָ���Ԫ��
	}
}

/***********************************************************************
* �� �� ����Assign(int count, int value)
* �� �� ��
*			1 ) count ---->( int ) : ������Ľڵ����
*			2 ) value ---->( int ) : ����ÿ���ڵ��������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����СΪ count ��ֵ��Ϊ value ������
*			-- 2 -- ���� count �� value �ĸ����滻���ݡ�
* �����ģ�
*			����ʱ�䣺�� 2023.6.1 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������������ʵ�ֹ���
***********************************************************************/
void SingleList::Assign(int count, int value) {
	// ��һ��Ԫ��Ϊ�գ����߳��Ȳ�Ϊ�㣬�����һ��
	if (!this->IsEmpty()) {
		this->Clear();
	}
	for (int i = 0; i < count; i++) {
		this->AddEndNum(value);  // β�巨
	}
}

/***********************************************************************
* �� �� ����Swap(SingleList& other)
* �� �� ��
*			1 ) other -->( SingleList& ) : ����һ��������
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���������� other �Ľ���
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������������ʵ�ֹ���
***********************************************************************/
void SingleList::Swap(SingleList& other) {
	SingleList temp;
	temp.Clear();
	temp = *this;
	this->Clear();
	*this = other;
	other.Clear();
	other = temp;
}

/***********************************************************************
* �� �� ����Merge(const SingleList& other)
* �� �� ��
*			1 ) other -->( const SingleList& ) : ����һ����������
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���鲢��������������
*			-- 2 -- ������Ӧ����������
* �����ģ�
*			����ʱ�䣺�� 2023.6.1 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������������ʵ�ֹ���
*					2 ����Ϊβ�巨
***********************************************************************/
void SingleList::Merge(const SingleList& other) {
	SingleList newList;  // ��ʱ����
	newList.Clear();

	Node* myTemp = this->m_pHead;
	Node* otherTemp = other.m_pHead;

	bool flag = true;
	while (flag) {
		if (nullptr == myTemp->NextNode) {  // ֱ������other��ʣ��
			while (nullptr != otherTemp->NextNode) {
				newList.AddEndNum(otherTemp->NextNode->number);  // ʹ��β�巨
				otherTemp = otherTemp->NextNode;
			}
			flag = false;
		}
		else if (nullptr == otherTemp->NextNode) {  // ֱ������mytemp��ʣ��
			while (nullptr != myTemp->NextNode) {
				newList.AddEndNum(myTemp->NextNode->number);  // ʹ��β�巨
				myTemp = myTemp->NextNode;
			}
			flag = false;
		}
		else {
			if (myTemp->NextNode->number < otherTemp->NextNode->number) {
				newList.AddEndNum(myTemp->NextNode->number);  // ʹ��β�巨
				myTemp = myTemp->NextNode;
			}
			else {
				newList.AddEndNum(otherTemp->NextNode->number);  // ʹ��β�巨
				otherTemp = otherTemp->NextNode;
			}
		}
	}

	this->Clear();  // �����һ�£���֪����û���ù�����
	*this = newList;  // ( = ) �����غ����е�����

}

/***********************************************************************
* �� �� ����Sort()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ð�����򣬵���
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע��
***********************************************************************/
void SingleList::Sort() {
	for (int i = 1; i < this->m_Len; i++) {  // ����
		Node* pTemp01 = this->m_pHead;
		for (int j = 0; j < this->m_Len - i; j++) {  // ÿ�˱ȽϵĴ���
			Node* pTemp02 = pTemp01->NextNode;
			if (pTemp01->NextNode->number > pTemp02->NextNode->number) {
				// ����
				pTemp01->NextNode = pTemp02->NextNode;
				pTemp02->NextNode = pTemp01->NextNode->NextNode;
				pTemp01->NextNode->NextNode = pTemp02;
				// ����
				pTemp01 = pTemp01->NextNode;
			}
			else {
				// ����
				pTemp01 = pTemp01->NextNode;
			}
		}
	}
}
