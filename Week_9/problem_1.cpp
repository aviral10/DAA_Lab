#include <bits/stdc++.h>
using namespace std;

// Implement Floyd-Warshall Shortest path algorithm
// Time Complexity: O(n^3)
// Space Complexity: O(1)



int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    //

    int n;
    cin >> n;
    string temp;
    vector<vector<int>> g(n+1, vector<int> (n+1, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> temp;
            if(temp != "INF"){
                g[i][j] = stoi(temp);
            }else{
                g[i][j] = 1e8;
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                g[i][j] = min({g[i][j], g[i][k]+g[k][j]});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j] >= 1e8) cout << "INF";
            else cout << g[i][j];
            cout << ' ';
        }
        cout << '\n';
    }


    



     
    return 0;
}
