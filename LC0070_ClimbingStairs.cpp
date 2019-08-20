//
// Created by hfq on 2019/8/20.
//

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if(n < 1) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        int pre1 = 1;
        int pre2 = 2;
        int tmp = 0;
        for(int i = 3; i <= n; i++) {
            tmp = pre1 + pre2;
            pre1 = pre2;
            pre2 = tmp;
        }
        return tmp;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int input1(44);
        int expects(1134903170);

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, int& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.climbStairs(input1);

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