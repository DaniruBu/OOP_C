#include <iostream>
using namespace std;

class Double
{
public:
    double d; // внутренняя переменная

    // операторная функция, перегружающая оператор ->
    Double* operator->()
    {
        return this; // возвратить указатель на класс
    }
};

void main()
{
    // перегрузка оператора доступа по указателю ->
    Double D; // экземпляр класса D
    double x;

    D.d = 3.85;

    // вызов операторной функции operator->()
    x = D->d;

    // другой способ доступа
    x = D.d; // x = 3.85

    cout << "x = " << x;
}