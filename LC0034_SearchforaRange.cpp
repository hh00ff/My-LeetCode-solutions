//
// Created by hfq on 19-7-2.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if(nums.empty()) {
            return {-1, -1};
        }

        std::vector<int> res = {-1, -1};
        if(nums[0] > target || nums.back() < target) {
            return res;
        }

        res[0] = find_begin(nums, 0, nums.size()-1, target);
        res[1] = find_end(nums, 0, nums.size()-1, target);
        return res;

    }

    int find_begin(std::vector<int>& nums, int left, int right, int target) {
        if(left >= right -1) {
            if(nums[left] != target && nums[right] != target) {
                return -1;
            }
            else if(nums[left] == target) {
                return left;
            }
            else {
                return right;
            }
        }
        int mid = static_cast<int>((left + right) / 2);
        if(nums[mid] == target && nums[mid-1] != target) {
            return mid;
        }
        else if(nums[mid] > target || (nums[mid] == target && nums[mid-1] == target)) {
            return find_begin(nums, left, mid, target);
        }
        else {
            return find_begin(nums, mid, right, target);
        }
    }

    int find_end(std::vector<int>& nums, int left, int right, int target) {
        if(left >= right -1) {
            if(nums[left] != target && nums[right] != target) {
                return -1;
            }
            else if(nums[right] == target) {
                return right;
            }
            else {
                return left;
            }
        }
        int mid = static_cast<int>((left + right) / 2);
        if(nums[mid] == target && nums[mid+1] != target) {
            return mid;
        }
        else if(nums[mid] < target || (nums[mid] == target && nums[mid+1] == target)) {
            return find_end(nums, mid, right, target);
        }
        else {
            return find_end(nums, left, mid, target);
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({5, 7, 7, 8, 8, 10});
        int input2(8);
        std::vector<int> expects({3, 4});
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, int& input2, const std::vector<int>& expects) {
        bool tst_pass = true;
        auto&& result = sol.searchRange(input1, input2);
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