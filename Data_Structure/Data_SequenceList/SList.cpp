#include"SList.h"

/*
* 判断顺序表已满
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
* 增加顺序表的长度
*/
void SList::AddLen() {
	SNUM tempLen = this->m_MaxSize;
	SNUM* ptemp = this->m_Array;

	this->m_MaxSize += ADDSIZE;
	this->m_Array = new SNUM[m_MaxSize];

	memcpy(this->m_Array, ptemp, sizeof(SNUM) * tempLen);
}

/*
* 构造一个长度为10的空顺序表
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
* 构造一个长度为 len ，数值都为 num 的顺序表
* len : 顺序表长度
* num : 元素
*/
SList::SList(SNUM len, SNUM num) {
	this->m_MaxSize = this->m_Usedsize = len;
	this->m_Array = new SNUM[m_MaxSize];
	for (SNUM i = 0; i < this->m_Usedsize; ++i) {
		this->m_Array[i] = num;
	}
}

/*
* 构造一个连续内存的值为顺序表的值（ 左闭右开 ）
* 内存开始地址
* 内存结束地址
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
* 拷贝构造函数
*/
SList::SList(const SList& other) {
	this->m_MaxSize = this->m_Usedsize = other.GetUsedsize();
	this->m_Array = new SNUM[m_MaxSize];
	memcpy(this->m_Array, other.GetArray(), sizeof(SNUM) * this->m_Usedsize);
}

/*
* 顺序释放内存
*/
SList::~SList() {
	delete[]this->m_Array;
	this->m_Array = nullptr;
}

/*
* 获得当前顺序表使用的大小
*/
SNUM SList::GetUsedsize()const {
	return this->m_Usedsize;
}

/*
* 获得当前顺序表的控制指针
*/
SNUM* SList::GetArray()const {
	return this->m_Array;
}

/*
* 判断顺序表为空
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
* 末尾添加元素
* num : 插入的元素
*/
void SList::Push_Back(SNUM num) {
	if (this->IsFull()) {
		this->AddLen();
	}
	this->m_Array[this->m_Usedsize] = num;
	++this->m_Usedsize;
}

/*
* 末尾删除元素
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
* 任意位置插入元素
* pos : 插入的位置
* num : 插入的元素
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
* 删除值为val的元素
* num ; 需要删除的元素
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
* 删除所有值为val的元素
* num ; 需要删除的元素
*/
void SList::RemoveAll(SNUM num) {
	for (SNUM i = m_Usedsize - 1; i >= 0; --i) {
		this->Remove(num);
	}
}

/*
* 链表排序，默认是升序
* flag : false 降序
*/
void SList::Sort(bool flag) {
	if (this->IsEmpty() || 1 == this->m_Usedsize) {
		cout << "为空或者元素数量为一" << endl;
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
* 排序之后相同元素保留一个
* flag : false 降序
*/
void SList::SortOne(bool flag) {
	// 排序
	this->Sort();

	// 记录当前元素的个数
	SNUM index = this->m_Usedsize - 1;

	// 当前比较的位置
	SNUM i = 0;
	while (i != index) {
		if (this->m_Array[i] == this->m_Array[i + 1]) {  // 元素相同
			for (SNUM k = 0; k < index - i - 1; ++k) {  // 元素后移
				SNUM temp = this->m_Array[k + i + 1];
				this->m_Array[k + i + 1] = this->m_Array[k + i + 2];
				this->m_Array[k + i + 2] = temp;
			}
			--index;  // 个数减一
		}
		else {
			++i;  // 位置加一
		}
	}
	this->m_Usedsize = index + 1;
}

/*
* 归并排序
*/

/*
* 打印顺序表
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
