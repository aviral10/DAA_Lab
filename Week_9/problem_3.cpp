#include <bits/stdc++.h>
using namespace std;

// Given an array of integers representing sizes of files, merge them in such a way 
// that the time required to merge them is mininum
// Two files take ai + aj amount of time for any 1<=i<j<= n;
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

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
    int mn = INT_MAX;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        q.push(arr[i]);
    }
    int ans = 0;
    while(q.size() != 1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a+b;
        q.push(a+b);
    }
    cout << ans << '\n';

    return 0;
}
