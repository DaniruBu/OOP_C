// класс Complex
class Complex
{
private:
    float real; // вещественная часть
    float imag; // мнимая часть

public:
    // конструкторы
    Complex(void)
    {
        real = imag = 0;
    }

    Complex(float _real, float _imag)
    {
        real = _real;
        imag = _imag;
    }

    // методы доступа
    float GetR(void) { return real; }
    float GetI(void) { return imag; }

    void SetRI(float _real, float _imag)
    {
        real = _real;
        imag = _imag;
    }

    // объявление "дружественной" к классу Complex операторной функции
    friend Complex operator-(Complex c1, Complex c2);
};

// "дружественная" к классу Complex операторная функция,
// реализована за пределами класса,
// осуществляет вычитание комплексных чисел
Complex operator-(Complex c1, Complex c2)
{
    Complex c; // создать объект класса Complex

    // вычитание комплексных чисел
    c.real = c1.real - c2.real;
    c.imag = c1.imag - c2.imag;

    return c;
}
int main(){
    // использование "дружественной" операторной функции
    Complex c1(5,6);
    Complex c2(3,-2);
    Complex c3; // результат
    float a, b;

    // проверка
    a = c1.GetR(); // a = 5
    b = c1.GetI(); // b = 6

    // вызов "дружественной" к классу Complex операторной функции
    c3 = c1 - c2;

    // результат
    a = c3.GetR(); // a = 5-3 = 2
    b = c3.GetI(); // b = 6-(-2) = 8
    return 0;
}