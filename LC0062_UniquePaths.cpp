//
// Created by hfq on 2019/8/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int w = std::min(n, m);
        int h = std::max(n, m);
        std::vector<int> tab(w, 1);

        for(int i = h - 2; i >= 0; i--) {
            for(int j = w - 1; j >= 0; j--) {
                if(j == w - 1) {
                    tab[j] = 1;
                }
                else {
                    tab[j] = tab[j] + tab[j + 1];
                }
            }
        }
        return tab[0];
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int input1(3);
        int input2(2);
        int expects(3);

        check("Test 1", input1, input2, expects);
    }


private:
    void check(const char* testname, int& input1, int& input2, const int& expects) {
        bool tst_pass = true;
        auto res = sol.uniquePaths(input1, input2);

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