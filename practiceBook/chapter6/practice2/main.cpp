#include <iostream>

using namespace std;

const char ESC = '27';
const char TOLL = 0.5;

class Toll_booth
{
private:
    unsigned int count;
    double proceeds;

public:
    Toll_booth():count(0), proceeds(0){}

    void paying_car()
    {
        count++;
        proceeds += TOLL;
    }

    void nopay_car()
    {
        count++;
    }

    void display() const
    {
        cout << "Машин проехало " << count << endl;
        cout << "Выручка " << proceeds << endl;
    }
};

int main()
{
    Toll_booth prog;
    cout << "Нажмите цифру 1, чтобы зафиксировать платный проезд\n и цифру 2, чтобы зафиксировать бесплатный.\n Для вывода итоговой стоимости нажмите Ecs" << endl;

    string ch[1];
    do
    {
        cin.get(ch,1);
        switch (ch[0])
        {
            case '1':
                prog.paying_car();
                break;
            case '2':
                prog.nopay_car();
                break;
        }
    } while (ch[0] != ESC);
    prog.display();
}
