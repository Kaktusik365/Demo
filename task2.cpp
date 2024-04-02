#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

/**
 * @brief  получает значения байтов
 * @param bites - введённое колиичество байтов, которые надо перевести
 * @return переводит байты в мегабайты
 */
double getMegaBite(double bites);

/**
 * @brief  получает значения байтов
 * @param bites - введённое колиичество байтов, которые надо перевести
 * @return переводит байты в гигабайты
 */
double getGigaBite(double bites);

/**
 * @brief считывает введённое значение с клавиатуры, чтобы не было отрицательных
 */
void checkvalue(double value);

/**
 * @brief Считывает значения с клавиатуры с проверкой ввода
 */
double getValue();


/**
 * @brief Получает значение с клавиатуры
 * @return переводит его в мегабайты и гигабайты
 */
int main()
{
  cout<<"Enter Bites ";
  double bites = getValue();
  checkvalue(bites);
  cout << getMegaBite(bites)<<" Mb"<<endl;
  
  cout << getGigaBite(bites)<<" Gb"<<endl;
  
    return 0;
}

/*проверка введенного значения*/
double getValue()
{
  double value;
  cin>>value;
  if (cin.fail())
  {
      cout<<"Incorrect value "<<endl;
      abort();
  }
  return value;
}


double getMegaBite(double bites)
{
    return bites / 1024;
}

double getGigaBite(double bites)
{
    return bites / pow(1024,2);
}

void checkvalue(double value)
{
    if (value < 0)
    {
        abort();
    }
}