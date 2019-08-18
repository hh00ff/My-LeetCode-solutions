//
// Created by hfq on 2019/8/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        if(matrix.empty()) {
            return res;
        }
        spiralOrderCore(matrix, res, 0);
        return res;
    }

    void spiralOrderCore(std::vector<std::vector<int>>& matrix, std::vector<int>& res, int begin) {
        int start = begin;
        int end = matrix[0].size() - begin - 1;
        for(int j = start; j <= end; j++) {
            res.push_back(matrix[begin][j]);
        }


        start = begin + 1;
        end = matrix.size() - begin - 1;
        for(int i = start; i <= end; i++) {
            res.push_back(matrix[i][matrix[0].size()-begin-1]);
        }

        if(begin < matrix.size() - begin - 1) {
            start = matrix[0].size() - begin - 2;
        }
        else {
            start = begin - 1;
        }
        end = begin;
        for(int j = start; j >= end; j--) {
            res.push_back(matrix[matrix.size()-begin-1][j]);
        }

        if(begin < matrix[0].size() - begin - 1) {
            start = matrix.size() - begin - 2;
        }
        else {
            start = begin - 1;
        }
        end = begin + 1;
        for(int i = start; i >= end; i--) {
            res.push_back(matrix[i][begin]);
        }

        if(begin + 1 <= (std::min(matrix.size(), matrix[0].size()) - 1) / 2) {
            spiralOrderCore(matrix, res, begin + 1);
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<std::vector<int>> input1({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});
        std::vector<int> expects({1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7});

        check("Test 1", input1, expects);
    }

    void test2() {
        std::vector<std::vector<int>> input1({{7}, {9}, {6}});
        std::vector<int> expects({7, 9, 6});

        check("Test 2", input1, expects);
    }

private:
    void check(const char* testname, std::vector<std::vector<int>>& input1, const std::vector<int>& expects) {
        bool tst_pass = true;
        auto res = sol.spiralOrder(input1);

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