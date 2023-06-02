#ifndef _SLIST_H_
#define _SLIST_H_

/***************************************************
*
*	��    ����SList
*
*	��    �ܣ������ݵ�˳�����Ա�
*
*	�޸ļ�¼��
*
*		�޸�ʱ�䣺�� 2023-06-1 ��
*		�޸����ݣ��� ��Ŀ������������Ա�Ļ������� ��
*
*		�޸�ʱ�䣺�� 2023-06-2 ���� ��
*		�޸����ݣ��� ע�ͣ���Ŀ����� ��
*
*	��    �ߣ��� xyt ��
*	��ϵ��ʽ��3124725835@qq.com
*
*	��    ����
*
***************************************************/

#include<iostream>
using namespace std;

#define SNUM short

#define MAXSIZE 10
#define ADDSIZE 10

/*
* ���ݳ�Ա����󳤶ȣ���ʹ�õĳ��ȣ��������ָ��
*/

class SList {
private:
	SNUM m_MaxSize;		// ��󳤶�
	SNUM m_Usedsize;	// ��ʹ�õĳ���
	SNUM* m_Array;		// �������ָ��

private:
	bool IsFull();  // ���Ա�����
	void AddLen();  // ����˳�����Ա���

public:
	SList();
	SList(SNUM len, SNUM num);
	SList(SNUM* begin, SNUM* end);
	SList(const SList& other);
	~SList();

	SNUM GetUsedsize()const;
	SNUM* GetArray()const;

	bool IsEmpty();
	void Push_Back(SNUM num);
	void Pop_Back();
	void Insert(SNUM pos, SNUM num);	// ָ��λ�ò���
	void Remove(SNUM num);				// ɾ��ֵΪval�ĵ�һ��Ԫ��
	void RemoveAll(SNUM num);			// ɾ������ֵΪval��Ԫ��
	void Sort(bool flag = true);		// ��������Ĭ��������
	void SortOne(bool flag = true);		// ����֮����ͬԪ�ر���һ��

	void PrintArr();

};

#endif // !_SLIST_H_
