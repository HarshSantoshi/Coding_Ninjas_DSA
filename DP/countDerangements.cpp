#include<iostream>
#include<vector>
#define Mod 1000000007
using namespace std;
// long long int solveMemo(int n , vector<long long int > &dp){
//     if(n==1){
//         return 0;
//     }
//     if(n==2){
//         return 1;
//     }

//     if(dp[n]!=-1){
//         return dp[n];
//     }

    
//     dp[n] = (((n-1)%Mod) * ((solveMemo(n-1 , dp)%Mod) +(solveMemo(n-2 , dp)))%Mod;
//     return dp[n];
// }
// long long int solveTabo(int n){
//     vector<long long int>dp(n+1,0);
//     dp[1]=0;
//     dp[2]=1;

//     for(int i=3;i<=n;i++){
//          dp[i] = (((i-1)%Mod)*((dp[i-1])%Mod+ (dp[i-2])%Mod))%Mod;
//     }
//     return dp[n];
// }
long long int solveBest(int n){
  int prev2 = 0;
  int prev1 = 1;
    for(int i=3;i<=n;i++){
         long long int ans = (((i-1)%Mod)*((prev1)%Mod+ (prev2)%Mod))%Mod;
         prev2 = prev1;
         prev1 = ans;
    }
    return prev1;
}
long long int countDerangements(int n) {
    // Write your code here.
    // vector<long long int > dp(n+1, -1);
    // long long int ans = solveMemo(n , dp);
    long long int ans = solveBest(n);
}
int main(){
    int n ;
    cin>>n;
    long long int ans = countDerangements(n);
    cout<<ans<<endl;
}