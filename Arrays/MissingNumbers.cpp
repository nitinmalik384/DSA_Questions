//  Missing Number
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

// Example 1:

// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
// Example 2:

// Input: nums = [0,1]
// Output: 2
// Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.


#include <iostream>
#include <vector>

using namespace std;

int missingNumberUsingHashing(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1, 0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]] = 1;
        }
        for(int i=1;i<=hash.size();i++)
        { 
            if(hash[i]==0)
            {
                return i;
            }
        }
        return 0;
    };
int missingNumberUsingMath(vector<int>& nums) {
        int n = nums.size();
        int total = (n*(n+1))/2;
        int sum=0;
        for(int i =0; i<n; i++ )
        {
            sum+=nums[i];
        }
        return total-sum;
    }
int main()
{
  vector<int> arr1 = {1,5,3};
  int missingValue = missingNumberUsingHashing(arr1);
  cout << "Union of arr1 and arr2 is  " << missingValue<< endl;
  missingValue = missingNumberUsingMath(arr1);
  cout << "Union of arr1 and arr2 is  " << missingValue<< endl;

  return 0;
}

