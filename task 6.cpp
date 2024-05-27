
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, const int min, const int max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief Заменяет минимальный элемент массива на средний, если количество элементов в массиве нечетное
 * @param arr  Массив целых чисел, в котором будет произведена замена
 * @param n Размер массива
 */
void replaceMinWithAverage(int arr[], int n);

/**
 * @brief проверяет, содержит ли массив две пары соседних элементов с одинаковыми знаками.
 * @param arr Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @return true, если в массиве есть две пары соседних элементов с одинаковыми знаками, иначе false.
 */
bool hasTwoPairsWithSameSign(int arr[], int n);

/**
 * @brief выводит индексы элементов массива, значения которых больше предыдущих элементов.
 * @param arr Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 */
void printIndicesGreaterThanPrevious(int arr[], int n);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int* arr, const int n, const int min, const int max);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int n = getSize();
    int* arr = new int[n];

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << " Для ручного заполнения" << endl;

    int choice = getNumber();

    switch ((SELECT)choice)
    {
    case RANDOM:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        return -1;
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    replaceMinWithAverage(arr, n);
    printIndicesGreaterThanPrevious(arr, n);

    if (hasTwoPairsWithSameSign(arr, n))
    {
        cout << "Есть две пары соседних элементов с одинаковыми знаками.\\n";
    }
    else
    {
        cout << "Две пары соседних элементов с одинаковыми знаками отсутствуют.\\n";
    }

    delete[] arr; // Освобождаем память массива
    return 0;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

size_t getSize()
{
    cout << "Введите размер массива: ";
    int n;
    cin >> n;
    checkN(n);
    return (size_t)n;
}

int getNumber()
{
    int number;
    cin >> number;
    if (cin.fail())
    {
        cout << "Неправильный ввод данных";
        abort();
    }
    return number;
}

void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void fillArrayRandom(int* arr, const int n, const int min, const int max)
{
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cout << "Введен неправильный диапазон" << endl;
        abort();
    }
}

void replaceMinWithAverage(int arr[], int n)
{
    int minIndex = 0;

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }

    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    arr[minIndex] = sum / n;
}

void printIndicesGreaterThanPrevious(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > arr[i - 1])
        {
            cout << "Индекс " << i << ": " << arr[i] << endl;
        }
    }
}

bool hasTwoPairsWithSameSign(int arr[], int n)
{
    for (int i = 0; i < n - 3; ++i)
    {
        if ((arr[i] > 0 && arr[i + 1] > 0 && arr[i + 2] > 0 && arr[i + 3] > 0) ||
            (arr[i] < 0 && arr[i + 1] < 0 && arr[i + 2] < 0 && arr[i + 3] < 0))
        {
            return true;
        }
    }

    return false;
}

void fillArray(int* arr, const int n, const int min, const int max)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter value for arr[" << i << "]: ";
        arr[i] = getNumber();

        if (arr[i] < min || arr[i] > max)
        {
            cout << "Значение вне диапазона" << endl;
            i--;
        }
    }
}