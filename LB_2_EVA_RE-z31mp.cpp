#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const vector<double> freqs = {8.08, 1.67, 3.18, 3.99, 12.56, 2.17, 1.80, 5.27, 7.24, 0.14, 0.63, 4.04, 2.60, 7.38, 7.47, 1.91, 0.09, 6.42, 6.59, 9.15, 2.79, 1.00, 1.89, 0.21, 1.65, 0.07};

int findShift(vector<double> letterFreq) {
    int best_shift = 0;
    double min_diff = 10000;

    for (int shift = 0; shift < 26; ++shift) {
        double diff = 0;
        for (int i = 0; i < 26; ++i) {
            diff += abs(letterFreq[(i + shift) % 26] - freqs[i]);
        }
        if (diff < min_diff) {
            min_diff = diff;
            best_shift = shift;
        }
    }

    return best_shift;
}

char shiftChar(char c, int shift) {
    if (!isalpha(c)) return c;
    bool is_lower = islower(c);
    c = toupper(c);
    int idx = (c - 'A' - shift + 26) % 26;
    return is_lower ? tolower('A' + idx) : 'A' + idx;
}

int main() {
    string msg;
    getline(cin, msg);

    vector<int> count(26, 0);
    int total = 0;
    for (char c : msg) {
        if (isalpha(c)) {
            total++;
            count[toupper(c) - 'A']++;
        }
    }

    vector<double> freq(26, 0);
    for (int i = 0; i < 26; ++i) {
        freq[i] = (count[i] * 100.0) / total;
    }

    int shift = findShift(freq);

    string result;
    for (char c : msg) {
        result += shiftChar(c, shift);
    }

    cout << result << endl;
    return 0;
}
