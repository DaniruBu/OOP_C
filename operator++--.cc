// перегрузка инкрементных операторов для класса Integer
class Integer
{
private:
    int number; // член данных

public:
    // конструкторы класса
    // конструктор без параметров
    Integer() { number = 0; }

    // конструктор с 1 параметром
    Integer(int _number) { number = _number; }

    // методы доступа
    void Set(int _number) { number = _number; }
    int Get(void) { return number; }

    // операторная функция, которая перегружает
    // префиксную форму оператора ++ для класса Integer
    Integer operator++(void)
    {
        number++;
        return *this; // вернуть объект данного класса
    }

    // операторная функция, которая перегружает
    // постфиксную форму оператора ++ для класса Integer
    Integer operator++(int d) // параметр d не используется
    {
        number++;
        return *this;
    }

    // перегрузка префиксного --
    Integer operator--(void)
    {
        number--;
        return *this;
    }

    // перегрузка постфиксного --
    Integer operator--(int d) // параметр d не используется
    {
        number--;
        return *this;
    }
};
int main(){
    // демонстрация использования перегруженных инкрементных
    // операторных функций
    Integer d1, d2(5); // объявление объектов класса Integer
    Integer d3;
    int t1, t2;

    // проверка
    t1 = d1.Get(); // t1 = 0
    t2 = d2.Get(); // t2 = 5

    // вызов перегруженных операторных функций
    ++d1; // вызов префиксной операторной функции operator++()
    t1 = d1.Get(); // t1 = 1

    d2++; // вызов постфиксной операторной функции operator++(int)
    t2 = d2.Get(); // t2 = 6

    --d1; // префиксный --
    d1--; // постфиксный --
    t1 = d1.Get(); // t1 = -1
    return 0;
}