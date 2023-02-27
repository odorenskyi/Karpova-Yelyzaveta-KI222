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

    cout << "";
    cin >> a;

    cout << "";
    cin >> b;

    cout << boolalpha << (a + 5 >= b) << endl;

    cout << "";
    cin >> x;

    cout << "" << dec << x << "" << hex << x << endl;

    cout << "";
    cin >> y;

    cout << "" << dec << y << "" << hex << y << endl;

    cout << "";
    cin >> z;

    cout << "" << dec << z << "" << hex << z << endl;

    cout << "" << s_calculation(x, y, z);

    return 0;
}
