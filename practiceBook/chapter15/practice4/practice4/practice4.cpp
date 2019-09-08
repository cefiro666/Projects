#include <iostream>
#include <set>
#include <string>

using namespace std;

class Person
{
public:
	Person() : lName(""), fName(""), number(0L) {}
	Person(string l, string f, long n) : lName(l), fName(f), number(n) {}

	void getPerson()
	{
		cout << "Insert person(lName fName number)... \n";
		cin >> lName >> fName >> number;
	}

	void displayPerson()
	{
		cout << lName << " " << fName << " number - " << number << endl;
	}

	friend bool operator < (const Person&, const Person&);

private:
	string lName;
	string fName;
	long number;
};

bool operator < (const Person& p1, const Person& p2)
{
	if (p1.lName == p2.lName)
	{
		return (p1.fName < p2.fName);
	}

	return (p1.lName < p2.lName);
}

class comparePerson
{
public:
	bool operator () (const Person* p1, const Person* p2) const
	{
		return (*p1 < *p2);
	}
};

int main()
{
	multiset<Person*, comparePerson> perset;

	Person* ptr1 = new Person("abc", "abc", 7875845);
	Person* ptr2 = new Person("rd", "sdf", 454322);
	Person* ptr3 = new Person("usd", "gfd", 1567876);
	Person* ptr4 = new Person("kfd", "hghg", 5454);
	Person* ptr5 = new Person("hddbc", "abdfdfc", 453453);
	Person* ptr6 = new Person("abc", "abc", 5646546);

	perset.insert(ptr1);
	perset.insert(ptr2);
	perset.insert(ptr3);
	perset.insert(ptr4);
	perset.insert(ptr5);
	perset.insert(ptr6);

	multiset<Person*, comparePerson>::iterator it = perset.begin();

	while (it != perset.end())
	{
		(**it++).displayPerson();
	}

	it = perset.begin();

	while (it != perset.end())
	{
		delete* it;
		perset.erase(it++);
	}
}