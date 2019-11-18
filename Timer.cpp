#include "Timer.h"

void Timer::stop()
{
	auto endTimepoint = std::chrono::high_resolution_clock::now();
	auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimepoint).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

	auto duration = end - start;
	double ms = duration * 0.001;

	std::cout << m_name << " took " << ms << " ms" << std::endl;
}
