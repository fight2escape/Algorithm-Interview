//
// Created by Shinelon on 2017/10/7.
//

#ifndef ALGORITHM_INTERVIEW2_683_K_EMPTY_SLOTS_H
#define ALGORITHM_INTERVIEW2_683_K_EMPTY_SLOTS_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 先转化成各花开花时间的数组，然后使用滑动窗口进行判断
     * 如果有多个值，返回小的结果
     * @param flowers
     * @param k
     * @return
     */
    int kEmptySlots(vector<int>& flowers, int k) {
        int n=flowers.size();
        vector<int> bloom(n+1, 0);
        for(int i=0; i<n; i++){
            bloom[flowers[i]] = i+1;
        }
        int res = n+1;
        for(int i=1; i<n-k; i++){
            int day = max(bloom[i], bloom[i+k+1]);
            bool flag = true;
            for(int j=i+1; j<i+k+1; j++){
                if(bloom[j] <= day){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res = min(res, day);
            }
        }
        return res>n ? -1 : res;
    }
};

class Test{
public:
    void test(){
//        vector<int> flowers = {1,3,2};
//        int k = 1;
//        vector<int> flowers = {6,5,8,9,7,1,10,2,3,4};
//        int k = 2;
        vector<int> flowers = {3,9,2,8,1,6,10,5,4,7};
        int k = 1;
        int res = Solution().kEmptySlots(flowers, k);
        cout<<res<<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_683_K_EMPTY_SLOTS_H
