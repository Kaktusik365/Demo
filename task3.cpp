#include <iostream>
#include <stdlib.h>
using namespace std;


/**
 * @brief получает значение времени суток с клавиатуры
 * @param hours - введенное значение времени суток
 * @return определяет соответствующее введенному времени суток приветствие
 */
void printGreeting(int hours);

/**
 * @brief Считывает значения с клавиатуры с проверкой ввода
 * @return введенное значение, если оно верное; "Incorrect value", если введенное значение некорректное
 */
int getValue();

/**
 * brief получает значение времени суток с клавиатуры
 * return выводит соответствующее введенному времени суток приветствие 
 */
int main() 
{
    

    cout << "Введите время суток: ";
    int hours = getValue();

    if (hours < 0 or hours > 23)
    {
        cout<< "Некорректное время. Пожалуйста, введите число от 0 до 23." <<endl;
        return 1;
    }

    printGreeting(hours);

    return 0;
}


void printGreeting(int hours) 
{
    if (hours >= 6 && hours < 12) 
    {
        cout<<"Доброго утра!"<<endl;
    }
    
    else if (hours >= 12 && hours < 18) 
    {
        cout<<"Доброго дня!"<<endl;
    }
    
    else if (hours >= 18 && hours < 22) 
    {
        cout<< "Доброго вечера!"<<endl;
    }
    
    else 
    {
        cout<<"Спокойной ночи!"<<endl;
    }
}

int getValue()
{
  int value;
  cin>>value;
  if (cin.fail())
  {
      cout<<"Incorrect value "<<endl;
      abort();
  }
  return value;
}

