//
// Created by hfq on 6/19/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        if(nums.size() <= 1) {
            return;
        }

        unsigned long index = 0;
        for(; index < nums.size() - 1; index++) {
            if(nums[index] < nums[index+1]) {
                break;
            }
        }
        if(index == nums.size()-1) {
            auto left = nums.begin();
            auto right = nums.end() - 1;
            while(right - left > 0) {
                swapelement<int>(left, right);
                left++;
                right--;
            }
            return;
        }

        int last = nums.back();
        for(unsigned long i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < last) {
                unsigned long ind = 0;
                if(nums.back() > nums[i]) {
                    ind = nums.size() - 1;
                }
                else{
                    for(unsigned long j = i + 1; j < nums.size(); j++) {
                        if(nums[i] < nums[j] && nums[i] >= nums[j+1]) {
                            ind = j;
                            break;
                        }
                    }
                }
                int tmp = nums[ind];
                nums[ind] = nums[i];
                nums[i] = tmp;

                auto left = nums.begin() + i + 1;
                auto right = nums.end() - 1;
                while(right - left > 0) {
                    swapelement<int>(left, right);
                    left++;
                    right--;
                }

                break;
            }
            last = nums[i];
        }
    }

    template <typename T>
    void swapelement(typename std::vector<T>::iterator& left, typename std::vector<T>::iterator& right) {
        T tmp = *left;
        *left = *right;
        *right = tmp;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input({1, 3, 2});
        std::vector<int> expects({2, 1, 3});
        check("Test 1", input, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input, const std::vector<int>& expects) {
        bool tst_pass = true;
        sol.nextPermutation(input);
        if(input != expects) {
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