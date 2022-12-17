#include<iostream>
using namespace std;

// bool isSafe(int row, int col ,vector<string> &board  ,int n){
//     int x= row; 
//     int y=col;
//     //Same row
//     while(y>=0){
//         if(board[x][y]=='Q'){
//             return false;
           
//         }
//          y--;
//     }

//     //Same diagonal
//     y=col;x=row;
//     //upper triangle
//     while(x>=0 &&y>=0){
//         if(board[x][y]=='Q'){
//             return false;
           
//         }
//          y--;
//          x--;
//     }

//     y=col;x=row;
//     //lower triangle
//     while(x<n &&y>=0){
//         if(board[x][y]=='Q'){
//             return false;
           
//         }
//          y--;
//          x++;
//     }
//     return true;

// }
// void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
// {
//     // Base Case
//     if (col == n)
//     {
//     //    addSolution(board,ans,n);
//     ans.push_back(board);
//             return ;
        
//     }
//     //Solving for 1 case and rest recursion will take care
//     for(int row = 0;row<n;row++){
//         if(isSafe(row,col ,board,n)){
//             board[row][col]='Q';
//             // Solve for next cols
//             solve(col+1,ans,board,n);
//             //Backtracking
//             board[row][col]='.';
//         }
//     }
// }
// vector<vector<string>> solveNQueens(int n)
// {
//    vector<string> board(n, string(n, '.'));
//    vector<vector<string>> ans;
//     solve(0, ans, board, n);
//     return ans;
// }


//Better Code using map
void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n ,unordered_map<int,bool>&checkDo , unordered_map<int,bool>&checkR , unordered_map<int,bool>&checkUp)
{
    
    if (col == n)
    {
    ans.push_back(board);
            return ;
        
    }
    //Solving for 1 case and rest recursion will take care
    for(int row = 0;row<n;row++){
          if(checkR[row]==false && checkDo[row+col] ==false && checkUp[n-1+col-row] ==false){
            board[row][col]='Q';
            // Solve for next cols
            checkR[row]=true;
            checkDo[row+col]=true;
            checkUp[n-1+(col-row)]=true;
            solve(col+1,ans,board,n , checkDo,checkR,checkUp);
            //Backtracking
            board[row][col]='.';
            checkR[row]=false;
            checkDo[row+col]=false;
            checkUp[n-1+(col-row)]=false;
        }
        
    }
}
vector<vector<string>> solveNQueens(int n )
{
    unordered_map<int,bool>checkR;
    
    unordered_map<int,bool>checkUp;
    
    unordered_map<int,bool>checkDo;
    
   vector<string> board(n, string(n, '.'));
   vector<vector<string>> ans;
    solve(0, ans, board, n , checkDo,checkR,checkUp);
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
