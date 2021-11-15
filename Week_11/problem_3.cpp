#include <bits/stdc++.h>
using namespace std;

// Given a set of elements, you have to partition the set into two subsets such that the sum of
// elements in both subsets is same. Design an algorithm and implement it using a program to solve
// this problem.
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

int dp[1003][1003];
bool solve(vector<int> &arr, int i, int sm){
    if(sm == 0) return true;
    if(i >= arr.size() or sm < 0) return false;

    if(dp[i][sm] != -1) return dp[i][sm];

    return dp[i][sm] = solve(arr,i+1,sm-arr[i]) or solve(arr, i+1, sm);
}   



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
    int sm = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sm += arr[i];
    }
    memset(dp, -1, sizeof(dp));
    if(sm%2 != 0){
        cout << "No\n";
        return 0;
    }
    sm /= 2;
    bool ans = solve(arr, 0, sm);
    if(ans){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}
