// перегрузка оператора =
class Complex
{
private:
    double real;
    double imag;

public:
    // конструкторы
    Complex()
    {
        real = imag = 0.0;
    }

    Complex(double _real, double _imag)
    {
        real = _real;
        imag = _imag;
    }

    // методы доступа
    void GetComplex(double& _real, double& _imag)
    {
        _real = real;
        _imag = imag;
    }

    void SetComplex(double _real, double _imag)
    {
        real = _real;
        imag = _imag;
    }

    // перегруженный оператор '='
    Complex operator=(Complex cm)
    {
        real = cm.real;
        imag = cm.imag;
        return *this; // возвращает объект, который сгенерировал вызов
    }
};
int main(){
    // перегрузка оператора =
    Complex c1(2.5, 3.8);
    Complex c2;
    double i,r;

    i=r=0.0;
    c1.GetComplex(r,i);

    // вызов операторной функции, перегружающей оператор =
    c2 = c1;
    c2.GetComplex(r, i); // r = 2.5; i = 3.8

    // указатель на класс Complex
    Complex * pc3 = new Complex(1.1, 0.9);

    c2 = *pc3; // перегруженный оператор присваивания =
    c2.GetComplex(r, i); // r = 1.1; i = 0.9
    return 0;
}