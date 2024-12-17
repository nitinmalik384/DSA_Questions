// 48. Rotate Image
// Problem Link: https://leetcode.com/problems/rotate-image/description/
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees(clockwise).
//         You have to rotate the image in
//         - place,
//     which means you have to modify the input 2D matrix directly.DO NOT allocate another 2D matrix and do the rotation.

#include <iostream>
#include <vector>
using namespace std;

void rotateByBruteForce(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = ans;
}
int main()
{
    // Write C++ code here
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateByBruteForce(matrix);

    return 0;
}