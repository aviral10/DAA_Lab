#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array of elements, design an algorithm and implement it using a program to
// find whether majority element exists or not. Also find median of the array. A majority element is
// an element that appears more than n/2 times, where n is the size of array.
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

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
    sort(arr.begin(), arr.end());
    int mx = 0;
    int ans = -1;
    for(int i=0;i<n-1;i++){
        int j = i;
        int c = 1;
        while(arr[j+1] == arr[i]){
            j++;
            c++;
        }
        mx = max(mx, c);
        i = j;
    }
    if(mx >= (n+1)/2){
        cout << "yes\n";
        cout << (arr[n/2]+arr[(n-1)/2])/2.0 << '\n';
    }else{
        cout << "no\n";
    }



    return 0;
}
