#include"DoubleList.h"

/*
* 私有成员
*/
/***********************************************************************
* 函 数 名：__InitList()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：初始化链表空头节点，初始化链表尾节点并指向头结点
*			-- 2 -- ：链表长度为零
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写个注释
***********************************************************************/
void DoubleList::__InitList() {
	// 初始化链表空头节点
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// 初始化链表尾节点并指向头结点
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;
}

/*
* 公有成员
*/
/***********************************************************************
* 函 数 名：DoubleList()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：无参构造函数。
*			-- 2 -- ：初始化空头节点，初始化尾节点并指向头结点。
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是把里面的内容全部集成到了私有成员函数  __InitList()
***********************************************************************/
DoubleList::DoubleList() {
	this->__InitList();  // 初始化链表
}

/***********************************************************************
* 函 数 名：DoubleList(int num)
* 形 参 表：
*			1 ) num -->( int ) : 需要初始化链表的节点个数
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：有参构造
*			-- 2 -- ：初始化空头节点，初始化尾节点并指向头结点。
*			-- 3 -- ：构造 1~num 的有序链表
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是把里面的头插法集成到了公有成员函数 AddHeadNum(int num)
***********************************************************************/
DoubleList::DoubleList(int num) {
	this->__InitList();  // 初始化链表

	for (int i = num; i >= 1; --i) {
		this->AddHeadNum(i);  // 头插法
	}
}

/***********************************************************************
* 函 数 名：DoubleList(int n, int num)
* 形 参 表：
*			1 ) n ---->( int ) : 需要初始化链表的节点个数
*			2 ) num -->( int ) : 链表每个节点数据域的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：有参构造
*			-- 2 -- ：初始化空头节点，初始化尾节点并指向头结点。
*			-- 3 -- ：构造值都为 num 的链表
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是把里面的头插法集成到了公有成员函数 AddHeadNum(int num)
***********************************************************************/
DoubleList::DoubleList(int n, int num) {
	this->__InitList();  // 初始化链表

	for (int i = n; i >= 1; --i) {
		this->AddHeadNum(num);  // 头插法
	}
}

/***********************************************************************
* 函 数 名：DoubleList(int* Begin, int* End)
* 形 参 表：
*			1 ) Begin --->( int* ) : 连续内存的第一个地址
*			2 ) End   --->( int* ) : 连续内存的最后一个地址
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：有参构造
*			-- 2 -- ：初始化空头节点，初始化尾节点并指向头结点。
*			-- 3 -- ：构造值为一段连续内存内的值的链表
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是把里面的头插法集成到了公有成员函数 AddHeadNum(int num)
***********************************************************************/
DoubleList::DoubleList(int* Begin, int* End) {
	this->__InitList();  // 初始化链表

	for (int* pNum = Begin; pNum < End; ++pNum) {
		this->AddEndNum(*pNum);  // 头插法
	}
}

/***********************************************************************
* 函 数 名：DoubleList(const DoubleList& other)
* 形 参 表：
*			1 ) other -->( const DoubleList& ) : 另外一个常链表类
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：复制构造函数
*			-- 2 -- ：初始化空头节点，初始化尾节点并指向头结点。
*			-- 3 -- ：深复制一个只有值相同的链表
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是把里面的尾插法集成到了公有成员函数 AddEndNum(int num)
***********************************************************************/
DoubleList::DoubleList(const DoubleList& other) {
	this->__InitList();  // 初始化链表

	Node* pNum = other.m_pHead->NextNode;  // 保存头节点的下一个节点

	// 这里采用尾插法
	while (pNum != nullptr) {
		this->AddEndNum(pNum->number);  // 尾插法

		// 指针后移
		pNum = pNum->NextNode;
	}
}

