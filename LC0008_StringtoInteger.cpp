//
// Created by hfq on 19-4-30.
//
#include <iostream>
#include <string>

class Solution {
public:
    int myAtoi(std::string str) {
        std::string::iterator iter = str.begin();
        while(*iter == ' ' && iter != str.end()) {
            iter ++;
        }
        if(iter == str.end()){
            return 0;
        }
        int flag = 1;
        if(*iter == '+'){
            iter++;
        }
        else if(*iter == '-'){
            flag = 0;
            iter++;
        }
        int res = 0;
        static const int max_int = 0x7FFFFFFF;
        static const int min_int = 0x80000000;
        static int max_check = 0x7FFFFFFF / 10;
        static const int tail_check = 7 + flag;
        int tmp = 0;
        while(*iter>='0' && *iter<='9') {
            tmp = *iter - '0';
            if(res>max_check || (res==max_check && tmp>=tail_check)) {
                if(flag) {
                    return max_int;
                }
                else {
                    return min_int;
                }
            }
            res = res * 10 + tmp;
            iter++;
        }
        if(flag) {
            return res;
        }
        else {
            return -res;
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("   42");
        int expected(42);
        check("Test 1", input1, expected);
    }

private:
    void check(const char* testname, std::string& input1, const int& expected) {
        bool tst_pass = true;
        auto&& result = sol.myAtoi(input1);
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
