#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "Iterator.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DoublyLinkedList
{
	private:
		Node *FirstNode;
		int Count;

		Iterator FindWithLocation(int location) const throw(Overflow)
		{
			if (location < 0 || location > Length()) 
			{
				throw Overflow();
			}
			int index = 0;
			Node *mobile = FirstNode;
			while (mobile->Next != NULL && location != index++)
			{
				mobile = mobile->Back;
			}
			return Iterator(mobile);
		}

		Iterator FindWithLocation2(int location) const throw(Overflow)
		{
			if (location < 0 || location > Length())
			{
				throw Overflow();
			}
			int index = 0;
			Node *mobile = FirstNode;
			while (mobile->Back != NULL && location != index++)
			{
				mobile = mobile->Back;
			}
			return Iterator(mobile);
		}

	public:
		DoublyLinkedList()
		{
			FirstNode = new Node();  // create empty node
			Count = 0;
		}

		bool IsEmpty() const
		{
			return FirstNode->Next == NULL;
		}

		int Length() const
		{
			return Count;
		}

		// return firt node of the list
		Iterator First() const throw(EmptyList)
		{
			if (IsEmpty())
			{
				throw EmptyList();
			}
			return Iterator(FirstNode->Next);
		}

		Iterator First2() const throw(EmptyList)
		{
			return Iterator(FirstNode->Back);
		}

		const string& FirstIndex() const throw(EmptyList)
		{
			if (IsEmpty())
			{
				throw EmptyList();
			}
			return FirstNode->Next->Member;
		}

		const string& FirstIndex2() const throw(EmptyList)
		{
			if (IsEmpty())
			{
				throw EmptyList();
			}
			return FirstNode->Back->Member;
		}

		// last member of the list
		const string& LastIndex() const throw(EmptyList)
		{
			Iterator iterator = FindWithLocation(Count - 1);
			return iterator.Current->Next->Member;
		}

		const string& LastIndex2() const throw(EmptyList)
		{
			if (IsEmpty())
			{
				throw EmptyList();
			}
			Iterator iterator = FindWithLocation2(Count);
			return iterator.Current->Back->Member;
		}

		// add new member last index of the list
		void Add(const string& _new)
		{
			Add(_new, Length());
		}

		// add new member selected index of the list
		void Add(const string& _new, int index) throw(Overflow)
		{
			Iterator iterator;
			try
			{
				iterator = FindWithLocation(index);
			}
			catch (Overflow overflow)
			{
				throw overflow;
			}

			Node *TempBack = iterator.Current->Next;
			iterator.Current->Next = new Node(_new, iterator.Current->Next, iterator.Current);
			if (TempBack != NULL)
			{
				TempBack->Back = iterator.Current->Next;
			}
			Count++;
		}

		void Erase(const string& search) throw(NoMember)
		{
			try
			{
				int index = FindLocation(search);
				EraseAtIndex(index);
			}
			catch (NoMember nm)
			{
				throw nm;
			}
		}

		void EraseAtIndex(int index) throw(Overflow)
		{
			try
			{
				Iterator iterator = FindWithLocation(index);
				Node *erase = iterator.Current->Next;
				iterator.Current->Next = iterator.Current->Next->Next;
				if (iterator.Current->Next != NULL)
				{
					iterator.Current->Next->Back = iterator.Current;
				}
				delete erase;
				Count++;
			}
			catch (Overflow overflow)
			{
				throw overflow;
			}
		}

		bool FindMember(const string& search) const
		{
			if (IsEmpty())
			{
				return false;
			}
			for (Iterator iterator(FirstNode->Next); !iterator.IsTheEnd(); iterator.MoveForward())
			{
				if (iterator.Bring() == search)
				{
					return true;
				}
			}
			return false;
		}

		bool FindLocation(const string& search) const throw(NoMember)
		{
			if (IsEmpty())
			{
				throw NoMember();
			}
			int index;
			for (Iterator iterator(FirstNode->Next); !iterator.IsTheEnd(); iterator.MoveForward())
			{
				if (iterator.Bring() == search)
				{
					return index;
				}
				index++;
			}
			throw NoMember();
		}

		void MoveLeft()
		{
			Iterator lastMember = NULL;
			string number;
			for (Iterator iterator(FirstNode->Next); iterator.Current->Next != NULL; iterator.MoveForward())
			{
				if (iterator.Current == FirstNode->Next)
				{
					number = FirstNode->Next->Member;
				}
				if (iterator.Current->Next != NULL)
				{
					iterator.Current->Member = iterator.Current->Next->Member;
				}
				lastMember = iterator.Current;
			}
			lastMember.MoveForward();
			lastMember.Current->Member = number;
		}

		void MoveRight()
		{
			Iterator firstMember = NULL;
			string number;
			for (Iterator iterator = FindWithLocation(Count); iterator.Current->Back != NULL; iterator.MoveBack())
			{
				if (iterator.Current == FirstNode->Back)
				{
					number = FirstNode->Back->Member;
				}
				if (iterator.Current->Back != NULL)
				{
					iterator.Current->Member = iterator.Current->Back->Member;
				}
				firstMember = iterator.Current;
			}
			firstMember.MoveBack();
			firstMember.Current->Member = number;
		}

		// clear member of the list
		void Clear()
		{
			while (!IsEmpty())
			{
				Erase(First().Bring());
			}
		}

		~DoublyLinkedList()
		{
			Clear();
			delete FirstNode;
		}

		friend ostream& operator<<(ostream& screen, DoublyLinkedList &right)
		{
			if (right.IsEmpty())
			{
				screen << "List is empty";
			}
			Iterator iterator = right.First();
			for (;!iterator.IsTheEnd(); iterator.MoveForward())
			{
				screen << iterator.Bring() << " ";
			}
			screen << endl;
			return screen;
		}
};

#endif