#include <bits/stdc++.h>
using namespace std;

// Implement Fractional Knapsack
// Time Complexity: O(nLogn)
// Space Complexity: O(n)

int main(){
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("inp2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    //

    int n;
    cin >> n;
    vector<int> weights(n);
    for(int i=0;i<n;i++){
        cin >> weights[i];
    }
    vector<int> cost(n);
    vector<int> knapsack(n);
    for(int i=0;i<n;i++){
        cin >> cost[i];
        knapsack[i] = i;
    }
    int W;
    cin >> W;
    sort(knapsack.begin(), knapsack.end(), [&](int a, int b){
        return (double)cost[a]/weights[a] > (double)cost[b]/weights[b];
    });

    double ans = 0;
    vector<pair<int,int>> choices;
    for(auto x: knapsack){
        double val = (double)cost[x]/weights[x];
        double amt = min(W, weights[x]);
        ans += val*amt;
        choices.push_back({x+1, amt});
        W -= min(W, weights[x]);
        if(W == 0) break;
    }
    cout << "Maximum Weight: ";
    cout << ans << '\n';
    cout << "Item-weight: \n";
    for(auto x: choices){
        cout << x.first << '-' << x.second << '\n';
    }
    return 0;
}
