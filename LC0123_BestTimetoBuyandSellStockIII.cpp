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
        std::vector<int> nums1(prices.size(), 0);
        std::vector<int> nums2(prices.size(), 0);
        int minNum = prices[0], tmp;
        for(int i = 1; i < nums1.size(); i++) {
            tmp = prices[i] - minNum;
            nums1[i] = tmp > nums1[i-1] ? tmp : nums1[i-1];
            if(prices[i] < minNum) {
                minNum = prices[i];
            }
        }

        int maxNum = prices.back();
        for(int i = nums2.size() - 2; i >= 0; i--) {
            tmp = maxNum - prices[i];
            nums2[i] = tmp > nums2[i+1] ? tmp : nums2[i+1];
            if(prices[i] > maxNum) {
                maxNum = prices[i];
            }
        }

        int sum = 0;
        for(int i = 0; i < nums1.size(); i++) {
            tmp = nums1[i] + nums2[i];
            if(tmp > sum) {
                sum = tmp;
            }
        }
        return sum;
    }
};