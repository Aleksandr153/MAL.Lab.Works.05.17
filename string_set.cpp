#include <crtdbg.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "string_set.h"

using namespace std;

string_set::string_set()
{
    m_size = 0;
    m_capacity = 0;
    m_data = nullptr;
}

string_set::string_set(const string_set& a)
{
    m_size = a.m_size;
    m_capacity = m_size;
    m_data = nullptr;
    if (m_size != 0)
        m_data = new string[m_size];
    else
        m_data = 0;
    for (int i = 0; i < m_size; ++i)
        m_data[i] = a.m_data[i];
}

string_set::string_set(int size)
{
    m_size = size;
    m_capacity = size;
    if (size != 0)
        m_data = new string[size];
    else
        m_data = 0;
}

string_set::~string_set()
{
    if (m_data)
        delete[] m_data;
}

void string_set::resize(int size)
{
    if (size > m_capacity)
    {
        int new_capacity = max(size, m_size * 2);
        string* new_data = new string[new_capacity];
        for (int i = 0; i < m_size; ++i)
            new_data[i] = m_data[i];
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
    m_size = size;
}

void string_set::push_back(string val)
{
    resize(m_size + 1);
    m_data[m_size - 1] = val;
}

int string_set::size() const
{
    return m_size;
}

string& string_set::operator[] (int i)
{
    return m_data[i];
}

char string_set::search_in_array(string_set array, int number_of_elements, string search_number)
{
    int j = 0;
    int k = 0;
    char awr = 'n';

    for (int i = 0; i < number_of_elements; i++)
        if (search_number == array[i])
            j = j + 1;
    if (j > 0)
    {
        string_set new_arr;
        new_arr.resize(j);
        for (int i = 0; i < number_of_elements; i++)
            if (search_number == array[i])
            {
                new_arr[k] = i;
                k = k + 1;
            }
        for (int k = 0; k < new_arr.size(); k++)
            cout << "������� ������� ������ �� ��������� ��� �������: " << new_arr[k] << " " << endl;
    }
    else
    {
        cout << "������� ������� ������ �� ��������� �� ������" << endl;
        cout << "������ �������� ������� �� ���������? y/n" << endl;
        cin >> awr;
    }
    return awr;
}

// b.������������� �������� ������������ � ����������;

string_set& string_set::operator= (const string_set& aRight)
{
    if (this != &aRight)
    {
        this->resize(aRight.size());
        for (int i = 0; i < aRight.size(); ++i)
            m_data[i] = aRight.m_data[i];
    }
    return *this;
}

//c.������� ��������(���) ���� �������� � ����, ��������� ������������� �������� +;

string_set string_set::operator+ (const string_set& aRight)
{
    bool elementsBool = false;
    string_set arrTemp;
    arrTemp = *this;
    for (int i = 0; i < aRight.size(); ++i)
    {
        elementsBool = false;
        for (int j = 0; j < this->size(); ++j)
            if (aRight.m_data[i] == this->m_data[j])
                elementsBool = true;
        if (!elementsBool)
            arrTemp.push_back(aRight.m_data[i]);
    }
    return string_set(arrTemp);
}

//���������� �1(+4 �����) c.������� ��������(���) ���� �������� � ����, ��������� ������������� �������� +=;

string_set string_set::operator+= (const string_set& aRight)
{
    bool elementsBool = false;
    string_set arrTemp;
    arrTemp = *this;
    for (int i = 0; i < aRight.size(); ++i)
    {
        elementsBool = false;
        for (int j = 0; j < this->size(); ++j)
            if (aRight.m_data[i] == this->m_data[j])
                elementsBool = true;
        if (!elementsBool)
            arrTemp.push_back(aRight.m_data[i]);
    }
    *this = arrTemp;
    return *this;
}

//d.������� ���������(�) ���� �������� � ����, ��������� ������������� �������� *;

string_set string_set::operator* (const string_set& aRight)
{
    bool elementsBool = false;
    string_set arrTemp;
    for (int i = 0; i < aRight.size(); ++i)
    {
        elementsBool = false;
        for (int j = 0; j < this->size(); ++j)
            if (aRight.m_data[i] == m_data[j])
                elementsBool = true;
        if (elementsBool)
            arrTemp.push_back(aRight.m_data[i]);
    }
    return string_set(arrTemp);
}

//���������� �1(+4 �����) d.������� ���������(�) ���� �������� � ����, ��������� ������������� �������� *=;

string_set string_set::operator*= (const string_set& aRight)
{
    bool elementsBool = false;
    string_set arrTemp;
    for (int i = 0; i < aRight.size(); ++i)
    {
        elementsBool = false;
        for (int j = 0; j < this->size(); ++j)
            if (aRight.m_data[i] == m_data[j])
                elementsBool = true;
        if (elementsBool)
            arrTemp.push_back(aRight.m_data[i]);
    }
    *this = arrTemp;
    return *this;
}

//e.������� ��������� ������ ��������� �� �������, ������� ���������� ��� �������� ������� ���������, ������� ��� �� ������, ��������� ������������� �������� -;

string_set string_set::operator- (const string_set& aRight)
{
    bool elementsBool = false;
    string_set arrTemp;

    for (int i = 0; i < this->size(); ++i)
    {
        bool elementsBool = false;
        for (int j = 0; j < aRight.size(); ++j)
        {
            if (m_data[i] == aRight.m_data[j])
                elementsBool = true;
        }
        if (!elementsBool)
        {
            arrTemp.push_back(m_data[i]);
        }
    }
    return string_set(arrTemp);
}

//���������� �1(+4 �����) e.������� ��������� ������ ��������� �� �������, ������� ���������� ��� �������� ������� ���������, ������� ��� �� ������, ��������� ������������� �������� -=;

string_set string_set::operator-= (const string_set& aRight)
{
    bool elementsBool = false;
    string_set arrTemp;

    for (int i = 0; i < this->size(); ++i)
    {
        bool elementsBool = false;
        for (int j = 0; j < aRight.size(); ++j)
        {
            if (m_data[i] == aRight.m_data[j])
                elementsBool = true;
        }
        if (!elementsBool)
        {
            arrTemp.push_back(m_data[i]);
        }
    }
    *this = arrTemp;
    return *this;
}

//f.������������� ������� �������� ��������� � ����� ��� ���������� ����� �� ���������;

string_set string_set::operator+ (string& valueRight)
{
    bool elementsBool = false;
    string_set arrTemp;
    arrTemp = *this;
    for (int i = 0; i < this->size(); ++i)
        if (m_data[i] == valueRight)
            elementsBool = true;
    if (!elementsBool)
        arrTemp.push_back(valueRight);
    else
        cout << "��������: " << valueRight << " ��� ���� �� ���������." << endl;
    *this = arrTemp;
    return *this;
}

//���������� �2(+3 �����). ����������� ������������� �������� ��������� � ������ ����������;

string_set string_set::operator== (const string_set& aRight)
{
    bool elementsBool = false;
    bool elementsPower = false;
    bool elementsEqual = false;

    if (this->size() == aRight.size())
    {
        elementsPower = true;
        if (elementsPower)
        {
            for (int i = 0; i < this->size(); ++i)
            {
                elementsBool = false;
                for (int j = 0; j < aRight.size(); ++j)
                    if (m_data[i] == aRight.m_data[j])
                    {
                        elementsBool = true;
                        elementsEqual = true;
                    }
                if (!elementsBool)
                {
                    elementsEqual = false;
                    i = this->size();
                }
            }
        }
        if (elementsEqual)
        {
            cout << endl;
            cout << "��������� string_set � string_set_new �����." << endl;
        }
        else
        {
            cout << endl;
            cout << "��������� string_set � string_set_new �����������, �� �� �����." << endl;
        }
    }
    else
    {
        cout << endl;
        cout << "��������� string_set � string_set_new �� �����." << endl;
    }


    return *this;
}