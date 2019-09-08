#include <iostream>

using namespace std;

class Int
{
private:
    int value;

public:
    Int():value(0){}

    Int(int v)
    {
        value = v;
    }

    void print_value()
    {
        cout << value << endl;
    }

    Int add_Int(Int val)
    {
        Int add = value + val.value;
        return add;
    }
};

int main ()
{
    Int val1;
    Int val2(5);
    Int val3(7);
    val1 = val2.add_Int(val3);
    val1.print_value();
}
