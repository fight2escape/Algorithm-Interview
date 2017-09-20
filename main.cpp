#include <iostream>
#include "80. Remove Duplicates from Sorted Array II.h"


using namespace std;

int main() {
    int arr[] = {1, 1, 1, 2, 2, 3};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
    int len = Solution().removeDuplicates(vec);

    cout<<"len : "<<len<<endl;
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }


    return 0;
}