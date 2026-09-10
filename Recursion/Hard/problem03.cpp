#include<bits/stdc++.h>
using namespace std;
bool isSafe(int vertex, int color, vector<int>& colors, vector<vector<int>>& adj){
    for(int neighbor : adj[vertex]){
        if(colors[neighbor] == color) return false;
    }
    return true;
}
bool solve(int vertex, vector<int>& colors, vector<vector<int>>& adj, int M, int N){
    if(vertex == N) return true;
    for(int color = 1; color <= M; color++){
    if(isSafe(vertex, color, colors, adj)){
        colors[vertex] = color;
        
        if(solve(vertex+1, colors, adj, M, N)) return true;
        
        colors[vertex] = 0;  // backtrack
    }
}
return false;
}

int main(){
    int N = 4, M = 3;
    vector<vector<int>> adj(N);
    
    // edges add karo: 0-1, 1-2
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    
    vector<int> colors(N, 0);
    cout<<boolalpha;
    cout << solve(0, colors, adj, M, N);
    
    return 0;

}