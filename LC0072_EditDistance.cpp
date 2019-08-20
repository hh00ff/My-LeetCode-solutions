//
// Created by hfq on 2019/8/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        std::vector<std::vector<int>> tab(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
        for(int i = 0; i <= word1.size(); i++) {
            tab[i][0] = i;
        }
        for(int i = 0; i <= word2.size(); i++) {
            tab[0][i] = i;
        }

        for(int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i-1] == word2[j-1]) {
                    tab[i][j] = tab[i-1][j-1];
                }
                else {
                    tab[i][j] = 1 + std::min(tab[i-1][j], std::min(tab[i][j-1], tab[i-1][j-1]));
                }
            }
        }
        return tab[word1.size()][word2.size()];
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("horse");
        std::string input2("ros");
        int expects(3);

        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::string& input1, std::string& input2, const int& expects) {
        bool tst_pass = true;
        auto res = sol.minDistance(input1, input2);

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
