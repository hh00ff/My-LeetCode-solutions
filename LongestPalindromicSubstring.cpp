//
// Created by hfq on 19-4-22.
//
#include <string>
#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if(s.empty()) {
            return s;
        }
        int start = 0;
        int end = 0;
        int len = 0;
        int len1 = 0;
        int len2 = 0;
        for(int i = s.size()-2; i >=0; i--) {
            len1 = checkFromCenter(s, i, i);
            len2 = checkFromCenter(s, i, i+1);
            len = len1 > len2 ? len1 : len2;
            if(len > end - start +1) {
                start = i - (len-1)/2;
                end = start + len -1;
            }
        }
        return s.substr(start, end-start+1);
    }

    int checkFromCenter(std::string& s, int left, int right) {
        while(left>=0 && right<s.size() && s[left] == s[right]) {
            left --;
            right ++;
        }
        return right - left -1;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("babad");
        std::string expected("aba");
        check("Test 1", input1, expected);
    }

private:
    void check(const char* testname, std::string& input1, const std::string& expected) {
        bool tst_pass = true;
        auto&& result = sol.longestPalindrome(input1);
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