#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class List {
public:
	struct Node
	{
		int data;
		Node* next;
	};

	Node* head;
	Node* tail;
	int count;

public:
	List();												//конструктор по умолчанию
	~List();											//деструктор
	void init();						 	//инициалиция
	bool isEmpty();							//проверка на пустоту 
	void addToHead(int elem);			//добавление в начало
	void addAfterNode(Node* pNode, int elem);			//добавление после заданного элемента
	void addToTail(int elem);
	void deleteFromHead();					//удаление с начала списка 
	void deleteAfterNode(Node* pNode);					//удаление после заданного элемента 
	void clear(Node*& head);							//очистка списка 
	void printList();									//печать списка
	void print(Node* head);							//рекурсивная печать списка 	

	Node* getHead();									//получение значений полей класса
	Node* getNext(Node* obj);
	int getCount();

	void createFromHead(ifstream& input);	//формирование списка в прямом порядке 
	void createFromTail();					//формирование списка в обратном порядке 
};
