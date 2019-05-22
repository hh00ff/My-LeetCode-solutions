//
// Created by hfq on 19-5-22.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if(nums.empty()) {
            return 0;
        }
        auto iter1 = nums.begin();
        auto iter2 = nums.begin();
        while(iter2 != nums.end()) {
            if(*iter2 != val) {
                *iter1 = *iter2;
                iter1++;
            }
            iter2++;
        }
        return iter1 - nums.begin();
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({3, 2, 2, 3});
        int input2(3);
        std::vector<int> expArray({2, 2});
        int expects(2);
        check("Test 1", input1, input2, expArray, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, int& input2, std::vector<int>& expArray, const int& expects) {
        bool tst_pass = true;
        auto&& result = sol.removeElement(input1, input2);
        if(result == expects) {
            for(int i = 0; i < expects; i++) {
                if(input1[i] != expArray[i]) {
                    tst_pass = false;
                    break;
                }
            }
        }
        else {
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
