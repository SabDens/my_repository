#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

template <typename T>
class Node
{
public:
	T value;
	Node* next;
	Node* prev;

	Node(const T& value) : value(value), next(nullptr), prev(nullptr)
	{}

	void print() const
	{
		std::cout << value;
	}
};

template<typename T>
class Doubly_List
{
public:
	Node<T>* head;
	Node<T>* back;


	Doubly_List() : head{ nullptr }, back{ nullptr }
	{}

	/*void add(const T& value)
	{
		Node<T>* nodePtr = new Node<T>(value);
		nodePtr->next = head;
		head = nodePtr;
	}*/

	void AddToHead(const T& value) {
		Node<T>* nodePtr = new Node<T>(value);
		nodePtr->next = head;
		nodePtr->prev = nullptr;
		if (head == nullptr) {
			back = nodePtr;

		}
		else {
			head->prev = nodePtr;
		}
		head = nodePtr;
		//back = nodePtr;
	}
	void AddToTail(const T& value) {
		if (head == nullptr)
		{
			AddToHead(value);
			return;
		}
		Node<T>* nodePtr = new Node<T>(value);
		nodePtr->prev = back;
		if (back != nullptr) {
			back->next = nodePtr;
		}
		back = nodePtr;
	}

	void DeleteFromHead() {
		if (head == nullptr) {
			return;
		}
		Node<T>* nodePtr = head;
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		else {
			back = nullptr;
		}
		delete nodePtr;


	}

	void DeleteFromTail() {
		if (back == nullptr) {
			return;
		}
		Node<T>* nodePtr = back;
		back = back->prev;
		if (back != nullptr) {
			back->next = nullptr;
		}
		else {
			head = nullptr;
		}
		delete nodePtr;
	}
	/*void remove()
	{
		if (head != nullptr)
		{
			Node<T>* nodePtr = head;
			head = head->next;
			delete nodePtr;
		}
	}*/
	void DeleteAll() {
		while (head != nullptr) {
			DeleteFromHead();
		}
	}


	/*Node<T>* find(const T& value) const
	{
		for (Node<T>* nodePtr = head;
			nodePtr != nullptr;
			nodePtr = nodePtr->next)
		{
			if (nodePtr->value == value)
			{
				return nodePtr;
			}
		}
		return nullptr;
	}

	Node<T>* findPrev(const T& value) const
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		for (Node<T>* nodePtr = head->next, *prevPtr = head;
			nodePtr != nullptr;
			nodePtr = nodePtr->next, prevPtr = prevPtr->next)
		{
			if (nodePtr->value == value)
			{
				return prevPtr;
			}
		}
		return nullptr;
	}

	Node<T>* addAfter(const T& value, Node<T>* afterPtr)
	{
		if (afterPtr == nullptr)
		{
			return nullptr;
		}
		Node<T>* nodePtr = new Node<T>(value);
		nodePtr->next = afterPtr->next;
		afterPtr->next = nodePtr;
		return afterPtr->next;
	}

	Node<T>* removeAfter(Node<T>* afterPtr)
	{
		if (afterPtr != nullptr && afterPtr->next != nullptr)
		{
			Node<T>* nodePtr = afterPtr->next;
			afterPtr->next = afterPtr->next->next;
			delete nodePtr;
		}
		return afterPtr;
	}

	void clear()
	{
		while (head != nullptr)
		{
			remove();
		}
	}

	void doForEach(void(*func)(Node<T>* nodePtr))
	{
		for (Node<T>* nodePtr = head; nodePtr != nullptr; nodePtr = nodePtr->next)
		{
			func(nodePtr);
		}
	}

	static void printNode(Node<T>* nodePtr)
	{
		nodePtr->print();
		std::cout << " > ";
	}

	void print()
	{
		std::cout << " > ";
		doForEach(printNode);
		std::cout << std::endl;
	}*/

