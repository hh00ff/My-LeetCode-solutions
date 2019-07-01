//
// Created by hfq on 6/26/19.
//
#include <iostream>
#include <string>


class Solution {
public:
    int longestValidParentheses(std::string s) {
        if(s.empty()) {
            return 0;
        }

        int res = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                left++;
            }
            else {
                right++;
            }

            if(right == left) {
                if(2 * right > res) {
                    res = 2 * right;
                }
            }
            if(right > left) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ')') {
                right++;
            }
            else {
                left++;
            }

            if(right == left) {
                if(2 * left > res) {
                    res = 2 * left;
                }
            }
            if(left > right) {
                left = 0;
                right = 0;
            }
        }

        return res;
    }
};


class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("()()((()");
        int expects(4);
        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::string& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.longestValidParentheses(input1);
        if(res != expects) {
            tst_pass = false;
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
