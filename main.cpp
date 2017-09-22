#include <iostream>
#include <string>
#include <vector>
#include "209. Minimum Size Subarray Sum.h"


using namespace std;

int main() {
    int arr1[] = {2,3,1,2,4,3}, s1 = 7;
    int arr2[] = {}, s2 = 100;
    int arr3[] = {1,2,3,4,5}, s3 = 15;
    int arr4[] = {1,1}, s4 = 3;
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    vector<int> vec3(arr3, arr3 + sizeof(arr3)/sizeof(int));
    vector<int> vec4(arr3, arr4 + sizeof(arr4)/sizeof(int));
    int res1 = Solution().minSubArrayLen(s1, vec1);
    int res2 = Solution().minSubArrayLen(s2, vec2);
    int res3 = Solution().minSubArrayLen(s3, vec3);
    int res4 = Solution().minSubArrayLen(s4, vec4);

    cout<<"minSubArrayLen : "<<res1<<endl;
    cout<<"minSubArrayLen : "<<res2<<endl;
    cout<<"minSubArrayLen : "<<res3<<endl;
    cout<<"minSubArrayLen : "<<res4<<endl;

//    for(int i=0; i<res.size(); i++){
//        cout<<res[i]<<" ";
//    }



    return 0;
}