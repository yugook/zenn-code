#include <iostream>
#include <thread>

int main()
{
	std::cout << "main�J�n" << std::endl;
	std::cout << "thread ID >> " << std::this_thread::get_id() << std::endl;
	std::cout << "main�I��" << std::endl;
	
	return 0;
}