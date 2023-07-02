// класс, реализующий массив целых чисел
class ArrayInt
{
private:
    int A[100]; // внутренняя переменная - массив целых чисел
    int size; // количество элементов массива

public:
    // конструкторы
    ArrayInt() { size = 0; }

    ArrayInt(int _size)
    {
        if (_size>100) _size=100;
        size = _size;

        for (int i=0; i<size; i++)
            A[i] = 0;
    }

    // методы доступа
    void SetAi(int index, int value)
    {
        if ((index>=0) && (index<=size))
            A[index] = value;
    }

    int GetAi(int index) { return A[index]; }
    int GetSize(void) { return size; }

    // перегруженный оператор ++
    // префиксная форма
    ArrayInt operator++(void)
    {
        for (int i=0; i<size; i++)
            A[i] = A[i] + 5;
        return *this;
    }

    // постфиксная форма оператора ++, параметр t не используется
    ArrayInt operator++(int t)
    {
        for (int i=0; i<size; i++)
            A[i] = A[i] + 5;
        return *this;
    }

    // префиксная форма оператора --
    ArrayInt operator--(void)
    {
        for (int i=0; i<size; i++)
            A[i] = A[i] - 5;
        return *this;
    }

    // постфиксная форма оператора --, параметр t не используется
    ArrayInt operator--(int t)
    {
        for (int i=0; i<size; i++)
            A[i] = A[i] - 5;
        return *this;
    }
};
int main(){
    // демонстрация использования перегруженных инкрементных
    // операторных функций
    ArrayInt AA(10);
    int t;

    // инициализация массива AA некоторыми значениями
    for (int i=0; i<AA.GetSize(); i++)
    AA.SetAi(i, i+1);

    // проверка
    t = AA.GetAi(2); // t = 3

    // вызов перегруженных операторных функций
    AA++;
    t = AA.GetAi(2); // t = 3+5 = 8

    --AA;
    AA--;
    t = AA.GetAi(2); // t = 8-5-5 = -2
    return 0;
}