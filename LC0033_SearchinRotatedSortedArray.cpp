//
// Created by hfq on 7/1/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }

        if(target == nums[0]) {
            return 0;
        }
        if(target == nums.back()) {
            return static_cast<int>(nums.size()-1);
        }

        int left = 0;
        int right = static_cast<int>(nums.size())-1;
        int mid = 0;

        while(left < right) {
            mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else {
                if(nums[mid] > nums[left] && nums[mid] < nums[right]) {
                    if(nums[mid] > target) {
                        right = mid;
                        continue;
                    }
                    else {
                        left = mid;
                        continue;
                    }
                }
                else if(nums[mid] > nums[left]) {
                    if(target > nums[left] && target < nums[mid]) {
                        right = mid;
                        continue;
                    }
                    else {
                        left = mid;
                        continue;
                    }
                }
                else if(nums[mid] == nums[left]) {
                    break;
                }
                else if(nums[mid] < nums[right]) {
                    if(target < nums[right] && target > nums[mid]) {
                        left = mid;
                        continue;
                    }
                    else {
                        right = mid;
                        continue;
                    }
                }
                else {
                    break;
                }
            }
        }
        return -1;
    }
};


class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({4, 5, 6, 7, 8, 1, 2, 3});
        int input2(8);
        int expects(4);
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, int& input2, const int& expects) {
        bool tst_pass = true;
        auto res = sol.search(input1, input2);
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