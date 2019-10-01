//
// Created by hfq on 10/1/19.
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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if(root == nullptr) {
            return res;
        }

        std::vector<TreeNode*> vSt1, vSt2;
        std::vector<int> curLayer;
        vSt1.push_back(root);
        TreeNode* curNode;
        bool isRev = true;
        while(!(vSt1.empty() && vSt2.empty() && curLayer.empty())) {
            if(isRev) {
                if(!vSt1.empty()) {
                    curNode = vSt1.back();
                    vSt1.pop_back();
                    curLayer.push_back(curNode -> val);
                    if(curNode -> left != nullptr) {
                        vSt2.push_back(curNode -> left);
                    }
                    if(curNode -> right != nullptr) {
                        vSt2.push_back(curNode -> right);
                    }
                }
                else {
                    isRev = !isRev;
                    res.push_back(curLayer);
                    curLayer.clear();
                }
            }
            else {
                if(!vSt2.empty()) {
                    curNode = vSt2.back();
                    vSt2.pop_back();
                    curLayer.push_back(curNode -> val);
                    if(curNode -> right != nullptr) {
                        vSt1.push_back(curNode -> right);
                    }
                    if(curNode -> left != nullptr) {
                        vSt1.push_back(curNode -> left);
                    }
                }
                else {
                    isRev = !isRev;
                    res.push_back(curLayer);
                    curLayer.clear();
                }
            }
        }
        return res;
    }
};