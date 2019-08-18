//
// Created by hfq on 2019/8/18.
//

#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        if(nums.empty()) {
            return false;
        }

        int curind = 0, nextind = 0, maxrange = 0, tmprange = 0;
        while(curind < nums.size() - 1) {
            if(curind + nums[curind] >= nums.size() - 1) {
                return true;
            }
            for(int i = curind; i <= curind + nums[curind]; i++) {
                tmprange = i + nums[i];
                if(tmprange > maxrange) {
                    maxrange = tmprange;
                    nextind = i;
                }
            }

            if(maxrange >= nums.size() - 1) {
                return true;
            }
            else if(maxrange == curind + nums[curind] && maxrange < nums.size() - 1) {
                return false;
            }
            else {
                curind = nextind;
            }
        }
        return true;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({2, 0});
        bool expects(true);

        check("Test 1", input1, expects);
    }

    void test2() {
        std::vector<int> input1({1, 1, 1, 0});
        bool expects(true);

        check("Test 2", input1, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const bool& expects) {
        bool tst_pass = true;
        auto res = sol.canJump(input1);

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
    tst.test2();
    return 0;
}