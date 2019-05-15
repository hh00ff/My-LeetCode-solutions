//
// Created by hfq on 19-5-9.
//

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<std::string, int> hash_tab = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
                                                          {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10},
                                                          {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
        int res = 0;
        auto sIter = s.begin();
        std::string key;
        while(sIter!=s.end()) {
            if(*sIter == 'C' && (sIter+1)!=s.end() && *(sIter+1)=='M') {
                key = "CM";
                sIter += 2;
            }
            else if(*sIter == 'C' && (sIter+1)!=s.end() && *(sIter+1)=='D') {
                key = "CD";
                sIter += 2;
            }
            else if(*sIter == 'X' && (sIter+1)!=s.end() && *(sIter+1)=='C') {
                key = "XC";
                sIter += 2;
            }
            else if(*sIter == 'X' && (sIter+1)!=s.end() && *(sIter+1)=='L') {
                key = "XL";
                sIter += 2;
            }
            else if(*sIter == 'I' && (sIter+1)!=s.end() && *(sIter+1)=='X') {
                key = "IX";
                sIter += 2;
            }
            else if(*sIter == 'I' && (sIter+1)!=s.end() && *(sIter+1)=='V') {
                key = "IV";
                sIter += 2;
            }
            else {
                key = *sIter;
                sIter ++;
            }
            auto mpIter = hash_tab.find(key);
            if(mpIter!=hash_tab.end()) {
                res += mpIter->second;
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
        std::string input1("MCMXCIV");
        int expected(1994);
        check("Test 1", input1, expected);
    }

private:
    void check(const char* testname, std::string& input1, const int& expected) {
        bool tst_pass = true;
        auto&& result = sol.romanToInt(input1);
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