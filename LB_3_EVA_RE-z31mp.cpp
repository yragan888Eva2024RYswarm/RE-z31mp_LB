#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

vector<unsigned char> hexToBytes(string hex) {
    vector<unsigned char> bytes;
    for (int i = 0; i < hex.length(); i += 2) {
        string byteString = hex.substr(i, 2);
        unsigned char byte = (unsigned char) strtol(byteString.c_str(), NULL, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

vector<unsigned char> xorThem(vector<unsigned char> a, vector<unsigned char> b) {
    vector<unsigned char> result;
    for (int i = 0; i < a.size(); i++) {
        result.push_back(a[i] ^ b[i]);
    }
    return result;
}

string bytesToStr(vector<unsigned char> bytes) {
    string str = "";
    for (int i = 0; i < bytes.size(); i++) {
        str += bytes[i];
    }
    return str;
}

int main() {
    string msg1, msg2, msg3;
    getline(cin, msg1);
    getline(cin, msg2);
    getline(cin, msg3);

    vector<unsigned char> msg1Bytes = hexToBytes(msg1);
    vector<unsigned char> msg2Bytes = hexToBytes(msg2);
    vector<unsigned char> msg3Bytes = hexToBytes(msg3);
    vector<unsigned char> firstXOR = xorThem(msg1Bytes, msg3Bytes);
    string finalMessage = bytesToStr(xorThem(firstXOR, msg2Bytes));

    cout << finalMessage << endl;

    return 0;
}
