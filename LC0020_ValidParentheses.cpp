//
// Created by hfq on 19-5-15.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        if(s.empty()) {
            return true;
        }
        std::stack<char, std::vector<char>> st;
        for(auto iter = s.begin(); iter != s.end(); iter ++) {
            if(*iter=='(' || *iter=='[' || *iter=='{') {
                st.push(*iter);
            }
            else if(*iter==')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
            else if(*iter==']') {
                if(!st.empty() && st.top() == '[') {
                    st.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
            else if(*iter=='}') {
                if(!st.empty() && st.top() == '{') {
                    st.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return st.empty();
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::string input1("(){}[]");
        bool expects(true);
        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::string& input1, const bool& expects) {
        bool tst_pass = true;
        auto&& result = sol.isValid(input1);
        if(result != expects) {
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
