#include "MyList.h"
#include <iostream>
#include <fstream>

using namespace std;

List::List() {
	init();
};

List::~List()
{
	//clear(head); 
}

void List::init() {
	head = NULL;
	tail = head;
}

bool List::isEmpty() {
	return head == 0;
}

void List::addToHead(int elem) {
	Node* p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
	if (head->next == NULL)
		tail = head;
}

void List::addAfterNode(Node* pNode, int elem) {
	Node* p = new Node;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
	if (pNode == tail)
		tail = p->next;
}

void List::addToTail(int elem) {
	if (isEmpty())
		addToHead(elem);
	Node* p = new Node;
	p->data = elem;
	tail->next = p;
	p->next = NULL;
	tail = p;
}

void List::deleteFromHead() {
	Node* p = head;
	head = head->next;
	p->next = 0;
	delete p;
}

void List::deleteAfterNode(Node* pNode) {
	if (pNode->next != 0)
	{
		Node* p = pNode->next;
		pNode->next = p->next;
		p->next = 0;
		if (p == tail)
			pNode = tail;
		delete p;
	}
}

void List::clear(Node*& head)
{
	while (!isEmpty())
		deleteFromHead();
	delete head;
}

void List::printList()
{
	Node* p = head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

void List::print(Node* head)
{
	if (head == 0)
		cout << endl;
	else
	{
		cout << head->data << " "; //используем перегрузку вывода
		print(head->next);
	}
}

List::Node* List::getHead()
{
	return head;
}

List::Node* List::getNext(Node* obj)
{
	return obj->next;
}


int List::getCount()
{
	return count;
}

void List::createFromHead(ifstream& input)
{
	init();
	int elem;
	while (input >> elem)			//используем перегрузку ввода 
		addToHead(elem);
}

void List::createFromTail()
{
	init();
	int n;
	cout << "¬ведите количество элементов: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int elem;
		cout << endl << "¬ведите элемент: ";
		cin >> elem;
		if (isEmpty())
		{
			addToHead(elem);
			tail = head;
		}
		else
		{
			addAfterNode(tail, elem);
			tail = tail->next;
		}
	}
}