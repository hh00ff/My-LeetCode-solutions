//
// Created by hfq on 19-8-14.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        if(nums.empty()) {
            return 1;
        }
        int res = 0;
        bool hasOne = false;
        for(auto iter = nums.begin(); iter != nums.end(); iter++) {
            if(*iter == 1) {
                hasOne = true;
            }
            if(*iter <= 0 || *iter > nums.size()) {
                *iter = 1;
            }
        }
        if(!hasOne) {
            return 1;
        }
        int ind = 0;
        for(auto iter = nums.begin(); iter != nums.end(); iter++) {
            ind = *iter;
            if(*iter < 0) {
                ind = -ind;
            }
            ind--;
            if(nums[ind] > 0) {
                nums[ind] = -nums[ind];
            }
        }
        for(auto iter = nums.begin(); iter != nums.end(); iter++) {
            if(*iter > 0) {
                res = iter - nums.begin() + 1;
                break;
            }
        }
        if(res) {
            return res;
        }
        else
            return nums.size() + 1;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1 = {1, 2, 0};
        int expects = 3;

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.firstMissingPositive(input1);

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
