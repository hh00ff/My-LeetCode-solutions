//
// Created by hfq on 19-5-10.
//
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        if(nums.size()<3) {
            return res;
        }
        std::sort(nums.begin(), nums.end(), std::less<int>());
        int tmp = 0;
        for(auto iter1 = nums.begin(); iter1 != nums.end()-2; ) {
            auto iter2 = iter1 + 1;
            auto iter3 = nums.end() - 1;
            while(iter3 - iter2 > 0) {
                if(*iter2 + *iter3 > -*iter1) {
                    iter3--;
                }
                else if(*iter2 + *iter3 < -*iter1) {
                    iter2++;
                }
                else {
                    res.emplace_back(std::vector<int>({*iter1, *iter2, *iter3}));
                    tmp = *iter2;
                    while(iter2 != nums.end() && *iter2 == tmp) {
                        iter2++;
                    }
                    tmp = *iter3;
                    while(iter3 != iter1 && *iter3 == tmp) {
                        iter3--;
                    }
                }
            }
            tmp = *iter1;
            while(iter1 != nums.end()-2 && *iter1 == tmp) {
                iter1++;
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
        std::vector<int> input1({-1,0,1,2,-1,-4});
        std::vector<std::vector<int>> expects({{-1,-1,2},{-1,0,1}});
        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const std::vector<std::vector<int>>& expects) {
        bool tst_pass = true;
        auto&& result = sol.threeSum(input1);
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
