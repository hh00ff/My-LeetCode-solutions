//
// Created by hfq on 10/2/19.
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        return buildTreeCore(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTreeCore(std::vector<int>& preorder, int pbeg, int pend,
            std::vector<int>& inorder, int ibeg, int iend) {
        if(pbeg > pend) {
            return nullptr;
        }
        int curVal = preorder[pbeg];
        TreeNode* curNode = new TreeNode(curVal);
        int ind = ibeg;
        while(ind <= iend) {
            if(inorder[ind] == curVal) {
                break;
            }
            ind++;
        }
        int pbegNew = pbeg + 1;
        int pendNew = pbeg + (ind - ibeg);
        curNode -> left = buildTreeCore(preorder, pbegNew, pendNew, inorder, ibeg, ind-1);
        pbegNew = pendNew + 1;
        pendNew = pend;
        curNode -> right = buildTreeCore(preorder, pbegNew, pendNew, inorder, ind + 1, iend);
        return curNode;
    }
};