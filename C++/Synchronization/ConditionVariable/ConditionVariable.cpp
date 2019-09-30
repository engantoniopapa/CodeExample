#include "pch.h"
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <map>
#include<string>

std::mutex mtx;
std::condition_variable condVar;

static std::map<int,std::string> msg;

static const int _num_msg = 5;
static std::string strMsg[_num_msg] = { "Hello" , "Good Morning" , "Good Bye" , "Hi" , "Good Night" };

void WaitMessage(int idthread, int idMessage)
{
	std::unique_lock<std::mutex> lck(mtx);
	std::cout << "Thread[" << idthread << "] Waiting for the message{" << strMsg[idMessage] << "}" << std::endl;
	while (msg.count(idMessage) == 0)
	{
		condVar.wait(lck);
	}
	std::cout << "Thread[" << idthread << "] Received the message{" << msg[idMessage] << "}" << std::endl;
}

void SendMessage(int idthread)
{
	for (int i = 0; i < _num_msg; ++i)
	{
		std::unique_lock<std::mutex> lck(mtx);
		msg[i] = strMsg[i];
		std::cout << "Thread[" << idthread << "] Sent the message{" << msg[i] << "}" << std::endl;
		condVar.notify_all();
	}
	std::cout << "Thread[" << idthread << "] Sent all the messages" << std::endl;
}

int main()
{
	std::thread threads[7];
	threads[0] = std::thread(WaitMessage, 0, 1);
	threads[1] = std::thread(WaitMessage, 1, 1);
	threads[2] = std::thread(WaitMessage, 2, 2);
	threads[3] = std::thread(WaitMessage, 3, 2);
	threads[4] = std::thread(WaitMessage, 4, 3);
	threads[5] = std::thread(WaitMessage, 5, 4);
	threads[6] = std::thread(SendMessage, 6);

	for (auto& th : threads)
	{
		th.join();
	}

	std::cout << "End Program" << std::endl;

	return 0;
}
