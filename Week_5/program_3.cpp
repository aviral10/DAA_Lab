#include <bits/stdc++.h>
using namespace std;

// Given 2 sorted arrays of size m and n respectively
// Find out common elements among the arrays.
// Time Complexity: O(m+n), Space Complexity: O(1)


int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp3.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);
    //
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    vector<int> brr(m);
    for(int i=0;i<m;i++){
        cin >> brr[i];
    }
    vector<int> ans;
    int i=0, j=0;
    while(i<n and j < m){
        if(arr[i] == brr[j]){
            ans.push_back(arr[i]);
            i++;
            j++;
        }else if(arr[i] < brr[j]){
            i++;
        }else{
            j++;
        }
    }
    for(auto &x: ans){
        cout << x << ' ';
    }
    cout << '\n';
    

    return 0;
}
