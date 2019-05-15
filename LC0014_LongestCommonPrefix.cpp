//
// Created by hfq on 19-5-9.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string res;
        for(auto vIter = strs.begin(); vIter != strs.end(); vIter ++) {
            if(vIter == strs.begin()) {
                res = *vIter;
                continue;
            }
            if(res.size()>(*vIter).size()) {
                res.erase((*vIter).size());
            }
            for(int i = 0; i < res.size() && i < (*vIter).size(); i++) {
                if(res[i] != (*vIter)[i]) {
                    res.erase(i);
                    break;
                }
            }
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
        std::vector<std::string> input1 = {"flower", "flow", "flight"};
        std::string expected("fl");
        check("Test 1", input1, expected);
    }

private:
    void check(const char* testname, std::vector<std::string>& input1, const std::string& expected) {
        bool tst_pass = true;
        auto&& result = sol.longestCommonPrefix(input1);
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