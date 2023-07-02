
#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

// класс содержащий перегруженные операторы new и delete
class Complex
{
private:
    double real;
    double imag;

public:
    // конструктор
    Complex(double _real, double _imag)
    {
        real = _real;
        imag = _imag;
    }

    // методы доступа
    void Get(double * r, double * i)
    {
        *r = real;
        *i = imag;
        return;
    }

    void Set(double r, double i)
    {
        real = r;
        imag = i;
    }

    // перегруженный оператор new,
    // выделяет память заданного размера
    void * operator new(size_t size)
    {
        void * ptr;

        cout<<"Попытка выделить память\n";
        ptr = malloc(size); // попытка выделения памяти

        if (!ptr) // если память не выделена, то сгенерировать исключительную ситуацию
        {
            bad_alloc ba;
            cout<<"Ошибка выделения памяти.\n";
            throw ba;
        }
        else
        {            
            cout<<"Память выделена успешно!\n";
            return ptr;
        }
    }

    // освобождает память, выделенную перегруженной
    // операторной функцией operator new()
    void operator delete(void * ptr)
    {
        cout<<"Освобождение памяти, выделенной оператором delete.\n";
        free(ptr);
    }
};

int _tmain(int argc, char* argv[])
{
    // демонстрация использования операторов new и delete в классе Complex
    Complex * p1; // объявить указатель на Complex

    try
    {
        // вызов операторной функции operator new()
        p1 = new Complex(5,6); // выделить память
    }
    catch (bad_alloc error)
    {
        return 1; // выйти из программы с кодом возврата 1
    }

    // освободить память
    // вызов операторной функции operator delete()
    delete p1;
    return 0;
}