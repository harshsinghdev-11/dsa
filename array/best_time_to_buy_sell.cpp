#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>&prices){
    int max_profit = 0;
    int min_price = prices[0];
    int prices_size = prices.size();
    for(int i=1;i<prices_size;i++){
        int profit = prices[i] - min_price;
        max_profit = max(max_profit,profit);
        min_price = min(min_price,prices[i]);
    }
    return max_profit;
}

int main(){
    vector<int>prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);
}