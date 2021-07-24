#include <bits/stdc++.h>
using namespace std;

// Find a squence of indices i < j < k in the sorted array such that arr[i]+arr[j]=arr[k].
// Time Complexity: O((n^2)logn), Space Complexity: O(1)
int binarySearch(vector<int> &arr, int low, int high, int key){
    while(low<=high){
        int mid = ((long long)low+high)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
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
        bool bro = 0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int key = arr[i]+arr[j];
                int k = binarySearch(arr, j+1, n-1, key);
                if(k != -1){
                    cout << i << ' ' << j << ' ' << k << ' ';
                    cout <<  " Elements: [" << arr[i] << ' ' << arr[j] << ' ' << arr[k] << "]\n";
                    bro = true;
                    break;
                }
            }if(bro) break;
        }
        if(!bro) cout << "No Sequence Found\n";
    }

    return 0;
}
