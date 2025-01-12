#include <iostream>
#include <vector>
#include <string>
#include "Header.h"

using namespace std;

//Функция для проверки является ли строчка числом
bool h(const string& str) {
    if (str.empty()) return false; //Пустая строчка не является числом
    for (char ch : str) {
        if (ch < '0' || ch > '9') return false; //проверяем является ли символ цифрой
    }
    return true; //Если строка состоит только из цифр
}

//Функция для вычисления 2^n - 1
vector<int> calculat(int n) {
    vector<int> res(1, 1); //Начальное значение 2^0 = 1
    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (size_t j = 0; j < res.size(); ++j) {
            int temp = res[j] * 2 + c;
            res[j] = temp % 10;
            c = temp / 10;
        }
        while (c > 0) {
            res.push_back(c % 10);
            c /= 10;
        }
    }

    //Уменьшаем результат на  1
    for (size_t i = 0; i < res.size(); ++i) {
        if (res[i] > 0) {
            res[i] -= 1;
            break;
        }
        res[i] = 9; // Если цифра была 0 делаем ее 9
    }

    return res;
}

//Функция для вывода числа из вектора цифр в обратном порядке
void printResult(const vector<int>& result) {
    bool leadingZero = true; //Флаг для пропуска ведущих нулей 
    for (size_t i = result.size(); i > 0; --i) {
        if (leadingZero && result[i - 1] == 0) continue; //Пропускаем ведущие нули
        leadingZero = false;
        cout << result[i - 1];
    }
    if (leadingZero) cout << "0"; //Если все нули
    cout << endl;
}
