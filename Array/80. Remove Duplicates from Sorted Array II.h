//
// Created by Shinelon on 2017/9/20.
//

#ifndef ALGORITHM_INTERVIEW2_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H
#define ALGORITHM_INTERVIEW2_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /**
     * 超神版
     * @param nums
     * @return
     */
    int removeDuplicates(vector<int>& nums) {
        int d = 2;
        int k = 0;
        for(int n:nums){
            if(k<d || n > nums[k-d]){
                nums[k++] = n;
            }
        }
        return k;
    }

    /**
     * 大神版
     * @param nums
     * @return
     */
    int removeDuplicates2(vector<int>& nums) {
        int d = 2;
        int n = nums.size();
        int k = 0;
        for(int i=0; i<n; i++){
            if(i<2 || nums[i] != nums[k-d]){
                nums[k++] = nums[i];
            }
        }
        return k;
    }

    /**
     * 菜鸟版
     * 设置count，灵活调控可重复元素数量
     * @param nums
     * @return
     */
    int removeDuplicates1(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return n;
        }
        int d = 2;
        int k = 0;
        int count = 1;
        for(int i=1; i<n; i++){
            if(nums[k] != nums[i]){
                count = 1;
                k++;
                if(k != i){
                    nums[k] = nums[i];
                }
            }else{
                if(count < d){
                    count++;
                    k++;
                    if(k != i){
                        nums[k] = nums[i];
                    }
                }
            }
        }
        return k+1;
    }
};

#endif //ALGORITHM_INTERVIEW2_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H
//int arr[] = {1, 1, 1, 2, 2, 3};
//vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
//int len = Solution().removeDuplicates(vec);
//
//cout<<"len : "<<len<<endl;
//for(int i=0; i<vec.size(); i++){
//cout<<vec[i]<<" ";
//}