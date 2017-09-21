//
// Created by Shinelon on 2017/9/21.
//

#ifndef ALGORITHM_INTERVIEW2_88_MERGE_SORTED_ARRAY_H
#define ALGORITHM_INTERVIEW2_88_MERGE_SORTED_ARRAY_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /**
     * 时间复杂度 O(m+n)
     * 空间复杂度 O(1)
     * @param res
     * @param m
     * @param nums
     * @param n
     */
    void merge(vector<int>& res, int m, vector<int>& nums, int n) {
        int idx = m+n-1;
        m--, n--;
        while(m>=0 && n>=0){
            res[idx--] = (res[m] < nums[n]) ? nums[n--] : res[m--];
        }
        while(n>=0){
            res[idx--] = nums[n--];
        }
    }

    /**
     * 菜鸟版
     * 借住了额外空间
     * 时间复杂度 O(m+n)
     * 空间复杂度 O(m+n)
     * @param nums1
     * @param m
     * @param nums2
     * @param n
     */
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                res.push_back(nums1[i++]);
            }else{
                res.push_back(nums2[j++]);
            }
        }

        while(i < m){
            res.push_back(nums1[i++]);
        }
        while(j < n){
            res.push_back(nums2[j++]);
        }

        int rn = res.size();
        for(i=0; i<rn; i++){
            nums1[i] = res[i];
        }

    }
};

#endif //ALGORITHM_INTERVIEW2_88_MERGE_SORTED_ARRAY_H
//int arr1[8] = {1, 1, 1, 2, 2}, arr2[] = {1, 2, 3};
//vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(int));
//vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(int));
//Solution().merge(vec1, vec1.size()-vec2.size(), vec2, vec2.size());
//
//for(int i=0; i<vec1.size(); i++){
//cout<<vec1[i]<<" ";
//}