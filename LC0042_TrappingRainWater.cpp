//
// Created by hfq on 19-8-16.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        if(height.size() < 2) {
            return 0;
        }
        std::vector<int> lmax;
        std::vector<int> rmax;
        lmax.resize(height.size(), 0);
        rmax.resize(height.size(), 0);
        int max = height[0];
        for(int i = 1; i < lmax.size(); i++) {
            if(height[i] > max) {
                max = height[i];
            }
            lmax[i] = max;
        }

        max = height.back();
        for(int i = height.size()-2; i >= 0; i--) {
            if(height[i] > max) {
                max = height[i];
            }
            rmax[i] = max;
        }

        int curnum = 0;
        int sum = 0;
        for(int i = 0; i < height.size(); i++) {
            curnum = lmax[i] < rmax[i] ? lmax[i] - height[i] : rmax[i] - height[i];
            curnum = curnum < 0 ? 0 : curnum;
            sum += curnum;
        }

        return sum;
    }
};

int main(int argc, char** argv) {
    auto sol = Solution();
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << sol.trap(height) << std::endl;
    return 0;
}