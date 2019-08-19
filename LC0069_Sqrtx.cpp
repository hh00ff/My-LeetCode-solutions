//
// Created by hfq on 2019/8/19.
//

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) {
            return 0;
        }
        if(x == 1) {
            return 1;
        }

        long mid = 0, left = 0, right = x, tmp = 0;
        while(right - left > 1) {
            mid = (left + right) / 2;
            tmp = mid * mid;
            if(tmp > x) {
                right = mid;
            }
            else if(tmp < x) {
                left = mid;
            }
            else {
                return mid;
            }
        }
        return left;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int input1(4);
        int expects(2);

        check("Test 1", input1, expects);
    }

    void test2() {
        int input1(2147395599);
        int expects(46339);

        check("Test 2", input1, expects);
    }

    void test3() {
        int input1(1);
        int expects(1);

        check("Test 3", input1, expects);
    }


private:
    void check(const char* testname, int& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.mySqrt(input1);

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
    tst.test2();
    tst.test3();
    return 0;
}