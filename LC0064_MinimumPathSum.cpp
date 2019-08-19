//
// Created by hfq on 2019/8/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        for(int i = 1; i < grid.size(); i++) {
            grid[i][0] = grid[i][0] + grid[i-1][0];
        }
        for(int i = 1; i < grid[0].size(); i++) {
            grid[0][i] = grid[0][i] + grid[0][i-1];
        }

        for(int i = 1; i < grid.size(); i++) {
            for(int j = 1; j < grid[0].size(); j++) {
                grid[i][j] = std::min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }

        return grid.back().back();
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<std::vector<int>> input1({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
        int expects(7);

        check("Test 1", input1, expects);
    }


private:
    void check(const char* testname, std::vector<std::vector<int>>& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.minPathSum(input1);

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