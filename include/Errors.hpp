#ifndef ERRORS_HPP
#define ERRORS_HPP
#include "Error.hpp"
class EndOfList : public Error
{
	public:
		EndOfList(string _message = "End of list ") : Error(_message){}
};

class NullException : public Error
{
	public:
		NullException(string _message = "Null exception ") : Error(_message) {}
};

class EmptyList : public Error
{
	public:
		EmptyList(string _message = "Empty list ") : Error(_message) {}
};

class Overflow : public Error
{
	public:
		Overflow(string _message = "Overflow ") : Error(_message) {}
};

class NoMember : public Error
{
	public:
		NoMember(string _message = "No member ") : Error(_message) {}
};
#endif
