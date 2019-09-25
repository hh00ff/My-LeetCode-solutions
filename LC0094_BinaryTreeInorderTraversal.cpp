//
// Created by hfq on 9/25/19.
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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::vector<TreeNode*> myStack;
        TreeNode* curNode = root;
        while(curNode != nullptr || !myStack.empty()) {
            if(curNode == nullptr) {
                curNode = myStack.back();
                myStack.pop_back();
                res.push_back(curNode->val);
                curNode = curNode -> right;
            }
            else {
                myStack.push_back(curNode);
                curNode = curNode -> left;
            }

        }
        return res;
    }
};