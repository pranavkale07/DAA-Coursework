// v1: display intermediate steps while calculating shortest distance (path not included)

#include<bits/stdc++.h>
using namespace std;

void printDistance(vector<int> &dist){
    int n = dist.size();
    for(int i=0; i<n; i++){
        if(dist[i] == INT_MAX){
            cout << "\u221E" << " ";
        }
        else{
            cout << dist[i] << " ";
        }
    }
}

void bellman_ford(int src, int n, vector<vector<int>> &edges){
    vector<int> dist(n, INT_MAX);
    vector<int> pred(n, -1);
    dist[src] = 0;
    pred[src] = 0;
    printDistance(dist);
    cout << endl;

    for(int i=0; i<n-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                pred[v] = u;
            }
        }
        printDistance(dist);
        cout << endl;
    }

    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
            cout << "Negative cycle exists in the graph" <<endl;
        }
    }
    return;
}

int main(){
    int n = 6;
    int src = 0;
    vector<vector<int>> edges = {{0,1,6}, {0,2,4},{0,3,5},
                                 {1,4,-1}, {2,1,-2}, {2,4,3},
                                 {3,2,-2}, {3,5,-1}, {4,5,3}};
    

    cout << "Source: " << char('A' + src) << endl;
    cout << "Vertex  : " << endl;
    for(int i=0; i<n; i++){
        cout << char('A' + i) << " ";
    }
    cout<<endl;
    // cout << "Distance: ";
    bellman_ford(src, n, edges);
    cout << endl;

    return 0;
}