//
// Created by hfq on 19-8-16.
//

#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(std::string& s, std::string& p) {
        if(s.empty()) {
            if(p.empty()) {
                return true;
            }
            for(int i = 0; i < p.size(); i++) {
                if(p[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(p.empty()) {
            return false;
        }
        return isMatchCore(s, p, 0, 0);

    }

    bool isMatchCore(std::string& s, std::string& p, int sind, int pind) {
        if(sind == s.size()) {
            if(pind == p.size()) {
                return true;
            }
            else {
                for(int i = pind; i < p.size(); i++) {
                    if(p[i] != '*') {
                        return false;
                    }
                }
                return true;
            }
        }

        if(pind == p.size()) {
            return false;
        }

        if(p[pind] == '?') {
            return isMatchCore(s, p, sind+1, pind+1);
        }
        if(p[pind] == '*') {
            while(pind < p.size() && p[pind] == '*') {
                pind++;
            }
            if(pind == p.size()) {
                return true;
            }
            if(p[pind] == '?') {
                bool match = false;
                for(int i = sind; i < s.size(); i++) {
                    match = match || isMatchCore(s, p, i, pind);
                }
                return match;
            }
            else {
                bool match = false;
                while(sind < s.size()) {
                    if(s[sind] == p[pind]) {
                        match = match || isMatchCore(s, p, sind, pind);
                    }
                    sind++;
                }
                return match;
            }
        }
        if(s[sind] != p[pind]) {
            return false;
        }
        return isMatchCore(s, p, sind+1, pind+1);
    }
};

int main(int argc, char** argv) {
    std::string s = "abefcdgiescdfimde";
    std::string p = "ab*cd?i*de";
    auto sol = Solution();
    std::cout << sol.isMatch(s, p) << std::endl;
    return 0;
}