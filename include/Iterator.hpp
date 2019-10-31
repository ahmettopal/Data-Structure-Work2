#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Errors.hpp"
#include "Node.hpp"

class Iterator
{
	public:
		Node *Current;
		Iterator()
		{
			Current = NULL;
		}

		Iterator(Node *node)
		{
			Current = node;
		}

		bool IsTheEnd() const
		{
			return Current == NULL;
		}

		void MoveForward() throw(EndOfList)
		{
			if (IsTheEnd())
			{
				throw EndOfList();
			}
			Current = Current->Next;
		}

		void MoveBack() throw(EndOfList)
		{
			if (IsTheEnd())
			{
				throw EndOfList();
			}
			Current = Current->Back;
		}

		const string& Bring() const throw(NullException)
		{
			if (Current == NULL)
			{
				throw NullException();
			}
			return Current->Member;
		}
};
#endif