	void Show() const {
		Node<T>* nodePtr = head;
		while (nodePtr != nullptr) {
			std::cout << nodePtr->value << " ";
			nodePtr = nodePtr->next;

		}
		std::cout << "\n";
	}
	void Reverse() {
		Node<T>* temp_h = head;
		Node<T>* temp_n = nullptr;

		while (temp_h != nullptr) {
			temp_n = temp_h->prev;
			temp_h->prev = temp_h->next;
			temp_h->next = temp_n;
			temp_h = temp_h->prev;

		}
		if (temp_n != nullptr) {
			head = temp_n->prev;

		}
	}
	void InsertPos(T value, int pos) {
		Node<T>* nodePtr = new Node<T>(value);
		Node<T>* temp_h = head;

		for (int i = 0; i < pos-1;i++) {
			if (temp_h == nullptr) {
				return; 

			}
			temp_h = temp_h->next;
		}
		nodePtr->next = temp_h->next;
		nodePtr->prev = temp_h;
		if (temp_h->next == nullptr) {
			back = nodePtr;
		}
		else {
			temp_h->next->prev = nodePtr;
		}
		temp_h->next = nodePtr;
	}
	void DeletePos(int pos) {

		Node<T>* temp_h = head;
		for (int i = 0; i < pos-1; i++) {
			if (temp_h == nullptr) {
				return; 
			}
			temp_h = temp_h->next;
		}
		temp_h->prev->next = temp_h->next;
		temp_h->next->prev = temp_h->prev;

		delete temp_h;
	}

	int Find(T value) const {
		Node<T>* temp_h = head;
		size_t position = 0;
		while (temp_h != nullptr) {
			position++;


			if (temp_h->value == value) {
				return position;

			}
			temp_h = temp_h->next;
		}
		std::cout << "NULL";
		return -1;
	}
	int Replace(T value,T newValue) {
		int count = 0;
		Node<T>* temp_h = head;
		while (temp_h != nullptr) {
			if (temp_h->value == value) {
				temp_h->value = newValue;
				count++;
			}
			temp_h = temp_h->next;
		}
		if (count > 0)
		{
			return count;
		}
		return  -1;
	}


	Node<T>* Clone() const {
		Node<T>* newList = new Node<T>(head->value); 
		Node<T>* temp_h = head->next; 
		Node<T>* nodePtr = newList;

		while (temp_h != nullptr) {

			Node<T>* newNode = new Node<T>(temp_h->value);
			nodePtr->next = newNode;
			newNode->prev = nodePtr;
			nodePtr = newNode;
			temp_h = temp_h->next;

		}


		return newList;
	}

	Node<T>* operator+(const Doubly_List<T>& other) const {
		Node<T>* newList = this->Clone();

		Node<T>* temp_h = newList;

		while (temp_h->next != nullptr) {
			temp_h = temp_h->next; 
		}
		Node<T>* tempOther = other.head;

		while (tempOther != nullptr) {
			Node<T>* nodePtr = new Node<T>(tempOther->value);

			temp_h->next = nodePtr;
			nodePtr->prev = temp_h;

			temp_h = nodePtr;
			tempOther = tempOther->next;
		}

		return newList;
	}





	//я страдал 
	Node<T>* operator*(const Doubly_List<T>& other) const {
		Doubly_List<T> List;
		List.head = *this + other;

		Doubly_List<T> newList;
		Node<T>* temp_h = List.head;

		while (temp_h != nullptr) {
			size_t count = 0;
			Node<T>* innerTemp = List.head;

			for (size_t i = 0; innerTemp != nullptr; i++) {

				if (innerTemp->value == temp_h->value) {
					count++;
				}

				if (count > 1) {
					Node<T>* checkTemp = newList.head;
					bool isDuplicate = true;

					while (checkTemp != nullptr) {

						if (checkTemp->value == temp_h->value) {
							isDuplicate = false;
							break;
						}
						checkTemp = checkTemp->next;
					}

					if (isDuplicate) {
						newList.AddToTail(temp_h->value);
						break;

					}
				}

				innerTemp = innerTemp->next;
			}

			temp_h = temp_h->next;
		}
		return newList.head;
	}


};

#endif