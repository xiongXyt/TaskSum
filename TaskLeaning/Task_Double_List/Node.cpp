#include "Node.h"

Node::Node() :pFront(nullptr), pNext(nullptr) {
	this->data = 0;
}

Node::~Node() {

}

Node::Node(int data, Node* pFront, Node* pNext)
	:data(data), pFront(pFront), pNext(pNext) {

}