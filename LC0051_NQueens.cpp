#include <iostream>
#include <cstring>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> tmp(n, std::string(n, '.'));
        solveNQueensCore(results, tmp, 0);
        return results;
    }

    void solveNQueensCore(std::vector<std::vector<std::string>>& results, std::vector<std::string>& tmp, int curRow) {
        if(curRow == tmp.size()) {
            results.push_back(tmp);
            return;
        }
        for(int i = 0; i < tmp.size(); i++) {
            if(check(curRow, i, tmp)) {
                tmp[curRow][i] = 'Q';
                solveNQueensCore(results, tmp, curRow+1);
                tmp[curRow][i] = '.';
            }
        }
    }

    static bool check(int row, int col, std::vector<std::string>& tmp) {
        for(int i = 0; i < row; i++) {
            if(tmp[i][col] == 'Q') {
                return false;
            }
        }
        int len = row < col ? row: col;
        for(int i = 1; i <= len; i++) {
            if(tmp[row-i][col-i] == 'Q') {
                return false;
            }
        }
        len = row < tmp.size()-col-1 ? row : tmp.size()-col-1;
        for(int i = 1; i <= len; i++) {
            if(tmp[row-i][col+i] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<std::vector<std::string>> expects;
        std::vector<std::string> tmp;
        tmp.emplace_back(std::string(".Q.."));
        tmp.emplace_back(std::string("...Q"));
        tmp.emplace_back(std::string("Q..."));
        tmp.emplace_back(std::string("..Q."));
        expects.push_back(tmp);
        tmp.clear();
        tmp.emplace_back(std::string("..Q."));
        tmp.emplace_back(std::string("Q..."));
        tmp.emplace_back(std::string("...Q"));
        tmp.emplace_back(std::string(".Q.."));
        expects.push_back(tmp);

        check("Test 1", 4, expects);
    }

private:
    void check(const char* testname, int input, const std::vector<std::vector<std::string>>& expected) {
        bool tst_pass = true;
        auto&& result = sol.solveNQueens(input);
        if(result != expected) {
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
