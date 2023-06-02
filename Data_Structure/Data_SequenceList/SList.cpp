#include"SList.h"

/*
* �ж�˳�������
*/
bool SList::IsFull() {
	if (this->m_Array != nullptr) {
		return this->m_MaxSize == this->m_Usedsize;
	}
	else {
		return false;
	}
}

/*
* ����˳���ĳ���
*/
void SList::AddLen() {
	SNUM tempLen = this->m_MaxSize;
	SNUM* ptemp = this->m_Array;

	this->m_MaxSize += ADDSIZE;
	this->m_Array = new SNUM[m_MaxSize];

	memcpy(this->m_Array, ptemp, sizeof(SNUM) * tempLen);
}

/*
* ����һ������Ϊ10�Ŀ�˳���
*/
SList::SList() {
	this->m_MaxSize = 10;
	this->m_Usedsize = 0;
	this->m_Array = new SNUM[m_MaxSize];
	SNUM flag = this->m_MaxSize;
	for (SNUM i = 0; i < this->m_MaxSize; ++i) {
		this->m_Array[i] = flag--;
		++this->m_Usedsize;
	}
}

/*
* ����һ������Ϊ len ����ֵ��Ϊ num ��˳���
* len : ˳�����
* num : Ԫ��
*/
SList::SList(SNUM len, SNUM num) {
	this->m_MaxSize = this->m_Usedsize = len;
	this->m_Array = new SNUM[m_MaxSize];
	for (SNUM i = 0; i < this->m_Usedsize; ++i) {
		this->m_Array[i] = num;
	}
}

/*
* ����һ�������ڴ��ֵΪ˳����ֵ�� ����ҿ� ��
* �ڴ濪ʼ��ַ
* �ڴ������ַ
*/
SList::SList(SNUM* begin, SNUM* end) {
	this->m_MaxSize = MAXSIZE;
	this->m_Usedsize = 0;
	this->m_Array = new SNUM[m_MaxSize];

	SNUM* pbegin = begin;
	SNUM i = 0;
	while (pbegin != end) {
		if (this->IsFull()) {
			this->AddLen();
		}
		this->m_Array[i++] = *pbegin;
		++pbegin;
		++this->m_Usedsize;
	}
}

/*
* �������캯��
*/
SList::SList(const SList& other) {
	this->m_MaxSize = this->m_Usedsize = other.GetUsedsize();
	this->m_Array = new SNUM[m_MaxSize];
	memcpy(this->m_Array, other.GetArray(), sizeof(SNUM) * this->m_Usedsize);
}

/*
* ˳���ͷ��ڴ�
*/
SList::~SList() {
	delete[]this->m_Array;
	this->m_Array = nullptr;
}

/*
* ��õ�ǰ˳���ʹ�õĴ�С
*/
SNUM SList::GetUsedsize()const {
	return this->m_Usedsize;
}

/*
* ��õ�ǰ˳���Ŀ���ָ��
*/
SNUM* SList::GetArray()const {
	return this->m_Array;
}

/*
* �ж�˳���Ϊ��
*/
bool SList::IsEmpty() {
	if (nullptr == this->m_Array) {
		return true;
	}
	else if (0 == this->m_Usedsize) {
		return true;
	}
	else {
		return false;
	}
}

/*
* ĩβ���Ԫ��
* num : �����Ԫ��
*/
void SList::Push_Back(SNUM num) {
	if (this->IsFull()) {
		this->AddLen();
	}
	this->m_Array[this->m_Usedsize] = num;
	++this->m_Usedsize;
}

/*
* ĩβɾ��Ԫ��
*/
void SList::Pop_Back() {
	if (this->IsEmpty()) {
		cout << "IsEmpty" << endl;
	}
	else {
		this->m_Array[this->m_Usedsize - 1] = -1;
		--this->m_Usedsize;
	}
}

/*
* ����λ�ò���Ԫ��
* pos : �����λ��
* num : �����Ԫ��
*/
void SList::Insert(SNUM pos, SNUM num) {
	if (pos <= 0 || pos > this->m_Usedsize) {
		cout << "insert error" << endl;
	}
	else {
		if (this->IsFull()) {
			this->AddLen();
		}
		for (SNUM i = m_Usedsize; i >= pos; --i) {
			int temp = 0;
			temp = this->m_Array[i];
			this->m_Array[i] = this->m_Array[i - 1];
			this->m_Array[i - 1] = temp;
		}
		this->m_Array[pos - 1] = num;
		++this->m_Usedsize;
	}
}
/*
* ɾ��ֵΪval��Ԫ��
* num ; ��Ҫɾ����Ԫ��
*/
void SList::Remove(SNUM num) {
	if (this->IsEmpty()) {
		cout << "IsEmpty" << endl;
	}
	for (SNUM i = 0; i < m_Usedsize; ++i) {
		if (this->m_Array[i] == num) {
			for (SNUM j = i; j < m_Usedsize - 1; ++j) {
				int temp = 0;
				temp = this->m_Array[j];
				this->m_Array[j] = this->m_Array[j + 1];
				this->m_Array[j + 1] = temp;
			}
			--this->m_Usedsize;
			break;
		}
	}

}

/*
* ɾ������ֵΪval��Ԫ��
* num ; ��Ҫɾ����Ԫ��
*/
void SList::RemoveAll(SNUM num) {
	for (SNUM i = m_Usedsize - 1; i >= 0; --i) {
		this->Remove(num);
	}
}

/*
* ��������Ĭ��������
* flag : false ����
*/
void SList::Sort(bool flag) {
	if (this->IsEmpty() || 1 == this->m_Usedsize) {
		cout << "Ϊ�ջ���Ԫ������Ϊһ" << endl;
		return;
	}
	SNUM temp = 0;
	for (SNUM i = this->m_Usedsize - 1; i > 0; --i) {
		for (SNUM j = 0; j < i; ++j) {
			if (this->m_Array[j] > this->m_Array[j + 1]) {
				temp = this->m_Array[j];
				this->m_Array[j] = this->m_Array[j + 1];
				this->m_Array[j + 1] = temp;
			}
		}
	}
}

/*
* ����֮����ͬԪ�ر���һ��
* flag : false ����
*/
void SList::SortOne(bool flag) {
	// ����
	this->Sort();

	// ��¼��ǰԪ�صĸ���
	SNUM index = this->m_Usedsize - 1;

	// ��ǰ�Ƚϵ�λ��
	SNUM i = 0;
	while (i != index) {
		if (this->m_Array[i] == this->m_Array[i + 1]) {  // Ԫ����ͬ
			for (SNUM k = 0; k < index - i - 1; ++k) {  // Ԫ�غ���
				SNUM temp = this->m_Array[k + i + 1];
				this->m_Array[k + i + 1] = this->m_Array[k + i + 2];
				this->m_Array[k + i + 2] = temp;
			}
			--index;  // ������һ
		}
		else {
			++i;  // λ�ü�һ
		}
	}
	this->m_Usedsize = index + 1;
}

/*
* �鲢����
*/

/*
* ��ӡ˳���
*/
void SList::PrintArr() {
	cout << "--------------------" << endl << endl;
	for (SNUM i = 0; i < this->m_Usedsize; ++i) {
		cout << i + 1 << " : " << this->m_Array[i] << endl;
	}
	cout << "m_MaxSize : " << this->m_MaxSize << endl;
	cout << "m_Usedsize : " << this->m_Usedsize << endl;

	cout << "--------------------" << endl << endl;
}
