#pragma once

#include <iostream>
#include <memory>
#include <chrono>
#include <string>

class Timer
{
public:
	Timer(const std::string& name) 
		: m_name(name) { m_startTimepoint = std::chrono::high_resolution_clock::now(); };
	~Timer() { stop(); };
	void stop();
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimepoint;
	const std::string m_name;
};