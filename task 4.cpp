#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода
 * @return Возвращает значение, если оно правильное, иначе завершает программу
 */
double getValue();

/**
 * @brief Функция для вычисления значения функции y = tan(x) - 1/3*tan^3(x) + 1/5*tan^5(x) - 1/3
 * @param x Входное значение x
 * @return Значение y = tan(x) - 1/3*tan^3(x) + 1/5*tan^5(x) - 1/3
 */
double calculateFunction(double x);

/**
 * @brief Функция для проверки, что шаг положительный
 * @return Положительный шаг
 */
double getPositiveStep();

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getValue();

    cout << "Введите конечное значение x: ";
    double endX = getValue();

    if (startX > endX)
    {
        cout << "Ошибка: xstart должно быть меньше, чем xend" << endl;
        return 1;
    }

    double step = getPositiveStep();

    cout << "x | y" << endl;
    cout << "--------" << endl;

    for (double x = startX; x < endX; x += step)
    {
        if (fabs(tan(x) - 1.0 / 3.0 * pow(tan(x), 3) + 1.0 / 5.0 * pow(tan(x), 5) - 1.0 / 3) < numeric_limits<double>::epsilon())
        {
            cout << "Решение невозможно для x = " << x << endl;
        }
        else
        {
            double y = calculateFunction(x);
            cout << x << " | " << y << endl;
        }
    }

    return 0;
}

double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

double calculateFunction(double x)
{
    return tan(x) - 1.0 / 3.0 * pow(tan(x), 3) + 1.0 / 5.0 * pow(tan(x), 5) - 1.0 / 3;
}

double getPositiveStep()
{
    double step;
    do {
        cout << "Введите шаг: ";
        step = getValue();
        if (step <= 0)
        {
            cout << "Ошибка. Шаг должен быть положительным. Повторите ввод." << endl;
        }
    } while (step <= 0);
    return step;
}
