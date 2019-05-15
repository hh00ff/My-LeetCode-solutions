//
// Created by hfq on 19-5-13.
//
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        if(nums.size() < 4) {
            return res;
        }
        std::sort(nums.begin(), nums.end(), std::less<int>());

        std::vector<int>::iterator iters[4];
        for(iters[0] = nums.begin(); iters[0] < nums.end()-3; iters[0]++) {
            for(iters[1] = iters[0] + 1; iters[1] < nums.end()-2; iters[1]++) {
                iters[2] = iters[1] + 1;
                iters[3] = nums.end() - 1;
                while(iters[2] < iters[3]) {
                    if(*iters[0] + *iters[1] + *iters[2] + *iters[3] < target) {
                        iters[2]++;
                    }
                    else if(*iters[0] + *iters[1] + *iters[2] + *iters[3] > target) {
                        iters[3]--;
                    }
                    else {
                        bool dup = true;
                        if(!res.empty()) {
                            for(int i = 0; i < 4; i ++) {
                                if(*iters[i] != res.back()[i]){
                                    dup = false;
                                    break;
                                }
                            }
                        }
                        if(res.empty() || !dup) {
                            res.emplace_back(std::vector<int>({*iters[0], *iters[1], *iters[2], *iters[3]}));
                        }
                        iters[2]++;
                        iters[3]--;
                    }
                }
                while(iters[1]+1!=nums.end() && *(iters[1]+1) ==(*iters[1])) {
                    iters[1]++;
                }
            }
            while(iters[0]+1!=nums.end() && *(iters[0]+1) ==(*iters[0])) {
                iters[0]++;
            }
        }
        return res;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({1, 0, -1, 0, -2, 2});
        int input2(0);
        std::vector<std::vector<int>> expects({{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}});
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, int& input2, const std::vector<std::vector<int>>& expects) {
        bool tst_pass = true;
        auto&& result = sol.fourSum(input1, input2);
        if(result != expects) {
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
