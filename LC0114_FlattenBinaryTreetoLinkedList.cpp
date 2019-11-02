//
// Created by hfq on 2019/11/2.
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
    void flatten(TreeNode* root) {
        if(!root) {
            return;
        }
        flattenCore(root);
    }

    TreeNode* flattenCore(TreeNode* root) {
        TreeNode* curNode = root;
        if(root->left) {
            curNode = flattenCore(root->left);
        }
        curNode->right = root->right;
        if(root->left) {
            root->right = root->left;
        }
        root->left = nullptr;
        if(curNode->right) {
            curNode = flattenCore(curNode->right);
        }
        return curNode;
    }
};