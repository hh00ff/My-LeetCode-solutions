//
// Created by hfq on 2019/8/22.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* curnode = head;
        while(curnode -> next != nullptr) {
            if(curnode -> val == curnode -> next -> val) {
                curnode -> next = curnode -> next -> next;
                continue;
            }
            curnode = curnode -> next;
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
        int pIn[] = {1, 1, 2};
        ListNode* input1(makeList(pIn, 3));
        int pExp[] = {1, 2};
        ListNode* expects(makeList(pExp, 2));
        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, ListNode* input1, const ListNode* expects) {
        bool tst_pass = true;
        auto&& result = sol.deleteDuplicates(input1);
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
