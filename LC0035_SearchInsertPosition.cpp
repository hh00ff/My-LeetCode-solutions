//
// Created by hfq on 19-7-3.
//
#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if(nums.empty()) {
            return 0;
        }

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left < right) {
            mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                right = mid;
            }
            else if(left + 1 != right) {
                left = mid;
            }
            else {
                if(nums[right] == target) {
                    return right;
                }
                else if(nums[right] < target) {
                    left = right;
                }
                else {
                    right = left;
                }
            }
        }

        if(nums[left] == target || nums[left] > target) {
            return left;
        }
        else {
            return left + 1;
        }
    }
};


class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({1, 3, 5, 6});
        int input2(2);
        int expects(1);
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, int& input2, const int& expects) {
        bool tst_pass = true;
        auto&& result = sol.searchInsert(input1, input2);
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