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

    // b.перегруженную операцию присваивани€ с множеством;

    string_set& operator= (const string_set& aRight);

    //c.функцию сложени€(»Ћ») двух множеств в одно, использу€ перегруженную операцию +;

    string_set operator+ (const string_set& aRight);

    //”сложнение є1(+4 балла) c.функцию сложени€(»Ћ») двух множеств в одно, использу€ перегруженную операцию +=;

    string_set operator+= (const string_set& aRight);

    //d.функцию умножени€(») двух множеств в одно, использу€ перегруженную операцию *;

    string_set operator* (const string_set& aRight);

    //”сложнение є1(+4 балла) d.функцию умножени€(») двух множеств в одно, использу€ перегруженную операцию *=;

    string_set operator*= (const string_set& aRight);

    //e.функцию вычитани€ одного множества из другого, котора€ возвращает все элементы первого множества, которых нет во втором, использу€ перегруженную операцию -;

    string_set operator- (const string_set& aRight);

    //”сложнение є1(+4 балла) e.функцию вычитани€ одного множества из другого, котора€ возвращает все элементы первого множества, которых нет во втором, использу€ перегруженную операцию -=;

    string_set operator-= (const string_set& aRight);

    //f.перегруженную функцию сложени€ множества с целым дл€ добавлени€ числа во множество;

    string_set operator+ (string& valueRight);

    //”сложнение є2(+3 балла). –еализовать перегруженную операцию сравнени€ с другим множеством;

    string_set operator== (const string_set& aRight);
};