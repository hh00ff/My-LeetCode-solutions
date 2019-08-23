//
// Created by hfq on 2019/8/23.
//
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        if(heights.empty()) {
            return 0;
        }
        std::vector<int> indstack;
        indstack.push_back(-1);
        indstack.push_back(0);
        int maxarea = 0;
        int i = 1;
        while(i < heights.size()) {
            while(indstack.back() != -1 && heights[i] < heights[indstack.back()]) {
                maxarea = std::max(maxarea, (i - *(indstack.end() - 2) - 1) * heights[indstack.back()]);
                indstack.pop_back();
            }
            indstack.push_back(i);
            i++;
        }
        while(indstack.back() != -1) {
            maxarea = std::max(maxarea, (i - *(indstack.end() - 2) - 1) * heights[indstack.back()]);
            indstack.pop_back();
        }
        return maxarea;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({2, 1, 5, 6, 2, 3});
        int expects(10);

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.largestRectangleArea(input1);

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
