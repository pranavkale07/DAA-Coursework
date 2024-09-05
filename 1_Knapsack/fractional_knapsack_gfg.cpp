//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    bool static comp(Item val1, Item val2){
        double r1 = double(val1.value)/double(val1.weight);
        double r2 = double(val2.value)/double(val2.weight);
        if(r1 >= r2)
            return true;
        return false;
    }
    
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr, arr+n, comp);
        double totalVal = 0;
        double remW = w;
        
        for(int i=0 ; i<n ; i++){
            Item curr = arr[i];
            if(curr.weight <= remW){
                totalVal += curr.value;
                remW -= curr.weight;
            }
            else{
                totalVal += (double(curr.value)/double(curr.weight))*remW;
                break;
            }
        }
        return totalVal;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends