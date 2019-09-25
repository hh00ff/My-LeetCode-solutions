//
// Created by hfq on 9/25/19.
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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        long Pre = INT64_MIN;
        return isValidBSTCore(root, Pre);
    }

    bool isValidBSTCore(TreeNode* root, long& Pre) {
        bool isValid = true;
        if(root -> left != nullptr) {
            isValid = isValidBSTCore(root -> left, Pre);
        }

        if(root -> val <= Pre) {
            return false;
        }
        Pre = root -> val;

        if(isValid && root -> right != nullptr) {
            isValid = isValidBSTCore(root -> right, Pre);
        }
        return isValid;

    }
};