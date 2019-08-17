//
// Created by hfq on 2019/8/17.
//

#include <iostream>
#include <cmath>

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }
        if(x == 0) {
            return 0;
        }

        if(n < 0) {
            x = 1 / x;
        }
        return myPowCore(x, n);

    }

    double myPowCore(double x, int n) {
        if(n == 0) {
            return 1;
        }
        double tmp = myPowCore(x, n/2);
        if(n & 1 == 1) {
            return tmp * tmp * x;
        }
        else {
            return tmp * tmp;
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        double input1(2.00000);
        int input2(10);
        double expects(1024.0);

        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, double& input1, int input2, const double& expects) {
        bool tst_pass = true;
        auto res = sol.myPow(input1, input2);

        if(fabs(res - expects) > 0.0000001) {
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