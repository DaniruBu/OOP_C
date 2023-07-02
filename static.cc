// класс, описывающий окружность на координатной плоскости
class CCircle
{
    // внутренние переменные класса
    int x, y; // координаты центра окружности
    int r; // радиус окружности

    public:
    // конструктор класса
    CCircle(void);

    // статический метод класса - только для глобальных переменных
    static void SetData1(int nx, int ny, int nr);

    // обычные (нестатические) методы класса
    // установить новые значения внутренних переменных класса
    void SetData2(int nx, int ny, int nr);

    // взять значение внутренних переменных класса
    int GetX(void) { return x; }
    int GetY(void) { return y; }
    int GetR(void) { return r; }

    // взять значение глобальных переменных класса
    int GetXX(void);
    int GetYY(void);
    int GetRR(void);
};

// глобальные переменные
int xx, yy, rr; // эти переменные может изменять статическая функция-член класса

// конструктор класса
CCircle::CCircle(void)
{
    // заполнение значений внутренних (локальных) переменных
    x = 0; y = 0; r = 1;
}

// статическая функция-член класса
void CCircle::SetData1(int nx, int ny, int nr)
{
    // присваивание значений глобальным переменным, объявленным за пределами класса
    xx = nx;
    yy = ny;
    rr = nr;

    // работать с внутренними переменными класса в статической функции запрещено
    // x = nx; // Запрещено! Ошибка: "... illegal reference to non-static member 'CCircle::х'
    // y = ny; // тоже запрещено
}

// установить новые значения обычных (нестатических) методов класса
void CCircle::SetData2(int nx, int ny, int nr)
{
    x = nx;
    y = ny;
    r = nr;
}

// прочитать значение глобальных переменных класса
int CCircle::GetXX(void)
{
    return xx;
}

int CCircle::GetYY(void)
{
    return yy;
}

int CCircle::GetRR(void)
{
    return rr;
}

int main(){
    // использование класса CCircle
    CCircle C1;
    int tx, ty, tr; // дополнительные переменные

    // вызов статической функции-члена
    C1.SetData1(2, 3, 4); // изменяются только глобальные переменные xx, yy, rr
    // прочитать значение внутренних переменных класса
    tx = C1.GetX(); // tx = 0 - внутренние переменные x,y,r инициализированы конструктором класса
    tr = C1.GetY(); // tr = 1

    // прочитать значение глобальных переменных, объявленных за пределами класса
    tx = C1.GetXX(); // tx = 2
    ty = C1.GetYY(); // ty = 3

    // вызов обычной (нестатической) функции-члена класса
    C1.SetData2(2, 3, 4); // изменяются только внутренние переменные x, y, r
    tx = C1.GetX(); // tx = 2
    tr = C1.GetR(); // tr = 4

    // другой способ вызова статической функции-члена
    CCircle::SetData1(7, 8, 9);
    tx = C1.GetXX(); // tx = 7
    ty = C1.GetYY(); // ty = 8
    return 0;
}