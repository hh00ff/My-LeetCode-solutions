//
// Created by hfq on 9/26/19.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p == nullptr && q == nullptr) {
                return true;
            }
            else if(p != nullptr && q != nullptr) {
                bool isSame = isSameTree(p->left, q->left);
                if(isSame) {
                    isSame = p->val == q->val;
                }
                if(isSame) {
                    isSame = isSameTree(p->right, q->right);
                }
                return isSame;
            }
            else {
                return false;
            }
    }
};