#include<iostream>
#include <climits>
#include<vector>
using namespace std;
// int solve (int n , int x , int y , int z){
//     if(n==0){
// return 0;}

// if(n<0){
//     return INT_MIN;
// } 
//     int xincl =solve (n-x , x , y , z) +1;
//      int yincl =solve (n-y , x , y , z) +1;
//      int zincl =solve (n-z , x , y , z) +1;
//     int result = max (xincl , max(yincl , zincl));
//     return result ;
// }
int solveMemo(int n , int x ,int y ,int z , vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = max(solveMemo(n-x , x,y ,z ,dp) +1 , max(solveMemo(n-y , x , y , z ,dp) +1 , solveMemo (n-z , x , y ,z ,dp) +1));
    return dp[n];

}
int solveTab(int n , int x , int y , int z){
    vector<int> dp (n+1 , INT_MIN);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        if(i-x>=0)
        dp[i] = max(dp[i] , dp[i-x] +1);
         if(i-y>=0)
        dp[i] = max(dp[i] , dp[i-y] +1);
         if(i-z>=0)
        dp[i] = max(dp[i] , dp[i-z] +1);
    }
    if(dp[n]<0){
        return 0;
    }
    else 
    return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
   // int ans = solve ( n , x, y , z);
//    vector<int>dp(n+1,-1);
//    int ans = solveMemo(n , x , y , z , dp);
//     if(ans <0){
//         return 0;
//     }
//     else{
//         return ans;
//     } 
 
 int ans = solveTab(n , x , y , z);
  if(ans <0){
        return 0;
    }
    else{
        return ans;
    } 
}
int main(){

    int n ,x , y  , z;
    cin>>n>>x>>y>>z;
    int ans = cutSegments(n , x, y , z);
    cout<<ans<<endl;
}