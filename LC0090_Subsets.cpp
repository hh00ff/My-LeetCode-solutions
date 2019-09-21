//
// Created by hfq on 2019/9/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> res;
        if(n == 0) {
            res.push_back(std::vector<int>());
            return res;
        }
        std::sort(nums.begin(), nums.end(), std::less<int>());
        std::vector<int> curSub;
        curSub.reserve(n);
        subsetsWithDupCore(res, nums, curSub, 0);
        res.emplace_back(std::vector<int>());
        return res;
    }

    void subsetsWithDupCore(std::vector<std::vector<int>>& res, std::vector<int>& nums,
            std::vector<int>& curSub, int ind) {
        if(ind >= nums.size()) {
            return;
        }
        int i = ind;
        while(i < nums.size() && nums[i] == nums[ind]) {
            curSub.push_back(nums[i]);
            res.push_back(curSub);
            i++;
        }
        int next = i;
        i--;
        while(i >= ind) {
            subsetsWithDupCore(res, nums, curSub, next);
            curSub.pop_back();
            i--;
        }
        subsetsWithDupCore(res, nums, curSub, next);
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }


    void test1() {
        std::vector<int> input1({1, 2, 2});
        std::vector<std::vector<int>> expects1({{1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}, {}});

        check("Test 1", input1, expects1);
    }

    void test2() {
        std::vector<int> input1({1, 1, 2, 2});
        std::vector<std::vector<int>> expects1({{1}, {1, 1}, {1, 1, 2}, {1, 1, 2, 2},
                                                {1, 2}, {1, 2, 2}, {2}, {2, 2}, {}});

        check("Test 2", input1, expects1);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const std::vector<std::vector<int>>& expects1) {
        bool tst_pass = true;
        auto res = sol.subsetsWithDup(input1);

        if(res != expects1) {
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
    tst.test2();
    return 0;
}
