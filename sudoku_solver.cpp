


#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row , int col , vector<vector<char>>&board ,char val){
    for(int i=0;i<9;i++){
        if(board[row][i]==val)return false;

        if(board[i][col]==val)return false;

        if(board[3*(row/3) +i/3][3*(col/3) +i%3]==val)return false;

    }
    return true;
}
bool solve(vector<vector<char>>&board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){

            if(board[i][j]=='.'){

                for(char val = '1' ;val<='9';val++){
                    if(isSafe(i ,j ,board , val)){
                        board[i][j]=val;
                        bool solveforMore = solve(board);
                        if(solveforMore){
                            return true;
                        }
                        else{
                            board[i][j]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
 void solveSudoku(vector<vector<char>>& board) {
       solve(board); 
    }
int main(){
    int n;
    cin>>n;
    vector<vector<char>>ans;
    char  a;
    // taking input into 2D vector from user
    for(int i=0 ; i<9 ; i++) {
         vector<char> p;
         for(int j=0 ; j<9 ; j++) {
              cin>>a;
              p.push_back(a);
         }
         ans.push_back(p);
    }
    

    solveSudoku(ans);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}
