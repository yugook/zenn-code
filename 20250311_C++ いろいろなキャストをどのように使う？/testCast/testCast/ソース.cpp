#include <iostream>

int main()
{
	int a = 10;
	double b = (double)a; // int �� double �ɃL���X�g

	int a = 10;
	double b = static_cast<double>(a); // int ���� double �ɕϊ�

	return 0;
}