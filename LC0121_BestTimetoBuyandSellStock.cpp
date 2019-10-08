//
// Created by hfq on 10/8/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.size() < 2) {
            return 0;
        }
        int ind = 1, minP = prices[0], max = 0;
        int tmp;
        while(ind < prices.size()) {
            tmp = prices[ind] - minP;
            if(tmp > max) {
                max = tmp;
            }
            if(prices[ind] < minP) {
                minP = prices[ind];
            }
            ind++;
        }
        return max;
    }
};