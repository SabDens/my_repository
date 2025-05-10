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
			throw  std::runtime_error("DeleteFromHead():head == nullptr");
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
			throw  std::runtime_error("DeleteFromTail():back == nullptr");
		}
		else if (head == nullptr) {
			throw  std::runtime_error("DeleteFromHead():head == nullptr");
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

	void DeleteAll() {
		if (head == nullptr) {
			throw  std::runtime_error("DeleteAll():head == nullptr");
		}
		while (head != nullptr) {
			DeleteFromHead();
		}
	}


	void Show() const {
		if (head == nullptr) {
			throw  std::runtime_error("Show():head == nullptr");
		}
		Node<T>* nodePtr = head;
		while (nodePtr != nullptr) {
			std::cout << nodePtr->value << " ";
			nodePtr = nodePtr->next;

		}
		std::cout << "\n";
	}
	void Reverse() {
		if (head == nullptr) {
			throw  std::runtime_error("Show():head == nullptr");
		}
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
		if (head == nullptr) {
			throw  std::runtime_error("InsertPos(T value, int pos):head == nullptr");
		}
		Node<T>* nodePtr = new Node<T>(value);
		Node<T>* temp_h = head;

		for (int i = 0; i < pos-1;i++) {
			if (temp_h == nullptr) {
				throw  std::runtime_error("InsertPos(T value, int pos):position non");

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
		if (head == nullptr) {
			throw  std::runtime_error("DeletePos(int pos):head == nullptr");
		}
		Node<T>* temp_h = head;
		for (int i = 0; i < pos-1; i++) {
			if (temp_h == nullptr) {
				throw  std::runtime_error("DeletePos(int pos):position non");
			}
			temp_h = temp_h->next;
		}
		temp_h->prev->next = temp_h->next;
		temp_h->next->prev = temp_h->prev;

		delete temp_h;
	}

	int Find(T value) const {
		if (head == nullptr) {
			throw  std::runtime_error("Find(T value):head == nullptr");
		}
		Node<T>* temp_h = head;
		size_t position = 0;
		while (temp_h != nullptr) {
			position++;


			if (temp_h->value == value) {
				return position;

			}
			temp_h = temp_h->next;
		}
		throw  std::runtime_error("Find(T value):NULL");

	}
	int Replace(T value,T newValue) {
		if (head == nullptr) {
			throw  std::runtime_error("Replace(T value,T newValue):head == nullptr");
		}
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
		throw  std::runtime_error("Replace(T value,T newValue):NULL");
	}


	Node<T>* Clone() const {
		if (head == nullptr) {
			throw  std::runtime_error("Clone():head == nullptr");
		}
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
		if (head == nullptr) {
			throw  std::runtime_error("operator+(const Doubly_List<T>& other):head == nullptr");
		}
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



	Node<T>* operator*(const Doubly_List<T>& other) const {
		if (other.head == nullptr) {
			throw  std::runtime_error("operator*(const Doubly_List<T>& other):other.head == nullptr");
		}
		else if (other.head == nullptr) {
			throw  std::runtime_error("operator*(const Doubly_List<T>& other):head == nullptr");
		}
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