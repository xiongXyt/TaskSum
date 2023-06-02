#include"SingleList.h"

/***********************************************************************
* 函 数 名：__InitList()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：初始化链表空头节点
*			-- 2 -- ：链表长度为零
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：编写函数
***********************************************************************/
void SingleList::__InitList() {
	// 初始化链表空头节点
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;
	this->m_pHead->number = this->m_Len = 0;  // 链表的长度为 零
}

/***********************************************************************
* 函 数 名：SingleList()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：初始化链表空头节点
*			-- 2 -- ：链表长度为零
*			-- 3 -- ：无参数构造
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：初始化链表空头节点，集成到 __InitList() 函数
***********************************************************************/
SingleList::SingleList() {
	this->__InitList();  // 初始化链表
}

/***********************************************************************
* 函 数 名：SingleList(int count)
* 形 参 表：
*			1 ) count -->( int ) : 需要初始化链表的节点个数
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：有参构造
*			-- 2 -- ：初始化链表空头节点
*			-- 3 -- ：构造 1~n 的有序链表
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：初始化链表空头节点，集成到 __InitList() 函数
*					2 ：尾插法，集成到 AddEndNum(int value) 函数
***********************************************************************/
SingleList::SingleList(int count) {
	this->__InitList();  // 初始化链表

	for (int i = 0; i < count; i++) {
		this->AddEndNum(i + 1);  // 尾插法
	}
}

/***********************************************************************
* 函 数 名：SingleList(int count, int value)
* 形 参 表：
*			1 ) count ---->( int ) : 需要初始化链表的节点个数
*			2 ) value ---->( int ) : 链表每个节点数据域的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：有参构造
*			-- 2 -- ：初始化链表空头节点
*			-- 3 -- ：构造值都为 value 的链表
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：初始化链表空头节点，集成到 __InitList() 函数
*					2 ：尾插法，集成到 AddEndNum(int value) 函数
***********************************************************************/
SingleList::SingleList(int count, int value) {
	this->__InitList();  // 初始化链表

	for (int i = 0; i < count; i++) {
		this->AddEndNum(value);  // 尾插法
	}
}

/***********************************************************************
* 函 数 名：DoubleListTable(int* Begin, int* End)
* 形 参 表：
*			1 ) Begin --->( int* ) : 连续内存的第一个地址
*			2 ) End   --->( int* ) : 连续内存的最后一个地址
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：有参构造
*			-- 2 -- ：初始化链表空头节点
*			-- 3 -- ：构造值为一段连续内存内的值的链表
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：初始化链表空头节点，集成到 __InitList() 函数
*					2 ：尾插法，集成到 AddEndNum(int value) 函数
***********************************************************************/
SingleList::SingleList(int* Begin, int* End) {
	this->__InitList();  // 初始化链表

	for (int* temp = Begin; temp < End; ++temp) {
		this->AddEndNum(*temp);  // 尾插法
	}
}

/***********************************************************************
* 函 数 名：SingleList(const SingleList& other)
* 形 参 表：
*			1 ) other -->( const SingleList& ) : 另外一个常链表类
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：复制构造函数
*			-- 2 -- ：初始化链表空头节点
*			-- 3 -- ：深复制一个只有值相同的链表
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：长度从赋值方式改为计数
*					2 ：初始化链表空头节点，集成到 __InitList() 函数
*					2 ：尾插法，集成到 AddEndNum(int value) 函数
***********************************************************************/
SingleList::SingleList(const SingleList& other) {
	this->__InitList();  // 初始化链表

	Node* pother = other.m_pHead;  // 临时保存传入的链表指针

	// 从头开始复制
	while (pother->NextNode != nullptr) {  // 临时保存传入的链表指针不为空
		this->AddEndNum(pother->NextNode->number);  // 尾插法

		// 节点指针后移
		pother = pother->NextNode;
	}
}

