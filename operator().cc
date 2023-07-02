#include <iostream>
using namespace std;

// класс, который реализует данные и методы решения квадратного уравнения
class SqEqual
{
private:
    // коэффициенты квадратного уравнения
    double a;
    double b;
    double c;

    // корни - решения
    double x1;
    double x2;

    // внутренний метод решения квадратного уравнения
    bool Solution(void)
    {
        double d; // дискриминант

        // есть ли вообще уравнение?
        if (a==0)
            return false;

        d = b*b-4*a*c;

        if (d>=0)
        {
            // уравнение имеет решение
            x1 = (-b - sqrt(d)) / (2*a);
            x2 = (-b + sqrt(d)) / (2*a);
        }
        else
            return false; // уравнение не имеет решения

        return true; // решение в переменных x1, x2
    }

public:
    // конструктор класса
    SqEqual(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    // общедоступные методы решения квадратного уравнения
    bool GetSolution(double& x1, double& x2)
    {
        if (Solution()) // вызвать внутренний метод решения
        {
            x1 = this->x1;
            x2 = this->x2;
            return true; // есть решение
        }

        return false; // нету решения
    }

    bool GetSolutionP(double* x1, double* x2)
    {
        if (Solution())
        {
            *x1 = this->x1;
            *x2 = this->x2;
            return true; // есть решение
        }
        return false; // нет решения
    }

    // операторная функция operator()(),решающая квадратное уравнение
    // операторная функция получает 5 параметров
    // функция возвращает true, если уравнение имеет решение,
    // x1, x2 - решение уравнения, передача по указателю
    bool operator()(double a, double b, double c, double* x1, double* x2)
    {
        this->a = a;
        this->b = b;
        this->c = c;

        if (Solution())
        {
            *x1 = this->x1;
            *x2 = this->x2;
            return true;
        }
        return false;
    }

    // вариант 2 - операторная функция получает только 2 параметра, которые есть решением
    // x1, x2 - передача по ссылке
    bool operator()(double& x1, double& x2)
    {
        // коэффициенты a, b, c получаются из текущего объекта
        if (Solution())
        {
            x1 = this->x1;
            x2 = this->x2;
            return true; // есть решение
        }
        return false; // уравнение не имеет решения
    }
};

void main(void)
{
    // перегрузка оператора () вызова функции
    double a = 2, b = -3, c = 1;
    SqEqual e(a, b, c); // создать экземпляр
    double x1, x2;
    bool f;

    // вызов операторной функции operator()() с двумя параметрами
    f = e(x1,x2);

    if (f)
    {
        // если есть решение уравнения 2*x2-3*x + 1 = 0, то вывести результат
        cout << a << "* x^2 + (" << b << ") * x + (" << c << ") = 0" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl << endl;
    }

    // вызов операторной функции с 5 параметрами
    f = e(5, -7, 2, &x1, &x2);

    if (f)
    {
        // если есть решение уравнения, то вывести результат
        cout << "5 * x^2 - 7*x + 2 = 0" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl << endl;
    }
}