#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>

using namespace std;

string getMD5(string str) {
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)str.c_str(), str.length(), result);

    stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)result[i];
    }
    return ss.str();
}

string crack(string hash) {
    for (int i = 0; i <= 99999; i++) {
        stringstream ss;
        ss << setw(5) << setfill('0') << i;
        string tryPin = ss.str();
        if (getMD5(tryPin) == hash) {
            return tryPin;
        }
    }
    return "cant find pin";
}
