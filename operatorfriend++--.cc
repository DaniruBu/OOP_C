// класс Integer, реализующий целое число
class Integer
{
private:
    int number;

public:
    // конструкторы класса
    Integer() { number = 0; }
    Integer(int _number) { number = _number; }

    // методы доступа
    int Get(void) { return number; }
    void Set(int _number) { number = _number; }

    // объявление "дружественных" операторных функций
    friend Integer operator++(Integer & ref);
    friend Integer operator--(Integer & ref);
    friend Integer operator++(Integer & ref, int d);
    friend Integer operator--(Integer & ref, int d);
};

// реализация "дружественных" операторных функций
Integer operator++(Integer & ref)
{
    ref.number++; // доступ по ссылке
    return ref;
}

Integer operator--(Integer & ref)
{
    ref.number--;
    return ref;
}

// постфиксная форма - x++
Integer operator++(Integer & ref, int d)
{
    ref.number++;
    return ref;
}

// постфиксная форма - x--
Integer operator--(Integer & ref, int d)
{
    ref.number--;
    return ref;
}
int main(){
    // "дружественные" операторные функции, перегрузка операторов ++, --
    Integer d1, d2(8);
    int t;

    // проверка
    t = d1.Get(); // t = 0
    t = d2.Get(); // t = 8

    // вызов "дружественных" операторных функций
    ++d1; // "дружественная" префиксная операторная функция operator++()
    d2--; // "дружественная" постфиксная операторная функция operator--()

    t = d1.Get(); // t = 1
    t = d2.Get(); // t = 7
    return 0;
}