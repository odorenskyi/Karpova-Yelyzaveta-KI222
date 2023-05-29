#include <iostream>
#include <locale>
#include <fstream>
#include <codecvt>
#include <string>
#include "ModulesKarpova.h"

using namespace std;

string input = "input.txt";
string output = "output.txt";

bool createInput(bool error=false) {
    wofstream data;
    data.open(input);

    data.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    if (!data) {
        cout << "Помилка запису вхідних даних." << endl;
        return false;
    }

    data << L"Як парость виноградної лози, плекайте мову" << (error ? ";" : ".") << endl << L"Пильно й ненаситно політь бур'ян." << endl << L"Чистіша від сльози вона хай буде." << endl << L"Вірно і слухняно нехай вона щоразу служить вам," << endl << L"Хоч і живе своїм живим життям." << endl;

    return true;
}

bool test1_1() {
    wstring line;
    const wstring lines[5] = {L"Розробник: Karpova Elizaveta", L"Установа/організація: Центральноукраїнський національний технічний університет", L"Місто: Кропивницький", L"Країна: Україна", L"Рік розробки: 2023"};
    bool linesFound[5] = {false, false, false, false, false};
    int currentLine = 0;
    if(!createInput())
        return false;

    t10_1(input, output);

    wifstream indata;
    indata.open(output);

    indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    while (getline(indata,line)) {
        if (line.find(lines[currentLine]) != wstring::npos) {
            linesFound[currentLine] = true;
            currentLine++;
        }
        if (linesFound[0] && linesFound[1] && linesFound[2] && linesFound[3] && linesFound[4])
            return true;
    }
    return false;
}

bool test1(bool isError) {
    wstring line;

    if(!createInput(isError))
        return false;

    t10_1(input, output);

    wifstream indata;
    indata.open(output);

    indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    while (getline(indata,line)) {
        if ((isError && line.find(L"знайдені") != wstring::npos) || (!isError && line.find(L"не знайдено") != wstring::npos))
            return true;
    }

    return false;
}

bool test2_1() {
    wstring line;
    if(!createInput())
        return false;

    t10_2(input);

    wifstream indata;
    indata.open(input);

    indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    while (getline(indata,line)) {
        if (line.find(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ") != wstring::npos)
            return true;
    }

    return false;
}

bool test2_2() {
    wstring line;

    wifstream indata;
    indata.open(input);

    indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    while (getline(indata,line)) {
        if (line.find(L"Дата й час дозапису: ") != wstring::npos)
            return true;
    }

    return false;
}

bool test3(int x, int y, int z, int b, wstring s, wstring bin) {
    wstring line;
    bool firstValid = false;
    t10_3(output, x, y, z, b);

    wifstream indata;
    indata.open(output);

    indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    while (getline(indata,line)) {
        if (!firstValid && (line.find(L"s = " + s) != wstring::npos))
            firstValid = true;
        else if (firstValid && (line.find(L"b у двійковому коді: " + bin) != wstring::npos))
            return true;
    }

    return false;
}

void result(wstring description, bool value) {
    wcout << "Test " << description << " " << (value ? "passed" : "failed") << endl;
}

int main() {
    const int x[] = {13, 7, 0, 16, 5};
    const int y[] = {6, 3, 9, 7, 11};
    const int z[] = {2, 0, 34, 1, 9};
    const int b[] = {1, 3, 8, 100, 127};
    const wstring s[] = {L"77.509", L"14.0256", L"972.468", L"165.713", L"5465.64"};
    const wstring bin[] = {L"1", L"11", L"1000", L"1100100", L"1111111"};

    setlocale(LC_ALL, "");

    for (int i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                for (int j = 0; j < 3; j++) {
                    switch (j) {
                        case 0:
                            result(L"1.1 (авторська інформація)", test1_1());
                            break;
                        case 1:
                            result(L"1.2 (відсутність помилок)", test1(false));
                            break;
                        case 2:
                            result(L"1.3 (наявність помилки)", test1(true));
                    }
                }
                break;
            case 1:
                for (int j = 0; j < 2; j++) {
                    switch (j) {
                        case 0:
                            result(L"2.1 (англійська абетка)", test2_1());
                            break;
                        case 1:
                            result(L"2.2 (дата й час дозапису)", test2_2());
                    }
                }
                break;
            case 2:
                for (int j = 0; j < 5; j++) {
                    bool value = test3(x[j], y[j], z[j], b[j], s[j], bin[j]);
                    string xtmpstr = to_string(x[j]);
                    wstring xwstr(xtmpstr.begin(), xtmpstr.end());
                    string ytmpstr = to_string(y[j]);
                    wstring ywstr(ytmpstr.begin(), ytmpstr.end());
                    string ztmpstr = to_string(z[j]);
                    wstring zwstr(ztmpstr.begin(), ztmpstr.end());
                    string btmpstr = to_string(b[j]);
                    wstring bwstr(btmpstr.begin(), btmpstr.end());
                    string numtmpstr = to_string(j + 1);
                    wstring numwstr(numtmpstr.begin(), numtmpstr.end());
                    wstring description = L"3." + numwstr + L" (x = " + xwstr + L", y = " + ywstr + L", z = " + zwstr + L", b = " + bwstr + L"; очікуваний результат: s = " + s[j] + L", b у двійковому коді: " + bin[j] + L")";
                    result(description, value);
                }
        }
    }

    return 0;
}
