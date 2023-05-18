#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include <Windows.h>

#include <iostream>
#include <fstream>

#include <string>

#include "string_set.h"
#include "ostream_operator_cout.h"

using namespace std;

struct Leaks
{
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

/*

17. Усовершенствовать (или разработать) класс «множество строк».

Разработать программу, которая сравнивает два файла по выбору пользователя и:
a. выводит или записывает в другой файл все слова/строки, которые есть и в первом и во втором файлах;
b. выводит или записывает в другой файл все слова/строки, которые есть в первом/втором файле, но которых нет во втором/первом файле.

string_set

*/

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream input1("StringSet1.txt");
    ifstream input2("StringSet2.txt");

    string_set stringSet1, stringSet2, stringSetResultMultiplication, stringSetResultSubtraction12, stringSetResultSubtraction21;

    string str;

    if (input1.is_open())
    {
        while (getline(input1, str))
            stringSet1.push_back(str);
        input1.close();
    }
    else
        cout << "Unable to open file\n";

    cout << endl;
    printf("Значения множества stringSet1:\n");
    cout << stringSet1 << endl;

    if (input2.is_open())
    {
        while (getline(input2, str))
            stringSet2.push_back(str);
        input2.close();
    }
    else
        cout << "Unable to open file\n";

    cout << endl;
    printf("Значения множества stringSet2:\n");
    cout << stringSet2 << endl;

    stringSetResultMultiplication = stringSet1 * stringSet2;

    cout << endl;
    printf("Значения множества stringSetResultMultiplication:\n");
    cout << stringSetResultMultiplication << endl;

    ofstream outputM("stringSetResultMultiplication.txt");
    if (outputM)
        outputM << stringSetResultMultiplication << endl;
    outputM.close();

    stringSetResultSubtraction12 = stringSet1 - stringSet2;

    cout << endl;
    printf("Значения множества stringSetResultSubtraction12:\n");
    cout << stringSetResultSubtraction12 << endl;

    ofstream outputS12("stringSetResultSubtraction12.txt");
    if (outputS12)
        outputS12 << stringSetResultSubtraction12 << endl;
    outputS12.close();

    stringSetResultSubtraction21 = stringSet2 - stringSet1;

    cout << endl;
    printf("Значения множества stringSetResultSubtraction21:\n");
    cout << stringSetResultSubtraction21 << endl;

    ofstream outputS21("stringSetResultSubtraction21.txt");
    if (outputS21)
        outputS21 << stringSetResultSubtraction21 << endl;
    outputS21.close();

    return 0;
}

