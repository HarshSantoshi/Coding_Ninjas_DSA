#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
bool isSafe(int newx , int newy ,  vector<vector<int>> &m , vector<vector<int>> & vis , int n){
        if(newx>=0 && newx<n &&newy>=0 &&newy<n && m[newx][newy]==1 && vis[newx][newy]!=1){
            return true;
        }
        return false;
    }
    void solve(int row , int col , vector<vector<int>> &m ,vector<string>&ans, string path , int n ,  vector<vector<int>>&vis){
        //base case
        if(row==n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        //Down
        if(isSafe(row+1 , col , m , vis,n)){
            vis[row][col]=1;
            solve(row+1 , col , m ,ans,path+'D' ,n ,vis);
            vis[row][col]=0;
        }
         //Left
        if(isSafe(row , col-1 , m , vis,n)){
            vis[row][col]=1;
           solve(row , col-1 , m ,ans,path+'L' ,n ,vis);
            vis[row][col]=0;
        }
         //Right
        if(isSafe(row , col+1 , m , vis,n)){
            vis[row][col]=1;
          solve(row , col+1 , m ,ans,path+'R' ,n ,vis);
            vis[row][col]=0;
        }
         //Up
        if(isSafe(row-1 , col , m , vis,n)){
            vis[row][col]=1;
            solve(row-1 , col , m ,ans,path+'U' ,n ,vis);
            vis[row][col]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string path ="";
        vector<string>ans;
        vector<vector<int>>vis(n ,vector<int>(n,0));
        if(m[0][0]==0){
            return ans;
        }
        solve(0 , 0, m ,ans, path ,n ,vis);
        return ans;
    }

    int main(){
        int n ;
        cin>>n;
        vector<vector<int>>maze(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>maze[i][j];
            }
        }
        vector<string>ans = findPath(maze , n);
        if(ans.size()==0){

            return -1;
        }
        else{
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            
        }
        cout<<endl;
    }
