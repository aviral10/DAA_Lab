#include <bits/stdc++.h>
using namespace std;

// Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
// For a given value N, you have to Design an algorithm and implement it using a program to find
// number of ways in which these coins can be added to make sum value equals to N.
// Time Complexity: O(n*sm)
// Space Complexity: O(n*sm)

int dp[1003][1003];
int solve(vector<int> &arr, int i, int sm){
    if(sm == 0) return 1;
    if(i >= arr.size() or sm < 0) return 0;
    if(dp[i][sm] != -1) return dp[i][sm];
    int ans = solve(arr, i, sm-arr[i])+ solve(arr, i+1, sm);
    return dp[i][sm] = ans;
}


int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    //

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }
    int sm;
    cin >> sm;
    memset(dp, -1, sizeof(dp));

    cout << solve(arr, 0, sm) << '\n';
     
    return 0;
}
