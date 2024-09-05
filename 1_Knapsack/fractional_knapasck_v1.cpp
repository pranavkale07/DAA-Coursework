#include<bits/stdc++.h>
using namespace std;

// solved using inbuilt sorting with custom comparator

bool comp(pair<int,int> item1, pair<int,int> item2){
    double r1 = double(item1.first)/double(item1.second);
    double r2 = double(item2.first)/double(item2.second);
    if(r1 >= r2)
        return true;
    return false;
}

double fractionalKnapsack(vector<pair<int,int>> &Items, int capacity) {
    sort(Items.begin(), Items.end(), comp);
    double totalVal = 0;
    double remW = capacity;
    int n = Items.size();

    for(int i=0 ; i<n ; i++){
        pair<int, int> curr = Items[i];

        if(curr.second <= remW){
            totalVal += curr.first;
            remW -= curr.second;
        }
        else{
            totalVal += (double(curr.first)/double(curr.second))*remW;
            break;
        }
    }
    return totalVal;
}


int main(){
    int capacity;

    // cout<<"Enter capacity of bag: ";
    cin>>capacity;

    int n;
    // cout<<"Enter no of items: ";
    cin>>n;

    vector<pair<int,int>> Items(n);

    // cout<<"Enter profits: ";
    for(int i=0 ; i<n ; i++){
        cin>>Items[i].first;
    }

    // cout<<"\nEnter weights: ";
    for(int i=0 ; i<n ; i++){
        cin>>Items[i].second;
    }

    double ans = fractionalKnapsack(Items, capacity);

    // cout<<"Maximum profit: "<<ans<<endl;
    cout<<ans;
    return 0;
}