//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_209_MINIMUM_SIZE_SUBARRAY_SUM_H
#define ALGORITHM_INTERVIEW2_209_MINIMUM_SIZE_SUBARRAY_SUM_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /**
     * 滑动窗口
     * 时间复杂度 O(n)
     * @param s
     * @param nums
     * @return
     */
    int minSubArrayLen(int s, vector<int>& nums) {
        int lt = 0, gt = -1;
        int sum = 0;
        int n= nums.size(),sz = n+1;
        while(lt < n){
            if(gt+1 < n && sum < s){
                sum += nums[++gt];
            }else{
                sum -= nums[lt++];
            }
            if(sum >= s){
                sz = min(sz, gt-lt+1);
            }
        }
        if(sz == n+1){
            return 0;
        }
        return sz;
    }

    /**
     * 时间复杂度 O(n^2)
     * 一定步长内的数组，首次计算后，可以只计算下一个元素和数组中的首个元素的差即可，免去中间元素的重复计算
     * @param s
     * @param nums
     * @return
     */
    int minSubArrayLen2(int s, vector<int>& nums) {
        int sum, sz=1;
        int n = nums.size();
        int add;
        while(sz <= n){
            sum = 0;
            for(int i = 0; i<=n-sz; i++){
                if(sum == 0){
                    for(int j=i; j<i+sz; j++){
                        sum += nums[j];
                    }
                }else{
                    sum += nums[i+sz-1] - nums[i-1];
                }
                if(sum >= s){
                    return sz;
                }
            }
            sz++;
        }
        return 0;
    }

    /**
     * 时间复杂度 O(n^3)
     * @param s
     * @param nums
     * @return
     */
    int minSubArrayLen1(int s, vector<int>& nums) {
        int sum, sz=1;
        int n = nums.size();
        while(sz <= n){
            for(int i = 0; i<=n-sz; i++){
                sum = 0;
                for(int j = i; j < i+sz; j++){
                    sum += nums[j];
                }
                if(sum >= s){
                    return sz;
                }
            }
            sz++;
        }
        return 0;
    }
};

#endif //ALGORITHM_INTERVIEW2_209_MINIMUM_SIZE_SUBARRAY_SUM_H
//int arr1[] = {2,3,1,2,4,3}, s1 = 7;
//int arr2[] = {}, s2 = 100;
//int arr3[] = {1,2,3,4,5}, s3 = 15;
//int arr4[] = {1,1}, s4 = 3;
//vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(int));
//vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(int));
//vector<int> vec3(arr3, arr3 + sizeof(arr3)/sizeof(int));
//vector<int> vec4(arr3, arr4 + sizeof(arr4)/sizeof(int));
//int res1 = Solution().minSubArrayLen(s1, vec1);
//int res2 = Solution().minSubArrayLen(s2, vec2);
//int res3 = Solution().minSubArrayLen(s3, vec3);
//int res4 = Solution().minSubArrayLen(s4, vec4);
//
//cout<<"minSubArrayLen : "<<res1<<endl;
//cout<<"minSubArrayLen : "<<res2<<endl;
//cout<<"minSubArrayLen : "<<res3<<endl;
//cout<<"minSubArrayLen : "<<res4<<endl;