#ifndef CAESER_H
#define CAESER_H

#include <string>
using namespace std;

string encryptCaesar(const string& text, int shift);
string decryptCaesar(const string& text, int shift);
bool isNumber(const string& s);

#endif
