#include<bits/stdc++.h>
using namespace std;


int partition(vector<pair<double, pair<int,int>>> &arr, int low, int high) {
    double pivot = arr[high].first;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].first >= pivot) {
            i++;  
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<pair<double, pair<int,int>>> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printPWRatio(const vector<pair<double, pair<int,int>>> &arr) {
    cout<<"Items sorted in descending order of P/W Ratio:"<<endl;
    for (const auto &item : arr) {
        cout << "(" << item.first << ", (" << item.second.first << ", " << item.second.second << "))\t";
        // cout << item.first << " ";
    }
    cout << endl;
}

double fractionalKnapsack(vector<pair<double, pair<int,int>>> &Items, int capacity) {
    quickSort(Items, 0, Items.size()-1);

    double totalVal = 0;
    double remW = capacity;
    int n = Items.size();

    for(int i=0 ; i<n ; i++){
        pair<int, int> curr = Items[i].second;

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
    int capacity, n;

    cout<<"Enter capacity of bag: ";
    cin>>capacity;
    cout<<"Enter no of items: ";
    cin>>n;


    vector<pair<double, pair<int,int>>> Items(n);

    cout<<"Enter profits: ";
    for(int i=0 ; i<n ; i++){
        cin>>Items[i].second.first;
    }

    cout<<"\nEnter weights: ";
    for(int i=0 ; i<n ; i++){
        cin>>Items[i].second.second;
    }

    for(int i=0 ; i<n ; i++){
        double r = (double(Items[i].second.first)/double(Items[i].second.second));
        Items[i].first = r;
    }

    double ans = fractionalKnapsack(Items, capacity);
    printPWRatio(Items);

    cout<<"Maximum profit: "<<ans<<endl;
    return 0;
}


//TESTCASES

/*
Capacity
No. of items
Profit
Weight

Testcase 1:
15
7
5 10 15 7 8 9 4
1 3 5 4 1 3 2
ANS: 51

Testcase 2:
50
3
60 100 120
10 20 30
ANS: 240

Testcase 3:
30
2
60 100
10 20
ANS: 160

*/