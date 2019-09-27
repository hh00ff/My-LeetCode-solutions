//
// Created by hfq on 9/27/19.
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
    bool isSymmetric(TreeNode* root) {
         if(root == nullptr) {
             return true;
         }
        return isSymCore(root, root);
    }

    bool isSymCore(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) {
            return true;
        }
        else if(p != nullptr && q != nullptr) {
            bool isSym = isSymCore(p->left, q->right);
            if(isSym) {
                isSym = p->val == q->val;
            }
            if(isSym) {
                isSym = isSymCore(p->right, q->left);
            }
            return isSym;
        }
        else {
            return false;
        }
    }

};