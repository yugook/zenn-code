#include <iostream>
#include <thread>

void threadFunc()	// �X���b�h�̏���
{
	std::cout << "threadFunc�J�n" << std::endl;
	std::cout << "threadFunc thread ID >> " << std::this_thread::get_id() << std::endl;
	std::cout << "threadFunc�I��" << std::endl;

	return;
}

int main()
{
	//std::thread thread1(threadFunc); // �T�u�X���b�h(thread1)���쐬�A�����Ƃ���threadFunc��ݒ肷��
	threadFunc();

	std::cout << "main�J�n" << std::endl;
	std::cout << "main thread ID >> " << std::this_thread::get_id() << std::endl;
	std::cout << "main�I��" << std::endl;

	//thread1.join();	// �T�u�X���b�h(thread1)�̏I����҂�

	return 0;
}