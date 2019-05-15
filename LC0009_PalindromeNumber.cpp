//
// Created by hfq on 19-5-6.
//
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0x80000000 || x < 0) {
            return false;
        }
        if(!x) {
            return true;
        }
        int rev = 0;
        int tmp = x % 10;
        if(!tmp) {
            return false;
        }
        while(x > rev) {
            tmp = x % 10;
            x = x / 10;
            rev = rev * 10 + tmp;
        }
        if(rev == x) {
            return true;
        }

        return rev/10 == x;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int input1(1220);
        bool expected(false);
        check("Test 1", input1, expected);
    }

private:
    void check(const char* testname, int& input1, const bool& expected) {
        bool tst_pass = true;
        auto&& result = sol.isPalindrome(input1);
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
<<<<<<< HEAD
}
=======
}
>>>>>>> 20004f1791f32705d7aea711649b1d5c288a4b5e
