//
// Created by hfq on 2019/8/18.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        if(n < 1) {
            std::vector<std::vector<int>> res;
            return res;
        }
        else {
            std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
            int curnum = 1;
            for(int begin = 0; begin <= (n - 1) / 2; begin++) {
                if(n - 2 * begin == 1) {
                    res[begin][begin] = curnum;
                }
                for(int i = begin; i <= n - begin - 2; i ++) {
                    res[begin][i] = curnum;
                    curnum++;
                }
                for(int i = begin; i <= n - begin - 2; i++) {
                    res[i][n - begin - 1] = curnum;
                    curnum++;
                }
                for(int i = n - begin - 1; i >= begin + 1; i--) {
                    res[n - begin - 1][i] = curnum;
                    curnum++;
                }
                for(int i = n - begin - 1; i >= begin + 1; i--) {
                    res[i][begin] = curnum;
                    curnum++;
                }
            }
            return res;
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int input1(3);
        std::vector<std::vector<int>> expects({{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, int& input1, const std::vector<std::vector<int>>& expects) {
        bool tst_pass = true;
        auto res = sol.generateMatrix(input1);

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