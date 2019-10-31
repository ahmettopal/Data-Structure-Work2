#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>
using namespace std;

class Error
{
private:
	string message;
public:
	Error(string);
	string Message() const;
};

#endif
