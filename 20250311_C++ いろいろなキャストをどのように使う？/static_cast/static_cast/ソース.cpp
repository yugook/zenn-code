#include <iostream>
#include <typeinfo>

int main()
{
	int a = 10;
	double b = static_cast<double>(a); // int から double にキャスト

	std::cout << "a の型: " << typeid(a).name() << std::endl;
	std::cout << "static_cast<double>(a)の型: " << typeid(static_cast<double>(a)).name() << std::endl;
	std::cout << "b の型: " << typeid(b).name() << std::endl;

	return 0;
}