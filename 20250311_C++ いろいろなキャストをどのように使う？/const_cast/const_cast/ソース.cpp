#include <iostream>
#include <typeinfo>

int main()
{
	int value = 0;
	const int* ptr = &value; // �ύX�s��
	std::cout << "ptr �̌^: " << typeid(ptr).name() << ", ptr = " << ptr << std::endl;

	int* modifiable = const_cast<int*>(ptr);
	*modifiable = 42; // const �C���q���O���ĕύX
	std::cout << "modifiable �̌^: " << typeid(modifiable).name() << ", modifiable = " << modifiable << std::endl;

	std::cout << "value = " << value << std::endl; // 42


	return 0;
}