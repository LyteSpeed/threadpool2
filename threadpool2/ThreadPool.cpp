#include "ThreadPool.h"

//what is life - :)


std::mutex ThreadPool::io_mtx_;

ThreadPool::ThreadPool() {
	// hardware_concurrency gets the guess of how many threads from the hardware
	for (uint32_t i = 0; i < std::thread::hardware_concurrency(); ++i) 
		threads_.emplace_back(&ThreadPool::f, this, i);
}

ThreadPool::ThreadPool(uint32_t const threads_to_spawn) {
	for(uint32_t i = 0; i < threads_to_spawn; ++i)
		threads_.emplace_back(&ThreadPool::f, this, i);
}

// When the ThreadPool gets destroyed.  Wait for all of its threads to terminate
ThreadPool::~ThreadPool() {
	for (std::thread & t : threads_)
		t.join();
}


void ThreadPool::f(int const id)
{
	std::lock_guard<std::mutex> lock{ io_mtx_ };
	std::cout << "I am thread " << id << "!" << std::endl;
}

void ThreadPool::insert(Task & t) {
	std::lock_guard<std::mutex> lock{ queue_mtx_ };
	
	task_queue_.push(&t);
}

// Returns # of threads

uint32_t ThreadPool::get_size() const {
	return threads_.size();
}


void ThreadPool::run(){	
	
	//Best place to do timing is in main.  We will keep the code for now tho

	/*
	auto start = std::chrono::steady_clock::now();

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> diff = end - start;
	std::cout << diff.count() << std::endl;
	*/
}

/*
void ThreadPool::exec() {

	auto start = std::chrono::steady_clock::now();

	for (uint32_t i = 0; i < get_size(); i++) {
		run(std::move(threads[i]));
	}

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> diff = end - start;
	std::cout << diff.count() << std::endl;

}
*/