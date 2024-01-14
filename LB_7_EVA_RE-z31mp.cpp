#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

unsigned long long bigmod(unsigned long long b, unsigned long long p, unsigned long long m) {
    unsigned long long result = 1;
    b = b % m;

    while (p > 0) {
        if (p % 2 == 1) {
            result = (__uint128_t)result * b % m;
        }

        p /= 2;
        b = (__uint128_t)b * b % m;
    }

    return result;
}

unsigned long long find_X(unsigned long long a, unsigned long long b, unsigned long long c) {
    unsigned long long n = static_cast<unsigned long long>(sqrt(c)) + 1;
    unordered_map<unsigned long long, unsigned long long> tempMap;

    unsigned long long val = 1;
    for (unsigned long long i = 0; i < n; ++i) {
        tempMap[val] = i;
        val = (__uint128_t)val * a % c;
    }

    unsigned long long inv = bigmod(a, c - n - 1, c);
    unsigned long long curr = b;
    for (unsigned long long j = 0; j <= n; ++j) {
        auto it = tempMap.find(curr);
        if (it != tempMap.end()) {
            return j * n + it->second;
        }

        curr = (__uint128_t)curr * inv % c;
    }

    return -1; 
}

int main() {
    unsigned long long num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    unsigned long long secret = find_X(num1, num2, num3);
    cout << secret << endl;

    return 0;
}
