//
// Created by hfq on 10/3/19.
//

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBSTCore(nums, 0, nums.size()-1);
    }

    TreeNode* sortedArrayToBSTCore(std::vector<int>& nums, int beg, int end) {
        if(beg > end) {
            return nullptr;
        }
        int curInd = (beg + end) / 2;
        auto curNode = new TreeNode(nums[curInd]);
        curNode -> left = sortedArrayToBSTCore(nums, beg, curInd-1);
        curNode -> right = sortedArrayToBSTCore(nums, curInd+1, end);
        return curNode;
    }
};