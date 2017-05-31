#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include "Task.h"


class ThreadPool {
public:
	
	// Default - Uses sys default thread count
	ThreadPool();

	// Allows us to specify how many threads the pool has
	ThreadPool(uint32_t const);

	ThreadPool::~ThreadPool();

	// We mark this method as constant because it will not effect the ThreadPool
	uint32_t get_size() const;
	
	
	void insert(Task &);
	void run();

private:
	// container to store our threads in
	std::vector<std::thread> threads_;
	
	// Added a more descripted mutex name
	std::mutex queue_mtx_;
	// make IO mutex static so the lock is global
	static std::mutex io_mtx_ ;
	std::queue<Task*> task_queue_;
	void f(int const);

};