/***********************************************************************
* 函 数 名：~SingleList()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：析构函数，手动释放申请的内存
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
SingleList::~SingleList() {
	Node* pTemp = nullptr;  // 临时保存节点

	// 从前向后遍历释放
	while (this->m_pHead != nullptr) {
		pTemp = this->m_pHead;
		this->m_pHead = this->m_pHead->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	// 长度置为零
	this->m_Len = 0;
	this->m_pHead = nullptr;
}

/***********************************************************************
* 函 数 名：operator+(const SingleList& other)
* 形 参 表：
*			1 ) other -->( const SingleList& ) : 另外一个常链表类
* 返 回 值：
*			1 ) SingleList : 返回当面的链表
* 函数功能：
*			-- 1 -- ：加法重载函数
*			-- 2 -- ：尾插法
*			-- 3 -- ：当前链表的最后一节点接一个链表的值
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
SingleList SingleList::operator+(const SingleList& other) {
	Node* pHead = this->m_pHead;  // 保存头指针

	// 移动到最后一个节点
	while (pHead->NextNode != nullptr) {
		pHead = pHead->NextNode;
	}

	// 挂载节点到最后一个
	for (Node* pOther = other.m_pHead->NextNode; pOther != nullptr; pOther = pOther->NextNode) {
		// 获取新链表的数据
		Node* pNum = new Node;
		pNum->number = pOther->number;
		pNum->NextNode = nullptr;

		//挂载新节点到最后节点
		pHead->NextNode = pNum;
		pHead = pHead->NextNode;
	}
	return *this;
}

/***********************************************************************
* 函 数 名：operator=(const SingleList& other)
* 形 参 表：
*			1 ) other -->( const SingleList& ) : 另外一个常链表类
* 返 回 值：
*			1 ) SingleList : 返回当前的链表
* 函数功能：
*			-- 1 -- ：等于重载函数
*			-- 2 -- ：尾插法
*			-- 3 -- ：当前链表的值为另外一个链表的值，深拷贝
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：尾插法，集成到 AddEndNum(int value) 函数
***********************************************************************/
SingleList SingleList::operator=(const SingleList& other) {
	this->__InitList();  // 初始化链表

	Node* pother = other.m_pHead;  // 临时保存传入的链表指针

	// 从头开始复制
	while (pother->NextNode != nullptr) {  // 临时保存传入的链表指针不为空
		this->AddEndNum(pother->NextNode->number);  // 尾插法

		// 节点指针后移
		pother = pother->NextNode;
	}
	return *this;
}

/***********************************************************************
* 函 数 名：PrintList()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：从头节点下一个节点打印全部链表的值
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：新增加链表长度的打印
***********************************************************************/
void SingleList::PrintList() const {
	Node* pPint = this->m_pHead->NextNode;  // 保存链表头节点的下一个节点

	// 打印链表长度
	cout << "m_Len : " << this->m_Len << endl;

	// 遍历打印链表
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;
		pPint = pPint->NextNode; // 后移
	}
	cout << endl << "--------------------" << endl << endl;
}

