#include <iostream>

struct Error
{
    Error(std::string er) : error(er) {}
    std::string error;
};

void f(int v)
{
    if(v < 10) throw Error("!");

    std::cout << v << '\n';
}

void g()
{
    try
    {
        f(12);
        f(5);
    }
    catch(Error& er)
    {
        std::cout << er.error << '\n';
    }
}

int main(int argc, char* argv[])
{
    g();
}