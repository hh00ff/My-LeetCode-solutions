//
// Created by hfq on 19-5-18.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* preNode = head;
        ListNode* curNode = head;
        ListNode* nextNode = head;
        if(preNode->next != nullptr) {
            curNode = head->next;
            head = curNode;
        }
        else {
            return head;
        }

        while(true) {
            if(preNode->next == nullptr) {
                break;
            }
            curNode = preNode->next;
            if(curNode->next == nullptr) {
                curNode->next = preNode;
                preNode->next = nullptr;
                break;
            }
            nextNode = curNode->next;
            curNode->next = preNode;
            if(nextNode->next != nullptr) {
                preNode->next = nextNode->next;
            }
            else {
                preNode->next = nextNode;
            }
            preNode = nextNode;
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
        int pIn1[] = {1, 2, 3, 4};
        ListNode* input1(makeList(pIn1, 4));
        int pExp[] = {2, 1, 4, 3};
        ListNode* expects(makeList(pExp, 4));
        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, ListNode* input1, const ListNode* expects) {
        bool tst_pass = true;
        auto&& result = sol.swapPairs(input1);
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
