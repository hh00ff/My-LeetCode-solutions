//
// Created by hfq on 19-8-13.
//

#include <iostream>
#include <vector>

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if(N <= 0) {
            return false;
        }
        std::vector<int>&& tab = digitCount(N);
        int curnum = 1;
        for(int i = 0; i < 31; i++) {
            if(tab == digitCount(curnum)) {
                return true;
            }
            curnum <<= 1;
        }
        return false;
    }

    std::vector<int> digitCount(int N) {
        std::vector<int> res;
        res.resize(10, 0);
        while(N) {
            res[N % 10] ++;
            N /= 10;
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
        int input1 = 46;
        bool expects = true;

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, int& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.reorderedPowerOf2(input1);

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
