#include <bits/stdc++.h>
using namespace std;

// Given a sorted array and a key return the number of occurrences of key in the array
// Time Complexity: O(logn), Space Complexity: O(1)


// bias = -1 denotes keep searching to the left
// bias = 1  denotes keep searching to the right
// bias = 0  denotes stop as soon as key is found
int binarySearch(vector<int> &arr, int key, int bias){
    int low = 0, high = arr.size()-1;
    while(low<=high){
        int mid = ((long long)low+high)/2;
        
        if(arr[mid] == key){
            if(bias == -1) high = mid-1;
            else if(bias == 1) low = mid+1;
            else return mid;
        }else if(arr[mid] < key) low = mid+1;
        else high = mid-1;
    }
    if(bias == -1) return low;
    else if(bias == 1) return high;
    else return -1;
}

int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    //

    int t;
    cin >> t;
    while(t--){
        int n, key;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        cin >> key;
        
        int left_ind = binarySearch(arr, key, -1);
        int right_ind = binarySearch(arr, key, 1);
        cout << key << "- " << right_ind-left_ind+1 << '\n';        
    }

    return 0;
}
