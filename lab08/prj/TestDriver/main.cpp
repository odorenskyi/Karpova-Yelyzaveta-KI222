#include <iostream>
#include <clocale>
#include <cmath>
#include "ModulesKarpova.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"ukr");

    float x[5] = {13, 7, 0, 16, 5};
    float y[5] = {6, 3, 9, 7, 11};
    float z[5] = {2, 0, 34, 1, 9};
    float S[5] = {77.51, 14.03, 972.46, 165.71, 5465.6};

    for(int i = 0; i < 5; i ++)
    {
        float calculation = s_calculation(x[i], y[i], z[i]);
        if (roundf(calculation * 100) / 100 == S[i]){
            cout << "Testcase ¹ " << i + 1 << " - passed" << endl;
        }
        else{
            cout << "Testcase ¹ " << i + 1 << " - failed" << endl;
        }
    }
    return 0;
}
