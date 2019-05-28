//
// Created by hfq on 19-5-28.
//

#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0 || divisor == 0) {
            return 0;
        }

        int res = 0;
        bool positive = true;
        if(dividend == 0x80000000 && divisor == -1) {
            return 0x7FFFFFFF;
        }
        if(divisor == 1) {
            return dividend;
        }
        if(divisor == 0x80000000) {
            return dividend != 0x80000000 ? 0 : 1;
        }
        if(divisor < 0) {
            positive = !positive;
            divisor = -divisor;
        }
        if(dividend == 0x80000000) {
            res = 1;
            dividend = dividend + divisor;
        }

        if(dividend < 0) {
            positive = !positive;
            dividend = -dividend;
        }

        int curdivisor = divisor;
        int curtime = 1;

        while(dividend >= divisor) {
            if(dividend < curdivisor) {
                curdivisor = divisor;
                curtime = 1;
            }
            dividend = dividend - curdivisor;
            res += curtime;
            if(curdivisor < 0x40000000) {
                curdivisor += curdivisor;
                curtime += curtime;
            }
        }

        return positive ? res : -res;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int input1(10);
        int input2(3);
        int expects(3);
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, int& input1, int& input2, const int& expects) {
        bool tst_pass = true;
        auto&& result = sol.divide(input1, input2);
        if(result != expects) {
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