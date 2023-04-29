#include <iostream>
#include <cctype>
#include <clocale>
#include <string>
#include <cmath>
#include "ModulesKarpova.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    while (true) {
        char data;
        char exit;
        cout << "¬ведiть h, f, d або s: ";
        cin >> data;

        switch (data) {
            case 'h':
                float x, y, z;
                cout << "¬ведiть x: ";
                cin >> x;
                cout << "¬ведiть y: ";
                cin >> y;
                cout << "¬ведiть z: ";
                cin >> z;
                cout << "s = " << s_calculation(x, y, z) << endl;
                break;
            case 'f':
                float value;
                int months;
                Deposit deposit;
                cout << "¬ведiть суму депозиту: ";
                cin >> value;
                cout << "¬ведiть строк дiњ угоди у мiс€ц€х: ";
                cin >> months;
                deposit = getPayment(value, months);
                if (deposit.dailyInterestPaid == -1 || deposit.totalInterest == -1)
                    cout << "¬ведено неправильнi данi." << endl;
                else
                    cout << "—ума щоденних нарахувань: " << deposit.dailyInterestPaid << ", сума вiдсоткiв: " << deposit.totalInterest << endl;
                break;
            case 'd': {
                string day;
                float temperatures[7];
                Temperature temperature;

                for (int i = 0; i < 7; i++) {
                    switch (i + 1) {
                        case 1:
                            day = "понедiлок";
                            break;
                        case 2:
                            day = "вiвторок";
                            break;
                        case 3:
                            day = "середу";
                            break;
                        case 4:
                            day = "четвер";
                            break;
                        case 5:
                            day = "п'€тницю";
                            break;
                        case 6:
                            day = "суботу";
                            break;
                        case 7:
                            day = "недiлю";
                            break;
                    }
                    cout << "¬ведiть температуру за шкалою ÷ельсi€ за " << day << ": ";
                    cin >> temperatures[i];
                }

                temperature = getTemperature(temperatures);
                cout << "—ередньотижнева температура за шкалою ÷ельсi€: " << round(temperature.celsiusAverage*10)/10 << ", за шкалою ‘аренгейта: " << round(temperature.farenheitAverage*10)/10 << endl;
                break;
            }
            case 's':
                int n;
                int result;
                cout << "¬ведiть N: ";
                cin >> n;
                result = Numb(n);
                if (result == -1)
                    cout << "¬ведено неправильнi данi." << endl;
                else
                    cout << "–езультат: " << result << endl;
                break;
            default:
                cout << "\a¬ведено неправильнi данi." << endl;
        }

        cout << "¬ведiть a, A або p дл€ виходу iз програми: ";
        cin >> exit;

        if (tolower(exit) == 'a' || exit == 'p')
            break;
    }

    return 0;
}
