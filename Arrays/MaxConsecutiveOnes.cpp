// Max Consecutive Ones
// Problem Link: https://leetcode.com/problems/max-consecutive-ones/description/
// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = 0;
    int count = 0;
    for (auto val : nums)
    {
        if (val == 1)
        {
            count += val;
            maxi = max(maxi, count);
        }
        else
        {
            count = 0;
        }
    }
    return maxi;
}
int main()

{
    vector<int> arr1 = {1, 1, 0, 1, 1, 1};
    int maxConsValue = findMaxConsecutiveOnes(arr1);
    cout << "Max Consecutive Ones is  " << maxConsValue << endl;
    return 0;
}
