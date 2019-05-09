//
// Created by hfq on 19-5-9.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        int tmp = 0;
        int base = 0;
        std::string res;
        std::vector<std::pair<int, std::string>> table = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                                          {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
                                                          {5, "V"}, {4, "IV"}, {1, "I"}};
        auto iter = table.begin();
        while(num > 0) {
            base = iter->first;
            tmp = num / base;
            for(int i = 0; i < tmp; i++) {
                res.append(iter->second);
            }
            num -= tmp * base;
            iter ++;
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
        int input1(1994);
        std::string expected("MCMXCIV");
        check("Test 1", input1, expected);
    }

private:
    void check(const char* testname, int& input1, const std::string& expected) {
        bool tst_pass = true;
        auto&& result = sol.intToRoman(input1);
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