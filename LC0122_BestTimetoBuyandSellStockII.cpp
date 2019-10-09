//
// Created by hfq on 10/9/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.size() < 2) {
            return 0;
        }
        int sum = 0;
        for(int i = 1; i< prices.size(); i++) {
            if(prices[i] > prices[i-1]) {
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }
};