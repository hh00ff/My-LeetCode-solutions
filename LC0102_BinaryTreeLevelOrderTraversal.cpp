//
// Created by hfq on 9/27/19.
//

#include <iostream>
#include <vector>
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if(root == nullptr) {
            return res;
        }
        std::deque<TreeNode*> q1;
        std::deque<TreeNode*> q2;
        std::vector<int> tmpVec;
        q1.push_back(root);
        bool isOne = true;
        TreeNode* curNode;
        while(!(q1.empty() && q2.empty() && tmpVec.empty())) {
            if(isOne) {
                if(!q1.empty()) {
                    curNode = q1.front();
                    tmpVec.push_back(curNode->val);
                    q1.pop_front();
                    if(curNode -> left != nullptr) {
                        q2.push_back(curNode->left);
                    }
                    if(curNode -> right != nullptr) {
                        q2.push_back(curNode->right);
                    }
                }
                else {
                    isOne = !isOne;
                    res.push_back(tmpVec);
                    tmpVec.clear();
                }
            }
            else {
                if(!q2.empty()) {
                    curNode = q2.front();
                    tmpVec.push_back(curNode->val);
                    q2.pop_front();
                    if(curNode -> left != nullptr) {
                        q1.push_back(curNode->left);
                    }
                    if(curNode -> right != nullptr) {
                        q1.push_back(curNode->right);
                    }
                }
                else {
                    isOne = !isOne;
                    res.push_back(tmpVec);
                    tmpVec.clear();
                }
            }
        }
        return res;
    }
};