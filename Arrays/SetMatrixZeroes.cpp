// 73. Set Matrix Zeroes
// Problem Link: https://leetcode.com/problems/set-matrix-zeroes/description/
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

#include <iostream>
#include <vector>
using namespace std;
void markRow(vector<vector<int>> &matrix, int row)
{
    int m = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        if (matrix[row][i] == 0)
            continue;
        matrix[row][i] = -999;
    }
}
void markColumn(vector<vector<int>> &matrix, int column)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][column] == 0)
            continue;
        matrix[i][column] = -999;
    }
}

void setZeroesUsingBruteForce(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;
    for (int i = 0; i < n; i++)
    { // Traversing Row

        for (int j = 0; j < m; j++)
        {
            // Traversing Column
            if (matrix[i][j] == 0)
            {
                count++;
                markColumn(matrix, j);
                markRow(matrix, i);
            }
        }
    }
    if (count == 0)
        return;
    for (int i = 0; i < n; i++)
    { // Traversing Row

        for (int j = 0; j < m; j++)
        {
            // Traversing Column
            if (matrix[i][j] == -999)
            //  cout<<"found zero"<<endl;
            {
                matrix[i][j] = 0;
            }
        }
    }
    // return matrix;
}
void setZeroesUsingBetterApproach(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++)
    { // Traversing Row

        for (int j = 0; j < m; j++)
        {
            // Traversing Column
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    { // Traversing Row

        for (int j = 0; j < m; j++)
        {
            // Traversing Column
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    // return matrix;
}
int main()
{
    // Write C++ code here
    vector<vector<int>> prices = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroesUsingBruteForce(prices);

    return 0;
}