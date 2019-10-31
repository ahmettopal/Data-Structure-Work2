#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node
{
public:
	string Member;
	Node *Next;
	Node *Back;

	Node(const string& Member = string(), Node *_next = NULL, Node *_back = NULL)
	{
		this->Member = Member;
		Next = _next;
		Back = _back;
	}
};

#endif
