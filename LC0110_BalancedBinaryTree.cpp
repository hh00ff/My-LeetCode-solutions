//
// Created by hfq on 10/8/19.
//
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedCore(root) >= 0;
    }

    static int isBalancedCore(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = isBalancedCore(root->left);
        if(left < 0) {
            return -1;
        }
        int right = isBalancedCore(root->right);
        if(right < 0) {
            return -1;
        }
        if(abs(left-right) > 1) {
            return -1;
        }
        return std::max(left, right) + 1;
    }
};
