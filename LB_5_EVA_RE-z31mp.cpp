#include <string>
#include <bitset>
#include <iostream>

using namespace std;

string encode(string text) {
    string bits;
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        bitset<8> ascii(c);
        for (int j = 0; j < 8; j++) {
            if (ascii[7 - j] == 1) {
                bits += "111";
            } else {
                bits += "000";
            }
        }
    }
    return bits;
}

string decode(string bits) {
    string correctedBits;
    for (int i = 0; i < bits.length(); i += 3) {
        string triplet = bits.substr(i, 3);
        int ones = 0;
        for (int j = 0; j < 3; j++) {
            if (triplet[j] == '1') ones++;
        }
        if (ones > 1) {
            correctedBits += '1';
        } else {
            correctedBits += '0';
        }
    }

    string text;
    for (size_t i = 0; i < correctedBits.size(); i += 8) {
        bitset<8> byte(string(correctedBits, i, 8));
        text += static_cast<char>(byte.to_ulong());
    }
    return text;
}
