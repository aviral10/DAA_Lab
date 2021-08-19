#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array of integers, 
// find  whether two elements exist such that their sum is equa to the given key element.
// Time Complexity: O(nlogn), Space Complexity: O(n)

int partition(vector<int> &arr, int low, int high, int key){
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= arr[key])i++;
        while(arr[j] > arr[key])j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[key], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low >= high) return;
    int n = arr.size();
    int p = partition(arr, low, high, low);
    quickSort(arr, low, p-1);
    quickSort(arr, p+1, high);
}

int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    //

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int sm;
        cin >> sm;
        quickSort(arr, 0, n-1);

        int i = 0, j = n-1;
        vector<pair<int,int>> ans;
        while(i < j){
           int curr = arr[i]+arr[j];
            if(curr == sm){
                ans.emplace_back(arr[i], arr[j]);
                i++;
                j--;
            }else if(curr < sm){
                i++;
            }else{
                j--;
            }
        }
        int sz = ans.size();
        if(sz != 0){
            for(int i=0;i<sz;i++){
                cout << ans[i].first << ' ' << ans[i].second << ",\n"[i==sz-1];
            }
        }else{
            cout << "No such pairs exist\n";
        }
    }
    return 0;
}
