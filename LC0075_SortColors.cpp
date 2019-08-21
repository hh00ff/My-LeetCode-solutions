//
// Created by hfq on 2019/8/21.
//

#include <iostream>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        if(nums.empty()) {
            return;
        }
        int left = 0, right = nums.size() - 1;
        int tmp;
        int i = left;
        while(i <= right) {

            if(nums[i] == 0) {
                swap(nums[left++], nums[i++]);

            }
            else if(nums[i] == 2) {
                swap(nums[right--], nums[i]);
            }
            else {
                i++;
            }
        }
    }

    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({2, 0, 2, 1, 1, 0});
        std::vector<int> expects({0, 0, 1, 1, 2, 2});

        check("Test 1", input1, expects);
    }

    void test2() {
        std::vector<int> input1({2, 0, 1});
        std::vector<int> expects({0, 1, 2});

        check("Test 2", input1, expects);
    }

    void test3() {
        std::vector<int> input1({0, 0});
        std::vector<int> expects({0, 0});

        check("Test 3", input1, expects);
    }

    void test4() {
        std::vector<int> input1({1, 1});
        std::vector<int> expects({1, 1});

        check("Test 4", input1, expects);
    }

    void test5() {
        std::vector<int> input1({1, 0});
        std::vector<int> expects({0, 1});

        check("Test 5", input1, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const std::vector<int>& expects) {
        bool tst_pass = true;
        sol.sortColors(input1);
        auto res = input1;

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
    tst.test3();
    tst.test4();
    tst.test5();
    return 0;
}

