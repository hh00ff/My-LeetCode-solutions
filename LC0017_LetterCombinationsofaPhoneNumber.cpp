//
// Created by hfq on 19-5-11.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> res;
        std::string curstr;
        if(digits.empty()) {
            return res;
        }
        letterCombinationsCore(res, curstr, digits);
        return res;
    }

    void letterCombinationsCore(std::vector<std::string>& res, std::string& curstr, const std::string& digits) {
        std::string nextlayer;
        if(curstr.size() == digits.size()) {
            res.push_back(curstr);
            return;
        }
        switch(digits[curstr.size()]) {
            case '2':
                nextlayer = "abc";
                break;
            case '3':
                nextlayer = "def";
                break;
            case '4':
                nextlayer="ghi";
                break;
            case '5':
                nextlayer="jkl";
                break;
            case '6':
                nextlayer="mno";
                break;
            case '7':
                nextlayer="pqrs";
                break;
            case '8':
                nextlayer="tuv";
                break;
            case '9':
                nextlayer="wxyz";
                break;
        }
        for(auto iter = nextlayer.begin(); iter != nextlayer.end(); iter++) {
            curstr.push_back(*iter);
            letterCombinationsCore(res, curstr, digits);
            curstr.pop_back();
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("23");
        std::vector<std::string> expects({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::string& input1, const std::vector<std::string>& expects) {
        bool tst_pass = true;
        auto&& result = sol.letterCombinations(input1);
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