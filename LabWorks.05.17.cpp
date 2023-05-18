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

17. ����������������� (��� �����������) ����� ���������� �����.

����������� ���������, ������� ���������� ��� ����� �� ������ ������������ �:
a. ������� ��� ���������� � ������ ���� ��� �����/������, ������� ���� � � ������ � �� ������ ������;
b. ������� ��� ���������� � ������ ���� ��� �����/������, ������� ���� � ������/������ �����, �� ������� ��� �� ������/������ �����.

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
    printf("�������� ��������� stringSet1:\n");
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
    printf("�������� ��������� stringSet2:\n");
    cout << stringSet2 << endl;

    stringSetResultMultiplication = stringSet1 * stringSet2;

    cout << endl;
    printf("�������� ��������� stringSetResultMultiplication:\n");
    cout << stringSetResultMultiplication << endl;

    ofstream outputM("stringSetResultMultiplication.txt");
    if (outputM)
        outputM << stringSetResultMultiplication << endl;
    outputM.close();

    stringSetResultSubtraction12 = stringSet1 - stringSet2;

    cout << endl;
    printf("�������� ��������� stringSetResultSubtraction12:\n");
    cout << stringSetResultSubtraction12 << endl;

    ofstream outputS12("stringSetResultSubtraction12.txt");
    if (outputS12)
        outputS12 << stringSetResultSubtraction12 << endl;
    outputS12.close();

    stringSetResultSubtraction21 = stringSet2 - stringSet1;

    cout << endl;
    printf("�������� ��������� stringSetResultSubtraction21:\n");
    cout << stringSetResultSubtraction21 << endl;

    ofstream outputS21("stringSetResultSubtraction21.txt");
    if (outputS21)
        outputS21 << stringSetResultSubtraction21 << endl;
    outputS21.close();

    return 0;
}

