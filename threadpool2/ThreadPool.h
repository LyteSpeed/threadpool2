#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include "Task.h"


class ThreadPool {
public:
	ThreadPool();
	ThreadPool(uint32_t s);
	uint32_t get_size();
	void insert(Task t);
	void exec();
	void run(std::thread th);
private:
	std::vector<std::thread> threads;
	std::mutex mtx;
	std::queue<Task> task_queue;
	uint32_t size;

};