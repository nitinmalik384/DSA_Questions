// Sort Colors
// Problem link: https://leetcode.com/problems/sort-colors/description/
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Better Approach
void sortColors(vector<int> &nums)
{
    int red = 0;
    int white = 0;
    int blue = 0;
    for (auto num : nums)
    {
        if (num == 0)
        {
            red++;
        }
        else if (num == 1)
        {
            white++;
        }
        else
        {
            blue++;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < red)
        {
            nums[i] = 0;
        }
        else if (i >= red && i < red + white)
        {
            nums[i] = 1;
        }
        else
        {
            nums[i] = 2;
        }
    }
}

// Optimised one
void sortColorsUsingDutchNationalFlag(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[high], nums[mid]);
            high--;
        }
    }
}
void traverse(vector<int> &nums)
{
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()

{
    vector<int> arr1 = {1, 2, 0, 0, 2, 1};
    sortColorsUsingDutchNationalFlag(arr1);

    traverse(arr1);

    arr1 = {1, 2, 0, 0, 2, 1};
    sortColors(arr1);
    traverse(arr1);

    return 0;
}
