#include<iostream>
#include<vector>

using namespace std; 


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int * left = &prices[0];    // Buy
        int * right = &prices[1];   // Sell

        // to check the memory address to know its end
        auto end = &prices[0] + prices.size(); 

        int maxProfit = 0;

        while (right < end) {

            // checking two numbers to buy
            if(*left < *right) {
                auto profit = *right - *left;
                maxProfit = max(maxProfit, profit);
            }
            else {
                left = right;
            }

            right++;
        }

        return maxProfit;
    }
};


int main() {

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution obj;

    int result = obj.maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}