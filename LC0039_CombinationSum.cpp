//
// Created by hfq on 7/29/19.
//
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        if(candidates.empty() || target < 1) {
            return res;
        }
        std::sort(candidates.begin(), candidates.end(), std::less<int>());
        int start = 0;
        std::vector<int> curres;
        for(int i = 0; i < candidates.size(); i++) {
            if(target < candidates[i]) {
                break;
            }
            combinationSumCore(candidates, target, i, curres, res);
        }
        return res;
    }

    void combinationSumCore(std::vector<int>& candidates, int target, int start,
            std::vector<int>& curres, std::vector<std::vector<int>>& res) {
        if(start == candidates.size()) {
            return;
        }
        target -= candidates[start];
        curres.push_back(candidates[start]);
        if(target == 0) {
            res.push_back(curres);
            curres.pop_back();
            return;
        }
        else {
            for(int i = start; i < candidates.size(); i++) {
                if(target < candidates[i]) {
                    break;
                }
                combinationSumCore(candidates, target, i, curres, res);
            }
            curres.pop_back();
        }
    }
};


class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1 = {2, 3, 6, 7};
        int input2(7);
        std::vector<std::vector<int>> expects = {{2, 2, 3}, {7}};

        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, int& input2,
            const std::vector<std::vector<int>>& expects) {
        bool tst_pass = true;
        auto res = sol.combinationSum(input1, input2);

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
