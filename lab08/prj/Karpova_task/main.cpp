#include <iostream>
#include <windows.h>
#include <cmath>
#include "ModulesKarpova.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int x, y, z;
    char a, b;

    cout << "\� Karpova Elizaveta" << endl;

    cout << "������ �������� a: ";
    cin >> a;

    cout << "������ �������� b: ";
    cin >> b;

    cout << boolalpha << (a + 5 >= b) << endl;

    cout << "������ �������� x: ";
    cin >> x;

    cout << "X � ��������� ������ ��������: " << dec << x << ", � � �������������� ������ ��������: " << hex << x << endl;

    cout << "������ �������� y: ";
    cin >> y;

    cout << "Y � ��������� ������ ��������: " << dec << y << ", Y � �������������� ������ ��������: " << hex << y << endl;

    cout << "������ �������� z: ";
    cin >> z;

    cout << "Z � ��������� ������ ��������: " << dec << z << ", Z � �������������� ������ ��������: " << hex << z << endl;

    cout << "��������� ���������� S: " << s_calculation(x, y, z);

    return 0;
}
