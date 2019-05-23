//
// Created by hfq on 19-5-23.
//
#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if(haystack.size() < needle.size()) {
            return -1;
        }
        for(int i = 0; i <= haystack.size()-needle.size(); i++) {
            if(strStrCore(haystack, needle, i, 0)) {
                return i;
            }
        }
        return -1;
    }
    bool strStrCore(std::string& haystack, std::string& needle, int hBegin, int nBegin) {
        if(nBegin == needle.size()) {
            return true;
        }
        if(hBegin == haystack.size()) {
            return false;
        }
        if(haystack[hBegin] == needle[nBegin]) {
            return strStrCore(haystack, needle, hBegin+1, nBegin+1);
        }
        else {
            return false;
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("hello");
        std::string input2("ll");
        int expects(2);
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::string& input1, std::string& input2, const int& expects) {
        bool tst_pass = true;
        auto&& result = sol.strStr(input1, input2);
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
