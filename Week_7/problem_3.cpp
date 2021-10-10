#include <bits/stdc++.h>
using namespace std;

// Find the smallest weight of a path from source vertex to destination vertex of length exactly k
// Time Complexity: O(k*V^3)
// Space Complexity: O(k*n^2);


int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp3.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);
    //

    int n;
    cin >> n;
    
    vector<vector<int>> g(n, vector<int> (n, 0));
    // input the adjacency matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    int source, dest, k;
    cin >> source >> dest;
    cin >> k;

    // Idea: Path of length 7 = path of length 6 + edge_weight
    int dp[n][n][k+1];
    memset(dp, 0, sizeof(dp));
    for(int len=1;len<=k;len++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j][len] = 1e8;

                // e.g: 1-2-3-----x-----5
                // this loop finds that x, if there is one then 
                // path of length k from 1 to 5 = path of length k-1 from 1 to x + weight(x, 5);
                // Maintain minimum of all such paths
                for(int x=0;x<n;x++){
                    if(g[x][j] != 0 and (x != i or len == 1)){
                        dp[i][j][len] = min(dp[i][j][len], dp[i][x][len-1] + g[x][j]);
                    }
                }
            }
        }
    }

    if(dp[source-1][dest-1][k] >= 1e8) 
        cout << "No paths of length " << k << " from " << source << " to " << dest << " exists\n";
    else
        cout << "Weight of shortest path from " << source << " to " << dest
        << " with " << k << " edges: " << dp[source-1][dest-1][k] << '\n'; 
    return 0;
}
