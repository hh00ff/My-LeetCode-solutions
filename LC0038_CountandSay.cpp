//
// Created by hfq on 19-7-19.
//

#include <iostream>
#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string res;
        if(n < 1) {
            return res;
        }

        res = "1";
        int count = 0;
        char curch = '1';
        std::string tmpstr;
        std::string numstack;
        for(int i = 1; i < n; i++) {
            count = 0;
            curch = res[0];
            for(auto iter = res.begin(); iter != res.end(); iter ++) {
                if(*iter == curch) {
                    count ++;
                }
                else {
                    while(count != 0) {
                        numstack.push_back(count % 10 + '0');
                        count = count / 10;
                    }
                    for(auto riter_num = numstack.rbegin(); riter_num != numstack.rend(); riter_num++) {
                        tmpstr.push_back(*riter_num);
                    }
                    tmpstr.push_back(curch);
                    curch = *iter;
                    numstack.clear();
                    count = 1;
                }
            }

            while(count != 0) {
                numstack.push_back(count % 10 + '0');
                count = count / 10;
            }
            for(auto riter_num = numstack.rbegin(); riter_num != numstack.rend(); riter_num++) {
                tmpstr.push_back(*riter_num);
            }
            tmpstr.push_back(curch);
            numstack.clear();

            res = tmpstr;
            tmpstr.clear();
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
            int input1(5);

            std::string expects("111221");

            check("Test 1", input1, expects);
        }

        private:
        void check(const char* testname, int& input1, const std::string& expects) {
            bool tst_pass = true;
            auto res = sol.countAndSay(input1);

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