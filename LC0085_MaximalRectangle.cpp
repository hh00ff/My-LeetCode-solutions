//
// Created by hfq on 2019/8/23.
//
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        std::vector<int> height(matrix[0].size(), 0);
        std::vector<int> left(matrix[0].size(), 0);
        std::vector<int> right(matrix[0].size(), matrix[0].size());
        int curleft;
        int curright;
        int maxarea = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '1') {
                    height[j] += 1;
                }
                else {
                    height[j] = 0;
                }
            }
            curleft = 0;
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '1') {
                    left[j] = std::max(left[j], curleft);
                }
                else {
                    curleft = j + 1;
                    left[j] = 0;
                }
            }

            curright = matrix[0].size();
            for(int j = matrix[0].size() - 1; j >= 0; j--) {
                if(matrix[i][j] == '1') {
                    right[j] = std::min(right[j], curright);
                }
                else {
                    curright = j;
                    right[j] = matrix[0].size();
                }
            }

            for(int j = 0; j < matrix[0].size(); j++) {
                maxarea = std::max(maxarea, (right[j] - left[j]) * height[j]);
            }
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
        std::vector<std::vector<char>> input1({{'1', '0', '1', '0', '0'},
                                               {'1', '0', '1', '1', '1'},
                                               {'1', '1', '1', '1', '1'},
                                               {'1', '0', '0', '1', '0'}});
        int expects(6);

        check("Test 1", input1, expects);
    }

    void test2() {
        std::vector<std::vector<char>> input1({{'1', '0'}});
        int expects(1);

        check("Test 2", input1, expects);
    }

private:
    void check(const char* testname, std::vector<std::vector<char>>& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.maximalRectangle(input1);

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

