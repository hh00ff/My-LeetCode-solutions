//
// Created by hfq on 2019/8/19.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return nullptr;
        }
        ListNode* curnode = head;
        ListNode* prenode = head;
        int listlen = 1;
        while(curnode -> next != nullptr) {
            listlen++;
            curnode = curnode -> next;
        }
        curnode = head;
        k = k % listlen;
        for(int i = 0; i < k; i++) {
            curnode = curnode->next;
        }
        while(curnode -> next != nullptr) {
            curnode = curnode -> next;
            prenode = prenode -> next;
        }
        curnode -> next = head;
        head = prenode -> next;
        prenode -> next = nullptr;
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
        int pExp[] = {4, 5, 1, 2, 3};
        ListNode* expects(makeList(pExp, 5));
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, ListNode* input1, int& input2, const ListNode* expects) {
        bool tst_pass = true;
        auto&& result = sol.rotateRight(input1, input2);
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