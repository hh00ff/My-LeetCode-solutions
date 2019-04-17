//
// Created by hfq on 19-4-17.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* Node = nullptr;
        ListNode* Node1 = l1;
        ListNode* Node2 = l2;
        int num = 0;
        bool carry = false;
        if(l1 == nullptr && l2 == nullptr) {
            return head;
        }
        if(Node1 != nullptr) {
            num += Node1->val;
            Node1 = Node1->next;
        }
        if(Node2 != nullptr) {
            num += Node2->val;
            Node2 = Node2->next;
        }
        if(num >= 10) {
            num -= 10;
            carry = true;
        }
        Node = new ListNode(num);
        head = Node;
        while(Node1 != nullptr || Node2 != nullptr || carry) {
            num = 0;
            if(Node1 != nullptr) {
                num += Node1->val;
                Node1 = Node1->next;
            }
            if(Node2 != nullptr) {
                num += Node2->val;
                Node2 = Node2->next;
            }
            if(carry) {
                num += 1;
                carry = false;
            }
            if(num >= 10) {
                num -= 10;
                carry = true;
            }
            Node->next = new ListNode(num);
            Node = Node->next;
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
