#ifndef _LIST_H_
#define _LIST_H_

// ����:Ϊ�˷�ֹͷ�ļ���������
class Node;
class Iterator;

// �Զ����˫��������
class List {
private:
	void Init_Node(int num);

public:
	List();
	~List();
	void push_back(const int& val); // ��β������Ԫ��
	void pop_front();				// ��ͷ��ɾ��
	void print();					// ��ӡ�����е�����
	bool empty() const;				// �ж�Ϊ��
	void clear();
	void remove(const int& val);
	void unique();
	void swap(List& lst);
	void reverse();
	void merge(List& lst);
	void sort();
	int size();

public:
	Iterator begin();			  // begin:����ָ��ͷ���ĵ�����
	Iterator end();				  // end:����ָ����β���ĵ�����
	Iterator erase(Iterator pos); // erase
	Iterator erase(Iterator start, Iterator end);
	Iterator insert(Iterator pos, const int& val);
	void splice(Iterator pos, List& lst); // splice// ���lst����
	void splice(Iterator pos, List& other, Iterator first, Iterator last);
private:
	Node* pHead; // ָ����ͷ(���洢����)����ָ��
	Node* pRear; // ָ����β(���洢����)����ָ��
private:
	bool isOrder(); // �ж������Ƿ�����(����)
};

#endif // !_LIST_H_
