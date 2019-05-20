//
// Created by hfq on 19-5-20.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k <= 1) {
            return head;
        }
        ListNode* curNode = head;
        ListNode* preNode = head;
        ListNode* nextNode = head;
        for(int i = 0; i < k; i++) {
            if(curNode == nullptr) {
                return head;
            }
            curNode = curNode->next;
        }
        curNode = head;
        nextNode = curNode->next;
        ListNode* tail = head;
        for(int i = 0; i < k-1; i++) {
            preNode = curNode;
            curNode = nextNode;
            nextNode = curNode->next;
            curNode->next = preNode;
            head = curNode;
        }
        tail->next = reverseKGroup(nextNode, k);
        return head;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int pIn1[] = {1, 2, 3, 4, 5};
        ListNode* input1(makeList(pIn1, 5));
        int input2 = 2;
        int pExp[] = {2, 1, 4, 3, 5};
        ListNode* expects(makeList(pExp, 5));
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, ListNode* input1, int& input2, const ListNode* expects) {
        bool tst_pass = true;
        auto&& result = sol.reverseKGroup(input1, input2);
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
