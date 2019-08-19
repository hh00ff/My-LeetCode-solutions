//
// Created by hfq on 2019/8/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        if(digits.empty()) {
            return digits;
        }
        bool carry = true;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(carry) {
                digits[i] = digits[i] + 1;
            }
            if(digits[i] / 10 == 0) {
                carry = false;
                break;
            }
            else {
                digits[i] = digits[i] % 10;
            }
        }
        if(carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({9});
        std::vector<int> expects({1, 0});

        check("Test 1", input1, expects);
    }


private:
    void check(const char* testname, std::vector<int>& input1, const std::vector<int>& expects) {
        bool tst_pass = true;
        auto res = sol.plusOne(input1);

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