//
// Created by hfq on 19-4-18.
//
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> hashChar;
        std::vector<int> vLongestSubs;
        int maxLen = 0;
        int curLen = 0;
        if(s.empty()) {
            return 0;
        }
        std::unordered_map<char, int>::iterator mp_iter;
        for(int i = 0; i < s.size(); i++) {
            mp_iter = hashChar.find(s[i]);
            if(mp_iter == hashChar.end()) {
                hashChar.insert(std::make_pair(s[i], i));
                curLen++;
            }
            else if(i - mp_iter->second > curLen) {
                curLen++;
                mp_iter -> second = i;
            }
            else {
                curLen = i - mp_iter->second;
                mp_iter -> second = i;
            }
            maxLen = maxLen > curLen ? maxLen : curLen;
            vLongestSubs.push_back(curLen);
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
    return 0;
}
