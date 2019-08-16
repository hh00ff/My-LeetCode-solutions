//
// Created by hfq on 19-8-16.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string &s, std::string &p) {
        if (s.empty()) {
            if (p.empty()) {
                return true;
            }
            for (int i = 0; i < p.size(); i++) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (p.empty()) {
            return false;
        }

        std::vector< std::vector<bool> > dp(s.size()+1, std::vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        for(int j = 1; j < p.size()+1; j++) {
            if(p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }

        for(int i = 1; i < s.size()+1; i++) {
            for(int j = 1; j < p.size()+1; j++) {
                if(p[j-1] == '?' || s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[s.size()][p.size()];

    }
};