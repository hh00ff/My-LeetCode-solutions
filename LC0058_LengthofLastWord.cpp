//
// Created by hfq on 2019/8/18.
//

#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        if(s.empty()) {
            return 0;
        }

        int end = -1;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] != ' ' && end < 0) {
                end = i;
            }
            if(end >= 0 && s[i] == ' ') {
                return end - i;
            }
        }
        if(end >= 0) {
            return end + 1;
        }
        else {
            return 0;
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("Hello World");
        int expects(5);

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::string& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.lengthOfLastWord(input1);

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