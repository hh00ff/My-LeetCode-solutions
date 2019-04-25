//
// Created by hfq on 19-4-25.
//

#include <iostream>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(s.empty() || numRows==1) {
            return s;
        }
        if(numRows == 0) {
            return "error";
        }
        std::string res;
        int numChar = s.size();
        int stepLen = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j + i < numChar; j += stepLen) {
                res.push_back(s[j+i]);
                if(i!=0 && i!=numRows-1 && j+stepLen-i<numChar) {
                    res.push_back(s[j+stepLen-i]);
                }
            }
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
        std::string input1("LEETCODEISHIRING");
        int input2 = 4;
        std::string expected("LDREOEIIECIHNTSG");
        check("Test 1", input1, input2, expected);
    }

private:
    void check(const char* testname, std::string& input1, int& input2, const std::string& expected) {
        bool tst_pass = true;
        auto&& result = sol.convert(input1, input2);
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
