#include <iostream>
#include "75. Sort Colors.h"


using namespace std;

int main() {
    int arr[] = {1, 1, 1, 2, 2, 0};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
    Solution().sortColors(vec);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }


    return 0;
}