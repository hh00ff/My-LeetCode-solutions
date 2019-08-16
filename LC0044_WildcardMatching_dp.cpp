//
// Created by hfq on 19-8-16.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string &s, std::string &p) {
        if (s.empty()) {
            if (p.empty()) {
                return true;
            }
            for (int i = 0; i < p.size(); i++) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (p.empty()) {
            return false;
        }

        std::vector< std::vector<bool> > dp(s.size()+1, std::vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        for(int j = 1; j < p.size()+1; j++) {
            if(p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }

        for(int i = 1; i < s.size()+1; i++) {
            for(int j = 1; j < p.size()+1; j++) {
                if(p[j-1] == '?' || s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[s.size()][p.size()];

    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("abefcdgiescdfimde");
        std::string input2("ab*cd?i*de");
        bool expects = true;

        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::string& input1, std::string& input2, const int& expects) {
        bool tst_pass = true;
        auto res = sol.isMatch(input1, input2);

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

