#include <iostream>
#include "Array.h"
//#include "Fifo.h"
//#include "Lifo.h"
#include "My_String.h"
//#include "list.h"
//#include "Stack.h"
//#include "doubly_list.h"
//#include "Queue.h"
#include "Student.h"

int main() { 

	srand(time(0));
	//1 è 2


	try
	{
		//Array<int> obj_arr(0);
		Array<int> obj_arr(10);
		obj_arr.RandArray(10);
		//obj_arr.RandArray(0);
		obj_arr.Errase(20);
		//obj_arr.Reserve(0);
		obj_arr.Print();
		
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
	/*My_String string("Denys");
	My_String string1;
	string.Print();	

	string1 = std::move(string);
	string1.Print();*/
	//string.Print();

	


	//3 è 4

	/*Student student1;
	student1.Init_Auto(5);
	student1.Show();


	Student student2 = std::move(student1);
	student2.Show();
	Student student3(std::move(student1));
	student3.Show();*/
	/*Doubly_List<int> dList;
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
	dList2.Show();*/
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


