#include "name.h"

numbers Numb = nullptr;
letters Lett = nullptr;
trhold Beg = nullptr;
trhold End = nullptr;

void numbers_callback(numbers callback_n)
{
	Numb = callback_n;
}

void letters_callback(letters callback_l)
{
	Lett = callback_l;
}

void beg_callback(trhold callback_b)
{
	Beg = callback_b;
}

void end_callback(trhold callback_e)
{
	End = callback_e;
}
void initial_callback(numbers callbac_n, \
    letters callback_l, \
    trhold callback_b, \
    trhold callback_e)
{
    beg_callback(callback_b);
    numbers_callback(callbac_n);
    letters_callback(callback_l);
    end_callback(callback_e);
}

void parser(const string& str)
{
	size_t position = 0;
	string token;
    size_t pred_tok = 0;
    if (Beg != nullptr)
    {
        Beg();
    }
    while ((pred_tok = str.find_first_of(" \n\t", position)) != std::string::npos) {
        token = str.substr(position, pred_tok - position);
        if ((isdigit(token[0])) && (Numb != nullptr)) {
            int number = atoi(token.c_str());
            Numb(number);
        }
        else if (Lett != nullptr && token != "")
        {
            Lett(token);
        }
        position = str.find_first_not_of(" \n\t", pred_tok);
    }
    if (End != nullptr)
    {
        End();
    }
}