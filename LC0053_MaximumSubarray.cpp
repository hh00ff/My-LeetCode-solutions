//
// Created by hfq on 2019/8/18.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int cursum = 0;
        int max = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            cursum += nums[i];
            if(cursum < nums[i]) {
                cursum = nums[i];
            }
            if(cursum > max) {
                max = cursum;
            }
        }
        return max;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({-2, 1, -3, 4, -1, 2, 1, -5, 4});
        int expects(6);

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.maxSubArray(input1);

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