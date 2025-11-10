#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board,int row,int col,int n){
    //column
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q') return false;
    }

    //left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q') return false;
    }

    //right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}

void printboard(vector<string>& v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" "<<endl;
        }
}

void solvenqueen(vector<vector<string>>& res,vector<string>& board,int row,int n){
    if(row==n){
        res.push_back(board);
        return;
    }

     for (char c : board[row]) {
        if (c == 'Q') {
            solvenqueen(res, board, row + 1, n);
            return;
        }
    }

    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solvenqueen(res,board,row+1,n);
            board[row][col]='.';
        }
    }
}

int main(){
    int n, firstRow, firstCol;
    cout << "Enter board size (n): ";
    cin >> n;
    cout << "Enter row and column for first queen (0-based): ";
    cin >> firstRow >> firstCol;

    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    // Place the first queen
    if (firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n) {
        cout << "Invalid coordinates." << endl;
        return 1;
    }
    board[firstRow][firstCol] = 'Q';

    // Start solving from the next row
    solvenqueen(res, board, 0, n);

    // Print all solutions
    if (res.empty()) {
        cout << "No solution possible with first queen at (" << firstRow << ", " << firstCol << ")" << endl;
    } else {
        for (auto& solution : res) {
            printboard(solution);
            cout<<"next : "<<endl;
        }
    }
}