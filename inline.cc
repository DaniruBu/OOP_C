// класс, который содержит inline-функции
class CMyPoint
{
    int x, y;

    public:
    // конструктор класса
    CMyPoint(void);

    int GetX(void); // обычная (не inline) функция класса

    inline int GetY(void) // inline-функция
    {
        return y; // реализация в теле класса
    }

    // обычная (не inline) функция
    void SetXY(int nx, int ny);
};

// конструктор класса
CMyPoint::CMyPoint(void)
{
    x = y = 0;
}

// реализация не inline-функции GetX()
int CMyPoint::GetX(void)
{
    return x;
}

// реализация обычной не inline функции SetXY()
void CMyPoint::SetXY(int nx, int ny)
{
    x = nx;
    y = ny;
}

int main(){
    CMyPoint MP1; // объект класса, содержащий inline-функцию

    // вызов обычной (не inline) функции
    MP1.SetXY(25,30);

    int tx, ty;
    tx = MP1.GetX(); // вызов не inline функции
    ty = MP1.GetY(); // вызов inline функции
}