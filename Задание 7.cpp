﻿ #include <cstdlib>
#include <iostream>
using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
 * @brief Проверяет, что количество строк и столбцов являются положительными числами.
 *
 * @param max_rows Максимальное количество строк.
 * @param max_cols Максимальное количество столбцов.
 * @return true, если оба значения положительные; false в противном случае.
 */
bool checkPositiveValues(const int max_rows, const int max_cols);

/**
 *@brief Заполняет двумерный массив случайными значениями.
 *@param array Указатель на двумерный массив.
 *@param rows Количество строк в массиве.
 *@param cols Количество столбцов в массиве.
 */
void fillArrayRandomly(int** array, const int rows, const int cols);

/**
 * @brief Заменяет максимальное по модулю значение в каждом столбце двумерного массива на ноль.
 *
 * @param array Указатель на двумерный массив.
 * @param rows Количество строк в массиве.
 * @param cols Количество столбцов в массиве.
 */
void replaceMaxWithZero(int** array, const int rows, const int cols);

/**
 * @brief Вставляет первую строку после строки с максимальным по модулю элементом в каждом столбце двумерного массива.
 * @param arr3 Указатель на двумерный массив новый.
 * @param array Указатель на двумерный массив шаблонный.
 * @param rows Количество строк в массиве в новом массиве.
 * @param rows Количество строк в массиве.
 * @param cols Количество столбцов в массиве.
 */
void insertFirstRowAfterMaxAbsColumn(int** arr3, int** array, const int new_rows, const int rows, const int cols);

/**
*@brief Выводит двумерный массив на экран.
*@param  array Указатель на двумерный массив
*@param rows Количество строк в массиве.
*@param cols Количество столбцов в массиве
*/
void printArray(int** array, const int rows, const int cols);

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
*@brief Точка входа в программу
*@return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    cout << "Введите количество строк: ";
    int max_rows = getValue();

    cout << "Введите количество столбцов: ";
    int max_cols = getValue();

    if (!checkPositiveValues(max_rows, max_cols))
    {
        return 1;
    }

    int** array = getNewArray(max_rows, max_cols);
    fillArrayRandomly(array, max_rows, max_cols);

    cout << "Случайно заполненный массив:" << endl;
    printArray(array, max_rows, max_cols);

    int** secondArr = copyArray(array, max_rows, max_cols);
    replaceMaxWithZero(secondArr, max_rows, max_cols);

    cout << "\nМассив после замены максимального элемента столбца на 0:" << endl;
    printArray(secondArr, max_rows, max_cols);

    deleteArray(secondArr, max_rows);


    cout << "\nВставляет первую строку после строки с максимальным по модулю элементом в каждом столбце двумерного массива:" << endl;
    int newrows = max_rows + 1;
    int** arr3 = getNewArray(newrows, max_cols);
    insertFirstRowAfterMaxAbsColumn(arr3, array, newrows, max_rows, max_cols);

    printArray(arr3, newrows, max_cols);

    deleteArray(arr3, newrows);
    deleteArray(array, max_rows);

    return 0;
}

void fillArrayRandomly(int** array, const int rows, const int cols)
{
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            array[i][j] = rand() % (100 - -100 + 1) + -100;
        }
    }
}

void replaceMaxWithZero(int** array, const int rows, const int cols) {
    for (size_t j = 0; j < cols; ++j) {
        int maxAbsValue = 0;
        for (size_t i = 1; i < rows; ++i) {
            if (abs(array[i][j]) > abs(array[maxAbsValue][j])) {
                maxAbsValue = i;
            }
        }
        array[maxAbsValue][j] = 0;
    }
}

void insertFirstRowAfterMaxAbsColumn(int** arr3, int** array, const int new_rows, const int rows, const int cols) {
    int i_max_elem = 0;
    int j_max_elem = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (abs(array[i_max_elem][j_max_elem]) < abs(array[i][j])) {
                i_max_elem = i;
                j_max_elem = j;
            }
        }
    }
    // находим индексы максимального элемента
    cout << "MAX=" << array[i_max_elem][j_max_elem] << endl;
    int* temprow = new int[cols]();
    for (size_t j = 0; j < cols; j++) {
        temprow[j] = array[0][j];
    }
    // "запоминаем" нашу первую строку
    for (size_t i = 0, i_original = 0; i < new_rows; i++, i_original++) {
        if (i_original == i_max_elem) {
            // если нашли строку совпадающуюю по индексу с индексом строки макс элемента копируем 
            // сначала исходную строку массива, потом нашу "первую" строку
            for (size_t j = 0; j < cols; j++) {
                arr3[i][j] = array[i_original][j];
            }
            i++;
            for (size_t j = 0; j < cols; j++) {
                arr3[i][j] = temprow[j];
            }
        }
        else {
            // обычное копирование элементов
            for (size_t j = 0; j < cols; j++) {
                arr3[i][j] = array[i_original][j];
            }
        }
    }
    delete[] temprow;
}

void printArray(int** array, const int rows, const int cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

double getValue() {
    double value;
    cin >> value;
    if (cin.fail()) {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

int** getNewArray(const int max_rows, const int max_cols) {
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

bool checkPositiveValues(const int max_rows, const int max_cols)
{
    if (max_rows > 0 && max_cols > 0)
    {
        return true; // Оба значения положительные
    }
    else
    {
        cout << "Ошибка: Количество строк и столбцов должно быть положительным числом." << endl;
        return false; // Хотя бы одно значение не положительное
    }
}
