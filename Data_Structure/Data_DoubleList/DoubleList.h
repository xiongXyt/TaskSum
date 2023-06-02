#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_

/***************************************************
*
*	��    ����DoubleList
*
*	��    �ܣ�int ����˫������
*
*	�޸ļ�¼��
*
*		�޸�ʱ�䣺�� 2023-05-11 ��
*		�޸����ݣ��� ��Ŀ������������ݳ�Ա���塢�������� ��
*
*		�޸�ʱ�䣺�� 2023-05-12 ���� ��
*		�޸����ݣ��� ��ɲ������ܣ�����һ������ȷ�����µ����� ��
*
*		�޸�ʱ�䣺�� 2023-05-12 ���� ��
*		�޸����ݣ��� ��������ȷ�����µ�����ע�ͣ���Ŀ����� ��
*
*		�޸�ʱ�䣺�� 2023-05-13 ���� ��
*		�޸����ݣ��� ��Ŀ��β���� ��
* 
*		�޸�ʱ�䣺�� 2023-06-2 ���� ��
*		�޸����ݣ��� �޸�����Ϊ DoubleList ��
*
*	��    �ߣ��� xyt ��
*	��ϵ��ʽ��3124725835@qq.com
*
*	��    ����
*
***************************************************/

#include<iostream>
using namespace std;

/***************************************************
* �ڵ�ṹ�壬�ڵ���ָ����һ���ڵ����һ���ڵ�
***************************************************/
struct Node {
	// ������
	int number;
	// ָ����
	Node* FrontNode;  // ǰ���ڵ�
	Node* NextNode;   // ����ڵ�
};

/***************************************************
*	˵����ʹ�ÿյ�ͷ�ڵ㣬�����������������������ĳ���
*
*	��    ��    [ DoubleList ]
*
*	��Ĺ��ܣ��Լ�д����������
*
*	��    ����ʹ�ÿյ�ͷ�ڵ㣬�ǿ�Ϊ�ڵ㣬�����ͷ����������������������ĳ���
*			  ͷ������һ���ڵ��ʾ��һ���ڵ�
*			  һ���ڵ��ܹ�ָ����һ���ڵ����һ���ڵ�
*
*	�ϴ�����
*		��Ŀ������ǰ�ڲݸ壬��ȷ����
*		���������������롢ɾ��
*		��Ŀ����򻯡�ע�͡�����
*
*	��������
*		���ԣ�����ӿڣ����ղο��ֲ�ʵ�ֺ�������
*
***************************************************/
class DoubleList {
private:
	Node* m_pHead;
	Node* m_pEnd;
	int m_Len;

	void __InitList();  // ��ʼ������

public:
	DoubleList();
	DoubleList(int num);
	DoubleList(int n, int num);
	DoubleList(int* Begin, int* End);
	DoubleList(const DoubleList& other);
	~DoubleList();

	DoubleList operator+(const DoubleList& other);
	DoubleList operator=(const DoubleList& other);

	void PrintTable();  // ��ӡ����

	void AddHeadNum(int num);  // ͷ����
	void AddEndNum(int num);  // β����
	void AddIndexNum(int index, int num);  // ����ָ��λ�ò���

	void DeleteHeadNum();  // ͷɾ��
	void DeleteEndNum();  // βɾ��

	void DeleteIndexNum(int index);  // ����ָ��λ��ɾ��
	void DeleteNum(int num, bool flag = false);     // ɾ������ num ���ݵĵ�һ���ڵ�

	void Sort();           // ����

};

#endif // !_DOUBLELIST_H_
