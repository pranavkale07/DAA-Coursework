#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int src, int n, vector<vector<int>> &edges){
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for(int i=0; i<n-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
            return {-1};
        }
    }

    return dist;
}

int main(){
    int n = 6;
    int src = 0;
    vector<vector<int>> edges = {{0,1,6}, {0,2,4},{0,3,5},
                                 {1,4,-1}, {2,1,-2}, {2,4,3},
                                 {3,2,-2}, {3,5,-1}, {4,5,3}};
    
    vector<int> distance = bellman_ford(src, n, edges);

    if(distance.size() == 1){
        cout << "Negative cycle exists in the graph" <<endl;
    }
    else{
        cout << "Source: " << src << endl;
        cout << "Vertex  : ";
        for(int i=0; i<n; i++){
            cout << char('A' + i) << " ";
        }
        cout<<endl;
        cout << "Distance: ";
        for(int i=0; i<n; i++){
            cout << distance[i] << " ";
        }
        cout << endl;
    }
    return 0;
}