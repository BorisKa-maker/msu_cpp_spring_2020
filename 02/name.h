#pragma once
#include <iostream>
#include <string>

using namespace std;

using numbers = void(*)(int token);
using letters = void(*)(const string & token);
using trhold = void(*)();

void initial_callback(numbers callbac_n, \
	letters callback_l, \
	trhold callback_b, \
	trhold callback_e);

void numbers_callback(numbers callbac_n);

void letters_callback(letters callback_l);

void beg_callback(trhold callback_b);

void end_callback(trhold callback_e);

void parser(const string& str);