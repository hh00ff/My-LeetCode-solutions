//
// Created by hfq on 19-4-19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int iMin = 0;
        int iMax = m;
        int i, j;

        if(m>n) {
            nums1.swap(nums2);
            m = nums1.size();
            n = nums2.size();
            iMax= m;
        }

        if(m==0 && n==0) {
            return 0.0;
        }
        else if(m==0) {
            if(n & 0x00000001) {
                return static_cast<double>(nums2[n/2+1]);
            }
            else {
                return (static_cast<double>(nums2[n/2]) + static_cast<double>(nums2[n/2+1]))/2.0;
            }
        }

        while(iMin <= iMax) {
            i = (iMax + iMin)/2;
            j = (m + n + 1)/2 - i;
            if(i<iMax && j>0 && nums1[i]<nums2[j-1]) {
                iMin = i + 1;
            }
            else if(i>iMin && j<n && nums1[i-1]>nums2[j]) {
                iMax = i - 1;
            }
            else {
                int maxLeft = 0;
                if(i == 0) {
                    maxLeft = nums2[j-1];
                }
                else if(j == 0) {
                    maxLeft = nums1[i-1];
                }
                else {
                    maxLeft = std::max(nums1[i-1], nums2[j-1]);
                }
                if((m + n) & 0x00000001) {
                    return static_cast<double>(maxLeft);
                }

                int minRight = 0;
                if(i == m) {
                    minRight = nums2[j];
                }
                else if(j == n) {
                    minRight = nums1[i];
                }
                else{
                    minRight = std::min(nums1[i], nums2[j]);
                }
                return (static_cast<double>(maxLeft) + static_cast<double>(minRight))/2.0;
            }
        }
        return 0.0;
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
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 20004f1791f32705d7aea711649b1d5c288a4b5e
