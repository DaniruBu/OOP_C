#include <iostream>
using namespace std;

// класс, который определяет координаты точки в пространстве
class Coords3D
{
private:
    double x, y, z;

public:
    Coords3D()
    {
        x = y = z = 0;
    }

    Coords3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // метод чтения x, y, z
    void Get(double& x, double& y, double& z)
    {
        x = this->x;
        y = this->y;
        z = this->z;
    }

    // перегруженный оператор ,
    Coords3D operator,(Coords3D obj)
    {
        Coords3D tmp;
        tmp.x = obj.x;
        tmp.y = obj.y;
        tmp.z = obj.z;
        return tmp;
    }
};

void main()
{
    double x, y, z;
    Coords3D c1(1, 3, 5); // экземпляры класса Coords3D
    Coords3D c2(2, 4, 6);
    Coords3D c3;

    // вызов операторной функции c3.operator,(c2)
    c3 = (c1, c2); // в c3 записывается c2

    // проверка
    c3.Get(x, y, z); // x = 2, y = 4, z = 6

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    //------------------------
    //создать другой экземпляр
    Coords3D c4(10, 15, 20);

    c3 = (c2, c1, c4); // c3 <= c4

    // проверка
    c3.Get(x, y, z); // x = 10, y = 15, z = 20

    cout << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}