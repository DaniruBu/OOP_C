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

    // объявление "дружественной" к классу Integer операторной функции
    // которая перегружает оператор %=
    friend Integer operator%=(Integer& obj1, Integer& obj2);
};

// "дружественная" операторная функция к классу Integer
// в операторную функцию передается ссылка на класс Integer
Integer operator%=(Integer& obj1, Integer& obj2)
{
    obj1.number = obj1.number % obj2.number; // доступ по ссылке
    return obj1;
}
int main(){
    // перегрузка сокращенных операторов присваивания +=, -= и т.д.
    Integer d1(14), d2(6); // экземпляры класса Integer
    int t;

    // вызов "дружественной" операторной функции operator%=()
    d1 %= d2; // d1.number = d1.number + d2.number
    t = d1.Get(); // t = 2

    Integer d3(9), d4(5);
    d3 %= d4;
    t = d3.Get(); // t = 4
    return 0;
}