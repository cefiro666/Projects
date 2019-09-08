#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int main()
{
	ofstream out("data.dat");
	list<int> ls{ 4, 6, 7, 9, 2, 4, 22 };

	ostream_iterator<int> listinit(out, " ");
	copy(ls.begin(), ls.end(), listinit);
	out.close();

	ifstream in("data.dat");
	istream_iterator<int> init(in);
	istream_iterator<int> eos;

	out.open("data2.dat");
	ostream_iterator<int> outit(out, " ");

	copy(init, eos, outit);
	in.close();
	out.close();
}