//
// Created by hufen on 2021/7/26.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) {
            return l2;
        }
        if(l2 == nullptr) {
            return l1;
        }
        auto head = new ListNode(0);
        int carry = 0;
        addTwoNumbersCore(l1, l2, head, carry);
        return head;
    }

    void addTwoNumbersCore(ListNode* l1, ListNode* l2, ListNode* head, int carry) {
        if(l1) {
            head->val += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            head->val += l2->val;
            l2 = l2->next;
        }
        head->val += carry;
        carry = head->val / 10;
        head->val = head->val % 10;
        if(l1 || l2 || carry) {
            head->next = new ListNode(0);
            addTwoNumbersCore(l1, l2, head->next, carry);
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int list1[] = {2, 4, 3};
        int list2[] = {5, 6, 4};
        int expList[] = {7, 0, 8};
        ListNode* head1 = makeListNode(list1, 3);
        ListNode* head2 = makeListNode(list2, 3);
        ListNode* expected = makeListNode(expList, 3);

        check("Test 1", head1, head2, expected);
    }

private:
    ListNode* makeListNode(int* list, int length) {
        ListNode* Node = nullptr;
        if(!length) {
            return Node;
        }
        Node = new ListNode(list[0]);
        ListNode* head = Node;
        for(int i = 1; i < length; i++) {
            Node->next = new ListNode(list[i]);
            Node = Node->next;
        }
        return head;
    }

    void check(const char* testname, ListNode* node1, ListNode* node2, const ListNode* expNode) {
        bool tst_pass = true;
        auto&& result = sol.addTwoNumbers(node1, node2);
        while(result != nullptr || expNode != nullptr) {
            if(result == nullptr || expNode == nullptr) {
                tst_pass = false;
                break;
            }
            if(result->val != expNode->val) {
                tst_pass = false;
                break;
            }
            result = result->next;
            expNode = expNode->next;
        }

        if(tst_pass){
            std::cout << testname << ": " << "pass" << std::endl;
        }
        else {
            std::cout << testname << ": " << "fail" << std::endl;
        }
    }

    Solution sol;
};

int main(int argc, char** argv) {
    Test tst = Test();
    tst.test1();
    return 0;
}