#include <iostream>
#include <vector>
#include <string>
#include "Header.h"

using namespace std;
//Функция
// Ôóíêöèÿ äëÿ ïðîâåðêè, ÿâëÿåòñÿ ëè ñòðîêà ÷èñëîì
bool h(const string& str) {
    if (str.empty()) return false; // Ïóñòàÿ ñòðîêà íå ÿâëÿåòñÿ ÷èñëîì
    for (char ch : str) {
        if (ch < '0' || ch > '9') return false; // Ïðîâåðÿåì, ÿâëÿåòñÿ ëè ñèìâîë öèôðîé
    }
    return true; // Ñòðîêà ñîñòîèò òîëüêî èç öèôð
}

// Ôóíêöèÿ äëÿ âû÷èñëåíèÿ 2^n - 1
vector<int> calculat(int n) {
    vector<int> res(1, 1); // Íà÷àëüíîå çíà÷åíèå 2^0 = 1
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

    // Óìåíüøàåì ðåçóëüòàò íà 1
    for (size_t i = 0; i < res.size(); ++i) {
        if (res[i] > 0) {
            res[i] -= 1;
            break;
        }
        res[i] = 9; // Åñëè öèôðà áûëà 0, äåëàåì å¸ 9
    }

    return res;
}

// Ôóíêöèÿ äëÿ âûâîäà ÷èñëà èç âåêòîðà öèôð â îáðàòíîì ïîðÿäêå
void printResult(const vector<int>& result) {
    bool leadingZero = true; // Ôëàã äëÿ ïðîïóñêà âåäóùèõ íóëåé
    for (size_t i = result.size(); i > 0; --i) {
        if (leadingZero && result[i - 1] == 0) continue; // Ïðîïóñêàåì âåäóùèå íóëè
        leadingZero = false;
        cout << result[i - 1];
    }
    if (leadingZero) cout << "0"; // Åñëè âñå íóëè
    cout << endl;
}
