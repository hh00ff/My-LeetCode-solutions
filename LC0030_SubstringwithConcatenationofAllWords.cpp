//
// Created by hfq on 19-6-13.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> res;
        if(s.empty() || words.empty()) {
            return res;
        }

        std::unordered_map<std::string, int> wordTab;

        int wl = words[0].size();
        int wc = words.size();
        int winlen = wl * wc;
        for(int i = 0; i < words.size(); i++) {
            if(wordTab.find(words[i]) == wordTab.end()) {
                wordTab.insert(std::make_pair(words[i], 1));
            }
            else {
                wordTab[words[i]]++;
            }
        }

        int* wordNums = new int[wordTab.size()]();
        int* sMatch = new int[s.size()]();
        int ind = 0;
        int pos = 0;
        for(int i = 0; i < s.size(); i++) {
            sMatch[i] = -1;
        }

        for(auto iter = wordTab.begin(); iter != wordTab.end(); iter ++) {
            wordNums[ind] = iter -> second;
            pos = 0;
            while(pos != std::string::npos) {
                pos = s.find(iter -> first, pos);
                if(pos != std::string::npos) {
                    sMatch[pos] = ind;
                    pos += 1;
                }
            }
            ind++;
        }

        for(int i = 0; i < s.size()-winlen+1; i++) {
            if(sMatch[i] != -1) {
                ind = 0;
                for(auto iter = wordTab.begin(); iter != wordTab.end(); iter++) {
                    wordNums[ind] = iter -> second;
                    ind++;
                }
                int j = 0;
                for(; j < wc; j++) {
                    if(sMatch[i + j * wl] == -1 || wordNums[sMatch[i + j * wl]] == 0) {
                        break;
                    }
                    else {
                        wordNums[sMatch[i + j * wl]]--;
                    }
                }
                if(j == wc) {
                    res.push_back(i);
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
        std::string input1("aaaaaaaa");
        std::vector<std::string> input2({"aa", "aa", "aa"});
        std::vector<int> expects({0, 1, 2});
        check("Test 1", input1, input2, expects);
    }

private:
    void check(const char* testname, std::string& input1, std::vector<std::string>& input2, const std::vector<int>& expects) {
        bool tst_pass = true;
        auto&& result = sol.findSubstring(input1, input2);
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