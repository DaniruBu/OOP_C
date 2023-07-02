class Complex
{
private:
    double real; // вещественная часть
    double imag; // мнимая часть

public:
    // конструктор класса
    Complex(double _real, double _imag)
    {
        real = _real;
        imag = _imag;
    }

    // методы доступа
    double GetReal(void) { return real; }
    double GetImag(void) { return imag; }

    void Set(double _real, double _imag)
    {
        real = _real;
        imag = _imag;
    }

    // операторная функция, которая перегружает оператор *=
    // функция реализует умножение комплексных чисел
    Complex operator*=(Complex obj)
    {
        double r;
        double i;
        r = real*obj.real - imag*obj.imag;
        i = real*obj.imag + obj.real*imag;
        real = r;
        imag = i;
        return *this;
    }
};
int main(){
    // перегрузка сокращенного оператора *=
    Complex c1(2,3); // 2+3j
    Complex c2(-1,1); // -1+j
    double t;

    // вызов операторной функции *=
    c1 *= c2; // c1 = -5-1j

    t = c1.GetReal(); // t = -5
    t = c1.GetImag(); // t = -1
    return 0;
}