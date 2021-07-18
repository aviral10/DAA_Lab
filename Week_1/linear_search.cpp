#include <bits/stdc++.h>
using namespace std;

// Given an array and a key, search the key in the array
// if found print the number of comparisons made else print -1

// Linear search
int linearSearch(vector<int> &arr, int key, int &comps){
    for(int i=0;i<(int)arr.size();i++){
        comps++;
        if(arr[i] == key){
            return comps;
        }
    }
    return -1;
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
        cin >> n >> key;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int comps = 0;
        int ans = linearSearch(arr, key, comps);
        if(ans == -1) cout << "Not ";
        cout << "Present " << comps << '\n';
    }

    return 0;
}
