#include <iostream>
#include <cmath>

float s_calculation(float x, float y, float z){

    float S;
    float e = 2.71828;

    S = sqrt(fabs(pow(z, 2.0) * (1.0/2.0) * y)) +((M_PI * x + (pow(e, fabs(y)))) / y);

    return S;
}
