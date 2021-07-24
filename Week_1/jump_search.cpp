#include <bits/stdc++.h>
using namespace std;

// Given an array and a key, search the key in the array
// if found print the number of comparisons made else print -1


int binarySearch(vector<int> &arr, int low, int high, int key, int &comps){
    while(low<=high){
        int mid = ((long long)low+high)/2;
        comps++;
        if(arr[mid] == key) return comps;
        else if(arr[mid] < key) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int jumpSearch(vector<int> &arr, int key, int &comps){
    int low = 1, high = 2, n = arr.size();
    int factor = sqrt(n);
    while(high <= n){
        comps++;
        if(arr[high-1] > key) break;
        low = high;
        high += factor;
    }
    if(high > n) high = n;
    return binarySearch(arr, low-1, high-1, key, comps);
}



int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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
        int comps = 0;
        int ans = jumpSearch(arr, key, comps);
        if(ans == -1) cout << "Not ";
        cout << "Present " << comps << '\n';
    }
    return 0;
}
