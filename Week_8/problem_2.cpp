#include <bits/stdc++.h>
using namespace std;

// Use Bellman Ford's Algorithm to find the shortest path to all vertices from a given source vertex
// Time Complexity: O(E*(V-1)) for edge list representation and O( V^2* (V-1) ) for adjacency matrix
// Space Complexity: O(V);

int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    //

    int n;
    cin >> n;
    
    vector<vector<int>> g(n+1, vector<int> (n+1, 0));
    // {a,b}, a represents the distance to that node, b represent the parent node that was used to reach this node 
    vector<pair<int,int>> distance(n+1, {1e8, -1});
    
    // input the adjacency matrix
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> g[i][j];
        }
    }

    // source node
    int source;
    cin >> source;

    distance[source] = {0, 0};
    // Relax nodes untill every node is processed
    for(int k=0;k<n-1;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // if(i == j) distance[j] = {0,j};
                if(g[i][j] == 0) continue;
                if(distance[i].first + g[i][j] < distance[j].first){
                    distance[j].first = distance[i].first + g[i][j];
                    distance[j].second = i; 
                }
            }
        }
    }
    // Backtrack the path
    for(int i=1;i<=n;i++){
        vector<int> path;
        int prev = distance[i].second;
        if(i != source){
            while(prev != 1){
                path.push_back(prev);
                prev = distance[prev].second;
            }   
        }
        path.push_back(source);
        cout << i << " ";
        for(auto &x: path){
            cout << x << ' ';
        }
        cout << ": " << distance[i].first << '\n';
    }    
    return 0;
}
