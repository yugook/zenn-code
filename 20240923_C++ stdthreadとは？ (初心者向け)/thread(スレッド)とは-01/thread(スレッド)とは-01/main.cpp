#include <iostream>
#include <thread>

int main()
{
	std::cout << "mainŠJŽn" << std::endl;
	std::cout << "thread ID >> " << std::this_thread::get_id() << std::endl;
	std::cout << "mainI—¹" << std::endl;
	
	return 0;
}