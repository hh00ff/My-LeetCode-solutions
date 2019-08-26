//
// Created by hfq on 2019/8/23.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) {
            return head;
        }
        ListNode* leftbeg = nullptr;
        ListNode* rightbeg = nullptr;
        ListNode* leftend = nullptr;
        ListNode* rightend = nullptr;
        ListNode* curnode = head;
        ListNode* nextnode = head;
        while(curnode != nullptr) {
            nextnode = curnode->next;
            if(curnode->val < x) {
                if(leftbeg == nullptr) {
                    leftbeg = curnode;
                    leftend = leftbeg;
                    leftend->next = nullptr;
                }
                else {
                    leftend->next = curnode;
                    leftend = leftend->next;
                    leftend->next = nullptr;
                }
            }
            else {
                if(rightbeg == nullptr) {
                    rightbeg = curnode;
                    rightend = rightbeg;
                    rightend->next = nullptr;
                }
                else {
                    rightend->next = curnode;
                    rightend = rightend->next;
                    rightend->next = nullptr;
                }
            }
            curnode = nextnode;
        }

        if(leftbeg != nullptr) {
            leftend->next = rightbeg;
            head = leftbeg;
        }
        else {
            head = rightbeg;
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
        int pIn[] = {1, 4, 3, 2, 5, 2};
        ListNode* input1(makeList(pIn, 6));
        int input2(3);
        int pExp[] = {1, 2, 2, 4, 3, 5};
        ListNode* expects(makeList(pExp, 6));
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, ListNode* input1, int& input2, const ListNode* expects) {
        bool tst_pass = true;
        auto&& result = sol.partition(input1, input2);
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

