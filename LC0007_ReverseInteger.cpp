//
// Created by hfq on 19-4-29.
//
#include <iostream>


class Solution {
public:
    int reverse(int x) {
        int max_int = 0x7FFFFFFF;
        int min_int = 0x80000000;
        int max_check = max_int/10;
        int min_check = min_int/10;
        int res = 0;
        int tmp = 0;
        while(x!=0) {
            tmp = x % 10;
            x = x / 10;
            if(res>max_check || res<min_check) {
                return 0;
            }
            else if((res==max_check && tmp>7) || (res==min_check && tmp<=-8)) {
                return 0;
            }
            res = res * 10 + tmp;
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
        int input1(123);
        int expected(321);
        check("Test 1", input1, expected);
    }

private:
    void check(const char* testname, int& input1, const int& expected) {
        bool tst_pass = true;
        auto&& result = sol.reverse(input1);
        if(result != expected) {
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
