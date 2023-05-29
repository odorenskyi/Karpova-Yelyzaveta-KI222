#include <cmath>
#include <ctime>
#include <string>
#include <fstream>
#include <codecvt>
#include <bitset>
#include <limits>
#include "ModulesKarpova.h"

using namespace std;

wstring punctuation = L".,!\";:?()[]{}";

float s_calculation(float x, float y, float z) {
    if (y != 0)
        return sqrt(fabs(pow(z, 2.0) * (1.0/2.0) * y)) + ((M_PI * x + (pow(M_E, fabs(y)))) / y);
    else
        return NAN;
}

int t10_1(string inputFile, string outputFile) {
    wstring line;
    bool error = false;
    int lineNumber = 0;

    wifstream indata;
    indata.open(inputFile);
    ofstream outdata;
    outdata.open(outputFile);

    if (!indata || !outdata)
        return 1;

    indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    while (!error && lineNumber < 5 && getline(indata,line)) {
        lineNumber++;
	int length = line.length();

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < 13; j++) {
                if (line[i] == punctuation[j]) {
                    if ((lineNumber == 1 && i == 27) || (lineNumber == 4 && i == 46)) {
                        if (j != 1)
                            error = true;
                    } else if ((lineNumber == 1 && i == 42) || (lineNumber == 2 && i == 32) || (lineNumber == 3 && i == 32) || (lineNumber == 5 && i == 29)) {
                        if (j != 0)
                            error = true;
                    } else
                        error = true;

                    break;
                }
            }
            if (error)
                break;
        }
    }

    outdata << "Розробник: Karpova Elizaveta" << endl << "Установа/організація: Центральноукраїнський національний технічний університет" << endl << "Місто: Кропивницький" << endl << "Країна: Україна" << endl << "Рік розробки: 2023" << endl << endl;

    srand(time(NULL));
    outdata << "Випадкове число від 10 до 100: " << rand() % 91 + 10 << endl;

    outdata << "У вхідному файлі " << (error ? "знайдені пунктуаційні помилки" : "не знайдено пунктуаційних помилок") << "." << endl;

    return 0;
}

int t10_2(string file) {
    time_t rawtime;
    time(&rawtime);

    wifstream indata;
    indata.open(file);
    ofstream outdata;
    outdata.open(file, ios_base::app);

    if (!indata || !outdata)
        return 1;

    indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    for (int i = 65; i <= 90; i++)
        outdata << char(i);

    outdata << endl << "Дата й час дозапису: " << ctime(&rawtime);
    return 0;
}

int t10_3(string file, int x, int y, int z, int b) {
    ofstream data;
    data.open(file, ios_base::app);

    if (!data)
        return 1;

    data << endl << "s = " << s_calculation(x, y, z) << endl;
    if (b > 0) {
        string binary = bitset<numeric_limits<int>::digits>(b).to_string();
        binary.erase(0, binary.find_first_not_of('0'));
        data << "b у двійковому коді: " << binary << endl;
    }
    else
        data << "b — не натуральне число" << endl;

    return 0;
}
