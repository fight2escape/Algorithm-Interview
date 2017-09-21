//
// Created by Shinelon on 2017/9/21.
//

#ifndef ALGORITHM_INTERVIEW2_167_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_H
#define ALGORITHM_INTERVIEW2_167_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /**
     * 大神版 3ms
     * 对撞指针
     * 两边向中间逐渐逼近，9ms
     * 直接返回{}，比使用vector快
     * nb[i] + nb[j] 不使用局部变量存储更快
     * @param nb
     * @param target
     * @return
     */
    vector<int> twoSum(vector<int>& nb, int target) {
        int i = 0, j = nb.size()-1;
        while(i<j){
            if(nb[i] + nb[j] < target){
                i++;
            }else if(nb[i] + nb[j] > target){
                j--;
            }else{
                return {i+1, j+1};
            }
        }
        return {};
    }


    /**
     * 菜鸟版 86ms
     * 遍历一遍O(n)，利用二分查找O(logn)，尝试找到第二个数
     * 总的时间复杂度 O(nlogn)
     * 空间复杂度 O(1) 没有额外开辟
     */

    int binarySearch(vector<int> numbers, int tar, int left, int right){
        int mid;
        while(left <= right){
            mid = left + (right - left)/2;
            if(numbers[mid] == tar){
                return mid;
            }else if(tar < numbers[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }

    vector<int> twoSum1(vector<int>& numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        int tar;
        int get;
        for(int i=0; i<n; i++){
            tar = target - numbers[i];
            get = binarySearch(numbers, tar, i+1, n-1);
            if(get >= 0){
                res.push_back(i+1);
                res.push_back(get+1);
                return res;
            }
        }
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_167_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_H
