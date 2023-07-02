#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
// класс, реализующий точку
class Point
{
private:
    int x, y;

public:
    Point()
    {
        x = y = 0;
    }

    // методы доступа
    void SetP(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    int GetX() { return x; }
    int GetY() { return y; }

    // перегрузка операторной функции operator()() без параметров
    Point operator()()
    {
        return *this; // вернуть текущий объект
    }

    // перегрузка операторной функции operator()() с двумя параметрами
    Point operator()(int _x, int _y)
    {
        x = _x;
        y = _y;
        return *this;
    }
};
int main(){
    // перегрузка оператора () вызова функции
    Point p1; // создать объект
    int t;

    p1.SetP(3,5); // установить значение

    Point p2; // новый объект

    // вызов операторной функции без параметров
    p2 = p1();

    // проверка
    t = p2.GetX(); // t = 3
    t = p2.GetY(); // t = 5

    // вызов операторной функции operator()() с двумя параметрами
    p2 = p1(7,8);

    // проверка
    t = p2.GetX(); // t = 7
    t = p2.GetY(); // t = 8
    return 0;
}