//
// Created by Shinelon on 2017/9/21.
//

#ifndef ALGORITHM_INTERVIEW2_215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H
#define ALGORITHM_INTERVIEW2_215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H

#include <iostream>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

class Solution {
public:

    /**
     * 进化版
     * 使用最小堆，保存前K大的数
     * @param nums
     * @param k
     * @return
     */
    int findKthLargest(vector<int>& nums , int k){
        priority_queue<int, vector<int>, greater<int>> min_pq;
        for(int i=0; i<nums.size(); i++){
            min_pq.push(nums[i]);
            if(min_pq.size() > k){
                min_pq.pop();
            }
        }
        return min_pq.top();
    }

    /**
     * 菜鸟版
     * 快排中，只对所在的那部分进行partition
     */

    int __partition(vector<int>& nums, int l, int r){
        swap(nums[rand() % (r-l+1) + l],nums[l]);

        int p = nums[l];
        // [l, lt], p, [lt+1, r]
        int lt = l;
        for(int i=l+1; i<=r; i++){
            if(nums[i] < p){
                swap(nums[i], nums[++lt]);
            }
        }
        swap(nums[l], nums[lt]);
        return lt;
    }

    int __findKthLargest(vector<int>& nums, int l, int r, int k){

        int m = __partition(nums, l, r);
        if(k < m){
            return __findKthLargest(nums, l, m-1, k);
        }else if(k > m){
            return __findKthLargest(nums, m+1, r, k);
        }else{
            return nums[m];
        }
    }

    int findKthLargest1(vector<int>& nums, int k) {
        srand(time(NULL));

        k = nums.size() - k;
        int res = __findKthLargest(nums, 0, nums.size()-1, k);
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H
//int arr[] = {7,6,5,4,3,2,1}, k = 2;
//vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
//int res = Solution().findKthLargest(vec, k);
//
//cout<<"res : "<<res<<endl;
//
//for(int i=0; i<vec.size(); i++){
//cout<<vec[i]<<" ";
//}