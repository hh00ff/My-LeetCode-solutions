//
// Created by hfq on 2019/11/2.
//

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int n = s.size(), m = t.size();
        std::vector<std::vector<long>> dp(n+1, std::vector<long>(m+1, 0));
        for(int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }
        for(int j = m-1; j >= 0; j--) {
            for(int i = n-1; i >= 0; i--) {
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
                }
                else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};