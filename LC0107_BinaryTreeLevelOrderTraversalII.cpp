//
// Created by hfq on 10/3/19.
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> res;
        std::vector<int> curRes;
        if(root == nullptr) {
            return res;
        }
        std::deque<TreeNode*> que;
        que.push_back(root);
        int layerSize;
        TreeNode* curNode;
        while(!que.empty()) {
            layerSize = que.size();
            for(int i = 0; i < layerSize; i++) {
                curNode = que.front();
                que.pop_front();
                curRes.push_back(curNode->val);
                if(curNode -> left) {
                    que.push_back(curNode -> left);
                }
                if(curNode -> right) {
                    que.push_back(curNode -> right);
                }
            }
            res.push_back(curRes);
            curRes.clear();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

};