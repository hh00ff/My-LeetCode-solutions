//
// Created by hfq on 19-5-16.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        ListNode* head = nullptr;
        if(l1!=nullptr && l2!=nullptr) {
            if(l1->val <= l2->val) {
                head = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                head = new ListNode(l2->val);
                l2 = l2->next;
            }
        }
        else if(l1 == nullptr) {
            head = new ListNode(l2->val);
            l2 = l2->next;
        }
        else {
            head = new ListNode(l1->val);
            l1 = l1->next;
        }
        ListNode* curNode = head;
        while(l1 != nullptr || l2 != nullptr) {
            if(l1 == nullptr || (l2!=nullptr && l1->val>l2->val)) {
                curNode -> next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else {
                curNode -> next = new ListNode(l1->val);
                l1 = l1->next;
            }
            curNode = curNode->next;
        }
        return head;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int pIn1[] = {1, 2, 4};
        int pIn2[] = {1, 3, 4};
        ListNode* input1(makeList(pIn1, 3));
        ListNode* input2(makeList(pIn2, 3));
        int pExp[] = {1, 1, 2, 3, 4, 4};
        ListNode* expects(makeList(pExp, 6));
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, ListNode* input1, ListNode* input2, const ListNode* expects) {
        bool tst_pass = true;
        auto&& result = sol.mergeTwoLists(input1, input2);
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
