#ifndef MODULESKARPOVA_H_INCLUDED
#define MODULESKARPOVA_H_INCLUDED

float s_calculation(float, float, float);

typedef struct Deposit {
    float dailyInterestPaid;
    float totalInterest;
} Deposit;

typedef struct Temperature {
    float celsiusAverage;
    float farenheitAverage;
} Temperature;

Deposit getPayment(float, int);

Temperature getTemperature(float[7]);

int Numb(int number);

#endif // MODULESKARPOVA_H_INCLUDED
