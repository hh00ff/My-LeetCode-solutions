//
// Created by hfq on 19-5-14.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || n <= 0) {
            return head;
        }
        int len = 0;
        ListNode* pcurNode = head;
        ListNode* ppreNode = head;
        while(pcurNode != nullptr) {
            pcurNode = pcurNode->next;
            len++;
            if(len > n+1) {
                ppreNode = ppreNode->next;
            }
        }
        if(len == n) {
            ListNode* tmp = head -> next;
            delete head;
            return tmp;
        }
        ListNode* tmp = ppreNode->next->next;
        delete ppreNode->next;
        ppreNode->next = tmp;
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
        int pExp[] = {1, 2, 3, 5};
        ListNode* expects(makeList(pExp, 4));
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, ListNode* input1, int& input2, const ListNode* expects) {
        bool tst_pass = true;
        auto&& result = sol.removeNthFromEnd(input1, input2);
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
