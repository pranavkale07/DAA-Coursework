#include<bits/stdc++.h>
using namespace std;

// Solved using brute force approach

bool isValid(const vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Check if two queens are in the same column or diagonal
            if (board[i] == board[j] || abs(board[i] - board[j]) == abs(i - j)) {
                return false;
            }
        }
    }
    return true;
}

void printBoard(const vector<int>& board) {
    int n = board.size();
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (col == board[row]) {
                cout << 'Q' << ' ';
            } else {
                cout << ". " ;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void printBoard2(const vector<int>& board) {
    int n = board.size();
    for (int row = 0; row < n; ++row) {
        cout << board[row] << " ";
    }
    cout << endl;
}

void solveNQueens(int n) {
    int ans = 0;
    vector<int> board(n);
    for (int i = 0; i < n; ++i) {
        board[i] = i;
    }

    do {
        if (isValid(board)) {
        printBoard(board);
        ans++;
        break;
        }
    } while (next_permutation(board.begin(), board.end()));

    cout << endl << ans <<endl;
}

int main() {
    solveNQueens(8);
    return 0;
}
