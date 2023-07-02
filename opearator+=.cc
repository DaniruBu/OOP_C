// класс Integer - реализует целое число
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

    // перегрузка оператора +=, операторная функция внутри класса
    Integer operator+=(Integer obj)
    {
        number = number + obj.number; // доступ по ссылке
        return *this;
    }
};
int main(){
    // перегрузка сокращенных операторов присваивания +=, -= и т.д.
    Integer d1(10), d2(18); // экземпляры класса Integer
    int t;

    // вызов операторной функции operator+=()
    d1+=d2; // d1.number = d1.number + d2.number

    t = d1.Get(); // t = 28
    return 0;
}