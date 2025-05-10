#include <iostream>


template<typename T>
struct Arr
{
	T* arr;
	size_t size;

};

template<typename T>
void rand_arr(Arr<T>& arr) {
	for (size_t i = 0; i < arr.size; i++)
	{
		arr.arr[i] = rand() % 20;
	}
}

template<typename T>
void print(Arr<T>& arr)
{
	std::cout << "arr: ";
	for (int i = 0; i < arr.size; i++) {
		std::cout << arr.arr[i] << " ";
	}
	std::cout << std::endl;

}

template<typename T>
void implement(Arr<T>& arr) {
	std::cin >> arr.size;
	arr.arr = new T[arr.size];

}


template<typename T>
void combine(const Arr<T>& arr_A, const Arr<T>& arr_B, Arr<T>& arr_c ) {
	arr_c.size = arr_A.size + arr_B.size;
	arr_c.arr = new T[arr_c.size];
	for (size_t i = 0; i < arr_A.size; i++)
	{
		arr_c.arr[i] = arr_A.arr[i];
	}
	size_t temp_size = 0;
	for (size_t i = arr_A.size; i < arr_c.size; i++)
	{
		arr_c.arr[i] = arr_B.arr[temp_size];
		temp_size++;
	}
}


template<typename T>
Arr<T> not_repeat(const Arr<T>& arr_A, const Arr<T>& arr_B) {
	Arr<T> arr_c;
	
	combine(arr_A, arr_B, arr_c);
	size_t cout = 0;
	for (size_t i = 0; i < arr_A.size; i++)
	{
		bool in = false;

		for (size_t j = 0; j < arr_B.size; j++)
		{
			if (arr_A.arr[i] == arr_B.arr[j])
			{
				in = true;
			}
		}
		if (!in)
		{
			bool in_c = false;
			for (size_t c = 0; c < cout; c++)
			{
				if (arr_c.arr[c] == arr_A.arr[i])
				{
					in_c = true;
				}
			}
			if (!in_c)
			{
				arr_c.arr[cout] = arr_A.arr[i];
				cout++;

			}
			in = false;
		}
	}
	for (size_t i = 0; i < arr_A.size; i++)
	{
		bool in = false;

		for (size_t j = 0; j < arr_B.size; j++)
		{
			if (arr_B.arr[i] == arr_A.arr[j])
			{
				in = true;
			}
		}
		if (!in)
		{
			bool in_c = false;
			for (size_t c = 0; c < cout; c++)
			{
				if (arr_c.arr[c] == arr_B.arr[i])
				{
					in_c = true;
				}
			}
			if (!in_c)
			{
				arr_c.arr[cout] = arr_B.arr[i];
				cout++;

			}
			in = false;
		}
	}
	size_t new_cout_2 = cout;
	/*for (size_t i = 0; i < new_cout_2; i++)
	{
		for (size_t j = i+1; j < new_cout_2; j++)
		{
			if (arr_c.arr[i] == arr_c.arr[j])
			{
				for (size_t c = j; c < new_cout_2-1; c++)
				{
					arr_c.arr[c] = arr_c.arr[c + 1];
				}
				j--;
				new_cout_2--;
			}
		}
	}*/
	arr_c.size = new_cout_2;
	//print(arr_c);
	return arr_c;
}

template<typename T>
Arr<T> repeat(const Arr<T>& arr_A, const Arr<T>& arr_B) {
	Arr<T> arr_c;

	combine(arr_A, arr_B, arr_c);
	size_t cout = 0;

	for (size_t i = 0; i < arr_A.size; i++)
	{
		bool in = true;

		for (size_t j = 0; j < arr_B.size; j++)
		{
			if (arr_A.arr[i] == arr_B.arr[j])
			{
				in = false;
			}
		}
		if (!in)
		{
			bool in_c = false;
			for (size_t c = 0; c < cout; c++)
			{
				if (arr_c.arr[c] == arr_A.arr[i])
				{
					in_c = true;
				}
			}
			if (!in_c)
			{
				arr_c.arr[cout] = arr_A.arr[i];
				cout++;

			}
			in = false;
		}
	}
	for (size_t i = 0; i < arr_A.size; i++)
	{
		bool in = true;

		for (size_t j = 0; j < arr_B.size; j++)
		{
			if (arr_B.arr[i] == arr_A.arr[j])
			{
				in = false;
			}
		}
		if (!in)
		{
			bool in_c = false;
			for (size_t c = 0; c < cout; c++)
			{
				if (arr_c.arr[c] == arr_B.arr[i])
				{
					in_c = true;
				}
			}
			if (!in_c)
			{
				arr_c.arr[cout] = arr_B.arr[i];
				cout++;

			}
			in = false;
		}
	}

	arr_c.size = cout;
	return arr_c;
}
int main()
{
	srand(time(0));

	Arr<int> arr_1, arr_2;
	std::cout << "M: ";
	implement(arr_1);
	std::cout << "N: ";
	implement(arr_2);
	rand_arr(arr_1);
	rand_arr(arr_2);
	print(arr_1);
	print(arr_2);
	std::cout << std::endl;

	Arr<int> arr_c;
	arr_c = repeat(arr_1, arr_2);
	print(arr_c);

	arr_c = not_repeat(arr_1, arr_2);
	print(arr_c);
	delete[] arr_1.arr;
	delete[] arr_2.arr;
	delete[] arr_c.arr;


}