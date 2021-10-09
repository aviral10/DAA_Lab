#include <bits/stdc++.h>
using namespace std;

// Use Prims Algorithm to Calculate Minimum Spanning Tree of a graph
// Time Complexity:
// Space Complexity: 


void primsMST(vector<vector<int>> &g){
    
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
    vector<vector<int>> g(n+1, vector<int> (n+1, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }


     
    return 0;
}
