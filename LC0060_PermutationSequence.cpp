//
// Created by hfq on 2019/8/18.
//

#include <iostream>
#include <string>
#include <set>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        int factorial = 1;
        if(n < 1 || n > 9 || k < 1) {
            return "err";
        }
        std::set<char> tab;
        for(int i = 1; i <= n; i++) {
            factorial *= i;
            tab.insert(i + '0');
        }
        if(k > factorial) {
            return "err";
        }

        std::string res;
        int sum = 0, curind = 0, curnum = 0, count = 0;
        std::set<char>::iterator iter;

        for(int i = n; i >= 2; i--) {
            factorial /= i;
            curind = k / factorial;
            k = k % factorial;
            curind += k == 0 ? 0 : 1;

            count = 0;
            for(int j = 1; j <= n; j++) {
                iter = tab.find(j + '0');
                if(iter != tab.end()) {
                    count++;
                }
                if(count == curind) {
                    curnum = *iter - '0';
                    tab.erase(iter);
                    break;
                }
            }
            sum += curnum;
            res.push_back( curnum + '0');


            if(k == 0 ){
                std::string tmp;
                for(int j = 1; j <= 9; j++) {
                    iter = tab.find(j + '0');
                    if(iter != tab.end()) {
                        tmp.push_back(*iter);
                        tab.erase(iter);
                    }
                }
                for(int j = i - 2; j >= 0; j--) {
                    res.push_back( tmp[j]);
                }
                break;
            }

        }
        if(k != 0){
            res.push_back((1 + n) * n / 2 - sum + '0');
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
        int input1(3);
        int input2(3);
        std::string expects("213");

        check("Test 1", input1, input2, expects);
    }

    void test2() {
        int input1(4);
        int input2(9);
        std::string expects("2314");

        check("Test 2", input1, input2, expects);
    }

    void test3() {
        int input1(2);
        int input2(2);
        std::string expects("21");

        check("Test 3", input1, input2, expects);
    }

    void test4() {
        int input1(3);
        int input2(2);
        std::string expects("132");

        check("Test 4", input1, input2, expects);
    }

    void test5() {
        int input1(9);
        int input2(54494);
        std::string expects("248716395");

        check("Test 5", input1, input2, expects);
    }

private:
    void check(const char* testname, int& input1, int& input2, const std::string& expects) {
        bool tst_pass = true;
        auto res = sol.getPermutation(input1, input2);

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
    tst.test5();
    return 0;
}