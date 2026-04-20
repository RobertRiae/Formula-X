#ifndef TRANSPOSE_H
#define TRANSPOSE_H

#include <vector>
#include <string>
using namespace std;

bool isvalid(string &v);

vector<vector<char>> fillGrid(const string &text, int rows, int cols);

vector<vector<char>> shiftGrid(vector<vector<char>> &grid, int rows, int cols, int rowShift, int colShift);

void showGrid(const vector<vector<char>> &grid, int rows, int cols, string title);

string transposeEncrypt(vector<vector<char>> &grid, int rows, int cols);

string transposeDecrypt(string cipher, int rows, int cols, int rowShift, int colShift);

#endif
