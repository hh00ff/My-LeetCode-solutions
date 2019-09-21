//
// Created by hfq on 2019/9/21.
//

#include <iostream>
#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        if(s.empty()) {
            return 0;
        }
        return numDecodingsCore(s, 0);
    }

    int numDecodingsCore(std::string& s, int beg) {
        if(beg >= s.size()) {
            return 1;
        }
        int res = 0;
        if(s[beg] <= '9' && s[beg] >= '1') {
            res += numDecodingsCore(s, beg + 1);
        }

        if(beg + 1 < s.size()) {
            if(s[beg] == '1' || (s[beg] == '2' && s[beg+1] <= '6')) {
                res += numDecodingsCore(s, beg + 2);
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
        std::string input1("12");
        int expects1(2);

        check("Test 1", input1, expects1);
    }

    void test2() {
        std::string input1("0");
        int expects1(0);

        check("Test 2", input1, expects1);
    }

    void test3() {
        std::string input1("00");
        int expects1(0);

        check("Test 3", input1, expects1);
    }

private:
    void check(const char* testname, std::string& input1, const int& expects1) {
        bool tst_pass = true;
        auto res = sol.numDecodings(input1);

        if(res != expects1) {
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