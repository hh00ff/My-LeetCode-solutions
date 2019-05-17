//
// Created by hfq on 19-5-17.
//

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        return merge(lists, 0, lists.size()-1);
    }

    ListNode* merge(std::vector<ListNode*>& lists, int left, int right) {
        if(left == right) {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        ListNode* leftL = merge(lists, left, mid);
        ListNode* rightL = merge(lists, mid+1, right);
        return mergeTwoLists(leftL, rightL);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l2 == nullptr) {
            return l1;
        }
        if(l1 == nullptr) {
            return l2;
        }
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int pIn1[] = {1, 4, 5};
        int pIn2[] = {1, 3, 4};
        int pIn3[] = {2, 6};
        std::vector<ListNode*> input1({makeList(pIn1, 3), makeList(pIn2, 3), makeList(pIn3, 2)});
        int pExp[] = {1, 1, 2, 3, 4, 4, 5, 6};
        ListNode* expects(makeList(pExp, 8));
        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<ListNode*>& input1, const ListNode* expects) {
        bool tst_pass = true;
        auto&& result = sol.mergeKLists(input1);
        while(result != nullptr && expects != nullptr) {
            if(result->val != expects->val) {
                tst_pass = false;
                break;
            }
            result = result->next;
            expects = expects->next;
        }
        if(result!=nullptr || expects!= nullptr) {
            tst_pass = false;
        }

        if(tst_pass){
            std::cout << testname << ": " << "pass" << std::endl;
        }
        else {
            std::cout << testname << ": " << "fail" << std::endl;
        }
    }

    static ListNode* makeList(int* pNum, int len) {
        auto phead = new ListNode(pNum[0]);
        ListNode* pcurNode = phead;
        for(int i = 1; i < len; i++) {
            pcurNode->next = new ListNode(pNum[i]);
            pcurNode = pcurNode->next;
        }
        return phead;
    }

    Solution sol;
};

int main(int argc, char** argv) {
    Test tst = Test();
    tst.test1();
    return 0;
}
