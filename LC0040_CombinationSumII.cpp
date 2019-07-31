//
// Created by hfq on 7/31/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        if(candidates.empty() || target < 1) {
            return res;
        }
        std::sort(candidates.begin(), candidates.end(), std::less<int>());
        std::vector<int> curRes;
        for(int i = 0; i < candidates.size(); i++) {
            if(i > 0 && candidates[i - 1] == candidates[i]) {
                continue;
            }
            bool prune = combinationSum2Core(candidates, target, i, res, curRes, 0);
            curRes.pop_back();
            if(prune) {
                break;
            }
        }

        return res;
    }

    bool combinationSum2Core(std::vector<int>& candidates, int target, int ar_beg,
            std::vector<std::vector<int>>& res, std::vector<int>& curRes, int curSum) {
        curRes.push_back(candidates[ar_beg]);
        curSum += candidates[ar_beg];
        if(curSum == target) {
            if(res.empty() || curRes != res.back()){
                res.push_back(curRes);
            }
            return true;
        }
        else if(curSum > target) {
            return true;
        }
        else {
            if(ar_beg + 1 >= candidates.size()) {
                return true;
            }
            for(int i = ar_beg + 1; i < candidates.size(); i++) {
                if(i - 1 > ar_beg && candidates[i - 1] == candidates[i]) {
                    continue;
                }
                bool prune = combinationSum2Core(candidates, target, i, res, curRes, curSum);
                curRes.pop_back();
                if(prune) {
                    break;
                }
            }
            return false;
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1 = {10, 1, 2, 7, 6, 1, 5};
        int input2(8);
        std::vector<std::vector<int>> expects = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};

        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, int& input2,
               const std::vector<std::vector<int>>& expects) {
        bool tst_pass = true;
        auto res = sol.combinationSum2(input1, input2);

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
