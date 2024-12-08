// Two Sum
// Problem Link: https://leetcode.com/problems/two-sum/description/
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSumUsingBruteForce(vector<int> &nums, int target)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}

vector<int> twoSumUsingMap(vector<int> &nums, int target)
{
    vector<int> res;
    map<int, int> mapItemWithIndex;
    for (int i = 0; i < nums.size(); i++)
    {
        int sec = target - nums[i];
        if (mapItemWithIndex.find(sec) != mapItemWithIndex.end())
        {
            res.push_back(i);
            res.push_back(mapItemWithIndex[sec]);
            break;
        }
        mapItemWithIndex[nums[i]] = i;
    }

    return res;
}
//  only suitable  for the question where out put will be the boolean or for the question where the output will be the value not index;
vector<int> twoSumUsingGreedyApproach(vector<int> &nums, int target)
{
    vector<int> res;
    sort(nums.begin(), nums.end());
    int b = 0;
    int e = nums.size() - 1;

    while (b < e)
    {
        int sum = nums[b] + nums[e];
        if (sum > target)
        {
            e--;
        }
        else if (sum < target)
        {
            b++;
        }
        else
        {
            // this point will be reached when sum == target and the two numbers are present at the index b and e
            cout << nums[b] << ", " << nums[e] << endl;
            break;
        }
    }

    return res;
}

int main()

{
    vector<int> arr1 = {4, 1, 2, 1, 2};
    vector<int> res = twoSumUsingMap(arr1, 6);
    return 0;
}
