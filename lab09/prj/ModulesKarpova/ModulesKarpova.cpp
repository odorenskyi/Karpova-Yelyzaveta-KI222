#include <cmath>
#include <string>
#include "ModulesKarpova.h"

using namespace std;

float s_calculation(float x, float y, float z){

    float S;
    float e = 2.71828;
    if(y != 0)
        return sqrt(fabs(pow(z, 2.0) * (1.0/2.0) * y)) +((M_PI * x + (pow(e, fabs(y)))) / y);
    else
        return NAN;
}

Deposit getPayment(float value, int months) {
    Deposit deposit;
    if (months == 6 || months == 12) {
        float interest;
        deposit.totalInterest = months == 12 ? 27 : 19.5/(float)2;
        interest = deposit.totalInterest / months / 30;
        deposit.dailyInterestPaid = value*(interest/100.0);
    } else {
        deposit.dailyInterestPaid = -1;
        deposit.totalInterest = -1;
    }
    return deposit;
}

Temperature getTemperature(float temperatures[7]) {
    Temperature temperature;
    float sum = 0;
    for (int i = 0; i < 7; i++)
        sum += temperatures[i];
    temperature.celsiusAverage = sum/7.0;
    temperature.farenheitAverage = 32 + (9/5.0) * temperature.celsiusAverage;
    return temperature;
}

int Numb(int number) {
    unsigned int count = 0;
    if (number > 0 || number <= 17948360) {
        bool set = !((number >> 9) & 1);
        while (number) {
            count += (number & 1) == set;
            number >>= 1;
        }
    } else {
        return -1;
    }
    return count;
}
