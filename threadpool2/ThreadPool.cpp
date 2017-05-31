#include "ThreadPool.h"

//what is life

ThreadPool::ThreadPool() {
	size = 1;
	threads.emplace_back(std::thread());
}

ThreadPool::ThreadPool(uint32_t s) {
	size = s;
	for (uint32_t i = 0; i < get_size(); i++) {
		std::thread th;
		//threads.push_back(std::move(th));
		threads.emplace_back(std::thread());
	}
}

void ThreadPool::insert(Task t) {
	std::lock_guard<std::mutex> lock{ mtx };
	task_queue.push(t);
}

/*
uint32_t ThreadPool::get_size() {
	std::lock_guard<std::mutex> lock{ mtx };
	return size;
}


void exec() {
	auto start = std::chrono::steady_clock::now();




	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> diff = end - start;
	std::cout << diff.count() << std::endl;
}

*/


void ThreadPool::run(std::thread th) {
		
	while (!task_queue.empty()) {
		mtx.lock();
		Task t = task_queue.front();
		mtx.unlock();

		t.run();
		task_queue.pop();
	}


}

uint32_t ThreadPool::get_size() {
	std::lock_guard<std::mutex> lock{ mtx };
	return size;
}

void ThreadPool::exec() {

	auto start = std::chrono::steady_clock::now();

	for (uint32_t i = 0; i < get_size(); i++) {
		run(std::move(threads[i]));
	}

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> diff = end - start;
	std::cout << diff.count() << std::endl;

}