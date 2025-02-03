//#include <ostream> // output stream <<
//#include <istream> // input stream >>
//#include <iostream>
//#include <memory>
//#include <string>
//	
//template <class T>
//class UniquePtr
//{
//	T* U_ptr;
//public:
//	UniquePtr(T* ptr) : U_ptr(ptr)
//	{}
//	UniquePtr() : UniquePtr(nullptr) {}
//
//	UniquePtr(UniquePtr&& other) : U_ptr(other.U_ptr)
//	{
//		other.U_ptr = nullptr;
//	}
//	~UniquePtr()
//	{
//		if (U_ptr)
//			delete U_ptr;
//	}
//
//
//	T* release()
//	{
//		T* temp = U_ptr;
//		U_ptr = nullptr;
//		return temp;
//	}
//
//	void reset(T* ptr)
//	{
//		if (U_ptr != ptr)
//		{
//			delete U_ptr;
//			U_ptr = ptr;
//		}
//	}
//
//
//	T& operator*() const
//	{
//		return *U_ptr;
//	}
//	UniquePtr& operator=(UniquePtr&& other)
//	{
//		if (this != &other)
//		{
//			delete U_ptr;
//			U_ptr = other.U_ptr;
//			other.U_ptr = nullptr;
//		}
//		return *this;
//	}
//
//
//};
//template <class T>
//class SharedPtr {
//private:
//	T* S_ptr;
//	size_t*		Count;
//};
//int main() {
//	UniquePtr<int> obj = new int(15);
//	UniquePtr<int> obj1 = new int(25);
//	obj= std::move(obj1);
//	std::cout << *obj << "\n";
//	return 0;
//
//}