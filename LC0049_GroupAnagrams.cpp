//
// Created by hfq on 2019/8/17.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& str) {
        std::vector<std::vector<std::string>> res;
        if(str.empty()) {
            return res;
        }

        std::unordered_map<std::string, std::vector<std::string>> htab;
        std::string tmpstr;
        for(int i = 0; i < str.size(); i++) {
            tmpstr = str[i];
            std::sort(tmpstr.begin(), tmpstr.end());
            htab[tmpstr].push_back(str[i]);
        }

        for(auto iter = htab.begin(); iter != htab.end(); iter++) {
            res.push_back(iter->second);
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
        std::vector<std::string> input1({"eat", "tea", "tan", "ate", "nat", "bat"});
        std::vector<std::vector<std::string>> expects({{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}});

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector<std::string>& input1, const std::vector<std::vector<std::string>>& expects) {
        bool tst_pass = true;
        auto res = sol.groupAnagrams(input1);

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