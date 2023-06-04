//var 3
// malahov

#include <iostream>
#include <array>
#include<cstdlib>
#include <ctime>
#include <string>
using namespace std;

/*--------------------zadanie 1-------------------------------*/
/*
 Объявить указатели на две переменные типа int . Используя указатели произвести операции сложения и вычитания над переменными. Вывести адреса указателей.
 */
int main()
{
int a = 10, b = 5;
    int* ptr_a = &a;
    int* ptr_b = &b;
        int sum = *ptr_a + *ptr_b;
        int diff = *ptr_a - *ptr_b;
            cout << "Сумма переменных: " << sum << endl;
            cout << "Разность переменных: " << diff << endl;
            cout << "Адрес переменной a: " << ptr_a << endl;
            cout << "Адрес переменной b: " << ptr_b << endl;

    return 0;
}
/*-----------------------zadanie 2----------------------------*/
/*
 Написать функцию для обмена значений переменных, указанных выше. Передача по указателю. Выполнить программу по шагам и вывести адреса указателей и величины переменных.
 */

void swapValues(int* ptr_a, int* ptr_b)
{
    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}
/*------------------------zadanie 3-----------------------------------*/
/*
 
 Объявить динамический массив. Размер массива задаёт пользователь. Заполнить массив случайными числами. Вывести на экран адреса и значения элементов массива.
 */
int main()
{
    int size;
    
    cout << "Введите размер массива: ";
    cin >> size;
    
    int* arr = new int[size];
    
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    
    
    for (int i = 0; i < size; i++)
    {
        cout << "Адрес элемента " << i << ": " << &arr[i] << ", значение элемента " << i << ": " << arr[i] << endl;
    }
    
    return 0;
}
/*-------------------zadanie 4---------------------------------*/
/*
 Объявить сущность и описать её свойства. Объявить динамический массив
 сущностей. Реализовать функцию, которая изменяет значения элемента (структура)
 массива. Заполнить атрибуты числовыми и текстовыми значениями (диапазон
 значений определить самостоятельно).
 */

// Объявляем сущность "Цветок"
struct Flower {
    string name;
    string color;
    int height;
    bool hasThorns;
};

// Функция для изменения значения элемента массива
void modifyFlower(Flower* arr, int index, string newName, string newColor, int newHeight, bool newHasThorns) {
    arr[index].name = newName;
    arr[index].color = newColor;
    arr[index].height = newHeight;
    arr[index].hasThorns = newHasThorns;
}

int main() {
    int size;

    // Запрашиваем у пользователя размер массива
    cout << "Введите размер массива: ";
    cin >> size;

    // Объявляем динамический массив сущностей "Цветок"
    Flower* flowers = new Flower[size];

    // Заполняем массив случайными значениями
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        flowers[i].name = "Flower " + to_string(i+1);
        flowers[i].color = (rand() % 2 == 0) ? "Red" : "Yellow";
        flowers[i].height = rand() % 40 + 10;
        flowers[i].hasThorns = (rand() % 2 == 0) ? true : false;
    }

    // Выводим на экран изначальный массив сущностей "Цветок"
    cout << "Изначальный массив:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Цветок " << i+1 << ": " << flowers[i].name << ", " << flowers[i].color << ", " << flowers[i].height << " см, ";
        if (flowers[i].hasThorns) {
            cout << "есть шипы" << endl;
        } else {
            cout << "нет шипов" << endl;
        }
    }

    // Изменяем значение элемента массива
    modifyFlower(flowers, 2, "New Flower", "Blue", 20, true);

    // Выводим на экран измененный массив сущностей "Цветок"
    cout << endl << "Измененный массив:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Цветок " << i+1 << ": " << flowers[i].name << ", " << flowers[i].color << ", " << flowers[i].height << " см, ";
        if (flowers[i].hasThorns) {
            cout << "есть шипы" << endl;
        } else {
            cout << "нет шипов" << endl;
        }
    }

    // Удаляем динамически выделенную память
    delete[] flowers;

    return 0;
}
