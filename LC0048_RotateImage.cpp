//
// Created by hfq on 2019/8/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        transpose2d(matrix);
        flip_row(matrix);
    }

    void transpose2d(std::vector<std::vector<int>>& matrix) {
        if(matrix.empty()) {
            return;
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i; j < matrix[0].size(); j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void flip_row(std::vector<std::vector<int>>& matrix) {
        if(matrix.empty()) {
            return;
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size()/2; j++) {
                std::swap(matrix[i][j], matrix[i][matrix[0].size()-1-j]);
            }
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<std::vector<int>> input1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
        std::vector<std::vector<int>> expects({{7, 4, 1}, {8, 5, 2}, {9, 6, 3}});

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<std::vector<int>>& input1, const std::vector<std::vector<int>>& expects) {
        bool tst_pass = true;
        sol.rotate(input1);
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
    return 0;
}

