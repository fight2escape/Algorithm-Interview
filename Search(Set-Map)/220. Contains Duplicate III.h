//
// Created by Shinelon on 2017/9/23.
//

#ifndef ALGORITHM_INTERVIEW2_220_CONTAINS_DUPLICATE_III_H
#define ALGORITHM_INTERVIEW2_220_CONTAINS_DUPLICATE_III_H

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * 滑动窗口 + 有序的表搜索
     * 将 |v+w| <= t，转化为 v-t <= w <= v+t
     * 接着利用下界函数获取到w最小的可能取值
     * 由于相加可能越界，需要使用(long long)转化为64位的
     * @param nums
     * @param k
     * @param t
     * @return
     */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> set;
        for(int i=0; i<nums.size(); i++){
            if(set.lower_bound((long long)nums[i]-(long long)t) != set.end() && *set.lower_bound((long long)nums[i]-(long long)t) <= (long long)nums[i]+(long long)t){
                return true;
            }
            set.insert((long long)nums[i]);
            if(set.size() == k+1){
                set.erase(nums[i-k]);
            }
        }
        return false;
    }
};

#endif //ALGORITHM_INTERVIEW2_220_CONTAINS_DUPLICATE_III_H
//vector<int> vec = {-2147483648,-2147483647};
//int k = 3;
//int v = 3;
//bool res = Solution().containsNearbyAlmostDuplicate(vec,k,v);
//cout<<"res:"<<res<<endl;