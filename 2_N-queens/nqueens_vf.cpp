#include<bits/stdc++.h>
using namespace std;

void printBoard(int queenPositions[], int n) {
    cout << "   ";
    for (int col = 0; col < n; ++col) {
        cout << col + 1 << " ";  
    }
    cout << endl;

    for(int i=1; i<=n; i++){
        cout<<i<<" |";
        for(int j=1; j<=n; j++){
            if(j == queenPositions[i])
                cout<<"Q"<<" ";
            else
                cout<<"- ";
        }
        cout<<endl;
    }
    cout << endl;
}

void displayMirror(int queenPositions[], int n) {
    cout << "   ";
    for (int col = 1; col <= n; ++col) {
        cout << col << " ";
    }
    cout << endl;

    for (int i=1; i<=n; i++) {  // Iterate from the last row to the first
        cout << i << " |";
        for (int j=1; j<=n; j++) {
            // Access the queen's position for the mirrored row
            if (queenPositions[n - i + 1] == j)  // The mirrored position of the queen
                cout << "Q ";
            else
                cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

bool placeQueen(int row, int col, int n, int queenPositions[]){
    for(int j=1; j<row; j++){
        if(queenPositions[j] == col || (abs(row-j) == abs(col - queenPositions[j]))){
            // cout<<"Unable to place "<<row<<" queen at position "<<row<<" "<<col<<endl;
            return false;
        }
    }
    // cout<<"Placed "<<row<<" queen at row "<<row<<" col "<<col<<endl;
    return true;
}

void nqueens(int currQueen, int n, int queenPositions[]){
    if (currQueen > n) {
        return;
    }
    for(int i=1; i<=n; i++){
        // cout << "Trying to place queen at row " << currQueen << ", col " << i << endl;
        if(placeQueen(currQueen, i, n, queenPositions)){
            queenPositions[currQueen] = i;
            printBoard(queenPositions, n);
            nqueens(currQueen+1, n, queenPositions);
            if (queenPositions[n] != 0) {  // Last queen placed, so complete solution is found, return
                return;
            }
            cout << "Backtracking: Removing queen from row " << currQueen << ", col " << i << endl;
            queenPositions[currQueen] = 0;
            printBoard(queenPositions, n);
        }    
    }
    cout << "Unable to place queen at row " << currQueen << ", backtracking..." << endl;
    
}

int main(){
    int n;
    // cout<<"Enter no. of queens: ";
    cin>>n;

    if(n<4){
        cout<<"Cannot solve N-Queens problem for value of N less than 4"<<endl;
        return 0;
    }
    int queenPositions[n+1] = {0};
    cout << "Trying to place queens" << endl;
    nqueens(1, n, queenPositions);

    // for(int i=1; i<=n; i++){
    //     cout<<queenPositions[i]<< " ";
    // }
    cout<<endl<<endl;
    cout<<"Solution 1:"<<endl;
    printBoard(queenPositions, n);
    cout<<endl;
    cout<<"Solution 2:"<<endl;
    displayMirror(queenPositions, n);
    return 0;
}

