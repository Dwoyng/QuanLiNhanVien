#pragma once
#include "Employee.h"
#include<iostream>
#include<string.h>
using namespace std;

struct Node {
	Employee employee;
	Node* nextL;
	Node* nextR;
	Node() : nextL(nullptr), nextR(nullptr) {}
};

struct DoubleLinkedList {
	Node* Head;
	Node* Tail;
};



void InitDoubleLinkedList(DoubleLinkedList& H) {
	H.Head = H.Tail = NULL;
}

bool IsEmpty(DoubleLinkedList& H) {
	return H.Head == NULL;
}

Node* Searching(DoubleLinkedList& H, Employee& data) {
	if (IsEmpty(H)) return NULL;
	else {
		Node* ptr = H.Head;
		while (ptr)
		{
			if (data == ptr->employee) return ptr;
			ptr = ptr->nextR;
		}
	}
	return NULL;
}

Node* MakeNode(Employee a) {
	Node* newNode = new Node;
	newNode->employee = a;
	newNode->nextL = NULL;
	newNode->nextR = NULL;
	return newNode;
}
void InsertBegin(DoubleLinkedList& H, Employee& data) {
	Node* newNode = MakeNode(data);
	if (IsEmpty(H)) {
		H.Head = H.Tail = newNode;
	}
	else {
		newNode->nextR = H.Head;
		H.Head->nextL = newNode;
		H.Head = newNode;
	}
}


void DisPlay(DoubleLinkedList& DL) {
	if (IsEmpty(DL)) { cout << "Danh Sach Rong!"; }


	else {
		cout << "Hien Thi: ";
		Node* ptr = DL.Head;
		while (ptr)
		{
			CoutE(ptr->employee);
			ptr = ptr->nextR;
		}
	}
	cout << '\n';
}
// Bo sung phan tu vao truoc phan tu duoc tro boi P
void InsertBefore(DoubleLinkedList& DL, Employee& data, Node* P) {
	Node* newNode = MakeNode(data);
	if (IsEmpty(DL)) {
		DL.Head = DL.Tail = newNode;
		return;
	}
	if (P == NULL) return;

	if (P == DL.Head) {
		InsertBegin(DL, data);
		return;
	}
	else
	{
		newNode->nextR = P;
		newNode->nextL = P->nextL;
		P->nextL = newNode;
		newNode->nextL->nextR = newNode;
	}


}
void InsertTail(DoubleLinkedList& H, Employee& data) {
	Node* A = Searching(H, data);
	if (IsEmpty(H)) {
		InsertBegin(H, data);
		return;
	}
	if (A == NULL) return;

	Node* ptr = H.Tail;
	A->nextL = ptr->nextR;
	A->nextR = NULL;
	ptr->nextR = A;
}


// THEM PHAN TU VAO 1 PHAN TU SAU 1 PHAN TU DUOC CHI DINH
void InSertAfter(DoubleLinkedList& H, Employee data, Node* P) {
	if (IsEmpty(H)) {
		InsertBegin(H, data);
		return;
	}
	if (P == H.Tail) {
		InsertTail(H, data);
		return;
	}
	if (!P) return;

	Node* A = MakeNode(data);
	A->nextL = P->nextR;
	A->nextR = P->nextR->nextL;
	P->nextR = A;
}

void DeleteEnd(DoubleLinkedList& H) {
	if (IsEmpty(H)) return;
	if (H.Head == H.Tail) {
		delete H.Head;
		H.Head = H.Tail = NULL;
		return;
	}
	Node* ptr = H.Head;
	while (ptr->nextR != NULL) {
		ptr = ptr->nextR;
	}
	ptr->nextL->nextR = NULL;
	delete ptr;
}

void DeleteBegin(DoubleLinkedList& H) {
	if (IsEmpty(H)) return;
	if (H.Head == H.Tail) {
		Node* ptr = H.Head;
		delete ptr;
		H.Head = H.Tail = NULL;
	}
	else {
		Node* ptr = H.Head;
		H.Head = ptr->nextR;
		H.Head->nextL = NULL;
		delete ptr;
	}
}
void DeleteSelected(DoubleLinkedList& H, Node* P) {
	if (IsEmpty(H)) return;
	if (P == NULL) return;
	if (P == H.Head) {
		DeleteBegin(H);
		return;
	}
	if (P == H.Tail) {
		DeleteEnd(H);
		return;
	}
	else
	{
		P->nextL->nextR = P->nextR;
		P->nextR->nextL = P->nextL;
		delete P;
	}
}

