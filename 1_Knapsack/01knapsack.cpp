#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,c;
    cout<<"Enter the capacity of the bag: ";
    cin>>c;
    cout<<"Enter the no. of items available: ";
    cin>>n;

    int weight[n+1] = {0};
    int profit[n+1] = {0};

    cout<<"Enter weights of the items: ";
    for(int i=1 ; i<n+1 ; i++){
        cin>>weight[i];
    }

    cout<<"Enter profits of the items: ";
    for(int i=1 ; i<n+1 ; i++){
        cin>>profit[i];
    }


    int dp[n+1][c+1];   //DP matrix
    // we can further optimize this problem to use 1D dp array (as we only need the current and the row above it)

    for(int i=0 ; i<=c ; i++){  
        dp[0][i] = 0;       //Initializing 1st row with 0
    }
    for(int j=0 ; j<=n ; j++){
        dp[j][0] = 0;       //Initializing 1st column with 0    
    }

    for(int i=1; i<=n ; i++){
        for(int j=1 ; j<=c ; j++){
            if(weight[i] > j){
                //if weight of the item is greater than current bag capacity, copy above row's value
                dp[i][j] = dp[i-1][j];
            }
            else{
                //maximum of above row value and (current item's profit + profit of remaining size from above row)
                dp[i][j] = max(dp[i-1][j], (profit[i] + dp[i-1][j-weight[i]]));
            }
        }
    }

    cout<<"\nDP Matrix:"<<endl;
    for(int i=0; i<=n ; i++){
        for(int j=0 ; j<=c ; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    cout<<"Maximum profit is : "<<dp[n][c]<<endl;

    int res = dp[n][c];
    int w = c;

    cout<<"Following items are included:"<<endl;
    for(int i=n; i>0; i--){
        if(res == dp[i-1][w]){
            //this item is not included
            continue;
        }
        else{
            //this item is included in the bag
            cout<<"Item "<<i<<": "<<weight[i]<<", "<<profit[i]<<endl;
            res = dp[i-1][w - weight[i]];
            w = w - weight[i];
        }
    }

    return 0;
}



//TESTCASES

/*
Bag Capacity
No. of items
Weights
Profits

8
4
3 4 6 5
2 3 1 4
ANS: 6

8
4
2 3 4 5
1 2 5 6
ANS: 8


4
3
4 5 1
1 2 3
ANS: 220


*/