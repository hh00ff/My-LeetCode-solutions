//
// Created by hfq on 2019/8/22.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        if(nums.empty()) {
            return res;
        }
        std::vector<int> curcom;
        subsetsCore(res, nums, curcom, 0);
        return res;
    }

    void subsetsCore(std::vector<std::vector<int>>& res, std::vector<int>& nums, std::vector<int>& curcom, int begin) {
        res.push_back(curcom);
        for(int i = begin; i < nums.size(); i++) {
            curcom.push_back(nums[i]);
            subsetsCore(res, nums, curcom, i + 1);
            curcom.pop_back();
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({1, 2, 3});
        std::vector<std::vector<int>> expects({{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}});

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const std::vector<std::vector<int>>& expects) {
        bool tst_pass = true;
        auto res = sol.subsets(input1);

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
