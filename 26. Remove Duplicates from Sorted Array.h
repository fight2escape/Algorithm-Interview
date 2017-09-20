//
// Created by Shinelon on 2017/9/20.
//

#ifndef ALGORITHM_INTERVIEW2_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define ALGORITHM_INTERVIEW2_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return n;
        }
        int k = 0;
        for(int i=1; i<n; i++){
            if(nums[k] != nums[i]){
                k++;
                if(k != i){
                    nums[k] = nums[i];
                }
            }
        }
        return k+1;
    }
};

#endif //ALGORITHM_INTERVIEW2_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
//int arr[] = {1, 1, 2};
//vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
//int len = Solution().removeDuplicates(vec);
//
//cout<<"len : "<<len<<endl;
//for(int i=0; i<vec.size(); i++){
//cout<<vec[i]<<" ";
//}