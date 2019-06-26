//
// Created by hfq on 6/26/19.
//
#include <iostream>
#include <string>


class Solution {
public:
    int longestValidParentheses(std::string s) {
        if(s.empty()) {
            return 0;
        }

        int res = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                left++;
            }
            else {
                right++;
            }

            if(right == left) {
                if(2 * right > res) {
                    res = 2 * right;
                }
            }
            if(right > left) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ')') {
                right++;
            }
            else {
                left++;
            }

            if(right == left) {
                if(2 * left > res) {
                    res = 2 * left;
                }
            }
            if(left > right) {
                left = 0;
                right = 0;
            }
        }

        return res;
    }
};


int main(int argc, char** argv) {
    auto sol = Solution();
    std::cout << sol.longestValidParentheses("()()((()");
    return 0;
}