// Тестирование работы "Усовершенствовать (или разработать) класс «множество строк»".
/*

    string valueNew;
    bool valueBool = false;

    string_set arr;
    int sizeDA;

    cout << "Введите размер множества: ";
    cin >> sizeDA;                             // получение от пользователя размера массива
    getline(cin, valueNew);

    arr.resize(sizeDA);

    for (int i = 0; i < arr.size(); i++)
    {
        printf("Введите значение №%d: ", i);

        getline(cin, valueNew);

        valueBool = false;
        for (int j = 0; j < arr.size(); j++) {

            if (valueNew == arr[j])
            {
                valueBool = true;
                j = arr.size();
            }
        }
        if (!valueBool)
            arr[i] = valueNew;
        else
        {
            cout << "Значение: " << valueNew << " уже есть во множестве." << endl;
            i--;
        }
    }

    cout << endl;
    printf("Значения множества string_set:\n");
    cout << arr << endl;

    string searchDA;

    cout << endl;
    cout << "Введите значение, которое вы хотите найти в множестве: " << endl;
    getline(cin, searchDA);                         // получение от пользователя искомого элемента массива

    char answer;

    answer = arr.search_in_array(arr, arr.size(), searchDA);

    if (answer == 'y' || answer == 'Y')
    {
        arr.push_back(searchDA);

        cout << endl;
        printf("Значения множества string_set:\n");
        cout << arr << endl;
    }

    string_set arr_copy;
    char answer_copy;

    cout << endl;
    cout << "Хотите сделать копию множества string_set? y/n" << endl;
    cin >> answer_copy;                         // получение от пользователя ответа копировать или нет

    if (answer_copy == 'y' || answer_copy == 'Y')
    {
        string_set arr_copy = arr;

        cout << endl;
        printf("Значения множества string_set_copy:\n");
        cout << arr_copy << endl;
    }

    string_set arrNew;
    int sizeDAN;

    cout << endl;
    cout << "Введите размер нового, второго множества string_set_new: ";
    cin >> sizeDAN;                             // получение от пользователя размера массива
    getline(cin, valueNew);

    arrNew.resize(sizeDAN);

    for (int i = 0; i < arrNew.size(); i++)
    {
        //valueNew = nullptr;
        printf("Введите значение множества string_set_new №%d: ", i);
        //cin >> valueNew;
        getline(cin, valueNew);

        valueBool = false;
        for (int j = 0; j < arrNew.size(); j++) {

            if (valueNew == arrNew[j])
            {
                valueBool = true;
                j = arrNew.size();
            }
        }
        if (!valueBool)
            arrNew[i] = valueNew;
        else
        {
            cout << "Значение: " << valueNew << " уже есть во множестве множества string_set_new." << endl;
            i--;
        }
    }

    cout << endl;
    printf("Значения множества string_set_new:\n");
    cout << arrNew << endl;

    char answer_assignment;

    cout << endl;
    cout << "Присвоить значения множества string_set множеству string_set_new? " << endl;
    cin >> answer_assignment;                   // получение от пользователя ответа присваивать или нет

    if (answer_assignment == 'y' || answer_assignment == 'Y')
    {
        arr_copy = arrNew;

        arrNew = arr;                           // b.перегруженную операцию присваивания с множеством;

        cout << "Результат присваивания множеств string_set и string_set_new" << endl;

        cout << arrNew << endl;                 //a.функцию потокового вывода множества для консоли ( операция << );

        cout << endl;
        printf("Значения множества string_set_new:\n");
        cout << arrNew << endl;

        cout << endl;
        cout << "Для дальнейшей демонстрации программы вернем изначальные значения множества string_set_new" << endl;

        arrNew = arr_copy;

        cout << endl;
        printf("Значения множества string_set_new:\n");
        cout << arrNew << endl;
    }

    char answer_plus;

    cout << endl;
    cout << "Сложить (+) значения множества string_set и множества string_set_new? " << endl;
    cin >> answer_plus;                         // получение от пользователя ответа складывать или нет

    if (answer_plus == 'y' || answer_plus == 'Y')
    {
        cout << "Результат сложения множеств string_array и string_array_new" << endl;;

        cout << arr + arrNew << endl;           //c.функцию сложения(ИЛИ) двух множеств в одно, используя перегруженную операцию +;

    }

    cout << endl;
    cout << "Сложить и присвоить (+=) значения множества string_set и множества string_set_new? " << endl;
    cin >> answer_plus;                         // получение от пользователя ответа складывать и присваивать или нет

    if (answer_plus == 'y' || answer_plus == 'Y')
    {
        string_set arrPlus;

        arr_copy = arr;

        arr += arrNew;                          //Усложнение №1(+4 балла) c.функцию сложения(ИЛИ) двух множеств в одно, используя перегруженную операцию +=;

        cout << "Результат сложения множеств string_set и string_set_new" << endl;

        cout << arr << endl;                    //a.функцию потокового вывода множества для консоли ( операция << );

        cout << endl;
        printf("Значения множества string_set:\n");
        cout << arr << endl;

        cout << endl;
        cout << "Для дальнейшей демонстрации программы вернем изначальные значения множества string_set," << endl;
        cout << "а результат сложения присвоим множеству string_set_plus" << endl;

        arrPlus = arr;

        arr = arr_copy;

        cout << endl;
        printf("Значения множества string_set_plus:\n");
        cout << arrPlus << endl;
    }

    char answer_multiplication;

    cout << endl;
    cout << "Умножить (*) значения множества string_set и множества string_set_new? " << endl;
    cin >> answer_multiplication;               // получение от пользователя ответа умножать или нет

    if (answer_multiplication == 'y' || answer_multiplication == 'Y')
    {
        cout << "Результат сложения множеств string_set и string_set_new" << endl;;

        cout << arr * arrNew << endl;           //d.функцию умножения(И) двух множеств в одно, используя перегруженную операцию *;

    }

    cout << endl;
    cout << "Умножить и присвоить (*=) значения множества string_set и множества string_set_new? " << endl;
    cin >> answer_multiplication;               // получение от пользователя ответа умножать и присваивать или нет

    if (answer_multiplication == 'y' || answer_multiplication == 'Y')
    {
        string_set arrMultiplication;

        arr_copy = arr;

        arr *= arrNew;                           //Усложнение №1(+4 балла) d.функцию умножения(И) двух множеств в одно, используя перегруженную операцию *=;

        cout << "Результат умножения множеств string_set и string_set_new" << endl;

        cout << arr << endl;                    //a.функцию потокового вывода множества для консоли ( операция << );

        cout << endl;
        printf("Значения множества string_set:\n");
        cout << arr << endl;

        cout << endl;
        cout << "Для дальнейшей демонстрации программы вернем изначальные значения множества string_set," << endl;
        cout << "а результат умножения присвоим множеству string_set_multiplication" << endl;

        arrMultiplication = arr;

        arr = arr_copy;

        cout << endl;
        printf("Значения множества string_set_multiplication:\n");
        cout << arrMultiplication << endl;
    }

    char answer_subtraction;

    cout << endl;
    cout << "Вычесть (-) значения множества string_set из множества string_set_new? " << endl;
    cin >> answer_subtraction;

    if (answer_subtraction == 'y' || answer_subtraction == 'Y')
    {
        cout << "Результат вычитания множеств string_set и string_set_new" << endl;;

        cout << arr - arrNew << endl;           //e.функцию вычитания одного множества из другого, которая возвращает все элементы первого множества, которых нет во втором, используя перегруженную операцию - ;

    }

    cout << endl;
    cout << "Вычесть и присвоить (-=) значения множества string_set из множества string_set_new? " << endl;
    cin >> answer_subtraction;

    if (answer_subtraction == 'y' || answer_subtraction == 'Y')
    {
        string_set arrSubtraction;

        arr_copy = arr;

        arr -= arrNew;                          //Усложнение №1(+4 балла) e.функцию вычитания одного множества из другого, которая возвращает все элементы первого множества, которых нет во втором, используя перегруженную операцию -=;

        cout << "Результат вычитания множеств string_set и string_set_new" << endl;

        cout << arr << endl;                    //a.функцию потокового вывода множества для консоли ( операция << );

        cout << endl;
        printf("Значения множества string_set:\n");
        cout << arr << endl;

        cout << endl;
        cout << "Для дальнейшей демонстрации программы вернем изначальные значения множества string_set," << endl;
        cout << "а результат вычитания присвоим множеству string_set_subtraction" << endl;

        arrSubtraction = arr;

        arr = arr_copy;

        cout << endl;
        printf("Значения множества string_set_subtraction:\n");
        cout << arrSubtraction << endl;

    }

    char answer_adding;

    valueBool = true;

    while (valueBool)
    {

        cout << endl;
        cout << "Добавить значение во множество string_set? " << endl;
        cin >> answer_adding;
        getline(cin, valueNew);

        if (answer_adding == 'y' || answer_adding == 'Y')
        {
            cout << endl;
            printf("Значения множества string_set:\n");
            cout << arr << endl;

            cout << endl;
            printf("Введите значение №%d: ", arr.size() + 1);

            getline(cin, valueNew);

            valueBool = false;

            for (int i = 0; i < arr.size(); i++)
            {
                if (valueNew == arr[i])
                {
                    valueBool = true;
                    i = arr.size();
                }
            }
            if (!valueBool)
            {
                arr + valueNew;                 //f.перегруженную функцию сложения множества с целым для добавления числа во множество;

                cout << arr;                    //a.функцию потокового вывода множества для консоли ( операция << );

                cout << endl;
                cout << endl;
                printf("Значения множества string_set:\n");
                cout << arr << endl;
            }
            else
            {
                cout << "Значение: " << valueNew << " уже есть во множестве." << endl;
                valueBool = true;
            }
        }
        else
            valueBool = false;
    }

    char answer_compare;

    cout << endl;
    cout << "Сравнить два множества string_set и string_set_new? " << endl;
    cin >> answer_compare;

    if (answer_compare == 'y' || answer_compare == 'Y')
    {

        arr == arrNew;                          //Усложнение №2(+3 балла). Реализовать перегруженную операцию сравнения с другим множеством;

    }

    return 0;
}
*/