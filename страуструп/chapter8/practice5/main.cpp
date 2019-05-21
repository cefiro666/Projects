#include <iostream>

struct Exc
{
    Exc(int c, std::string f) : count(c), func(f) {}
    int count;
    std::string func;
};

void g(int);
void f(int count)
{
    if(count == 9) throw Exc(count, "f");
    g(++count);
}

void g(int count)
{
    if(count == 9) throw Exc(count, "g");
    f(++count);
}

int main(int argc, char* argv[])
{
    try
    {
        f(1);
    }
    catch(Exc& exc)
    {
        std::cerr << exc.count << " " << exc.func << '\n';
    }
}