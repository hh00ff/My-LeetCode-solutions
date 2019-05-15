//
// Created by hfq on 19-5-8.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        if(height.empty()) {
            return 0;
        }
        int indl = 0;
        int indr = height.size()-1;
        int max_area = 0;
        int cur_area = 0;
        while(indr-indl >= 1) {
            if(height[indl]<height[indr]) {
                cur_area = height[indl] * (indr - indl);
                indl++;
            }
            else {
                cur_area = height[indr] * (indr - indl);
                indr --;
            }
            max_area = cur_area > max_area ? cur_area : max_area;
        }
        return max_area;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1({1,8,6,2,5,4,8,3,7});
        int expected(49);
        check("Test 1", input1, expected);
    }

private:
    void check(const char* testname, std::vector<int>& input1, const int& expected) {
        bool tst_pass = true;
        auto&& result = sol.maxArea(input1);
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