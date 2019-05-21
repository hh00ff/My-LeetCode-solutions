//
// Created by hfq on 19-5-21.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        auto iter1 = nums.begin();
        for(auto iter2 = nums.begin(); iter2 != nums.end(); iter2++) {
            if(*iter1 != *iter2) {
                iter1++;
                *iter1 = *iter2;
            }
        }
        return iter1 - nums.begin() +1;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({0,0,1,1,1,2,2,3,3,4});
        std::vector<int> expArray({0,1,2,3,4});
        int expects(5);
        check("Test 1", input1, expArray, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, std::vector<int>& expArray, const int& expects) {
        bool tst_pass = true;
        auto&& result = sol.removeDuplicates(input1);
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
