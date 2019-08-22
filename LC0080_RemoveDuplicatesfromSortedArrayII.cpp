//
// Created by hfq on 2019/8/22.
//
#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() < 3) {
            return nums.size();
        }

        int curind = 1;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[curind-1] != nums[i]) {
                nums[++curind] = nums[i];
            }
        }
        return curind + 1;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }


    void test1() {
        std::vector<int> input1({1, 1, 1, 2, 2, 3});
        int expects1(5);
        std::vector<int> expects2({1, 1, 2, 2, 3});

        check("Test 1", input1, expects1, expects2);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const int& expects1, const std::vector<int>& expects2) {
        bool tst_pass = true;
        auto res = sol.removeDuplicates(input1);

        if(res != expects1) {
            tst_pass = false;
        }

        for(int i = 0; tst_pass && i < res; i++) {
            if(input1[i] != expects2[i]) {
                tst_pass = false;
            }
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


