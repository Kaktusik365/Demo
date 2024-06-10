#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// Считывает значение с клавиатуры с проверкой ввода
// Возвращает значение, если оно правильное, иначе завершает программу
double getValue();

// Функция для вычисления значения функции y = tan(x) - 1/3*tan^3(x) + 1/5*tan^5(x) - 1/3
// Входное значение x
// Значение y = tan(x) - 1/3*tan^3(x) + 1/5*tan^5(x) - 1/3
double calculateFunction(const double x);

// Функция для проверки, что шаг положительный
// Положительный шаг
double getPositiveStep();

// Функция вычисляет значения функции и выводит их для заданного диапазона x.
// Начальное значение x
// Конечное значение x
// Шаг изменения x
void calculateAndPrintValues(const double startX, const double endX, const double step);

// Точка входа в программу
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

    calculateAndPrintValues(startX, endX, step);
    return 0;
}

double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        exit(1);
    }
    return value;
}

double calculateFunction(const double x)
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

void calculateAndPrintValues(const double startX, const double endX, const double step)
{
    for (double x = startX; x < endX + step; x += step)
    {
        if (fabs(cos(x)) < numeric_limits<double>::epsilon())
        {
            cout << "Ошибка: Тангенс не существует для x = " << x << endl;
        }
        else
        {
            double y = calculateFunction(x);
            cout << x << " | " << y << endl;
        }
    }
}