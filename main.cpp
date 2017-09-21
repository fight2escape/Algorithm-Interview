#include <iostream>
#include "215. Kth Largest Element in an Array.h"


using namespace std;

int main() {
    int arr[] = {7,6,5,4,3,2,1}, k = 2;
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
    int res = Solution().findKthLargest(vec, k);

    cout<<"res : "<<res<<endl;

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }


    return 0;
}