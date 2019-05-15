//
// Created by hfq on 19-4-16.
//
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        if(nums.empty()) {
            return result;
        }
        std::unordered_map<int, int> mp;
        std::unordered_map<int, int>::iterator iter;
        for(int i = 0; i < nums.size(); i++) {
            iter = mp.find(target-nums[i]);
            if(iter != mp.end()) {
                result.push_back(iter->second);
                result.push_back(i);
                break;
            }
            mp.insert(std::make_pair(nums[i], i));
        }
        return result;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> expects = {0, 1};
        std::vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        check("Test 1", expects, nums, target);
    }

private:
    void check(const char* testname, const std::vector<int>& expects, std::vector<int>& nums, int target) {
        bool tst_pass = true;
        auto&& result = sol.twoSum(nums, target);
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
