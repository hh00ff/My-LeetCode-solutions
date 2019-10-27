//
// Created by hfq on 10/27/19.
//
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) {
            return false;
        }
        bool hasSum = false;
        if(!(root->left || root->right)) {
            return root->val == sum;
        }
        hasSum = hasPathSum(root->left, sum-root->val);
        if(hasSum) {
            return true;
        }
        hasSum = hasPathSum(root->right, sum-root->val);
        return hasSum;
    }
};
