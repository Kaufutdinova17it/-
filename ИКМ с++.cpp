#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления 2^n - 1
vector<int> calculat(int n) {
    vector<int> res(1, 1); // Начальное значение 2^0 = 1
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

    // Уменьшаем результат на 1
    for (size_t i = 0; i < res.size(); ++i) {
        if (res[i] > 0) {
            res[i] -= 1;
            break;
        }
        res[i] = 9; // Если цифра была 0, делаем её 9
    }

    return res;
}

// Функция для вывода числа из вектора цифр в обратном порядке
void printResult(const vector<int>& result) {
    for (size_t i = result.size(); i > 0; --i) {
        cout << result[i - 1];
    }
    cout << endl;
}

// Функция для тестирования программы
void runTests() {
    cout << "Тестирование программы:" << endl;
    int testV[] = { 41, 50, 60, 70, 80,100,1000 };
    for (int n : testV) {
        cout << "Тест: n = " << n << endl;
        vector<int> result = calculat(n);
        cout << "Результат (2^" << n << " - 1): ";
        printResult(result);
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите значение n (n > 40): ";
    while (true) {
        cin >> n;
        if (cin.fail() || n <= 40) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Пожалуйста, введите число больше 40: ";
        }
        else {
            break;
        }
    }

    vector<int> result = calculat(n);
    cout << "Результат (2^" << n << " - 1): ";
    printResult(result);

    runTests();

    return 0;
}
