#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
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
 *
 * @param arr3 Указатель на двумерный массив.
 * @param rows Количество строк в массиве.
 * @param cols Количество столбцов в массиве.
 */
void insertFirstRowAfterMaxAbsColumn(int** arr3, const int max_rows, const int cols);

/**
*brief Выводит двумерный массив на экран.
*@param  array Указатель на двумерный массив, в котором нужно заменить нулевые элементы.
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
*brief Точка входа в программу
*return 0
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

    int newrows = max_rows;
    int** arr3 = copyArray(array, max_cols, max_rows);
    insertFirstRowAfterMaxAbsColumn(arr3, max_rows, newrows);

    cout << "\nВставить после всех строк, содержащих максимальный по модулю элемент, первую строку:" << endl;
    printArray(arr3, max_cols, newrows);

    deleteArray(arr3, newrows);
    deleteArray(array, newrows);

    return 0;
}

void fillArrayRandomly(int** array, int rows, int cols)
{
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            array[i][j] = rand() - RAND_MAX / 2;
        }
    }
}

void replaceMaxWithZero(int** array, const int rows, const int cols) 
{
    for (size_t j = 0; j < cols; ++j) 
    {
        int maxAbsValue = abs(array[0][j]);
        // находим максимолаьное
        for (size_t i = 1; i < rows; ++i) 
        {
            if (abs(array[i][j]) > maxAbsValue) 
            {
                maxAbsValue = abs(array[i][j]);
            }
        }
        // заменяем нулями
        for (size_t i = 0; i < rows; ++i) 
        {
            if (abs(array[i][j]) == maxAbsValue) 
            {
                array[i][j] = 0;
            }
        }
    }
}

void insertFirstRowAfterMaxAbsColumn(int** arr3, int rows, int cols) {
    for (size_t j = 0; j < cols; ++j) {
        int maxAbsValue = 0;
        for (size_t i = 0; i < rows; ++i) {
            if (abs(arr3[i][j]) > abs(arr3[maxAbsValue][j])) {
                maxAbsValue = i;
            }
        }
        if (maxAbsValue != 0) {
            int* tempRow = new int[cols]; // Создаем временный массив для хранения первой строки
            for (size_t l = 0; l < cols; ++l) {
                tempRow[l] = arr3[0][l]; // Сохраняем первую строку во временный массив
            }

            for (size_t k = rows; k > maxAbsValue + 1; --k) {
                for (size_t l = 0; l < cols; ++l) {
                    arr3[k][l] = arr3[k - 1][l]; // Сдвигаем строки вниз
                }
            }

            for (size_t l = 0; l < cols; ++l) {
                arr3[maxAbsValue + 1][l] = tempRow[l]; // Вставляем первую строку после строки с максимальным по модулю элементом
            }

            delete[] tempRow; // Освобождаем память, выделенную для временного массива
        }
    }
}


void printArray(int** array, int rows, int cols) {
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

bool checkPositiveValues(int max_rows, int max_cols)
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