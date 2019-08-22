//
// Created by hfq on 2019/8/21.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        if(n < k || n <= 0 || k <= 0) {
            return res;
        }
        std::vector<int> curnum(k + 1, 0);
        for(int i = 0; i < k; i++) {
            curnum[i] = i + 1;
        }
        curnum[k] = n + 1;
        int i = 0;
        while(i < k) {
            res.emplace_back(curnum.begin(), curnum.end() - 1);
            i = 0;
            while(i < k && curnum[i] + 1 == curnum[i+1]) {
                curnum[i] = i + 1;
                i++;
            }
            curnum[i]++;
        }
        return res;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        int input1(4);
        int input2(2);
        std::vector<std::vector<int>> expects({{1, 2}, {1, 3}, {2, 3}, {1, 4}, {2, 4}, {3, 4}});

        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, int& input1, int& input2, const std::vector<std::vector<int>>& expects) {
        bool tst_pass = true;
        auto res = sol.combine(input1, input2);

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
