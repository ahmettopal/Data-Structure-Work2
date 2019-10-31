#include "Error.hpp"

Error::Error(string _message)
{
	message = _message;
}
string Error::Message() const
{
	return message;
}