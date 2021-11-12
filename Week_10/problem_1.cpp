#include <bits/stdc++.h>
using namespace std;

// Given a list of activities with their starting time and finishing time. Your goal is to select
// maximum number of activities that can be performed by a single person such that selected
// activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
// activity is greater than or equal to the finishing time of the other activity. Assume that a person
// can only work on a single activity at a time.
// Time Complexity: O(nlogn)
// Space Complexity: O(n)



int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
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
    int prev = -1;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i].second.first > prev){
            prev = arr[i].first;
            ans.push_back(arr[i].second.second);
        }
    }
    cout << "No. of non-conflicting activities: " << ans.size() << '\n'; 
    cout << "List of selected activities: ";
    for(auto &x: ans){
        cout << x << ' ';
    }
    cout << '\n';




     
    return 0;
}
