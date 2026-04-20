#include "caeser.h"
#include <cctype>

string encryptCaesar(const string& text, int shift) {
    string result;
    result.reserve(text.size());
    shift = (shift % 26 + 26) % 26; 

    for (unsigned char c : text) {
        if (isupper(c)) result += char(((c - 'A' + shift) % 26) + 'A');
        else if (islower(c)) result += char(((c - 'a' + shift) % 26) + 'a');
        else result += c;
    }
    return result;
}

string decryptCaesar(const string& text, int shift) {
    int normShift = (26 - (shift % 26) + 26) % 26;
    return encryptCaesar(text, normShift);
}

bool isNumber(const string& s) {
    if (s.empty()) return false;
    size_t start = 0;
    if (s[0] == '-') start = 1;
    for (size_t i = start; i < s.size(); i++)
        if (!isdigit(s[i])) return false;
    return true;
}
