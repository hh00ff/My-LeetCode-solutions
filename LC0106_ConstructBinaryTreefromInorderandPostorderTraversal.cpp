//
// Created by hfq on 10/3/19.
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
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        return buildTreeCore(inorder, 0, inorder.size()-1,
                postorder, 0, postorder.size()-1);
    }

    TreeNode* buildTreeCore(std::vector<int>& inorder, int inbeg, int inend,
            std::vector<int>& postorder, int pobeg, int poend) {
        if(inbeg > inend) {
            return nullptr;
        }
        int curVal = postorder[poend];
        TreeNode* curNode = new TreeNode(curVal);
        int ind = inbeg;
        while(ind <= inend) {
            if(inorder[ind] == curVal) {
                break;
            }
            ind++;
        }

        int inbegNew = inbeg;
        int inendNew = ind - 1;
        int pobegNew = pobeg;
        int poendNew = pobegNew + (inendNew - inbegNew);
        curNode -> left = buildTreeCore(inorder, inbegNew, inendNew, postorder, pobegNew, poendNew);
        inbegNew = ind + 1;
        inendNew = inend;
        pobegNew = poendNew + 1;
        poendNew = poend - 1;
        curNode -> right = buildTreeCore(inorder, inbegNew, inendNew, postorder, pobegNew, poendNew);
        return curNode;
    }
};