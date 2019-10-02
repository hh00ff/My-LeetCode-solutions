//
// Created by hfq on 10/2/19.
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        return std::max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }

};
