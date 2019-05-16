//
// Created by hfq on 19-5-16.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string curStr;
        if(n < 1) {
            return res;
        }
        generateParenthesisCore(res, curStr, 0, 0, n);
        return res;
    }
    void generateParenthesisCore(std::vector<std::string>& res, std::string& curStr, int left, int right, int n) {
        if(curStr.size() == 2 * n) {
            res.push_back(curStr);
            return;
        }
        if(left < n) {
            curStr.push_back('(');
            left ++;
            generateParenthesisCore(res, curStr, left, right, n);
            curStr.pop_back();
            left --;
        }
        if(right < left) {
            curStr.push_back(')');
            right ++;
            generateParenthesisCore(res, curStr, left, right, n);
            curStr.pop_back();
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int input1(3);
        std::vector<std::string> expects({"((()))", "(()())", "(())()", "()(())", "()()()"});
        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, int& input1, const std::vector<std::string>& expects) {
        bool tst_pass = true;
        auto&& result = sol.generateParenthesis(input1);
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
