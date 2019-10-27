//
// Created by hfq on 10/27/19.
//

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        std::unordered_set<int> uset(nums.begin(), nums.end());
        int curnum = 0, maxcount = 0, count = 0;
        for(int i = 0; i < nums.size(); i++) {
            curnum = nums[i];
            if(!uset.count(curnum-1)) {
                count = 1;
                curnum++;
                while(uset.count(curnum)) {
                    count++;
                    curnum++;
                }
                if(count > maxcount) {
                    maxcount = count;
                }
            }
        }
        return maxcount;
    }
};