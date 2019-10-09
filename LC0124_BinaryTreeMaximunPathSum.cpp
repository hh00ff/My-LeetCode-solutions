//
// Created by hfq on 10/9/19.
//
#include <iostream>
#include <algorithm>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT32_MIN;
        maxPathSumCore(root, sum);
        return sum;
    }

    static int maxPathSumCore(TreeNode* root, int& sum) {
        if(!root) {
            return 0;
        }
        int lVal = maxPathSumCore(root -> left, sum);
        int rVal = maxPathSumCore(root -> right, sum);
        int tmp = root->val;
        if(lVal > 0) {
            tmp += lVal;
        }
        if(rVal > 0) {
            tmp += rVal;
        }
        if(tmp > sum) {
            sum = tmp;
        }
        if(lVal < 0 && rVal < 0) {
            return root -> val;
        }
        return std::max(lVal, rVal) + root->val;
    }
};