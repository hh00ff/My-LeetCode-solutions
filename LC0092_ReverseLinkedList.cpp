//
// Created by hfq on 2019/9/21.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr) {
            return head;
        }
        ListNode* pre = m > 1 ? head : nullptr;
        ListNode* next = nullptr;
        if(m >= n) {
            return head;
        }
        int i = 1;
        while(i < m - 1) {
            pre = pre -> next;
            i++;
        }

        ListNode* beg;
        if(pre == nullptr) {
            beg = head;
        }
        else {
            beg = pre -> next;
        }
        ListNode* end;
        ListNode* curNode = beg -> next;
        ListNode* preNode = beg;
        ListNode* nextNode;
        i = m + 1;
        while(i <= n) {
            nextNode = curNode -> next;
            curNode -> next = preNode;
            preNode = curNode;
            curNode = nextNode;
            i++;
        }
        end = preNode;
        next = curNode;
        if(pre == nullptr) {
            head = end;
        }
        else {
            pre -> next = end;
        }
        beg -> next = next;
        return head;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int pIn[] = {1, 2, 3, 4, 5};
        ListNode* input1(makeList(pIn, 5));
        int input2(2);
        int input3(4);
        int pExp[] = {1, 4, 3, 2, 5};
        ListNode* expects(makeList(pExp, 5));
        check("Test 1", input1, input2, input3, expects);
    }

    void test2() {
        int pIn[] = {3, 5};
        ListNode* input1(makeList(pIn, 2));
        int input2(1);
        int input3(2);
        int pExp[] = {5, 3};
        ListNode* expects(makeList(pExp, 2));
        check("Test 2", input1, input2, input3, expects);
    }

private:
    void check(const char* testname, ListNode* input1, int input2, int input3, const ListNode* expects) {
        bool tst_pass = true;
        auto&& result = sol.reverseBetween(input1, input2, input3);
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
    tst.test2();
    return 0;
}
