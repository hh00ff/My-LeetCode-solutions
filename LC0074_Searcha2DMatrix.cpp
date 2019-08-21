//
// Created by hfq on 2019/8/21.
//

#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty() || target < matrix[0][0]) {
            return false;
        }

        int mid;
        int left = 0, right = matrix.size() - 1;
        if(matrix[right][0] <= target) {
            left = right;
        }
        while(left < right) {
            mid = (left + right) / 2;
            if(matrix[mid][0] > target) {
                right = mid;
                continue;
            }
            if(matrix[mid][0] == target || matrix[mid + 1][0] == target) {
                return true;
            }
            if(matrix[mid][0] < target) {
                left = mid;
                if(matrix[mid + 1][0] > target) {
                    break;
                }
            }

        }

        int row = left;
        left = 0, right = matrix[0].size() - 1;
        if(matrix[row][right] < target) {
            return false;
        }
        if(matrix[row][right] == target || matrix[row][left] == target) {
            return true;
        }
        while(left < right - 1) {
            mid = (left + right) / 2;
            if(matrix[row][mid] == target) {
                return true;
            }
            else if(matrix[row][mid] < target) {
                left = mid;
            }
            else {
                right = mid;
            }
        }

        return matrix[row][right] == target || matrix[row][left] == target;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<std::vector<int>> input1({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}});
        int input2(3);
        bool expects(true);

        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::vector<std::vector<int>>& input1, int& input2, const bool& expects) {
        bool tst_pass = true;
        auto res = sol.searchMatrix(input1, input2);

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

