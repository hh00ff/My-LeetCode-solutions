//
// Created by hfq on 2019/9/21.
//
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> res;
        std::string curS;
        if(s.size() < 4 || s.size() > 12) {
            return res;
        }
        curS.reserve(16);
        restoreCore(s, curS, res, 0, 0);
        return res;
    }

    void restoreCore(std::string& s, std::string& curS, std::vector<std::string>& res, int ind, int dot) {

        if(dot == 3) {
            if(isValid(s, ind, s.size()-1)) {
                int i = ind;
                while(i < s.size()) {
                    curS.push_back(s[i]);
                    i++;
                }
                res.push_back(curS);
                while(i > ind) {
                    curS.pop_back();
                    i--;
                }
            }
            return;
        }

        int i = ind;
        while(i - ind < 3){

            if(i < s.size() && isValid(s, ind, i)) {
                curS.push_back(s[i]);
                curS.push_back('.');
                restoreCore(s, curS, res, 1+i, dot+1);
                curS.pop_back();
            }
            else {
                break;
            }
            i++;
        }
        while(i > ind) {
            curS.pop_back();
            i--;
        }

    }

    bool isValid(std::string& s, int beg, int end) {
        int len = end - beg + 1;
        if(len == 1) {
            return true;
        }
        if(len == 2) {
            return s[beg] != '0';
        }
        if(len == 3) {
            if(s[beg] == '1') {
                return true;
            }
            else if(s[beg] == '2') {
                if(s[beg + 1] >= '0' && s[beg + 1] <= '4') {
                    return true;
                }
                else if(s[beg + 1] == '5') {
                    return s[beg + 2] <= '5';
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return false;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }


    void test1() {
        std::string input1("25525511135");
        std::vector<std::string> expects1({"255.255.11.135", "255.255.111.35"});

        check("Test 1", input1, expects1);
    }

    void test2() {
        std::string input1("000256");
        std::vector<std::string> expects1({});

        check("Test 2", input1, expects1);
    }

private:
    void check(const char* testname, std::string& input1, const std::vector<std::string>& expects1) {
        bool tst_pass = true;
        auto res = sol.restoreIpAddresses(input1);

        if(res != expects1) {
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