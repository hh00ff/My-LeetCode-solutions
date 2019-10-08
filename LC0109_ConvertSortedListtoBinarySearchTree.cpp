//
// Created by hfq on 10/4/19.
//

#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        ListNode* l = head;
        ListNode* r = head;
        ListNode* pre = nullptr;
        while(r->next != nullptr && r->next->next != nullptr) {
            pre = l;
            l = l->next;
            r = r->next->next;
        }
        if(pre) {
            pre->next = nullptr;
        }
        TreeNode* curNode = new TreeNode(l->val);
        if(l != head){
            curNode->left = sortedListToBST(head);
        }
        curNode->right = sortedListToBST(l->next);
        return curNode;
    }
};