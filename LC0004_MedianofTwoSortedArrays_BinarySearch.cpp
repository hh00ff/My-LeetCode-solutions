//
// Created by hfq on 2021/7/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findKthElement(const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(nums1.empty() && nums2.empty()) {
            return 0;
        }
        if(k > len1 + len2) {
            return 0;
        }

        int ind1 = 0;
        int ind2 = 0;
        while(true) {
            if(ind1 >= len1) {
                return nums2[ind2 + k - 1];
            }
            if(ind2 >= len2) {
                return nums1[ind1 + k - 1];
            }
            if(k == 1) {
                return std::min(nums1[ind1], nums2[ind2]);
            }
            int newInd1 = std::min(ind1 + k / 2 - 1, len1 - 1);
            int newInd2 = std::min(ind2 + k / 2 - 1, len2 - 1);
            if(nums1[newInd1] <= nums2[newInd2]) {
                k -= newInd1 - ind1 + 1;
                ind1 = newInd1 + 1;
            }
            else {
                k -= newInd2 - ind2 + 1;
                ind2 = newInd2 + 1;
            }
        }
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if((len1 + len2) % 2) {
            return static_cast<double>(findKthElement(nums1, nums2, (len1 + len2) / 2 + 1));
        }
        else {
            return static_cast<double>(findKthElement(nums1, nums2, (len1+len2)/2+1) + findKthElement(nums1, nums2, (len1+len2)/2))/2.0;
        }
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<int> input1 = {1, 3};
        std::vector<int> input2 = {2};
        double expected = 2.0;
        check("Test 1", input1, input2, expected);
    }

    void test2() {
        std::vector<int> input1 = {1, 2};
        std::vector<int> input2 = {3, 4};
        double expected = 2.5;
        check("Test 2", input1, input2, expected);
    }

    void test3() {
        std::vector<int> input1 = {4};
        std::vector<int> input2 = {1, 2, 3, 5, 6};
        double expected = 3.5;
        check("Test 3", input1, input2, expected);
    }

private:
    void check(const char* testname, std::vector<int>& input1, std::vector<int>& input2,const double& expected) {
        bool tst_pass = true;
        auto&& result = sol.findMedianSortedArrays(input1, input2);
        static const double delta = 1e-8;
        if(result - expected > delta || result - expected < -delta) {
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
    tst.test2();
    tst.test3();
    return 0;
}
