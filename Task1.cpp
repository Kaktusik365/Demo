#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Функция для вычисления значения переменной a по заданным константам.
 * @return Результат вычисления переменной a.
*/

double calculateA(double x, double y, double z)
{
    return pow(sin(pow(x, 2) + z), 3) - sqrt(x / y);
}

/*
 * @brief Функция для вычисления значения переменной b по заданным константам.
 * @return Результат вычисления переменной b.
*/

double calculateB(double x, double z)
{
    return pow(x, 2) / z + pow(cos(x), 3);
}

int main()
{
   const double x = 0.2;
   const double y = 0.004;
   const double z = 1.1;

    double a = calculateA(x, y, z);
    double b = calculateB(x, z);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}