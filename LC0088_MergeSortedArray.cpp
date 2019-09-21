//
// Created by hfq on 2019/9/21.
//

#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int curInd = m + n - 1;
        m--;
        n--;
        while(m >= 0 || n >= 0) {
            if(m < 0) {
                nums1[curInd] = nums2[n];
                n--;
                curInd--;
            }
            else if(n < 0) {
                nums1[curInd] = nums1[m];
                m--;
                curInd--;
            }
            else {
                if(nums1[m] > nums2[n]) {
                    nums1[curInd] = nums1[m];
                    m--;
                    curInd--;
                }
                else {
                    nums1[curInd] = nums2[n];
                    n--;
                    curInd--;
                }
            }
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }


    void test1() {
        std::vector<int> input1({1, 2, 3, 0, 0, 0});
        int input2(3);
        std::vector<int> input3({2, 5, 6});
        int input4(3);
        std::vector<int> expects1({1, 2, 2, 3, 5, 6});

        check("Test 1", input1, input2, input3, input4, expects1);
    }

private:
    void check(const char* testname, std::vector<int>& input1, int input2, std::vector<int>& input3, int input4,
            const std::vector<int>& expects1) {
        bool tst_pass = true;
        sol.merge(input1, input2, input3, input4);
        auto res = input1;

        if(res != expects1) {
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