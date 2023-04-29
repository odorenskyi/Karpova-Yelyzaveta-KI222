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
        cout << "����i�� h, f, d ��� s: ";
        cin >> data;

        switch (data) {
            case 'h':
                float x, y, z;
                cout << "����i�� x: ";
                cin >> x;
                cout << "����i�� y: ";
                cin >> y;
                cout << "����i�� z: ";
                cin >> z;
                cout << "s = " << s_calculation(x, y, z) << endl;
                break;
            case 'f':
                float value;
                int months;
                Deposit deposit;
                cout << "����i�� ���� ��������: ";
                cin >> value;
                cout << "����i�� ����� �i� ����� � �i�����: ";
                cin >> months;
                deposit = getPayment(value, months);
                if (deposit.dailyInterestPaid == -1 || deposit.totalInterest == -1)
                    cout << "������� ����������i ���i." << endl;
                else
                    cout << "���� �������� ����������: " << deposit.dailyInterestPaid << ", ���� �i�����i�: " << deposit.totalInterest << endl;
                break;
            case 'd': {
                string day;
                float temperatures[7];
                Temperature temperature;

                for (int i = 0; i < 7; i++) {
                    switch (i + 1) {
                        case 1:
                            day = "�����i���";
                            break;
                        case 2:
                            day = "�i������";
                            break;
                        case 3:
                            day = "������";
                            break;
                        case 4:
                            day = "������";
                            break;
                        case 5:
                            day = "�'������";
                            break;
                        case 6:
                            day = "������";
                            break;
                        case 7:
                            day = "���i��";
                            break;
                    }
                    cout << "����i�� ����������� �� ������ �����i� �� " << day << ": ";
                    cin >> temperatures[i];
                }

                temperature = getTemperature(temperatures);
                cout << "��������������� ����������� �� ������ �����i�: " << round(temperature.celsiusAverage*10)/10 << ", �� ������ ����������: " << round(temperature.farenheitAverage*10)/10 << endl;
                break;
            }
            case 's':
                int n;
                int result;
                cout << "����i�� N: ";
                cin >> n;
                result = Numb(n);
                if (result == -1)
                    cout << "������� ����������i ���i." << endl;
                else
                    cout << "���������: " << result << endl;
                break;
            default:
                cout << "\a������� ����������i ���i." << endl;
        }

        cout << "����i�� a, A ��� p ��� ������ i� ��������: ";
        cin >> exit;

        if (tolower(exit) == 'a' || exit == 'p')
            break;
    }

    return 0;
}
