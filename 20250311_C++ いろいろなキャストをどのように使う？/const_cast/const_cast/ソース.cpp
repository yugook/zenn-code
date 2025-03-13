#include <iostream>
#include <typeinfo>

int main()
{
	int value = 0;
	const int* ptr = &value; // 変更不可
	std::cout << "ptr の型: " << typeid(ptr).name() << ", ptr = " << ptr << std::endl;

	int* modifiable = const_cast<int*>(ptr);
	*modifiable = 42; // const 修飾子を外して変更
	std::cout << "modifiable の型: " << typeid(modifiable).name() << ", modifiable = " << modifiable << std::endl;

	std::cout << "value = " << value << std::endl; // 42


	return 0;
}