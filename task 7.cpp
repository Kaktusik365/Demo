﻿#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
 *@brief Заполняет двумерный массив случайными значениями.
 *@param array Указатель на двумерный массив.
 *@param rows Количество строк в массиве.
 *@param cols Количество столбцов в массиве.
 */
void fillArrayRandomly(int** array, const int rows, const int cols);

/**
*@brief Заменяет нулевые элементы в столбцах двумерного массива на максимальные по модулю значения в этих столбцах.
*@param  array Указатель на двумерный массив, в котором нужно заменить нулевые элементы.
*@param rows Количество строк в массиве.
*@param cols Количество столбцов в массиве
*/
void replaceZeroWithMaxAbsElement(int** array, const int rows, const int cols);

/**
@brief вставляет нули после элемента с максимальным по модулю значением в каждом столбце двумерного массива
*@param  array Указатель на двумерный массив, в котором нужно заменить нулевые элементы.
*@param rows Количество строк в массиве.
*@param cols Количество столбцов в массиве
*/
void insertZerosAfterMaxAbsColumn(int** array, const int rows, const int cols);

/**
*brief Выводит двумерный массив на экран.
*@param  array Указатель на двумерный массив, в котором нужно заменить нулевые элементы.
*@param rows Количество строк в массиве.
*@param cols Количество столбцов в массиве
*/
void printArray(int** array, const int rows, const int cols) const;

/**
 * @brief Создает новый двумерный массив с заданным количеством строк и столбцов.
 * @param rows Количество строк в новом массиве.
 * @param columns Количество столбцов в новом массиве.
 * @return Указатель на новый двумерный массив типа int.
 */
int** getNewArray(const int rows, const int columns);

/**
 * @brief Создает копию существующего двумерного массива с заданным количеством строк и столбцов.
 * @param arr Указатель на существующий двумерный массив типа int, который нужно скопировать.
 * @param rows Количество строк в существующем массиве.
 * @param columns Количество столбцов в существующем массиве.
 * @return Указатель на новую копию двумерного массива типа int.
 */
int** copyArray(int** arr, const int rows, const int columns);

/**
 * Освобождает память, выделенную под двумерный массив типа int.
 * @param arr Указатель на двумерный массив типа int, который нужно освободить.
 * @param rows Количество строк в двумерном массиве.
 */
void deleteArray(int** arr, const int rows);

/**
*brief Точка входа в программу
*return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));


    cout << "Введите количество строк: ";
    int max_rows = getValue();
    cin >> max_rows;
    //checkValue

    cout << "Введите количество столбцов: ";
    int max_cols = getValue();
    cin >> max_cols;
    //checkValue

    int** array = getNewArray(max_rows, max_cols);



    // Заполнить массив случайными числами и вывести его
    fillArrayRandomly(array, max_rows, max_cols);
    cout << "Случайно заполненный массив:" << endl;
    printArray(array, max_rows, max_cols);
    int** secondArr = copyArray(array, max_rows, max_cols);
    // Заменить нули максимальными по модулю элементами в каждом столбце
    replaceZeroWithMaxAbsElement(secondArr, max_rows, max_cols);
    cout << "\nМассив после замены нулей максимальными по модулю элементами в каждом столбце:" << endl;
    printArray(secondArr, max_rows, max_cols);
    deleteArray(secondArr, max_rows);
    size_t newcols = max_cols + getNumerOfColumns(arr, max_rows, max_cols);
    int** arr3 = getNewArray(max_rows, newcols);
    // Вставить строки из нулей после столбцов с максимальным по модулю элементом
    insertZerosAfterMaxAbsColumn(array, arr3, max_rows, max_cols);
    cout << "\nМассив после вставки строк из нулей после столбцов с максимальным по модулю элементом:" << endl;
    printArray(arr3, max_rows, newcols);
    deleteArray(arr3, max_rows);
    deleteArray(array, max_rows);



    return 0;
}


void fillArrayRandomly(int** array, int rows, int cols)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            array[i][j] = rand() - RAND_MAX / 2;
        }
    }
}

void replaceZeroWithMaxAbsElement(int** array, int rows, int cols)
{
    for (size_t j = 0; j < cols; ++j)
    {
        int maxAbsValue = 0;
        for (size_t i = 0; i < rows; ++i)
        {
            if (abs(array[i][j]) > abs(array[maxAbsValue][j]))
            {
                maxAbsValue = i;
            }
        }
        array[maxAbsValue][j] = 0;
    }
}

void insertZerosAfterMaxAbsColumn(int** array, int rows, int cols)
{
    for (size_t j = 0; j < cols; ++j)
    {
        int maxAbsValue = 0;
        for (size_t i = 0; i < rows; ++i)
        {
            if (abs(array[i][j]) > abs(array[maxAbsValue][j]))
            {
                maxAbsValue = i;
            }
        }
        if (maxAbsValue != 0)
        {
            // Вставить строки из нулей после столбцов с максимальным по модулю элементом
            for (size_t k = rows; k > j + 1; --k)
            {
                for (size_t l = 0; l < cols; ++l)
                {
                    array[k][l] = array[k - 1][l];
                }
            }
            for (size_t l = 0; l < cols; ++l)
            {
                array[j + 1][l] = 0;
            }
        }
    }
}

void printArray(int** array, int rows, int cols)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
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

int** getNewArray(const int rows, const int columns)
{
    int** array = new int* [max_rows];
    for (size_t i = 0; i < max_rows; ++i)
    {
        array[i] = new int[max_cols];
    }
    return array;
}

int** copyArray(int** arr, const int rows, const int columns)
{
    int** resultArray = getNewArray(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            resultArray[i][j] = arr[i][j];
        }
    }
    return resultArray;
}

void deleteArray(int** arr, const int rows)
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}