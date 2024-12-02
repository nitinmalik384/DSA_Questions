// Single Number
// Problem Link: https://leetcode.com/problems/single-number/description/
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:

// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4
// Example 3:

// Input: nums = [1]
// Output: 1

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int singleNumberUsingMap(vector<int> &nums)
{
    map<int, int> mapping;
    for (auto num : nums)
    {
        if (mapping.find(num) != mapping.end())
        {
            mapping[num] += 1;
        }
        else
        {
            mapping[num] = 1;
        }
    }
    for (const auto &pair : mapping)
    {
        if (pair.second == 1)
        {
            return pair.first;
        }
    }
    return 0;
}

int singleNumber(vector<int> &nums)
{
    int xorr = 0;
    for (auto num : nums)
    {
        xorr = xorr ^ num;
    }
    return xorr;
}

int main()

{
    vector<int> arr1 = {4, 1, 2, 1, 2};
    int singleNum = singleNumberUsingMap(arr1);
    cout << "single Number is  " << singleNum << endl;
    singleNum = singleNumber(arr1);
    cout << "single Number is  " << singleNum << endl;
    return 0;
}
