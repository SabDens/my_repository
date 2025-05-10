//#include <iostream>
//#include <memory>
//
//
//namespace my {
//    template<class T>
//    class auto_ptr
//    {
//    private:
//        T* m_ptr;
//
//    public:
//        auto_ptr(T* ptr) : m_ptr(ptr)
//        {
//            std::cout << m_ptr << " - smart pointer created" << std::endl;
//        }
//
//        auto_ptr() : auto_ptr(nullptr) {}
//
//        auto_ptr(auto_ptr& other)
//        {
//            m_ptr = other.m_ptr;
//            other.m_ptr = nullptr;
//        }
//
//        ~auto_ptr()
//        {
//            std::cout << m_ptr << " - smart pointer deleted" << std::endl;
//            if (m_ptr)
//                delete m_ptr;
//        }
//
//        T& operator*()
//        {
//            return *m_ptr;
//        }
//    };
//
//    
//}
//
////template<class T>
////void myFunc(my::auto_ptr<T>& ptr)
////{
////    // Function body
////}
//
//template<class T>
//std::unique_ptr<T> myFunc(std::unique_ptr<T> ptr)
//{
//    return std::move(ptr);
//}
//
//int main()
//{
//    std::unique_ptr<int> sp_ptr(new int(5));
//    sp_ptr = myFunc(std::move(sp_ptr));
//    std::unique_ptr<int> sp_ptr2 = std::move(sp_ptr);
//    std::cout << *sp_ptr2 << std::endl;
//    // std::cout << *int_ptr << std::endl; // This line is commented out
//    std::cout << *sp_ptr << std::endl;
//
//    std::unique_ptr<int> 
//}                 
