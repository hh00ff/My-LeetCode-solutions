//
// Created by hfq on 19-8-16.
//
#include <vector>
#include <iostream>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        if(nums.size() <= 1) {
            return 0;
        }
        int curind = 0;
        int jump = 0;
        int tmpind = 0;
        int tmpmax = 0;
        while (curind + nums[curind] < nums.size() - 1) {
            tmpind = 0;
            tmpmax = 0;
            for(int i = curind + 1; i <= curind + nums[curind]; i++) {
                if(i + nums[i] > tmpmax) {
                    tmpind = i;
                    tmpmax = i + nums[i];
                }
            }
            curind = tmpind;
            jump++;
        }
        jump++;
        return jump;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({2, 3, 1, 1, 4});
        int expects = 2;

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.jump(input1);

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

