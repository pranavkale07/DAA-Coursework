#include<bits/stdc++.h>
#include <Windows.h>
using namespace std;

void printDistance(vector<int> &dist){
    int n = dist.size();
    for(int i=0; i<n; i++){
        if(dist[i] == INT_MAX){
            // cout << "\u221E" << " ";
            SetConsoleOutputCP(CP_UTF8);
            printf(u8"\u221E");
            printf(" ");
        }
        else{
            cout << dist[i] << " ";
        }
    }
}

void printShortestPathToAll(int src, int n, vector<int> &pred){
    cout << endl << "Shortest path to each vertex from source: " << endl;
    for(int i=0; i<n; i++){
        string path = "";
        int curr = i;
        cout << char('A' + i) << ": ";
        path += char('A' + curr);
        if(curr != src)
                path += ">-";
        while(curr != src){
            path += char('A' + pred[curr]);
            curr = pred[curr];
            if(curr != src)
                path += ">-";
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
}

void bellman_ford(int src, int n, vector<vector<int>> &edges){
    vector<int> dist(n, INT_MAX);
    vector<int> pred(n, -1);
    dist[src] = 0;
    pred[src] = src;
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
            return;
        }
    }
    printShortestPathToAll(src, n, pred);
    return;
}

int main(){

    int n; // Number of vertices
    // cout << "Enter the number of vertices: ";
    cin >> n;

    int src; // Source vertex
    // cout << "Enter the source vertex (0-based index): ";
    cin >> src;

    vector<vector<int>> edges;

    // cout << "Enter the number of edges: ";
    int m; // Number of edges
    cin >> m;

    // cout << "Enter each edge in the format (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    cout << "Source: " << char('A' + src) << endl;
    cout << "Distances  : " << endl;
    for(int i=0; i<n; i++){
        cout << char('A' + i) << " ";
    }
    cout<<endl;
    // cout << "Distance: ";
    bellman_ford(src, n, edges);
    cout << endl;

    return 0;
}



/*
1)
{{0,1,6}, {0,2,4}, {0,3,5}, {1,4,-1}, {2,1,-2}, {2,4,3}, {3,2,-2}, {3,5,-1}, {4,5,3}}

6 0
9
0 1 6
0 2 4
0 3 5
1 4 -1
2 1 -2
2 4 3 
3 2 -2
3 5 -1
4 5 3

2)
{{0,1,2}, {1,2,2}, {1,3,-2}, {2,3,1}, {3,0,-1}}

4 0
5
0 1 2
1 2 2
1 3 -2
2 3 1
3 0 -1


3)
{{0,1,1}, {1,2,2}, {2,3,3}, {3,0,4}}

4 0
4
0 1 1
1 2 2
2 3 3
3 0 4


4)
{{0,1,2}, {0,2,7}, {1,2,9}, {1,3,5}, {2,3,-8}, {2,4,10}, {3,1,-3}, {4,3,5}}

5 0
8
0 1 2
0 2 7
1 2 9
1 3 5
2 3 -8
2 4 10
3 1 -3
4 3 5


5)
{{3,2,6}, {5,3,1}, {0,1,5}, {1,5,-3}, {1,2,-2}, {3,4,-2}, {2,4,3}}

6 0
7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3

*/