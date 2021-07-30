//
// Created by hfq on 2021/7/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(nums1.empty() && nums2.empty()) {
            return 0.0;
        }
        if(nums1.empty()) {
            if(len2 % 2){
                return static_cast<double>(nums2[len2 / 2]);
            }
            else {
                return (static_cast<double>(nums2[len2/2-1]) + static_cast<double>(nums2[len2/2])) / 2;
            }
        }
        if(nums2.empty()) {
            if(len1 % 2){
                return static_cast<double>(nums1[len1 / 2]);
            }
            else {
                return (static_cast<double>(nums1[len1/2-1]) + static_cast<double>(nums1[len1/2])) / 2;
            }
        }
        int offset1 = 0;
        int offset2 = 0;
        int target = (len1 + len2) / 2 + 1;
        int curTar = target;
        int i = 0;
        int j = 0;
        while(offset1 < len1 && offset2 < len2 && curTar > 1) {
            i = offset1 + curTar / 2;
            j = offset2 + curTar / 2;
            if(i >= len1) {
                i = len1 - 1;
            }
            if(j >= len2) {
                j = len2 - 1;
            }
            if(nums1[i] <= nums2[j]) {
                offset1 = i;
            }
            else {
                offset2 = j;
            }
            curTar = target - offset1 - offset2;
        }
        if(curTar == 1) {

        }
        if(offset1 == len1) {
            j = offset2 + curTar - 1;
            if(curTar == 1) {

            }
        }
        else {
            i = offset1 + curTar - 1;
        }
    }
};