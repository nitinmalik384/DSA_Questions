
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void printAllSubArrays(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            cout << "[ ";
            for (int k = i; k < j; k++)
            {
                cout << nums[k] << ", ";
                /* code */
            }
            cout << "]" << endl;
        }
    }
}
int getLargestSubArray(vector<int> &nums)
{
    int maxSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int longestSubarrayWithGivenSumK(vector<int> &a, long long k)
{
    int n = a.size();
    if (n == 0)
        return 0;
    vector<int> prefixSum(n, 0);
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    // Step 2: Find the maximum subarray sum using prefix sums
    long long max_sum = 0; // Initialize to minimum possible value
    int largest_sub_arr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // Calculate sum of subarray a[i...j]
            long long sum = i > 0 ? prefixSum[j] - prefixSum[i - 1] : prefixSum[j];
            max_sum = max(max_sum, sum);
            if (sum == k)
            {
                largest_sub_arr = max(largest_sub_arr, (j - i + 1));
            }
        }
    }
    return largest_sub_arr;
}

int main()

{
    vector<int> arr1 = {4, 1, 2, 1, 2};
    cout << longestSubarrayWithGivenSumK(arr1,3) << endl;
    return 0;
}
