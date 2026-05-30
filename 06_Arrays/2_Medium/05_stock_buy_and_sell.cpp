#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int min_price = prices[0];

        for(int i=0; i<n; i++){
            int current_profit = prices[i] - min_price;
            max_profit = max(max_profit , current_profit);
            min_price = min(min_price , prices[i]);
        }

        return max_profit;
    }
};

//! ================================================ OR ================================================

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int min_price = prices[0];

        for(int i=0; i<n; i++){
            if(prices[i] < min_price){
                min_price = prices[i];
            }
            if( (prices[i] - min_price) > profit ){
                profit = prices[i] - min_price;
            }
        }

        return profit;
    }
};