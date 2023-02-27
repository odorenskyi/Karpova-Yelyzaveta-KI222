#include <iostream>
#include <clocale>
#include <cmath>
#include "ModulesKarpova.h"

using namespace std;

int main() {
    setlocale(LC_ALL,"ukr");

    int x, y, z;
    char a, b;

    cout << "\© Karpova Yelyzaveta" << endl;

    cout << "Введiть значення a: ";
    cin >> a;

    cout << "Введiть значення b: ";
    cin >> b;

    cout << boolalpha << (a + 5 >= b) << endl;

    cout << "Введiть значення x: ";
    cin >> x;

    cout << "X у десятковiй системi числення: " << dec << x << ", X у шiстнадцятковiй системi числення: " << hex << x << endl;

    cout << "Введiть значення y: ";
    cin >> y;

    cout << "Y у десятковiй системi числення: " << dec << y << ", Y у шiстнадцятковiй системi числення: " << hex << y << endl;

    cout << "Введiть значення z: ";
    cin >> z;

    cout << "Z у десятковiй системi числення: " << dec << z << ", Z у шiстнадцятковiй системi числення: " << hex << z << endl;

    cout << "Рузультат обчислення S: " << s_calculation(x, y, z);

    return 0;
}
