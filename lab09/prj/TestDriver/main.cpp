#include "ModulesKarpova.h"
#include <iostream>
#include <clocale>
#include <limits>

using namespace std;

bool test_1(float value, int months, float interest, float paid) {
    Deposit deposit;
    deposit = getPayment(value, months);
    if (deposit.dailyInterestPaid == paid && deposit.totalInterest == interest)
        return true;
    else {
        cout << endl << "Очікуваний результат: Сума щоденних нарахувань: " << paid << ", сума відсотків: " << interest << endl << "Отриманий результат: Сума щоденних нарахувань: " << deposit.dailyInterestPaid << ", сума відсотків: " << deposit.totalInterest << endl;
        return false;
    }
}

bool test_2(float value[7], float celsius, float farenheit) {
    Temperature temperature = getTemperature(value);
    if (temperature.celsiusAverage == celsius && temperature.farenheitAverage == farenheit)
        return true;
    else {
        cout << endl << "Очікуваний результат: Середньотижнева температура за шкалою Цельсія: " << celsius << ", за шкалою Фаренгейта: " << farenheit << endl << "Отриманий результат: Середньотижнева температура за шкалою Цельсія: " << temperature.celsiusAverage << ", за шкалою Фаренгейта: " << temperature.farenheitAverage << endl;
        return false;
    }
}

bool test_3(float n, int count) {
    int result = Numb(n);
    if (result == count)
        return true;
    else {
        cout << endl << "Очікуваний результат: " << count << endl << "Отриманий результат: " << result << endl;
        return false;
    }
}

int main() {
    float value[5] = {1000, 1000.25, 10, 5000, 10000};
    int months[5] = {6, 12, 6, 12, 6};
    float interest[5] = {9.75, 27, 9.75, 27, 9.75};
    float paid[5] = {0.541666686534882, 0.750187516212463, 0.00541666662320495, 3.75000023841858, 5.41666650772095};

    float temperatures[5][7] = {
        {1, 2, 3, 4, 5, 6, 7},
        {10, 15, 10, 13, 20, 15, 10},
        {0, -1, 1, 2, -2, 3, -1},
        {10, 30, 20, 10, 25, 34, 24},
        {5, 7, 9, 4, 2, 6, 10}
    };
    float celsius[5] = {4, 13.2857141494751, 0.28571429848671, 21.8571434020996,  6.14285707473755};
    float farenheit[5] = {39.2000007629395, 55.9142837524414, 32.5142860412598, 71.3428573608398, 43.0571441650391};

    int n[5] = {1023, 1024, 1025, 1026, 1027};
    int result_3[5] = {0, 1, 2, 2, 3};

    cout.precision(std::numeric_limits<double>::digits10);

    setlocale(LC_ALL, "");

    for (int i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                for (int j = 0; j < 5; j++) {
                    cout << "Test " << i + 1 << "." << j + 1 << " (сума депозиту: " << value[j] << ", кількість місяців: " << months[j] << ", сума щоденних нарахувань: " << paid[j] << ", сума відсотків: " << interest[j] << ") ";
                    test_1(value[j], months[j], interest[j], paid[j])
                    ? cout << "passed"
                    : cout << "failed";
                    cout << endl;
                }
                break;
            case 1:
                for (int j = 0; j < 5; j++) {
                    cout << "Test " << i + 1 << "." << j + 1 << " (температура за: ";
                    for (int k = 0; k < 7; k++) {
                        switch (k + 1) {
                            case 1:
                                cout << "понеділок";
                                break;
                            case 2:
                                cout << "вівторок";
                                break;
                            case 3:
                                cout << "середу";
                                break;
                            case 4:
                                cout << "четвер";
                                break;
                            case 5:
                                cout << "п'ятницю";
                                break;
                            case 6:
                                cout << "суботу";
                                break;
                            case 7:
                                cout << "неділю";
                                break;
                        }
                        cout << ": " << temperatures[j][k] << ", ";
                    }
                    cout << "середньотижнева температура за шкалою Цельсія: " << celsius[j] << ", середньотижнева температура за шкалою Фаренгейта: " << farenheit[j] << ") ";
                    test_2(temperatures[j], celsius[j], farenheit[j])
                    ? cout << "passed"
                    : cout << "failed";
                    cout << endl;
                }
                break;
            case 2:
                for (int j = 0; j < 5; j++) {
                    cout << "Test " << i + 1 << "." << j + 1 << " (n = " << n[j] << ", результат = " << result_3[j] << ") ";
                    test_3(n[j], result_3[j])
                    ? cout << "passed"
                    : cout << "failed";
                    cout << endl;
                }
                break;
        }

    }

    return 0;
}
