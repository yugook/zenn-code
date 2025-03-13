#include <iostream>
#include <typeinfo>

int main()
{
	int a = 10;
	double b = static_cast<double>(a); // int ‚©‚ç double ‚ÉƒLƒƒƒXƒg

	std::cout << "a ‚ÌŒ^: " << typeid(a).name() << std::endl;
	std::cout << "static_cast<double>(a)‚ÌŒ^: " << typeid(static_cast<double>(a)).name() << std::endl;
	std::cout << "b ‚ÌŒ^: " << typeid(b).name() << std::endl;

	return 0;
}