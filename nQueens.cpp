#include<iostream>
using namespace std;

bool isSafe(int row, int col ,vector<string> &board  ,int n){
    int x= row; 
    int y=col;
    //Same row
    while(y>=0){
        if(board[x][y]=='Q'){
            return false;
           
        }
         y--;
    }

    //Same diagonal
    y=col;x=row;
    //upper triangle
    while(x>=0 &&y>=0){
        if(board[x][y]=='Q'){
            return false;
           
        }
         y--;
         x--;
    }

    y=col;x=row;
    //lower triangle
    while(x<n &&y>=0){
        if(board[x][y]=='Q'){
            return false;
           
        }
         y--;
         x++;
    }
    return true;

}
void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
{
    // Base Case
    if (col == n)
    {
    //    addSolution(board,ans,n);
    ans.push_back(board);
            return ;
        
    }
    //Solving for 1 case and rest recursion will take care
    for(int row = 0;row<n;row++){
        if(isSafe(row,col ,board,n)){
            board[row][col]='Q';
            // Solve for next cols
            solve(col+1,ans,board,n);
            //Backtracking
            board[row][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
   vector<string> board(n, string(n, '.'));
   vector<vector<string>> ans;
    solve(0, ans, board, n);
    return ans;
}

int main(){
int n ;
  cin>>n;
  vector<vector<string>>res =solveNQueens(n);
 
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<res[i][j];
    }
    cout<<endl;
}
  }
