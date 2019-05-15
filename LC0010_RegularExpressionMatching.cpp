//
// Created by hfq on 19-5-7.
//

#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        std::string::iterator sIter = s.begin();
        std::string::iterator pIter = p.begin();
        int* tab = new int[(s.size()+1)*(p.size()+1)];
        for(int i = 0; i < (s.size()+1)*(p.size()+1); i++) {
            tab[i] = -1;
        }
        bool res = isMatchCore(s, p, sIter, pIter, tab);
        delete[] tab;
        return res;
    }
    bool isMatchCore(std::string& s, std::string& p, std::string::iterator sIter, std::string::iterator pIter, int* tab) {
        int curInd = (sIter-s.begin()) * (p.size()+1) + (pIter-p.begin());
        if(tab[curInd]!=-1) {
            return tab[curInd];
        }
        bool tmp;
        if(sIter==s.end() && pIter==p.end()) {
            tab[curInd] = 1;
            return true;
        }
        if(sIter!=s.end() && pIter==p.end()){
            tab[curInd] = 0;
            return false;
        }
        if((pIter+1)!=p.end() && *(pIter+1)=='*') {
            if(sIter!=s.end() && (*sIter==*pIter || *pIter=='.')) {
                tmp = isMatchCore(s, p, sIter+1, pIter+2, tab) || isMatchCore(s, p, sIter+1, pIter, tab) || isMatchCore(s, p, sIter, pIter+2, tab);
                tab[curInd] = (int)tmp;
                return tmp;
            }
            else {
                tmp = isMatchCore(s, p, sIter, pIter+2, tab);
                tab[curInd] = (int)tmp;
                return tmp;
            }
        }
        if(sIter!=s.end() && (*pIter==*sIter || *pIter=='.')) {
            tmp = isMatchCore(s, p, sIter+1, pIter+1, tab);
            tab[curInd] = (int)tmp;
            return tmp;
        }
        tab[curInd] = 0;
        return false;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("aaaaab");
        std::string input2("a*a*a*a*a*c");
        bool expected(false);
        check("Test 1", input1, input2, expected);
    }

private:
    void check(const char* testname, std::string& input1, std::string& input2, const bool& expected) {
        bool tst_pass = true;
        auto&& result = sol.isMatch(input1, input2);
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