#include <iostream>

namespace my_lib
{
	class Exception
	{
	public:
		std::string error;

		Exception(std::string er) : error(er) {}
	};

	template<class T> class list
	{
	public:
		list() : head(0), tail(0) {}
		void push_back(T data);
		void push_front(T data);
		T pop_back();
		T pop_front();
		void sort();
		void reverse();

		class Empty {};

	private:
		struct Link
		{
			T data;
			Link* prev;
			Link* next;

			Link(T data) : data(data) {}
			Link() {}
		};

  	  	Link* head;
		Link* tail;
	};

	template<class T> void list<T>::push_back(T data)
	{
		Link* newlink = new Link(data);
		newlink->next = 0;

		if (head != 0)
		{
			newlink->prev = tail;
			tail->next = newlink;
			tail = newlink;

		} else {

			newlink->prev = 0;
			head = tail = newlink;
		}
	}

	template<class T> void list<T>::push_front(T data)
	{
		Link* newlink = new Link(data);
		newlink->prev = 0;

		if (head != 0)
		{
			newlink->next = head;
			head->prev = newlink;
			head = newlink;

		} else {

			newlink->next = 0;
			head = tail = newlink;
		}
	}

	template<class T> T list<T>::pop_back()
	{
		if (tail == 0) throw Exception("Empty list!");

		T data = tail->data;
		Link* temp = tail->prev;
		delete tail;
		tail = temp;

		return data;
	}

	template<class T> T list<T>::pop_front()
	{
		if (head == 0) throw Exception("Empty list!");

		T data = head->data;
		Link* temp = head->next;
		delete head;
		head = temp;

		return data;
	}

	template<class T> void list<T>::sort()
	{
		bool sort = false;
		Link* left = tail;
		Link* right = tail->prev;

		while (true)
		{
			if (left->prev == 0)
			{	
				if (!sort) break;

				left = tail;
				right = tail->prev;
				sort = false;
			}

			if (left->data > right->data)
			{
				T temp = left->data;
				left->data = right->data;
				right->data = temp;
				sort = true;
			}

			right = right->prev;
			left = left->prev;
		}
	}

	template<class T> void list<T>::reverse()
	{
		Link* left = tail;
		Link* right = head;

		while (true)
		{
			T temp = left->data;
			left->data = right->data;
			right->data = temp;

			left = left->prev;

			if (left == right) break;

			right = right->next;
		}
	}
}

class A
{
public:
	A(std::string s) : str(s) {}

	std::string get()
	{
		return str;
	}

private:
	std::string str;
};

int main (int argc, char* argv[])
{
	try
	{
		my_lib::list<A*> l;

		for (int i = 0; i < 10; i++)
		{
			A* obj = new A(std::to_string(i));
			l.push_back(obj); 
		}

		for (int i = 0; i < 10; i++)
		{
			A* obj = l.pop_back(); 
			std::cout << obj->get() << '\n';
		}

		std::cout << l.pop_back() << '\n';
		std::cout << l.pop_back() << '\n';
		
	}
	catch (my_lib::Exception& exception)
	{
		std::cerr << exception.error << '\n';
	}
}