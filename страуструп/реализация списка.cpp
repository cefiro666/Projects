#include <iostream>

template <class T> struct link
{
	T data;
	link* lost;
};

class Exception
{
public:
	std::string error;

	Exception(std::string er) : error(er) {}
};

template <class T> class list
{
	link<T>* next;

public:
	list() : next(0) {}

	void push_back(T data)
	{
		link<T>* newlink = new link<T>;
		newlink->data = data;
		newlink->lost = next;
		next = newlink;
	}

	T pop_back()
	{
		if (!next) throw Exception("List empty!");

		T data = next->data;
		link<T>* newnext = next->lost;
		delete next;
		next = newnext;

		return data;
	}
	
	void push_front(T data)
	{
		link<T>* temp = next;
		while (temp->lost != 0) temp = temp->lost;
		link<T>* newlink = new link<T>;
		newlink->data = data;
		newlink->lost = 0;
		temp->lost = newlink;
	}

	T pop_front()
	{
		if (!next) throw Exception("List empty!");

		link<T>* temp = next;
		while (temp->lost != 0) temp = temp->lost;
		T data = temp->data;
		delete temp;
		temp = 0;

		return data;
	}
};

int main()
{
	try
	{
		list<int> l;

		l.push_back(5);
		l.push_back(7);
		l.push_front(11);
		l.push_back(3);
		l.push_back(4);

		std::cout << l.pop_back() << std::endl;
		std::cout << l.pop_back() << std::endl;
		std::cout << l.pop_back() << std::endl;
		std::cout << l.pop_front() << std::endl;
		std::cout << l.pop_back() << std::endl;
	}
	catch (Exception & exception)
	{
		std::cout << exception.error << std::endl;
	}
}