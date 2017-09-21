#include <iostream>
#include <vector>
#include "167. Two Sum II - Input array is sorted.h"


using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7}, target = 8;
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
    vector<int> res = Solution().twoSum(vec, target);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }


    return 0;
}