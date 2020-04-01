#pragma once
#include <iostream>
#include <string>



using numbers = void(*)(int token);
using letters = void(*)(const std::string & token);
using trhold = void(*)();

void initial_callback(numbers callbac_n = nullptr, \
	letters callback_l=nullptr, \
	trhold callback_b = nullptr, \
	trhold callback_e = nullptr);

void numbers_callback(numbers callbac_n);

void letters_callback(letters callback_l);

void beg_callback(trhold callback_b);

void end_callback(trhold callback_e);

void parser(const std::string& str);