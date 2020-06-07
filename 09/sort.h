#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <vector>
#include <mutex>
#include <thread>
#include <fstream>
#include <exception>

void sorted(std::ifstream& input, std::ofstream& tmp, size_t buf_size, std::mutex& mut_1, std::mutex& mut_2);

void multi_merge(const std::string& input_path, const std::string& output_path);//многофазное слияние(классическое)

void star_sort(const std::string& input_path, const std::string& output_path, size_t byf_size);

//Тройка --- минимальный элемент в оставшемся бине, начало отсчета данного элемента в бине, конец бина
class MinEl
{
	uint64_t val_;
	uint64_t curr_;
	size_t ex_;
public:
	MinEl(uint64_t val, size_t curr, size_t ex)
		:val_(val)
		, curr_(curr)
		, ex_(ex)
	{

	}

	size_t my_size() const
	{
		return ex_ - curr_;
	}
	bool empty() const
	{
		return this->my_size() == 0;
	}
	uint64_t get_val() const
	{
		return val_;
	}
	uint64_t get_curr() const
	{
		return curr_;
	}
	size_t get_ex() const
	{
		return ex_;
	}
};

size_t mini(const std::vector< MinEl>& vec);