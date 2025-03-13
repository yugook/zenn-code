#include <iostream>
#include <typeinfo>

int main()
{
	int a = 10;
	double b = static_cast<double>(a); // int ���� double �ɃL���X�g

	std::cout << "a �̌^: " << typeid(a).name() << std::endl;
	std::cout << "static_cast<double>(a)�̌^: " << typeid(static_cast<double>(a)).name() << std::endl;
	std::cout << "b �̌^: " << typeid(b).name() << std::endl;

	return 0;
}