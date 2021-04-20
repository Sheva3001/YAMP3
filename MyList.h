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
	List();												//����������� �� ���������
	~List();											//����������
	void init();						 	//�����������
	bool isEmpty();							//�������� �� ������� 
	void addToHead(int elem);			//���������� � ������
	void addAfterNode(Node* pNode, int elem);			//���������� ����� ��������� ��������
	void addToTail(int elem);
	void deleteFromHead();					//�������� � ������ ������ 
	void deleteAfterNode(Node* pNode);					//�������� ����� ��������� �������� 
	void clear(Node*& head);							//������� ������ 
	void printList();									//������ ������
	void print(Node* head);							//����������� ������ ������ 	

	Node* getHead();									//��������� �������� ����� ������
	Node* getNext(Node* obj);
	int getCount();

	void createFromHead(ifstream& input);	//������������ ������ � ������ ������� 
	void createFromTail();					//������������ ������ � �������� ������� 
};
