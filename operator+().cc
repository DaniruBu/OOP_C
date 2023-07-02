#include <iostream>
using namespace std;

// класс, реализующий комплексное число
class Complex
{
private:
    double real; // вещественная часть комплексного числа
    double imag; // мнимая часть

public:
    // конструкторы
    Complex()
    {
        real = imag = 0;
    }

    Complex(double real, double imag)
    {
        this->real = real;
        this->imag = imag;
    }

    // методы доступа
    double GetI() { return imag; }
    double GetR() { return real; }

    // перегруженный оператор суммирования +
    Complex operator+(Complex c)
    {
        // суммирование комплексных чисел
        return Complex(real + c.real, imag + c.imag);
    }

    // перегруженный оператор вызова функции
    Complex operator()(double real, double imag)
    {
        this->real = real;
        this->imag = imag;
        return *this;
    }
};

void main()
{
    Complex c1(3, 4);
    Complex c2;
    Complex c3;
    double r, i;

    // вызов операторных функций operator+() и operator()()
    c3 = c1 + c2(5, 6); // c3 = c1.operator+(c2.operator(5,6))

    // проверка
    r = c3.GetR(); // r = 3 + 5 = 8
    i = c3.GetI(); // i = 4 + 6 = 10

    cout << "r = " << r << endl;
    cout << "i = " << i;
}