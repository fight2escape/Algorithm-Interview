#include <iostream>
#include <string>
#include <vector>
#include "11. Container With Most Water.h"


using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
    int res = Solution().maxArea(vec);

    cout<<"maxArea : "<<res<<endl;

//    for(int i=0; i<res.size(); i++){
//        cout<<res[i]<<" ";
//    }



    return 0;
}