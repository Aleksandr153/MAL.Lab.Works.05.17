#pragma once

#include <string>

using namespace std;

class string_set
{
private:
    int m_size;
    int m_capacity;
    string* m_data;

public:
    string_set();

    string_set(const string_set& a);

    string_set(int size);

    ~string_set();

    void resize(int size);

    void push_back(string val);

    int size() const;

    string& operator[] (int i);

    char search_in_array(string_set array, int number_of_elements, string search_number);

    // b.������������� �������� ������������ � ����������;

    string_set& operator= (const string_set& aRight);

    //c.������� ��������(���) ���� �������� � ����, ��������� ������������� �������� +;

    string_set operator+ (const string_set& aRight);

    //���������� �1(+4 �����) c.������� ��������(���) ���� �������� � ����, ��������� ������������� �������� +=;

    string_set operator+= (const string_set& aRight);

    //d.������� ���������(�) ���� �������� � ����, ��������� ������������� �������� *;

    string_set operator* (const string_set& aRight);

    //���������� �1(+4 �����) d.������� ���������(�) ���� �������� � ����, ��������� ������������� �������� *=;

    string_set operator*= (const string_set& aRight);

    //e.������� ��������� ������ ��������� �� �������, ������� ���������� ��� �������� ������� ���������, ������� ��� �� ������, ��������� ������������� �������� -;

    string_set operator- (const string_set& aRight);

    //���������� �1(+4 �����) e.������� ��������� ������ ��������� �� �������, ������� ���������� ��� �������� ������� ���������, ������� ��� �� ������, ��������� ������������� �������� -=;

    string_set operator-= (const string_set& aRight);

    //f.������������� ������� �������� ��������� � ����� ��� ���������� ����� �� ���������;

    string_set operator+ (string& valueRight);

    //���������� �2(+3 �����). ����������� ������������� �������� ��������� � ������ ����������;

    string_set operator== (const string_set& aRight);
};