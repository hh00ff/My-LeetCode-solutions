//
// Created by hfq on 19-5-10.
//

//
// Created by hfq on 19-5-10.
//
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        if(nums.size()<3) {
            return 0;
        }
        std::sort(nums.begin(), nums.end(), std::less<int>());
        int res = nums[0] + nums[1] + nums[2];
        for(auto iter1 = nums.begin(); iter1 != nums.end()-2; iter1++) {
            auto iter2 = iter1 + 1;
            auto iter3 = nums.end() - 1;
            while(iter3 - iter2 > 0) {
                if(abs(*iter1 + *iter2 + *iter3 - target) < abs(res - target)) {
                    res = *iter1 + *iter2 + *iter3;
                }
                if(*iter2 + *iter3 > target -*iter1) {
                    iter3--;
                }
                else if(*iter2 + *iter3 < target -*iter1) {
                    iter2++;
                }
                else {
                    return target;
                }
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
        std::vector<int> input1({-1,2,1,-4});
        int input2(1);
        int expects(2);
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, int& input2, const int& expects) {
        bool tst_pass = true;
        auto&& result = sol.threeSumClosest(input1, input2);
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
