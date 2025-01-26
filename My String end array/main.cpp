#include <iostream>
//#include "Array.h"
//#include "Fifo.h"
//#include "Lifo.h"
//#include "My_String.h"
//#include "list.h"
//#include "Stack.h"
#include "doubly_list.h"
#include "Queue.h"


int main() { 
	srand(time(0));
	Doubly_List<int> dList;
	dList.AddToHead(73);
	dList.AddToTail(14);
	dList.AddToTail(17);
	dList.AddToTail(37);
	dList.AddToTail(15);


	dList.Show();
	Doubly_List<int> dList1;
	dList1.AddToHead(11);
	dList1.AddToTail(12);
	dList1.AddToTail(13);
	dList1.AddToTail(14);
	dList1.AddToTail(15);
	dList1.Show();



	Node<int>* zvezda = dList* dList1;
	Doubly_List<int> dList2;
	dList2.head = zvezda;
	dList2.Show();
	//dList2.Reverse();
	/*Node<int>* clone = dList.Clone();
	Doubly_List<int> dList2;
	dList2.head = clone;
	dList2.Show();
	dList2.Reverse();

	Node<int>* plus = dList + dList2;
	Doubly_List<int> dList3;
	dList2.head = plus;
	dList2.Show();*/
	//dList.InsertPos(25, 2);
	//dList.DeletePos(5);
	//dList.Show();
	//dList.Reverse();
	//dList.Show();
	//std::cout << dList.Find(70);
	/*Queue<int> queue;
	queue.AddElement(10);
	queue.AddElement(11);
	queue.AddElement(12);
	queue.AddElement(13);
	queue.AddElement(14);
	queue.Show();
	queue.DelElement();
	queue.Show();
	std::cout<<queue.FElement();*/
	return 0;
}