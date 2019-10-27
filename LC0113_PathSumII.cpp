//
// Created by hfq on 10/27/19.
//

#include <istream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int num) {
        std::vector<std::vector<int>> res;
        std::vector<int> curPath;
        if(!root) {
            return res;
        }
        pathSumCore(root, num, res, curPath);
        return res;
    }

    void pathSumCore(TreeNode* curNode, int num, std::vector<std::vector<int>>& res, std::vector<int>& curPath) {
        curPath.push_back(curNode->val);
        if(!(curNode->left || curNode->right)) {
            if(curNode->val == num) {
                res.push_back(curPath);
            }
        }
        if(curNode->left) {
            pathSumCore(curNode->left, num-curNode->val, res, curPath);
        }
        if(curNode->right) {
            pathSumCore(curNode->right, num-curNode->val, res, curPath);
        }
        curPath.pop_back();
    }
};