/***********************************************************************
* 函 数 名：~DoubleList()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：析构函数
*			-- 2 -- ：遍历释放
*			-- 3 -- ：尾节点是单独释放的
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：单独释放了尾节点
***********************************************************************/
DoubleList::~DoubleList() {
	Node* pTemp = nullptr;  // 临时保存节点

	// 单独释放尾节点
	delete this->m_pEnd;
	this->m_pEnd = nullptr;

	// 从头节点开始向后释放节点
	while (this->m_pHead != nullptr) {
		pTemp = this->m_pHead;
		this->m_pHead = this->m_pHead->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	// 链表长度置为零
	this->m_Len = 0;
}

/***********************************************************************
* 函 数 名：operator+(const DoubleList& other)
* 形 参 表：
*			1 ) other -->( const DoubleList& ) : 另外一个常链表类
* 返 回 值：
*			1 ) DoubleList : 返回当面的链表
* 函数功能：
*			-- 1 -- ：加法重载函数
*			-- 2 -- ：尾插法
*			-- 3 -- ：当前链表的最后一节点接一个链表的值
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是把里面的尾插法集成到了公有成员函数 AddEndNum(int num)
***********************************************************************/
DoubleList DoubleList::operator+(const DoubleList& other) {
	Node* pOther = other.m_pHead->NextNode;  // 保存传入链表头节点的下一个节点

	// 遍历传入的链表
	while (pOther != nullptr) {
		this->AddEndNum(pOther->number);  // 尾插法

		// 指针后移
		pOther = pOther->NextNode;
	}
	return *this;
}

/***********************************************************************
* 函 数 名：operator=(const DoubleList& other)
* 形 参 表：
*			1 ) other -->( const DoubleList& ) : 另外一个常链表类
* 返 回 值：
*			1 ) DoubleList : 返回当面的链表
* 函数功能：
*			-- 1 -- ：等于重载函数
*			-- 2 -- ：尾插法
*			-- 3 -- ：当前链表的值为另外一个链表的值，深拷贝
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是把里面的尾插法集成到了公有成员函数 AddEndNum(int num)
***********************************************************************/
DoubleList DoubleList::operator=(const DoubleList& other) {
	this->__InitList();  // 初始化链表

	Node* pOther = other.m_pHead->NextNode;  // 保存传入链表头节点的下一个节点

	// 遍历传入的链表
	while (pOther != nullptr) {
		this->AddEndNum(pOther->number);  // 尾插法

		// 指针后移
		pOther = pOther->NextNode;
	}
	return *this;
}

/***********************************************************************
* 函 数 名：PrintTable()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：从头节点下一个节点打印全部链表的值
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：新增加链表长度的打印
***********************************************************************/
void DoubleList::PrintTable() {
	Node* pPint = this->m_pHead->NextNode;  // 保存链表头节点的下一个节点

	// 打印链表长度
	cout << "m_Len : " << this->m_Len << endl;

	// 遍历打印链表
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;
		pPint = pPint->NextNode; // 指针后移
	}
	cout << endl << "--------------------" << endl << endl;
}

