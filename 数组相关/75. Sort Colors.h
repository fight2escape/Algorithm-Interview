//
// Created by Shinelon on 2017/9/20.
//

#ifndef ALGORITHM_INTERVIEW2_75_SORT_COLORS_H
#define ALGORITHM_INTERVIEW2_75_SORT_COLORS_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /**
     * 三路快排
     * 时间复杂度 O(n)
     * 空间复杂度 O(1)
     * Runtime: 3 ms
     * @param nums
     */
    void sortColors(vector<int>& nums) {
        // [0, lt], [lt+1, gt-1], [gt, nums.size()-1]
        int q = 1;
        int lt = -1, gt = nums.size(), i=0;
        while(i < gt){
            if(nums[i] < q){
                swap(nums[++lt], nums[i]);
                i++;
            }else if(nums[i] > q){
                swap(nums[--gt], nums[i]);
            }else{
                i++;
            }
        }
    }

    /**
     * 菜鸟版
     * 计数排序
     * 时间复杂度 O(n)
     * 空间复杂度 O(1)
     * Runtime: 6 ms
     * @param nums
     */
    void sortColors1(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return;
        }
        vector<int> count = {0, 0, 0};
        for(int i=0; i<n; i++){
            count[nums[i]]++;
        }
        int k = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<count[i]; j++){
                nums[k++] = i;
            }
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_75_SORT_COLORS_H
//int arr[] = {1, 1, 1, 2, 2, 0};
//vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
//Solution().sortColors(vec);
//
//for(int i=0; i<vec.size(); i++){
//cout<<vec[i]<<" ";
//}