/***********************************************************************
* 函 数 名：Clear()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：清空链表，保留头指针
* 最后更改：
*			更改时间：【 2023.6.1 】
*			更改人员：xyt
*			更改内容：
*					1 ：创建函数，实现功能
***********************************************************************/
void SingleList::Clear() {
	Node* pTemp = nullptr;  // 临时保存节点

// 从前向后遍历释放
	while (this->m_pHead->NextNode != nullptr) {
		pTemp = this->m_pHead->NextNode;
		this->m_pHead->NextNode = this->m_pHead->NextNode->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	// 长度置为零
	this->m_Len = 0;
	this->m_pHead->number = 0;

	// 保留头指针
	this->m_pHead->NextNode = nullptr;
}

/***********************************************************************
* 函 数 名：IsEmpty()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：判断链表为空
*			-- 2 -- ：指针为空或者长度为空
* 最后更改：
*			更改时间：【 2023.6.1 】
*			更改人员：xyt
*			更改内容：
*					1 ：创建函数，实现功能
***********************************************************************/
bool SingleList::IsEmpty() {
	/* 指针为空或者长度为空 */
	return 0 == this->m_Len || 0 == this->m_pHead->number
		|| this->m_pHead->NextNode == nullptr;
}
/***********************************************************************
* 函 数 名：MaxSize()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：返回最大容量，本程序默认为200个节点
* 最后更改：
*			更改时间：【 2023.6.1 】
*			更改人员：xyt
*			更改内容：
*					1 ：创建函数，实现功能
***********************************************************************/
int SingleList::MaxSize() {
	return MAXSIZE;  // 200
}

/***********************************************************************
* 函 数 名：AddHeadNum(int value)
* 形 参 表：
*			1 ) value -->( int ) : 插入链表的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：插入新值到链表的头部
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
void SingleList::AddHeadNum(int value) {
	// 新节点
	Node* pNew = new Node;
	pNew->number = value;
	pNew->NextNode = nullptr;

	// 头插法
	if (0 == this->m_Len) {  // 长度为零，直接挂在第一个位置

		// 指针的变化
		this->m_pHead->NextNode = pNew;  // 头结点的下一个为 pNew

		// 长度和头指针的数据域变化
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 头插在头指针上面做修改

		// 指针的变化
		pNew->NextNode = this->m_pHead->NextNode;  // pNew 下一个节点为第一个节点
		this->m_pHead->NextNode = pNew;            // 头结点的下一个为 pNew

		// 长度和头指针的数据域变化
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

/***********************************************************************
* 函 数 名：AddEndNum(int value)
* 形 参 表：
*			1 ) value -->( int ) : 插入链表的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：插入新值到链表的尾部
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
void SingleList::AddEndNum(int value) {
	// 新节点
	Node* pNew = new Node;
	pNew->number = value;
	pNew->NextNode = nullptr;

	// 尾插法
	if (0 == this->m_Len) {  // 长度为零，直接挂在第一个位置

		// 指针的变化
		this->m_pHead->NextNode = pNew;  // 头结点的下一个为 pNew

		// 长度和头指针的数据域变化
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 尾插法在尾指针做修改
		Node* pTemp = this->m_pHead;

		// 移动到链表最后的节点
		while (pTemp->NextNode != nullptr) {
			pTemp = pTemp->NextNode;  // 后移
		}

		// 插入
		pTemp->NextNode = pNew;

		// 长度和头指针的数据域变化
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

/***********************************************************************
* 函 数 名：AddIndexNum(int pos, int value)
* 形 参 表：
*			1 ) pos -->( int ) : 插入链表的位置
*			2 ) value -->( int ) : 插入链表的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：插入新值 value 到链表的 pos 位置
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
void SingleList::AddIndexNum(int pos, int value) {
	if (pos<1 || pos>this->m_Len) {  // 索引有误
		cout << "----- 索引不合法 -----" << endl << endl;
	}
	else {
		Node* pTemp = this->m_pHead;  // 临时指针

		// 需要插入的节点初始化
		Node* pNum = new Node;
		pNum->number = value;
		pNum->NextNode = nullptr;

		// 找到需要插入的前一个位置
		for (int i = 1; i < pos; i++) {
			pTemp = pTemp->NextNode;  // 后移
		}

		// 插入
		pNum->NextNode = pTemp->NextNode; // 先挂上去
		pTemp->NextNode = pNum;           // 在链接

		// 长度更改
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

/***********************************************************************
* 函 数 名：DeleteHeadNum()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表的一个节点
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
***********************************************************************/
void SingleList::DeleteHeadNum() {
	if (this->m_Len != 0) {  // 长度不为零，删除第一个
		Node* pNum = nullptr;         // 保存节点的指针

		// 指针的变化，删除之后释放被删除的节点
		pNum = this->m_pHead->NextNode;  // 头结点的下一个
		this->m_pHead->NextNode = pNum->NextNode; // 头结点的下下个

		// 打印被删除的节点信息
		cout << "删除 : " << pNum->number << endl;
		cout << "位置 : 1 " << endl;

		// 释放被删除的节点
		delete pNum;
		pNum = nullptr;

		// 长度和头指针的数据域变化
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 长度为零
		cout << "链表为空！" << endl;
	}
}

/***********************************************************************
* 函 数 名：DeleteIndexNum(int pos)
* 形 参 表：
*			1 ) : pos -->( int ) 删除链表的位置
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表pos位置的节点
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
***********************************************************************/
void SingleList::DeleteEndNum() {
	if (0 != this->m_Len) {  // 长度不为零，删除最后一个
		Node* pNum = nullptr;      // 保存节点的指针

		Node* pTemp = this->m_pHead;   // 临时指针

		// 移动到链表最后节点的前一个位置
		while (pTemp->NextNode->NextNode != nullptr) {
			pTemp = pTemp->NextNode;  // 后移
		}

		// 指针的变化，删除之后释放被删除的节点
		pNum = pTemp->NextNode;
		pTemp->NextNode = nullptr;

		// 打印被删除的节点信息
		cout << "删除 : " << pNum->number << endl;
		cout << "位置 : " << this->m_Len << " " << endl;

		// 释放被删除的节点
		delete pNum;
		pNum = nullptr;

		// 长度和头指针的数据域变化
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 长度为零
		cout << "链表为空！" << endl;
	}
}

/***********************************************************************
* 函 数 名：DeleteIndexNum(int pos)
* 形 参 表：
*			1 ) : pos -->( int ) 删除链表的位置
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表pos位置的节点
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
*					2 ：新增链表长度为零的判断
***********************************************************************/
void SingleList::DeleteIndexNum(int pos) {
	if (0 != this->m_Len) {  // 长度不为零
		if (pos<1 || pos>this->m_Len) {  // 索引有误
			cout << "----- 索引不合法 -----" << endl << endl;
		}
		else {  // 索引正确
			Node* pTemp = this->m_pHead;  // 临时指针
			Node* pNum = nullptr;         // 保存节点的指针

			// 找到需要删除的前一个位置
			for (int i = 1; i < pos; i++) {
				pTemp = pTemp->NextNode;  // 后移
			}

			// 删除之后释放被删除的节点
			pNum = pTemp->NextNode;       // 保存被删除的节点
			pTemp->NextNode = pNum->NextNode;  // 断开并链接下下一个节点

			// 打印被删除的节点信息
			cout << "删除 : " << pNum->number << endl;
			cout << "位置 : " << pos << " " << endl;

			delete pNum;  // 释放被删除的节点
			pNum = nullptr;

			// 长度更改
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
	else {  // 长度为零
		cout << "链表为空！" << endl;
	}

}

/***********************************************************************
* 函 数 名：DeleteNum(int value, bool flag)
* 形 参 表：
*			1 ) : value --->( int ) 需删除的值
*			2 ) : flag -->( int ) 全部删除链表value值的标志
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表 value 值的第一个节点
*			-- 2 -- ：flag ( true ) 信息全部删除链表 value 值的节点
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
***********************************************************************/
void SingleList::DeleteNum(int value, bool flag) {  // flag为true,全部删除
	Node* pTemp = this->m_pHead;  // 临时指针
	Node* pNum = nullptr;         // 保存节点的指针

	int posindex = 1;  // 被删除节点位置

	while (pTemp->NextNode != nullptr) {  // 链表不为空
		if (pTemp->NextNode->number == value) {
			/*********************
			* 删除目标节点，并释放
			* 注意删除之后是不用移动的
			* 因为后面的节点被接上来了
			*********************/

			// 断开需删除节点
			pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;

			// 打印被删除的节点信息
			cout << "删除 : " << pNum->number << endl;
			cout << "位置 : " << posindex << " " << endl;

			// 释放被断开的节点
			delete pNum;
			pNum = nullptr;

			// 长度更改
			--this->m_Len;
			this->m_pHead->number = this->m_Len;

			if (!flag)break;  // flag为true,全部删除
		}
		else {  // 不删除节点时移动
			pTemp = pTemp->NextNode;

			// 删除节点位置信息增加一
			++posindex;
		}
	}
}

/***********************************************************************
* 函 数 名：Front()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：返回首元素的引用
* 最后更改：
*			更改时间：【 2023.6.1 】
*			更改人员：xyt
*			更改内容：
*					1 ：创建函数，实现功能
***********************************************************************/
int& SingleList::Front() {
	if (this->m_pHead->NextNode != nullptr) {  // 不为空返回第一个元素
		return this->m_pHead->NextNode->number;
	}
	else {
		return this->m_pHead->number;  // 为空返回头指针的元素
	}
}

/***********************************************************************
* 函 数 名：Assign(int count, int value)
* 形 参 表：
*			1 ) count ---->( int ) : 新链表的节点个数
*			2 ) value ---->( int ) : 链表每个节点数据域的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：大小为 count 新值都为 value 的链表
*			-- 2 -- ：以 count 份 value 的副本替换内容。
* 最后更改：
*			更改时间：【 2023.6.1 】
*			更改人员：xyt
*			更改内容：
*					1 ：创建函数，实现功能
***********************************************************************/
void SingleList::Assign(int count, int value) {
	// 第一个元素为空，或者长度不为零，就清空一次
	if (!this->IsEmpty()) {
		this->Clear();
	}
	for (int i = 0; i < count; i++) {
		this->AddEndNum(value);  // 尾插法
	}
}

/***********************************************************************
* 函 数 名：Swap(SingleList& other)
* 形 参 表：
*			1 ) other -->( SingleList& ) : 另外一个链表类
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：将内容与 other 的交换
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：创建函数，实现功能
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
* 函 数 名：Merge(const SingleList& other)
* 形 参 表：
*			1 ) other -->( const SingleList& ) : 另外一个常链表类
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：归并二个已排序链表
*			-- 2 -- ：链表应以升序排序
* 最后更改：
*			更改时间：【 2023.6.1 】
*			更改人员：xyt
*			更改内容：
*					1 ：创建函数，实现功能
*					2 ：改为尾插法
***********************************************************************/
void SingleList::Merge(const SingleList& other) {
	SingleList newList;  // 零时链表
	newList.Clear();

	Node* myTemp = this->m_pHead;
	Node* otherTemp = other.m_pHead;

	bool flag = true;
	while (flag) {
		if (nullptr == myTemp->NextNode) {  // 直接连接other的剩余
			while (nullptr != otherTemp->NextNode) {
				newList.AddEndNum(otherTemp->NextNode->number);  // 使用尾插法
				otherTemp = otherTemp->NextNode;
			}
			flag = false;
		}
		else if (nullptr == otherTemp->NextNode) {  // 直接连接mytemp的剩余
			while (nullptr != myTemp->NextNode) {
				newList.AddEndNum(myTemp->NextNode->number);  // 使用尾插法
				myTemp = myTemp->NextNode;
			}
			flag = false;
		}
		else {
			if (myTemp->NextNode->number < otherTemp->NextNode->number) {
				newList.AddEndNum(myTemp->NextNode->number);  // 使用尾插法
				myTemp = myTemp->NextNode;
			}
			else {
				newList.AddEndNum(otherTemp->NextNode->number);  // 使用尾插法
				otherTemp = otherTemp->NextNode;
			}
		}
	}

	this->Clear();  // 先清除一下，不知道有没有用哈哈哈
	*this = newList;  // ( = ) 的重载好像有点问题

}

/***********************************************************************
* 函 数 名：Sort()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：冒泡排序，递增
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释
***********************************************************************/
void SingleList::Sort() {
	for (int i = 1; i < this->m_Len; i++) {  // 趟数
		Node* pTemp01 = this->m_pHead;
		for (int j = 0; j < this->m_Len - i; j++) {  // 每趟比较的次数
			Node* pTemp02 = pTemp01->NextNode;
			if (pTemp01->NextNode->number > pTemp02->NextNode->number) {
				// 交换
				pTemp01->NextNode = pTemp02->NextNode;
				pTemp02->NextNode = pTemp01->NextNode->NextNode;
				pTemp01->NextNode->NextNode = pTemp02;
				// 后移
				pTemp01 = pTemp01->NextNode;
			}
			else {
				// 后移
				pTemp01 = pTemp01->NextNode;
			}
		}
	}
}
