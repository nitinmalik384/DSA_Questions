// 121. Best Time to Buy and Sell Stock
// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
#include <iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        for(int i=1; i<prices.size(); i++)
        {
            int cost = prices[i] - mini;
            profit = max(cost, profit); // 
            mini =min(mini,prices[i]);// maitaining previous minimum value


            cout<<"a[i]: "<<prices[i]<<endl;
            cout<<"cost: "<<cost<<endl;
            cout<<"profit: "<<profit<<endl;
            cout<<"mini: "<<mini<<endl<<endl;
            
        }
        
        return profit;
        
    }
int main() {
    // Write C++ code here
    vector<int> prices ={7, 1, 5, 3, 6, 4};
    maxProfit(prices);

    return 0;
}