#include "ostream_operator_cout.h"

using namespace std;

ostream& operator << (ostream& out, string_set a)   //������� ���������� ������ ������������������ ��� ������� ( �������� << );
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << endl;
    return out;
}