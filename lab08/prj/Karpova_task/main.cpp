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

    cout << "\© Karpova Elizaveta" << endl;

    cout << "¬вед≥ть значенн€ a: ";
    cin >> a;

    cout << "¬вед≥ть значенн€ b: ";
    cin >> b;

    cout << boolalpha << (a + 5 >= b) << endl;

    cout << "¬вед≥ть значенн€ x: ";
    cin >> x;

    cout << "X у дес€тков≥й систем≥ численн€: " << dec << x << ", ’ у ш≥стнадц€тков≥й систем≥ численн€: " << hex << x << endl;

    cout << "¬вед≥ть значенн€ y: ";
    cin >> y;

    cout << "Y у дес€тков≥й систем≥ численн€: " << dec << y << ", Y у ш≥стнадц€тков≥й систем≥ численн€: " << hex << y << endl;

    cout << "¬вед≥ть значенн€ z: ";
    cin >> z;

    cout << "Z у дес€тков≥й систем≥ численн€: " << dec << z << ", Z у ш≥стнадц€тков≥й систем≥ численн€: " << hex << z << endl;

    cout << "–езультат обчисленн€ S: " << s_calculation(x, y, z);

    return 0;
}
