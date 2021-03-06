//
// Created by hfq on 19-8-16.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        if(nums.empty()) {
            return res;
        }
        std::sort(nums.begin(), nums.end(), std::less<int>());
        permuteCore(nums, res, 0);
        return res;
    }

    void permuteCore(std::vector<int> nums, std::vector<std::vector<int>>& res, int begin) {
        if(begin == nums.size() - 1) {
            res.push_back(nums);
            return;
        }

        for(int i = begin; i < nums.size(); i++) {
            if(i > begin && nums[i] == nums[begin]) {
                continue;
            }

            std::swap(nums[begin], nums[i]);
            permuteCore(nums, res, begin + 1);
            //swap(nums, begin, i);
        }
    }

//    bool swap(std::vector<int>& nums, int i, int j) {
//        if(i < nums.size() && j < nums.size()) {
//            int tmp = nums[i];
//            nums[i] = nums[j];
//            nums[j] = tmp;
//            return true;
//        }
//        return false;
//    }
};


class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({1, 1, 2});
        std::vector<std::vector<int>> expects({{1, 1, 2}, {1, 2, 1}, {2, 1, 1}});

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const std::vector<std::vector<int>>& expects) {
        bool tst_pass = true;
        auto res = sol.permuteUnique(input1);

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

