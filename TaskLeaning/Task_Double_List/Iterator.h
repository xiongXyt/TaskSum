#ifndef _ITERATOR_H_
#define _ITERATOR_H_

class Node;
// ������:������ָ��,ָ����
/*
1.++/-- : ָ��ǰһ��/��һ�����
2.* : ������
3.==/!= : �ж������������Ƿ����
*/
class Iterator {
public:
	friend class List;
	Iterator(Node* pNode = nullptr);
	~Iterator();
public:// ���������
	Iterator& operator++();// ����ǰ��++:������������
	Iterator operator++(int);// ���غ���++:������������(��������֮ǰ����ʱ����)
	Iterator operator+(int num);
	// C++�����ı���:������_��������1_��������2_
	int& operator*();// ����*�����
	bool operator!=(const Iterator& other); // ����!=�����
private:
	Node* pNode; // pNodeָ��ĳ�����
};

#endif // !_ITERATOR_H_
