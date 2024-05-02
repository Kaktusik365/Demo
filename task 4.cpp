#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное, иначе завершает программу
*/
double getValue();

/**
*@brief  Функция для вычисления значения функции y = tan(X) - (1/3*(pow(tan(x), 3))) + (1/5*(pow(tan(x), 5)))-1/3
*@return tan(X) - (1/3*(pow(tan(x), 3))) + (1/5*(pow(tan(x), 5)))-1/3
*/
double calculateFunction(double x);

/**
*@brief  Функция для проверки, что шаг положительный
*@param step шаг с которым идёт постороение графика
*@return step
*/
double getStep();


/**
*@brief  точка хода в программу
*@return 0
*/
int main()
{

    cout << "Введите начальное значение x: ";
    double startX = getValue();

    cout << "Введите конечное значение x: ";
    double endX = getValue();

    if (startX > endX)
    {
        cout << "Ошибка: xstart должно быть меньше, чем xend" << endl;
        return 1;
    }

    cout << "Введите шаг: ";
    double step = getValue();
    double getStep();


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
    return tan(X) - (1/3*(pow(tan(x), 3))) + (1/5*(pow(tan(x), 5)))-1/3;
}


double getStep()
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