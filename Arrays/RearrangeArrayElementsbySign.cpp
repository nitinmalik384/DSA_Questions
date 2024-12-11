// 2149. Rearrange Array Elements by Sign
// Problem Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

#include <iostream>
#include <vector>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> positives;
    vector<int> negatives;
    for (auto num : nums)
    {
        if (num >= 0)
        {
            positives.push_back(num);
        }
        else
        {
            negatives.push_back(num);
        }
    }
    for (int i = 0; i < positives.size(); i++)
    {
        nums[i * 2] = positives[i];
    }
    for (int i = 0; i < negatives.size(); i++)
    {
        nums[(i * 2) + 1] = negatives[i];
    }
    return nums;
}

vector<int> rearrangeArrayOptimal(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    int pIndex = 0, nIndex = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans[pIndex] = nums[i];
            pIndex += 2;
        }
        else
        {
            ans[nIndex] = nums[i];
            nIndex += 2;
        }
    }
    return ans;
}

void traverseArray(vector<int> &nums)
{
    for (auto num : nums)
    {
        cout << num << ", ";
    }
}
int main()
{

    vector<int> prices = {-7, -1, 5, 3, -6, 4};

    // prices = rearrangeArray(prices);
    // traverseArray(prices);

    prices = rearrangeArrayOptimal(prices);
    traverseArray(prices);

    return 0;
}