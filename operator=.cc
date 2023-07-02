// Класс, который реализует точку на координатной плоскости
// класс содержит две операторные функции
class Point
{
private:
    int x, y;

public:
    Point(){
        x = y = 0;
    }

    Point(int nx, int ny){
        x = nx;
        y = ny;
    }

    // методы доступа к членам класса
    int GetX(void) { return x; }
    int GetY(void) { return y; }
    void SetX(int nx) { x = nx; }
    void Set(int ny) { y = ny; }

    // перегруженный бинарный оператор '+'
    Point operator+(Point pt){
        // p - временный объект, который создается с помощью конструктора без параметров
        Point p;
        p.x = x + pt.x;
        p.y = y + pt.y;
        return p;
    }

    // перегруженный унарный оператор '-'
    Point operator-(void){
        Point p;
        p.x = -x;
        p.y = -y;
        return p;
    }
    int main(){
        // объявление переменных - объектов класса CPoint
        Point P1(3,4);
        Point P2(5,7);
        Point P3;
        int x, y; // дополнительные переменные

        // 1. Использование перегруженного бинарного оператора '+'
        P3 = P1 + P2; // объект P1 вызывает операторную функцию

        // проверка
        x = P3.GetX(); // x = 8
        y = P3.GetY(); // y = 11

        // 2. Использование перегруженного унарного оператора '-'
        P3 = -P2;
        x = P3.GetX(); // x = -5
        y = P3.GetY(); // y = -7
        return 0;
    }
};