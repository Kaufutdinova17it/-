#include <iostream>
#include <vector>
#include <string>
#include "Header.h"

using namespace std;

// ������� ��� ��������, �������� �� ������ ������
bool h(const string& str) {
    if (str.empty()) return false; // ������ ������ �� �������� ������
    for (char ch : str) {
        if (ch < '0' || ch > '9') return false; // ���������, �������� �� ������ ������
    }
    return true; // ������ ������� ������ �� ����
}

// ������� ��� ���������� 2^n - 1
vector<int> calculat(int n) {
    vector<int> res(1, 1); // ��������� �������� 2^0 = 1
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

    // ��������� ��������� �� 1
    for (size_t i = 0; i < res.size(); ++i) {
        if (res[i] > 0) {
            res[i] -= 1;
            break;
        }
        res[i] = 9; // ���� ����� ���� 0, ������ � 9
    }

    return res;
}

// ������� ��� ������ ����� �� ������� ���� � �������� �������
void printResult(const vector<int>& result) {
    bool leadingZero = true; // ���� ��� �������� ������� �����
    for (size_t i = result.size(); i > 0; --i) {
        if (leadingZero && result[i - 1] == 0) continue; // ���������� ������� ����
        leadingZero = false;
        cout << result[i - 1];
    }
    if (leadingZero) cout << "0"; // ���� ��� ����
    cout << endl;
}
