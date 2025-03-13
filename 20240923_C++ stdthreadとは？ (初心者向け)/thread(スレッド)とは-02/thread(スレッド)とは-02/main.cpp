#include <iostream>
#include <thread>

void threadFunc()	// スレッドの処理
{
	std::cout << "threadFunc開始" << std::endl;
	std::cout << "threadFunc thread ID >> " << std::this_thread::get_id() << std::endl;
	std::cout << "threadFunc終了" << std::endl;

	return;
}

int main()
{
	//std::thread thread1(threadFunc); // サブスレッド(thread1)を作成、処理としてthreadFuncを設定する
	threadFunc();

	std::cout << "main開始" << std::endl;
	std::cout << "main thread ID >> " << std::this_thread::get_id() << std::endl;
	std::cout << "main終了" << std::endl;

	//thread1.join();	// サブスレッド(thread1)の終了を待つ

	return 0;
}