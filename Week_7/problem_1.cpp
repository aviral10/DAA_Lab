#include <bits/stdc++.h>
using namespace std;

// Use Dijkstra's Algorithm to find the shortest path to all vertices from a given source vertex
// Time Complexity: O(ElogE) for(adjacency list) and O(V^2) for adjacency matrix, 
// Space Complexity: O(V);

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
    vector<int> visited(n+1, 0);

    // {a,b}, a represents the distance to that node, b represent the parent node that was used to reach this node 
    vector<pair<int,int>> distance(n+1, {INT_MAX, -1});

    // Priority queue to sort the edges  
    priority_queue<pair<int,int>, vector<pair<int, int>>,  greater<pair<int,int>>> q;
    
    // input the adjacency matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    
    // source node
    int source;
    cin >> source;

    // push the source node and mark it's distance as 0
    q.push({0, source});
    distance[source] = {0, 0};

    // Relax nodes untill every node is processed
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        visited[u] = 1;
        for(int i=1;i<=n;i++){
            if(g[u-1][i-1] != 0 and !visited[i]){
                int W = g[u-1][i-1];
                // Relaxation
                if(distance[u].first + W  < distance[i].first){
                    distance[i].first = distance[u].first+W;
                    distance[i].second = u;
                    q.push({distance[i].first, i});
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
