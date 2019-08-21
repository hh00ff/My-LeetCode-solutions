//
// Created by hfq on 2019/8/21.
//
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if(t.empty()) {
            return t;
        }
        if(s.empty()) {
            return s;
        }
        std::unordered_map<char, int> htab;
        for(auto c: t) {
            if(htab.find(c) != htab.end()) {
               htab[c]++;
            }
            else {
                htab[c] = 1;
            }
        }

        int left = 0, right = 0, validlen = 0, minlen = 0x7FFFFFFF;
        std::string res;
        while(right < s.size()) {
            if(htab.find(s[right]) != htab.end()) {
                if(-- htab[s[right]] >= 0) {
                    ++validlen;
                }
            }

            while(validlen == t.size()) {
                if(right - left + 1 < minlen) {
                    res = s.substr(left, right - left + 1);
                    minlen = right - left + 1;
                }
                if(htab.find(s[left]) != htab.end()) {
                    if(++ htab[s[left]] > 0) {
                        --validlen;
                    }
                }
                left++;
            }
            right++;
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
        std::string input1("ADOBECODEBANC");
        std::string input2("ABC");
        std::string expects("BANC");

        check("Test 1", input1, input2, expects);
    }

    void test2() {
        std::string input1("ab");
        std::string input2("a");
        std::string expects("a");

        check("Test 2", input1, input2, expects);
    }


private:
    void check(const char* testname, std::string& input1, std::string& input2, const std::string& expects) {
        bool tst_pass = true;
        auto res = sol.minWindow(input1, input2);

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
    return 0;
}
