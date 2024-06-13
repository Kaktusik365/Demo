#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();


/**
 * @brief Проверяет, что количество строк и столбцов являются положительными числами.
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
void fillArrayRandomly(std::vector<std::vector<int>>& array, const int rows, const int cols);


/**
 * @brief Заменяет максимальное по модулю значение в каждом столбце двумерного массива на ноль.
 *
 * @param array Указатель на двумерный массив.
 * @param rows Количество строк в массиве.
 * @param cols Количество столбцов в массиве.
 */
void replaceMaxWithZero(std::vector<std::vector<int>>& array, const int rows, const int cols);


/**
*brief Выводит двумерный массив на экран.
*@param  array Указатель на двумерный массив, в котором нужно заменить нулевые элементы.
*@param rows Количество строк в массиве.
*@param cols Количество столбцов в массиве
*/
void printArray(const std::vector<std::vector<int>>& array, const int rows, const int cols);

int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    std::cout << "Введите количество строк: ";
    int max_rows = getValue();

    std::cout << "Введите количество столбцов: ";
    int max_cols = getValue();

    if (!checkPositiveValues(max_rows, max_cols)) {
        return 1;
    }

    std::vector<std::vector<int>> array(max_rows, std::vector<int>(max_cols));
    fillArrayRandomly(array, max_rows, max_cols);

    std::cout << "Случайно заполненный массив:" << std::endl;
    printArray(array, max_rows, max_cols);

    std::vector<std::vector<int>> secondArr = array;
    replaceMaxWithZero(secondArr, max_rows, max_cols);

    std::cout << "Массив после замены максимального элемента столбца на 0:" << std::endl;
    printArray(secondArr, max_rows, max_cols);

    return 0;
}


double getValue()
 {
    double value;
    std::cin >> value;
    if (std::cin.fail()) 
    {
        std::cerr << "Ошибка ввода. Программа завершена." << std::endl;
        exit(1);
    }
    return value;
}

bool checkPositiveValues(const int max_rows, const int max_cols) 
{
    if (max_rows <= 0 || max_cols <= 0) 
    {
        std::cerr << "Количество строк и столбцов должно быть положительным числом. Программа завершена." << std::endl;
        return false;
    }
    return true;
}

void fillArrayRandomly(std::vector<std::vector<int>>& array, const int rows, const int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = rand() % 100; // Заполнение случайными значениями от 0 до 99
        }
    }
}

void replaceMaxWithZero(std::vector<std::vector<int>>& array, const int rows, const int cols) 
{
    for (int j = 0; j < cols; j++) 
    {
        int maxVal = array[0][j];
        int maxRowIndex = 0;
        // Находим максимальный элемент в столбце
        for (int i = 1; i < rows; i++) 
        {
            if (array[i][j] > maxVal) 
            {
                maxVal = array[i][j];
                maxRowIndex = i;
            }
        }
        // Заменяем максимальный элемент нулём
        array[maxRowIndex][j] = 0;
    }
}

void printArray(const std::vector<std::vector<int>>& array, const int rows, const int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}