#include "transpose.h"
#include <iostream>
#include <algorithm>

#define YELLOW "\033[33m"
using namespace std;

bool isvalid(string &v)
{
    if (v.empty()) return false;
    for (char c : v)
        if (!isdigit(c) && c != '-') return false;
    return true;
}

vector<vector<char>> fillGrid(const string &text, int rows, int cols)
{
    string padded = text;
    int total = rows * cols;
    if ((int)padded.size() < total)
        padded += string(total - padded.size(), 'X');

    vector<vector<char>> grid(rows, vector<char>(cols, ' '));
    int idx = 0;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            grid[r][c] = padded[idx++];
    return grid;
}


vector<vector<char>> shiftGrid(vector<vector<char>> &grid, int rows, int cols, int rowShift, int colShift)
{
    vector<vector<char>> shifted(rows, vector<char>(cols, ' '));
    rowShift = (rowShift % rows + rows) % rows;
    colShift = (colShift % cols + cols) % cols;

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
        {
            int newRow = (r + rowShift) % rows;
            int newCol = (c + colShift) % cols;
            shifted[newRow][newCol] = grid[r][c];
        }
    return shifted;
}


void showGrid(const vector<vector<char>> &grid, int rows, int cols, string title)
{
    cout << string(52 , ' ') << YELLOW  << title << ":\n";
    for (int r = 0; r < rows; r++)
    {
        cout << string(52, ' ');
        for (int c = 0; c < cols; c++)
            cout << YELLOW << "|" << grid[r][c] << "|";
        cout << endl;
    }
}


string transposeEncrypt(vector<vector<char>> &grid, int rows, int cols)
{
    string cipher = "";
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            cipher += grid[r][c];
    return cipher;
}


string transposeDecrypt(string cipher, int rows, int cols, int rowShift, int colShift)
{
    vector<vector<char>> grid = fillGrid(cipher, rows, cols);

    int undoRowShift = (-rowShift % rows + rows) % rows;
    int undoColShift = (-colShift % cols + cols) % cols;
    vector<vector<char>> unshifted = shiftGrid(grid, rows, cols, undoRowShift, undoColShift);

    string plain = "";
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            plain += unshifted[r][c];

    return plain;
}
