//
// Created by hfq on 19-8-13.
//

#include <iostream>
#include <vector>

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if(N <= 0) {
            return false;
        }
        std::vector<int>&& tab = digitCount(N);
        int curnum = 1;
        for(int i = 0; i < 31; i++) {
            if(tab == digitCount(curnum)) {
                return true;
            }
            curnum <<= 1;
            std::cout << curnum << std::endl;
        }
        return false;
    }

    std::vector<int> digitCount(int N) {
        std::vector<int> res;
        res.resize(10, 0);
        while(N) {
            res[N % 10] ++;
            N /= 10;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    auto sol = Solution();
    std::cout << sol.reorderedPowerOf2(46);
    return 0;
}