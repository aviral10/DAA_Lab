#include <bits/stdc++.h>
using namespace std;

// Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
// deadline associated with it. You have to design an algorithm and implement it using a program to
// find maximum number of tasks that can be completed without crossing their deadlines and also
// find list of selected tasks.
// Time Complexity: O(nlogn)
// Space Complexity: O(1)



int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    //

    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].second.first;
    }
    for(int i=0;i<n;i++){
        cin >> arr[i].first;
        arr[i].second.second = i+1;
    }
    sort(arr.begin(), arr.end());
    int prev = 0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i].first-arr[i].second.first >= prev){
            prev += arr[i].second.first;
            ans.push_back(arr[i].second.second);
        }
    }
    sort(ans.begin(), ans.end());
    cout << "Maximum number of tasks: " << ans.size() << '\n'; 
    cout << "Selected task numbers: ";
    for(auto &x: ans){
        cout << x << ' ';
    }
    cout << '\n';
     
    return 0;
}
