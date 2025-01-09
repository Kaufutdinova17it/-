#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n;

    while (true) {
        cout << "Введите значение n (n > 40): ";
        string input;
        getline(cin, input); // Читаем всю строку

        // Проверяем на корректность ввода
        if (!h(input)) {
            cout << "Ошибка: Пожалуйста, введите корректное число без пробелов: ";
            continue;
        }

        n = 0;
        for (char ch : input) {
            n = n * 10 + (ch - '0'); // Преобразуем строку в число
        }

        if (n <= 40) {
            cout << "Ошибка: Пожалуйста, введите число больше 40: ";
        }
        else {
            break; // Ввод корректен
        }
    }

    vector<int> result = calculat(n);
    cout << "Результат (2^" << n << " - 1): ";
    printResult(result);

    return 0;
}

