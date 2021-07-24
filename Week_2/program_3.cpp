#include <bits/stdc++.h>
using namespace std;

// Given a key and an array return the count of pairs {a,b} such that a-b = key
// Time Complexity: O(N), Space Complexity: O(N)

int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp3.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);
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
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int k1 = arr[i]+key;
            int k2 = arr[i]-key;
            if(mp[k1] > 0) ans++;
            if(mp[k2] > 0) ans++;
            mp[arr[i]]++;
        }
        cout << ans << '\n';
    }

    return 0;
}