// ������������ ������ "����������������� (��� �����������) ����� ���������� �����".
/*

    string valueNew;
    bool valueBool = false;

    string_set arr;
    int sizeDA;

    cout << "������� ������ ���������: ";
    cin >> sizeDA;                             // ��������� �� ������������ ������� �������
    getline(cin, valueNew);

    arr.resize(sizeDA);

    for (int i = 0; i < arr.size(); i++)
    {
        printf("������� �������� �%d: ", i);

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
            cout << "��������: " << valueNew << " ��� ���� �� ���������." << endl;
            i--;
        }
    }

    cout << endl;
    printf("�������� ��������� string_set:\n");
    cout << arr << endl;

    string searchDA;

    cout << endl;
    cout << "������� ��������, ������� �� ������ ����� � ���������: " << endl;
    getline(cin, searchDA);                         // ��������� �� ������������ �������� �������� �������

    char answer;

    answer = arr.search_in_array(arr, arr.size(), searchDA);

    if (answer == 'y' || answer == 'Y')
    {
        arr.push_back(searchDA);

        cout << endl;
        printf("�������� ��������� string_set:\n");
        cout << arr << endl;
    }

    string_set arr_copy;
    char answer_copy;

    cout << endl;
    cout << "������ ������� ����� ��������� string_set? y/n" << endl;
    cin >> answer_copy;                         // ��������� �� ������������ ������ ���������� ��� ���

    if (answer_copy == 'y' || answer_copy == 'Y')
    {
        string_set arr_copy = arr;

        cout << endl;
        printf("�������� ��������� string_set_copy:\n");
        cout << arr_copy << endl;
    }

    string_set arrNew;
    int sizeDAN;

    cout << endl;
    cout << "������� ������ ������, ������� ��������� string_set_new: ";
    cin >> sizeDAN;                             // ��������� �� ������������ ������� �������
    getline(cin, valueNew);

    arrNew.resize(sizeDAN);

    for (int i = 0; i < arrNew.size(); i++)
    {
        //valueNew = nullptr;
        printf("������� �������� ��������� string_set_new �%d: ", i);
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
            cout << "��������: " << valueNew << " ��� ���� �� ��������� ��������� string_set_new." << endl;
            i--;
        }
    }

    cout << endl;
    printf("�������� ��������� string_set_new:\n");
    cout << arrNew << endl;

    char answer_assignment;

    cout << endl;
    cout << "��������� �������� ��������� string_set ��������� string_set_new? " << endl;
    cin >> answer_assignment;                   // ��������� �� ������������ ������ ����������� ��� ���

    if (answer_assignment == 'y' || answer_assignment == 'Y')
    {
        arr_copy = arrNew;

        arrNew = arr;                           // b.������������� �������� ������������ � ����������;

        cout << "��������� ������������ �������� string_set � string_set_new" << endl;

        cout << arrNew << endl;                 //a.������� ���������� ������ ��������� ��� ������� ( �������� << );

        cout << endl;
        printf("�������� ��������� string_set_new:\n");
        cout << arrNew << endl;

        cout << endl;
        cout << "��� ���������� ������������ ��������� ������ ����������� �������� ��������� string_set_new" << endl;

        arrNew = arr_copy;

        cout << endl;
        printf("�������� ��������� string_set_new:\n");
        cout << arrNew << endl;
    }

    char answer_plus;

    cout << endl;
    cout << "������� (+) �������� ��������� string_set � ��������� string_set_new? " << endl;
    cin >> answer_plus;                         // ��������� �� ������������ ������ ���������� ��� ���

    if (answer_plus == 'y' || answer_plus == 'Y')
    {
        cout << "��������� �������� �������� string_array � string_array_new" << endl;;

        cout << arr + arrNew << endl;           //c.������� ��������(���) ���� �������� � ����, ��������� ������������� �������� +;

    }

    cout << endl;
    cout << "������� � ��������� (+=) �������� ��������� string_set � ��������� string_set_new? " << endl;
    cin >> answer_plus;                         // ��������� �� ������������ ������ ���������� � ����������� ��� ���

    if (answer_plus == 'y' || answer_plus == 'Y')
    {
        string_set arrPlus;

        arr_copy = arr;

        arr += arrNew;                          //���������� �1(+4 �����) c.������� ��������(���) ���� �������� � ����, ��������� ������������� �������� +=;

        cout << "��������� �������� �������� string_set � string_set_new" << endl;

        cout << arr << endl;                    //a.������� ���������� ������ ��������� ��� ������� ( �������� << );

        cout << endl;
        printf("�������� ��������� string_set:\n");
        cout << arr << endl;

        cout << endl;
        cout << "��� ���������� ������������ ��������� ������ ����������� �������� ��������� string_set," << endl;
        cout << "� ��������� �������� �������� ��������� string_set_plus" << endl;

        arrPlus = arr;

        arr = arr_copy;

        cout << endl;
        printf("�������� ��������� string_set_plus:\n");
        cout << arrPlus << endl;
    }

    char answer_multiplication;

    cout << endl;
    cout << "�������� (*) �������� ��������� string_set � ��������� string_set_new? " << endl;
    cin >> answer_multiplication;               // ��������� �� ������������ ������ �������� ��� ���

    if (answer_multiplication == 'y' || answer_multiplication == 'Y')
    {
        cout << "��������� �������� �������� string_set � string_set_new" << endl;;

        cout << arr * arrNew << endl;           //d.������� ���������(�) ���� �������� � ����, ��������� ������������� �������� *;

    }

    cout << endl;
    cout << "�������� � ��������� (*=) �������� ��������� string_set � ��������� string_set_new? " << endl;
    cin >> answer_multiplication;               // ��������� �� ������������ ������ �������� � ����������� ��� ���

    if (answer_multiplication == 'y' || answer_multiplication == 'Y')
    {
        string_set arrMultiplication;

        arr_copy = arr;

        arr *= arrNew;                           //���������� �1(+4 �����) d.������� ���������(�) ���� �������� � ����, ��������� ������������� �������� *=;

        cout << "��������� ��������� �������� string_set � string_set_new" << endl;

        cout << arr << endl;                    //a.������� ���������� ������ ��������� ��� ������� ( �������� << );

        cout << endl;
        printf("�������� ��������� string_set:\n");
        cout << arr << endl;

        cout << endl;
        cout << "��� ���������� ������������ ��������� ������ ����������� �������� ��������� string_set," << endl;
        cout << "� ��������� ��������� �������� ��������� string_set_multiplication" << endl;

        arrMultiplication = arr;

        arr = arr_copy;

        cout << endl;
        printf("�������� ��������� string_set_multiplication:\n");
        cout << arrMultiplication << endl;
    }

    char answer_subtraction;

    cout << endl;
    cout << "������� (-) �������� ��������� string_set �� ��������� string_set_new? " << endl;
    cin >> answer_subtraction;

    if (answer_subtraction == 'y' || answer_subtraction == 'Y')
    {
        cout << "��������� ��������� �������� string_set � string_set_new" << endl;;

        cout << arr - arrNew << endl;           //e.������� ��������� ������ ��������� �� �������, ������� ���������� ��� �������� ������� ���������, ������� ��� �� ������, ��������� ������������� �������� - ;

    }

    cout << endl;
    cout << "������� � ��������� (-=) �������� ��������� string_set �� ��������� string_set_new? " << endl;
    cin >> answer_subtraction;

    if (answer_subtraction == 'y' || answer_subtraction == 'Y')
    {
        string_set arrSubtraction;

        arr_copy = arr;

        arr -= arrNew;                          //���������� �1(+4 �����) e.������� ��������� ������ ��������� �� �������, ������� ���������� ��� �������� ������� ���������, ������� ��� �� ������, ��������� ������������� �������� -=;

        cout << "��������� ��������� �������� string_set � string_set_new" << endl;

        cout << arr << endl;                    //a.������� ���������� ������ ��������� ��� ������� ( �������� << );

        cout << endl;
        printf("�������� ��������� string_set:\n");
        cout << arr << endl;

        cout << endl;
        cout << "��� ���������� ������������ ��������� ������ ����������� �������� ��������� string_set," << endl;
        cout << "� ��������� ��������� �������� ��������� string_set_subtraction" << endl;

        arrSubtraction = arr;

        arr = arr_copy;

        cout << endl;
        printf("�������� ��������� string_set_subtraction:\n");
        cout << arrSubtraction << endl;

    }

    char answer_adding;

    valueBool = true;

    while (valueBool)
    {

        cout << endl;
        cout << "�������� �������� �� ��������� string_set? " << endl;
        cin >> answer_adding;
        getline(cin, valueNew);

        if (answer_adding == 'y' || answer_adding == 'Y')
        {
            cout << endl;
            printf("�������� ��������� string_set:\n");
            cout << arr << endl;

            cout << endl;
            printf("������� �������� �%d: ", arr.size() + 1);

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
                arr + valueNew;                 //f.������������� ������� �������� ��������� � ����� ��� ���������� ����� �� ���������;

                cout << arr;                    //a.������� ���������� ������ ��������� ��� ������� ( �������� << );

                cout << endl;
                cout << endl;
                printf("�������� ��������� string_set:\n");
                cout << arr << endl;
            }
            else
            {
                cout << "��������: " << valueNew << " ��� ���� �� ���������." << endl;
                valueBool = true;
            }
        }
        else
            valueBool = false;
    }

    char answer_compare;

    cout << endl;
    cout << "�������� ��� ��������� string_set � string_set_new? " << endl;
    cin >> answer_compare;

    if (answer_compare == 'y' || answer_compare == 'Y')
    {

        arr == arrNew;                          //���������� �2(+3 �����). ����������� ������������� �������� ��������� � ������ ����������;

    }

    return 0;
}
*/