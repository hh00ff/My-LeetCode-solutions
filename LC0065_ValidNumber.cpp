//
// Created by hfq on 2019/8/19.
//

#include <iostream>
#include <string>

class Solution {
public:
    bool isNumber(std::string s) {
        trim(s);
        if(s.empty()) {
            return false;
        }
        bool isnum = true;
        int begin = 0;
        isnum = isnum && scanInteger(s, begin);
        if(begin == s.size()) {
            return true;
        }
        if(s[begin] == '.') {
            begin++;

            isnum = scanUnsignedInteger(s, begin) || isnum;
            if(begin == s.size()) {
                return isnum;
            }
        }
        if(s[begin] == 'e' || s[begin] == 'E') {
            begin++;
            isnum = isnum && scanInteger(s, begin);
        }
        isnum = isnum && (begin == s.size());
        return isnum;
    }

    bool scanInteger(std::string& s, int& begin) {
        if(begin < s.size() && (s[begin] == '-' || s[begin] == '+')) {
            begin++;
            return scanUnsignedInteger(s, begin);
        }
        else if(begin < s.size() && (s[begin] >= '0' && s[begin] <= '9')){
            return scanUnsignedInteger(s, begin);
        }
        else {
            return false;
        }
    }

    bool scanUnsignedInteger(std::string& s, int& begin) {
        int tmp = begin;
        while (begin < s.size() && (s[begin] >= '0' && s[begin] <= '9')){
            begin++;
        }
        return begin ^ tmp;
    }

    void trim(std::string &s)
    {
        if (s.empty())
        {
            return;
        }

        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }

};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("0");
        bool expects(true);

        check("Test 1", input1, expects);
    }

    void test2() {
        std::string input1("1 ");
        bool expects(true);

        check("Test 2", input1, expects);
    }

    void test3() {
        std::string input1(".1 ");
        bool expects(true);

        check("Test 3", input1, expects);
    }

    void test4() {
        std::string input1(".");
        bool expects(false);

        check("Test 4", input1, expects);
    }


private:
    void check(const char* testname, std::string& input1, const int& expects) {
        bool tst_pass = true;
        auto res = sol.isNumber(input1);

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
    tst.test2();
    tst.test3();
    tst.test4();
    return 0;
}