/***********************************************************************
* 函 数 名：AddHeadNum(int num)
* 形 参 表：
*			1 ) num -->( int ) : 插入链表的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：插入新值到链表的头部
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
void DoubleList::AddHeadNum(int num) {
	// 初始化新节点
	Node* pNew = new Node;
	pNew->number = num;
	pNew->FrontNode = pNew->NextNode = nullptr;

	if (0 == this->m_Len) {  // 链表为空
		// 在头节点后面挂载新的节点
		this->m_pHead->NextNode = pNew;
		pNew->FrontNode = this->m_pHead;

		// 尾节点指向最后一个节点
		this->m_pEnd->NextNode = pNew;

		// 长度增加一
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {  // 链表不为空
		// 在头节点插入新的节点
		pNew->NextNode = this->m_pHead->NextNode;
		pNew->FrontNode = this->m_pHead;
		this->m_pHead->NextNode = pNew;
		pNew->NextNode->FrontNode = pNew;

		// 长度增加一
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

/***********************************************************************
* 函 数 名：AddEndNum(int num)
* 形 参 表：
*			1 ) num -->( int ) : 插入链表的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：插入新值到链表的尾部
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
void DoubleList::AddEndNum(int num) {
	// 初始化新节点
	Node* pNew = new Node;
	pNew->number = num;
	pNew->FrontNode = pNew->NextNode = nullptr;

	// 挂载新节点到链表尾部
	this->m_pEnd->NextNode->NextNode = pNew;
	pNew->FrontNode = this->m_pEnd->NextNode;

	// 尾节点指向最后一个节点
	this->m_pEnd->NextNode = pNew;

	// 长度增加一
	++this->m_Len;
	this->m_pHead->number = this->m_Len;
	this->m_pEnd->number = this->m_Len;
}

/***********************************************************************
* 函 数 名：AddIndexNum(int index, int num)
* 形 参 表：
*			1 ) index -->( int ) : 插入链表的位置
*			2 ) num -->( int ) : 插入链表的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：插入新值 num 到链表的 index 位置
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
void DoubleList::AddIndexNum(int index, int num) {
	if (index > 0 && index <= this->m_Len + 1) {  // 索引正确
		if (this->m_Len + 1 == index) {  // 最后位置
			this->AddEndNum(num);    // 尾插法
		}
		else {  // 非最后位置
			// 初始化新节点
			Node* pNew = new Node;
			pNew->number = num;
			pNew->FrontNode = pNew->NextNode = nullptr;

			// 遍历至插入位置前一个节点
			Node* pIndex = this->m_pHead;
			for (int i = 1; i < index; i++) {
				pIndex = pIndex->NextNode;
			}

			// 插入新节点至 index 位置
			pNew->NextNode = pIndex->NextNode;
			pNew->FrontNode = pIndex;
			pIndex->NextNode = pNew;
			pNew->NextNode->FrontNode = pNew;

			// 长度增加一
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
		}
	}
	else {  // 索引有误
		cout << "插入位置有误！" << endl;
	}
}

/***********************************************************************
* 函 数 名：DeleteHeadNum()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表的一个节点
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
***********************************************************************/
void DoubleList::DeleteHeadNum() {
	if (this->m_Len == 0) {   // 链表为空
		cout << "链表为空！" << endl;
	}
	else if (this->m_Len == 1) {  // 链表长度为一
		Node* pTemp = this->m_pHead->NextNode;  // 保存链表头节点的下一个节点

		// 断开第一个节点
		this->m_pEnd->NextNode = this->m_pHead;
		this->m_pHead->NextNode = nullptr;

		// 打印被删除的节点信息
		cout << "删除 : " << pTemp->number << endl;
		cout << "位置 : 1 " << endl;

		// 释放被断开的节点
		delete pTemp;
		pTemp = nullptr;

		// 长度减少一
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {  // 链表长度不为一
		Node* pTemp = this->m_pHead->NextNode;  // 保存链表头节点的下一个节点

		// 断开第一个节点
		this->m_pHead->NextNode = pTemp->NextNode;
		pTemp->NextNode->FrontNode = this->m_pHead;

		// 打印被删除的节点信息
		cout << "删除 : " << pTemp->number << endl;
		cout << "位置 : 1 " << endl;

		// 释放被断开的节点
		delete pTemp;
		pTemp = nullptr;

		// 长度减少一
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

/***********************************************************************
* 函 数 名：DeleteEndNum()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表的最后一个节点
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
***********************************************************************/
void DoubleList::DeleteEndNum() {
	if (0 == this->m_Len) {  // 链表为空
		cout << "链表为空！" << endl;
	}
	else if (1 == this->m_Len) {  // 链表长度为一
		Node* pTemp = this->m_pHead->NextNode;  // 保存链表头节点的下一个节点

		// 断开最后一个节点
		this->m_pEnd->NextNode = this->m_pHead;
		this->m_pHead->NextNode = nullptr;

		// 打印被删除的节点信息
		cout << "删除 : " << pTemp->number << endl;
		cout << "位置 : 1 " << endl;

		// 释放被断开的节点
		delete pTemp;
		pTemp = nullptr;

		// 长度减少一
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {
		Node* pTemp = this->m_pEnd->NextNode;  // 保存链表最后一个节点

		// 断开最后一个节点
		this->m_pEnd->NextNode = pTemp->FrontNode;
		this->m_pEnd->NextNode->NextNode = nullptr;

		// 打印被删除的节点信息
		cout << "删除 : " << pTemp->number << endl;
		cout << "位置 : " << this->m_Len << " " << endl;

		// 释放被断开的节点
		delete pTemp;
		pTemp = nullptr;

		// 长度减少一
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

/***********************************************************************
* 函 数 名：DeleteIndexNum(int index)
* 形 参 表：
*			1 ) : index -->( int ) 删除链表的位置
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表index位置的节点
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
* *					2 ：新增链表长度为零的判断
***********************************************************************/
void DoubleList::DeleteIndexNum(int index) {
	if (0 == this->m_Len) {  // 链表为空
		cout << "链表为空！" << endl;
	}
	else {  // 链表不为空
		if (index > 0 && index <= this->m_Len) {  // 索引正确
			if (1 == index) {  // 第一个节点
				this->DeleteHeadNum();  // 删除头节点
			}
			else if (index == this->m_Len) {  // 最后一个节点
				this->DeleteEndNum();  // 删除尾节点
			}
			else {  // 非头尾节点
				Node* pIndex = this->m_pHead->NextNode;  // 保存链表第一个节点

				// 遍历至需要删除节点前一个节点
				for (int i = 1; i < index; i++) {
					pIndex = pIndex->NextNode;
				}

				// 断开需删除节点
				Node* pTemp = pIndex->NextNode;
				pIndex->NextNode = pTemp->NextNode;
				pTemp->NextNode->FrontNode = pIndex;

				// 打印被删除的节点信息
				cout << "删除 : " << pTemp->number << endl;
				cout << "位置 : " << index << " " << endl;

				// 释放被断开的节点
				delete pTemp;
				pTemp = nullptr;

				// 长度减少一
				--this->m_Len;
				this->m_pHead->number = this->m_Len;
				this->m_pEnd->number = this->m_Len;
			}
		}
		else {  // 索引有误
			cout << "插入位置有误！" << endl;
		}
	}

}

/***********************************************************************
* 函 数 名：DeleteNum(int num, bool flag)
* 形 参 表：
*			1 ) : num --->( int ) 需删除的值
*			2 ) : flag -->( int ) 全部删除链表num值的标志
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表 num 值的第一个节点
*			-- 2 -- ：flag ( true ) 信息全部删除链表 num 值的节点
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
***********************************************************************/
void DoubleList::DeleteNum(int num, bool flag) {  // flag为true,全部删除
	Node* pTemp = this->m_pHead;  // 保存头节点
	Node* pNum = nullptr;         // 保存数据的节点

	int posindex = 1;  // 被删除节点位置

	while (pTemp->NextNode != nullptr) {  // 链表不为空
		if (pTemp->NextNode == this->m_pEnd->NextNode &&
			pTemp->NextNode->number == num) {  // 为最后一个节点，并且值为 num 
			this->DeleteEndNum();
		}
		else if (pTemp->NextNode->number == num) {  // 不为最后一个节点，并且值为 num
			/*********************
			* 删除目标节点，并释放
			* 注意删除之后是不用移动的
			* 因为后面的节点被接上来了
			*********************/

			// 断开需删除节点
			Node* pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;
			pNum->NextNode->FrontNode = pTemp;

			// 打印被删除的节点信息
			cout << "删除 : " << pNum->number << endl;
			cout << "位置 : " << posindex << " " << endl;

			// 释放被断开的节点
			delete pNum;
			pNum = nullptr;

			// 长度减少一
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;

			if (!flag)break;  // flag为true,全部删除
		}
		else {  // 不删除节点时移动
			cout << pTemp->NextNode->number << endl;
			pTemp = pTemp->NextNode;

			// 删除节点位置信息增加一
			++posindex;
		}
	}
}

/***********************************************************************
* 函 数 名：Sort()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：冒泡排序，递增
* 最后更改：
*			更改时间：【 2023.5.12 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释
***********************************************************************/
void DoubleList::Sort() {
	for (int i = 1; i < this->m_Len; i++) {  // 趟次
		Node* pTemp1 = this->m_pHead->NextNode;
		for (int j = 0; j < this->m_Len - i; j++) {  // 每趟交换次数

			Node* pTemp2 = pTemp1->NextNode;
			if (pTemp1->number > pTemp2->number) {  // 大于

				// 交换节点的数据
				int temp = pTemp1->number;
				pTemp1->number = pTemp2->number;
				pTemp2->number = temp;
				/*
				if (pTemp1->NextNode == this->m_pEnd->NextNode) {

					// 向后的指针
					pTemp1->FrontNode->NextNode = pTemp2;
					pTemp1->NextNode = pTemp2->NextNode;
					pTemp2->NextNode = pTemp1;

					// 向前的指针
					pTemp2->FrontNode = pTemp1->FrontNode;
					pTemp1->FrontNode = pTemp2;

					// 尾指针
					this->m_pEnd->NextNode = pTemp1;

				}
				else {

					// 向后的指针
					pTemp1->FrontNode->NextNode = pTemp2;
					pTemp1->NextNode = pTemp2->NextNode;
					pTemp2->NextNode = pTemp1;

					// 向前的指针
					pTemp1->NextNode->FrontNode = pTemp1;
					pTemp2->FrontNode = pTemp1->FrontNode;
					pTemp1->FrontNode = pTemp2;

				}
				*/
			}
			// 指针后移
			pTemp1 = pTemp1->NextNode;
		}
	}
}
