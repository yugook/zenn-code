#include <iostream>
#include <typeinfo>

int main()
{
	int a = 42;
	void* ptr = &a;
	int* intPtr = reinterpret_cast<int*>(ptr);

	std::cout << "ptr �̌^: " << typeid(ptr).name() << std::endl;
	std::cout << "intPtr �̌^: " << typeid(intPtr).name() << std::endl;

	return 0;
}