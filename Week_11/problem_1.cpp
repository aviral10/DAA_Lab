#include <bits/stdc++.h>
using namespace std;

// Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
// matrices together. To find the optimal solution, you need to find the order in which these
// matrices should be multiplied. 
// Time Complexity: O(n^2)
// Space Complexity: O(n)

int dp[1003][1003];
int solve(vector<int> &arr, int i, int j){
    if(i >= j) return  0;
    
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][j] = min(dp[i][j], solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j];
}



int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    //
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin >> arr[i-1];
        cin >> arr[i];
    } 

    memset(dp, -1, sizeof(dp));
    cout << solve(arr, 1, n) << '\n';
     
    return 0;
}
