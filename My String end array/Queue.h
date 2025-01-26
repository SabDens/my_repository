#pragma once
#include "../My String end array/doubly_list.h"

template<typename T>
class Queue
{
public:
	Doubly_List<T> d_list;
	Queue():d_list(){}



	void AddElement(T value) {
		
		d_list.AddToTail(value);
	}

	void DelElement() {
		d_list.DeleteFromHead();
	}
	T FElement() {
		return d_list.head->value;
	}
	void Show() {
		d_list.Show();
	}
};

