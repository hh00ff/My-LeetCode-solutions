//
// Created by hfq on 2021/7/27.
//
#include <iostream>
#include <unordered_set>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if(s.empty()) {
            return 0;
        }
        std::unordered_set<char> st;
        auto l= s.begin();
        auto r = l;
        int maxLen = 0;
        int curLen = 0;
        for(; l!= s.end(); l++) {
            for(; r != s.end(); r++) {
                if(st.find(*r) != st.end()) {
                    break;
                }
                else {
                    st.insert(*r);
                    curLen++;
                }
            }
            if(curLen > maxLen) {
                maxLen = curLen;
            }
            st.erase(*l);
            curLen--;
        }
        return maxLen;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input("abcabcbb");
        int expected = 3;
        check("Test 1", input, expected);
    }

    void test2() {
        std::string input("pwwkew");
        int expected = 3;
        check("Test 2", input, expected);
    }

private:
    void check(const char* testname, std::string& input, const int expected) {
        bool tst_pass = true;
        auto&& result = sol.lengthOfLongestSubstring(input);
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
    tst.test2();
    return 0;
}
