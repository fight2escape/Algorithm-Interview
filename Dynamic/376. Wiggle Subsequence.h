//
// Created by Shinelon on 2017/10/2.
//

#ifndef ALGORITHM_INTERVIEW2_376_WIGGLE_SUBSEQUENCE_H
#define ALGORITHM_INTERVIEW2_376_WIGGLE_SUBSEQUENCE_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /**
     * 与LIS类似，但设置一升一降两个数组进行记录
     * @param nums
     * @return
     */
    int wiggleMaxLength(vector<int>& nums) {
        const int n = nums.size();
        if( n<= 0){ return 0; }
        vector<int> f(n, 1);
        vector<int> d(n, 1);
        int ret = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    f[i] = max(f[i], 1 + d[j]);
                }else if(nums[i] < nums[j]){
                    d[i] = max(d[i], 1 + f[j]);
                }
            }
            ret = max(ret, max(f[i], d[i]));
        }
        return ret;
    }


    /**
     * 设置一个flag，表示期待的下一个数的大小关系
     * -1表示第一个数以及和第一个数相等的数，0表示期待较小的数，1表示期待较大的数
     * @param nums
     * @return
     */
    int wiggleMaxLength1(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0){ return 0; }
        vector<pair<int,int>> res(n,make_pair(1,-1));
        for(int i=1; i<n; i++){
            int wig = 1;
            int flag = -1;
            for(int j=0; j<i; j++){
                if(res[j].second == -1){
                    if(nums[j] > nums[i]){
                        wig = max(wig, 1 + res[j].first);
                        flag = 1;
                    }else if(nums[j] < nums[i]){
                        wig = max(wig, 1 + res[j].first);
                        flag = 0;
                    }
                }else if(res[j].second == 1){
                    if(nums[j] < nums[i]){
                        wig = max(wig, 1 + res[j].first);
                        flag = 0;
                    }
                }else{
                    if(nums[j] > nums[i]){
                        wig = max(wig, 1 + res[j].first);
                        flag = 1;
                    }
                }
            }
            res[i].first = wig;
            res[i].second = flag;
        }
        int ret = 1;
        for(auto r:res){
            ret = max(ret, r.first);
        }
        return ret;
    }
};

#endif //ALGORITHM_INTERVIEW2_376_WIGGLE_SUBSEQUENCE_H
//    vector<int> vec = {1,7,4,9,2,5};
//    vector<int> vec = {1,17,5,10,13,15,10,5,16,8};
//    vector<int> vec = {1,2,3,4,5,6,7,8,9};
//    vector<int> vec = {};
//    cout<< Solution().wiggleMaxLength(vec) <<endl;
