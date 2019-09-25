//
// Created by hfq on 9/25/19.
//

#include <iostream>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        p1 = nullptr;
        p2 = nullptr;
        long pre = INT64_MIN;
        inorder(root, pre);
        int tmp = p1 -> val;
        p1 -> val = p2 -> val;
        p2 -> val = tmp;
    }

    void inorder(TreeNode* root, long& pre) {
        if(root -> left != nullptr) {
            inorder(root -> left, pre);
        }
        if(root -> val < pre) {
            if(p1 == nullptr) {
                p1 = preNode;
                p2 = root;
            }
            else {
                p2 = root;
            }
        }
        pre = root -> val;
        preNode = root;
        if(root -> right != nullptr) {
            inorder(root -> right, pre);
        }
    }

    TreeNode* preNode;
    TreeNode* p1;
    TreeNode* p2;
};